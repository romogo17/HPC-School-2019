#!/bin/bash

export PYTHONPATH=/home/jgimenez/tools/extrae-3.6.1/libexec:$PYTHONPATH
export EXTRAE_CONFIG_FILE=./extrae.xml

python ./test.py

