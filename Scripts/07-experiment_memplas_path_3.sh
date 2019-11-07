#!/bin/bash

cd $HOME
cd "Repositorios/Github/MemPlas-And-Path-Relinking/Instances/"

log=$HOME"/Repositorios/Github/MemPlas-And-Path-Relinking/Logs/results_memplas_path_3.csv"

echo "instance,strategy,result,time" > $log
for n in $(seq 1 7)
do
    for file in *
    do
	    if [ -f "$file" ]
	    then
		    echo "$n-$file"
		    ./../Project/Debug/Project 1 1 1 "$PWD/$file" --strategy mpr --sizePopulation 110 --elite 0.40 --limitIterations 3000 --sizePlasmideo 0.50 --cross 0.85 --selectionStrategy a --intermediaryStrategy stef >> $log && echo "Ok"
	    fi
    done
done

