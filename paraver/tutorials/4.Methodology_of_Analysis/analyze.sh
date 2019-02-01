#!/bin/sh
#
#  usage: ./compute_shifts.pl trace.prv
#  generates: file with offsets needed to synchronize across all processes
#             the start time of the last useful state
#


rm output.mcr
/home/jesus/bin/Pedro/paramedir $1.prv /data/cfgs/methodology/parallel_efficiency.cfg
efficiency=`grep Average output.mcr |  awk '/Running/ {print $(NF-1)}'`
loadbalance=`grep Avg output.mcr |  awk '/Running/ {print $(NF-1)}'`
comm_eff=`grep Maximum output.mcr |  awk '/Running/ {print $(NF-1)}'`
echo global efficiency is:  $efficiency
echo global load balance is:  $loadbalance
echo communication efficiency is: $comm_eff

rm output.mcr
/home/jesus/bin/juan/Dimemas -S 32K -pa $1.ideal.prv  ideal.cfg >dimemas.ideal.out
/home/jesus/bin/Pedro/paramedir $1.ideal.prv /data/cfgs/methodology/parallel_efficiency.cfg
microloadbalance=`grep Maximum output.mcr |  awk '/Running/ {print $(NF-1)}'`
echo ... microscopic load balance is:  $microloadbalance

ideal_time=`grep Paraver $1.ideal.prv | awk 'BEGIN { FS=":|_"} {print $3}'`
real_time=`grep Paraver $1.prv | awk 'BEGIN { FS=":|_"} {print $3}'`
real_comm_eff=`expr $ideal_time \* 1000 / $real_time`
echo ... actual communication efficiency:  0.$real_comm_eff

echo
echo Other metrics

rm output.mcr
/home/jesus/bin/Pedro/paramedir $1.prv /data/cfgs/methodology/Instructions_profile.cfg
computational_loadbalance=`grep Avg output.mcr |  awk '/Running/ {print $NF}'`
echo global computational load balance is:  $computational_loadbalance

rm output.mcr
/home/jesus/bin/Pedro/paramedir $1.prv /data/cfgs/methodology/IPC_profile.cfg
IPC_balance=`grep Avg output.mcr |  awk '/Running/ {print $NF}'`
echo global IPC balance is:  $IPC_balance

