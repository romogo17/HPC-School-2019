#!/bin/bash

source /home/jgimenez/tools/extrae-3.6.1/etc/extrae.sh

export EXTRAE_CONFIG_FILE=extrae.xml
export EXECUTABLE=./pi_instrumentedf # This is taken by extrae.xml

${EXECUTABLE}
