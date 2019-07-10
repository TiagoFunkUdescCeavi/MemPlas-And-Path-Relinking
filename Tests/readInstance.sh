#!/bin/bash

cp "../MemPlas Project/Debug/MemPlas" "./"

for arq in ../Instances/n/*
do
    ./MemPlas $arq
done
