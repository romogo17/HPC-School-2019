# Kabré Supercomputer tutorial

**Useful links**

- [Cluster Guide](http://cluster.cenat.ac.cr/guia/)
- [PBS jobs monitor](http://cluster.cenat.ac.cr/torquitor/)
- [Environment modules software](http://modules.sourceforge.net/)

## PBS file example


| Configuration | Description                                                         |
| ------------- | ------------------------------------------------------------------- |
| -N            | Specify the job’s name                                             |
| -q            | In which queue should it run                                        |
| -l nodes      | Requested number of nodes                                           |
| :ppn          | Process per node                                                    |
| -l walltime   | Approximate job’s duration                                         |
| -m / -M       | Send an email when the job begins (`b`), ends (`e`) or aborts (`a`) |

```pbs
#PBS -N pi_threads
#PBS -q phi-n1h72
#PBS -l nodes=1:ppn=1
#PBS -l walltime=00:15:00
#PBS -M example@mail.com
#PBS -m bea

cd $PBS_O_WORKDIR
time ./pi_threads 64 100000000000
```
To queue this job execute the following command:

```sh
qsub pi_threads.pbs
```

## Monitor an active job
```sh
watch -n 5 qstat -a
```
To watch all jobs in the cluster, or:
```sh
watch -n 5 'qstat -a | grep [job id]'
```
To watch a specific job.

## Retrieving results
By default, every job will generate two output files, corresponding to standard output and standard error, following the name convention below:

```
[job_name].o[job_id]
[job_name].e[job_id]
```

## Environment Modules

Different users have different needs, sometimes those needs could be conflincting, for example, multiple versions of the same library. These situations are solved with [environment modules](http://modules.sourceforge.net/).

```sh
# List available modules
module avail

# Load a module
module load [module name]

# Unload a module
module unload [module name]

# List loaded modules
module list
```