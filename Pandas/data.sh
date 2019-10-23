#!/bin/bash

python3 test.py "../Logs/results_memplas_e.csv" "../Logs/Results/memplas_e.csv"
python3 test.py "../Logs/results_memplas_n.csv" "../Logs/Results/memplas_n.csv"

python3 test.py "../Logs/results_memplas_path_e.csv" "../Logs/Results/memplas_path_e.csv"
python3 test.py "../Logs/results_memplas_path_n.csv" "../Logs/Results/memplas_path_n.csv"

python3 test.py "../Logs/results_operators_local_search_e.csv" "../Logs/Results/operators_local_search_e.csv"
python3 test.py "../Logs/results_operators_local_search_n.csv" "../Logs/Results/operators_local_search_n.csv"

python3 test.py "../Logs/results_path_e.csv" "../Logs/Results/path_e.csv"
python3 test.py "../Logs/results_path_n.csv" "../Logs/Results/path_n.csv"
