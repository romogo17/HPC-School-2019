#!/bin/bash

export EXTRAE_HOME=/home/jgimenez/tools/extrae-3.6.1

export EXTRAE_CONFIG_FILE=extrae/extrae.xml
export LD_PRELOAD=${EXTRAE_HOME}/lib/libmpitrace.so # For C apps
#export LD_PRELOAD=${EXTRAE_HOME}/lib/libmpitracef.so # For Fortran apps

## Run the desired program
$*

