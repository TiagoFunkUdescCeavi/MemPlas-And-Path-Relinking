#!/bin/bash

cd $HOME
cd "Repositorios/Github/MemPlas-And-Path-Relinking/Instances/"

log=$HOME"/Repositorios/Github/MemPlas-And-Path-Relinking/Logs/results_memplas_1.csv"

echo "instance,strategy,result,time" > $log
for n in $(seq 1 7)
do
    for file in *
    do
	    if [ -f "$file" ]
	    then
		    echo "$n-$file"
		    ./../../Project/Debug/Project 1 1 1 "$PWD/$file" --strategy m --sizePopulation 190 --elite 0.35 --limitIterations 1500 --sizePlasmideo 0.68 --cross 0.49 >> $log && echo "Ok"
	    fi
    done
done

