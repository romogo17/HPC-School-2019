#!/bin/bash

source /home/jgimenez/tools/extrae-3.6.1/etc/extrae.sh

export EXECUTABLE=./pi

${EXTRAE_HOME}/bin/extrae -config extrae.xml ${EXECUTABLE}
