#!/bin/bash

cd $HOME
cd "Repositorios/Github/MemPlas-And-Path-Relinking/Instances/"

log=$HOME"/Repositorios/Github/MemPlas-And-Path-Relinking/Logs/results.log"

echo "instance,strategy,result,time" > $log

for file in *
do
	if [ -f "$file" ]
	then
		echo "$file"
		echo -n "$file" >> $log
		./../Project/Debug/Project 1 1 1 "$PWD/$file" -strategy m --sizePopulation 150 --elite  0.3 --limitIterations 100 --sizePlasmideo 0.2 --cross 0.4 >> $log
	fi
done
