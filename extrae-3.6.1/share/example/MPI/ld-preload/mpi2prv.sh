#!/bin/bash

source /home/jgimenez/tools/extrae-3.6.1/etc/extrae.sh

${EXTRAE_HOME}/bin/mpi2prv -f TRACE.mpits -o mpi_ping.prv
