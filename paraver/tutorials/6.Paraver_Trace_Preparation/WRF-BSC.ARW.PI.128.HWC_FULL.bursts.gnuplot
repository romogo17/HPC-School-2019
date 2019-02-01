set title "Histogram of bursts"
set key top left
set ylabel "Num. bursts"
set y2label "% of running time"
set ytics nomirror
set y2tics
set y2range [1:100]
set xtics ("1 us" 0, "10 us" 2, "100 us" 4, "1 ms" 6, "10 ms" 8, "100 ms" 10, "1s" 12, "10 s" 14)
set offsets 2, 2, 0, 0
set style line 2 linecolor rgb "#32CD32"
set boxwidth 0.5 absolute
set style fill  solid 1.00 border -1
plot 'WRF-BSC.ARW.PI.128.HWC_FULL.bursts.dat' using 0:1 t "num burst" w lines, 'WRF-BSC.ARW.PI.128.HWC_FULL.bursts.dat' using 0:2 axes x1y2 ls 2 t "% of time" with boxes
