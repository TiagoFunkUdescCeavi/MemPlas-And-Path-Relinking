#!/bin/bash

log=""

cd $HOME

cp repositorios/github/MemPlas-And-Path-Relinking/Project/Debug/Project repositorios/github/MemPlas-And-Path-Relinking/Scripts/

cd 
cd repositorios/github/MemPlas-And-Path-Relinking/Instances/n/

for file in *
do
	if [ -f "$file" ]
	then
		log=$HOME"/repositorios/github/MemPlas-And-Path-Relinking/Logs/"$file".log"
		echo "$file"
		echo "$file" > $log
		./../../Scripts/Project $file 150 3 0.4 0.3 100 >> $log
	fi
done
