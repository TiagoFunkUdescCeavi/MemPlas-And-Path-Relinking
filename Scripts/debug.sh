#!/bin/bash

cd $HOME
cd "Repositorios/Github/MemPlas-And-Path-Relinking/Instances/n/"

for file in *
do
	if [ -f "$file" ]
	then
		log=$HOME"/Repositorios/Github/MemPlas-And-Path-Relinking/Logs/"$file".log"
		echo "$file"
		echo "$file" > $log
		./../../Project/Debug/Project 0 "$PWD/$file" 150 3 0.4 0.3 100 >> $log && echo "Ok"
	fi
done

cd "../e/"

for file in *
do
	if [ -f "$file" ]
	then
		log=$HOME"/Repositorios/Github/MemPlas-And-Path-Relinking/Logs/"$file".log"
		echo "$file"
		echo "$file" > $log
		./../../Project/Debug/Project 0 "$PWD/$file" 150 3 0.4 0.3 100 >> $log && echo "Ok"
	fi
done
