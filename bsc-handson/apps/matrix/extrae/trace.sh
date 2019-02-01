#!/bin/bash

export EXTRAE_HOME=/home/jgimenez/tools/extrae-3.6.1
#export EXTRAE_HOME=/home/jgimenez/tools_old/extrae-3.6.1_mpich-3.2.1

export EXTRAE_CONFIG_FILE=extrae/extrae.xml
export LD_PRELOAD=${EXTRAE_HOME}/lib/libomptrace.so # For C apps

## Run the desired program
$*

