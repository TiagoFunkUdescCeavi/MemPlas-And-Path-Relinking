#!/bin/bash

cd $HOME
cd "Repositorios/Github/MemPlas-And-Path-Relinking/Irace/"

rm Project
rm target-runner

cp "../Project/Debug/Project" "."

mv Project target-runner
