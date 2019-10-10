#!/bin/bash

cd $HOME
cd "Repositorios/Github/MemPlas-And-Path-Relinking/Instances/"

log=$HOME"/Repositorios/Github/MemPlas-And-Path-Relinking/Logs/results_operators_local_search_1.csv"

echo "instance,strategy,result,time" > $log
for n in $(seq 1 15)
do
    for file in *
    do
	    if [ -f "$file" ]
	    then
		    echo "$n-$file"
		    ./../Project/Debug/Project 1 1 1 "$PWD/$file" --strategy ols --sizePopulation 190 --elite 0.35 --limitIterations 1500 >> $log && echo "Ok"
	    fi
    done
done

