set datafile separator ","
set title "DBSCAN (Eps=0.045, MinPoints=5)\nTrace 'Iberia-128-CA.chop1.1it.shifted.clustered.prv'" font ",13"
set xlabel "IPC"
set ylabel "Instructions Completed"
set key right outside
plot 'Iberia-128-CA.chop1.1it.shifted.clustered.clustered.csv' using 2:($4 == 4 ? $1 : 1/0) w points ps 1.5 lt rgbcolor "#b30000" title 'NOISE',\
'Iberia-128-CA.chop1.1it.shifted.clustered.clustered.csv' using 2:($4 == 5 ? $1 : 1/0) w points ps 1.5 lt rgbcolor "#00ff00" title 'Cluster 1',\
'Iberia-128-CA.chop1.1it.shifted.clustered.clustered.csv' using 2:($4 == 6 ? $1 : 1/0) w points ps 1.5 lt rgbcolor "#ffff00" title 'Cluster 2',\
'Iberia-128-CA.chop1.1it.shifted.clustered.clustered.csv' using 2:($4 == 7 ? $1 : 1/0) w points ps 1.5 lt rgbcolor "#eb0000" title 'Cluster 3',\
'Iberia-128-CA.chop1.1it.shifted.clustered.clustered.csv' using 2:($4 == 8 ? $1 : 1/0) w points ps 1.5 lt rgbcolor "#00a200" title 'Cluster 4',\
'Iberia-128-CA.chop1.1it.shifted.clustered.clustered.csv' using 2:($4 == 9 ? $1 : 1/0) w points ps 1.5 lt rgbcolor "#ff00ff" title 'Cluster 5',\
'Iberia-128-CA.chop1.1it.shifted.clustered.clustered.csv' using 2:($4 == 10 ? $1 : 1/0) w points ps 1.5 lt rgbcolor "#6464b1" title 'Cluster 6',\
'Iberia-128-CA.chop1.1it.shifted.clustered.clustered.csv' using 2:($4 == 11 ? $1 : 1/0) w points ps 1.5 lt rgbcolor "#acae29" title 'Cluster 7',\
'Iberia-128-CA.chop1.1it.shifted.clustered.clustered.csv' using 2:($4 == 12 ? $1 : 1/0) w points ps 1.5 lt rgbcolor "#ff901a" title 'Cluster 8',\
'Iberia-128-CA.chop1.1it.shifted.clustered.clustered.csv' using 2:($4 == 13 ? $1 : 1/0) w points ps 1.5 lt rgbcolor "#02ffb1" title 'Cluster 9',\
'Iberia-128-CA.chop1.1it.shifted.clustered.clustered.csv' using 2:($4 == 14 ? $1 : 1/0) w points ps 1.5 lt rgbcolor "#c0e000" title 'Cluster 10',\
'Iberia-128-CA.chop1.1it.shifted.clustered.clustered.csv' using 2:($4 == 15 ? $1 : 1/0) w points ps 1.5 lt rgbcolor "#424242" title 'Cluster 11',\
'Iberia-128-CA.chop1.1it.shifted.clustered.clustered.csv' using 2:($4 == 16 ? $1 : 1/0) w points ps 1.5 lt rgbcolor "#bda864" title 'Cluster 12'
pause -1 "Hit return to continue..."
