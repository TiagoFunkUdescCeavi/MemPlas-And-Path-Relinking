#!/bin/bash

cd $HOME
cd "Repositorios/Github/MemPlas-And-Path-Relinking/Instances/"

log=$HOME"/Repositorios/Github/MemPlas-And-Path-Relinking/Logs/results_only_path_relinking_1.csv"

echo "instance,strategy,result,time" > $log
for n in $(seq 1 8)
do
    for file in *
    do
	    if [ -f "$file" ]
	    then
		    echo "$n-$file"
		    ./../Project/Debug/Project 1 1 1 "$PWD/$file" --strategy opr --sizePopulation 195 --elite 0.4 --limitIterations 1900 --selectionStrategy a --intermediaryStrategy etsf >> $log && echo "Ok"
	    fi
    done
done

