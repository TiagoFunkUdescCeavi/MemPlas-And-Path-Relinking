#!/bin/bash

cp "../Project/Debug/Project" "./"

for arq in ../Instances/n/*
do
    ./Project $arq
done
