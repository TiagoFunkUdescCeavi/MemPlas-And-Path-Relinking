#!/bin/bash

cd $HOME
cd "Repositorios/Github/MemPlas-And-Path-Relinking/Instances/"

log=$HOME"/Repositorios/Github/MemPlas-And-Path-Relinking/Logs/results_only_memplas_2.csv"

echo "instance,strategy,result,time" > $log
for n in $(seq 1 8)
do
    for file in *
    do
	    if [ -f "$file" ]
	    then
		    echo "$n-$file"
		    ./../Project/Debug/Project 1 1 1 "$PWD/$file" --strategy om --sizePopulation 200 --elite 0.5 --limitIterations 1500 --sizePlasmideo 0.50 --cross 0.55 >> $log && echo "Ok"
	    fi
    done
done

