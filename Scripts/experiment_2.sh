#!/bin/sh

log=""

cd $HOME

cp repositorios/github/MemPlas-And-Path-Relinking/Project/Debug/Project repositorios/github/MemPlas-And-Path-Relinking/Scripts/

file="China17n.pcar"

cd 
cd repositorios/github/MemPlas-And-Path-Relinking/Instances/n/

log=$HOME"/repositorios/github/MemPlas-And-Path-Relinking/Logs/"$file".log"
echo "$file"
echo "$file" > $log
./../../Scripts/Project $file 150 3 0.4 0.3 100 >> $log

