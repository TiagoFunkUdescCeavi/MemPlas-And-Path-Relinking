#!/bin/bash

cd $HOME

#cp -f Repositorios/Github/MemPlas-And-Path-Relinking/Project/Debug/Project Repositorios/Github/MemPlas-And-Path-Relinking/Scripts/ && echo "Executavel copiado!!"

instance="Canada17n.pcar"
log=$HOME"/Repositorios/Github/MemPlas-And-Path-Relinking/Logs/"$file".log"
file=$HOME"/Repositorios/Github/MemPlas-And-Path-Relinking/Instances/n/"$instance
exe=$HOME"/Repositorios/Github/MemPlas-And-Path-Relinking/Project/Debug/"

#cd 
#cd Repositorios/Github/MemPlas-And-Path-Relinking/Instances/n/

for count in $(seq 0 10)
do
	log=$HOME"/Repositorios/Github/MemPlas-And-Path-Relinking/Logs/"$instance"."$count".log"
	echo "$instance:$count"
	echo $log
	echo "$file:$count" > $log
	cd /home/tiago/Repositorios/Github/MemPlas-And-Path-Relinking/Project/Debug/
	./Project $count $file 150 3 0.4 0.3 100 >> $log
done

