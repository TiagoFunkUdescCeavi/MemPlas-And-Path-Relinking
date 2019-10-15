#!/bin/bash

cd $HOME
cd "Repositorios/Github/MemPlas-And-Path-Relinking/Instances/"

log=$HOME"/Repositorios/Github/MemPlas-And-Path-Relinking/Logs/results_path_4.csv"

echo "instance,strategy,result,time" > $log
for n in $(seq 1 7)
do
    for file in *
    do
	    if [ -f "$file" ]
	    then
		    echo "$n-$file"
		    ./../Project/Debug/Project 1 1 1 "$PWD/$file" --strategy pr --sizePopulation 215 --elite 0.55 --limitIterations 2000 --selectionStrategy a --intermediaryStrategy stef >> $log && echo "Ok"
	    fi
    done
done

