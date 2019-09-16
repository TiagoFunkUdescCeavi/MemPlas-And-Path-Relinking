#!/bin/bash

cd $HOME
cd "Repositorios/Github/MemPlas-And-Path-Relinking/Validator/Debug/"

./Validator ../../Instances/expected.txt ../../Logs/results.log > ../../Logs/check.log
