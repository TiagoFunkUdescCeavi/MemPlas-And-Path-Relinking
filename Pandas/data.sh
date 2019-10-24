#!/bin/bash

process() {
	echo "Process "
	python3 process.py "../Logs/results_memplas_e.csv" "../Logs/Results/memplas_e.csv"
	python3 process.py "../Logs/results_memplas_n.csv" "../Logs/Results/memplas_n.csv"
	echo "memplas"

	python3 process.py "../Logs/results_memplas_path_e.csv" "../Logs/Results/memplas_path_e.csv"
	python3 process.py "../Logs/results_memplas_path_n.csv" "../Logs/Results/memplas_path_n.csv"
	echo "memplas and path"

	python3 process.py "../Logs/results_operators_local_search_e.csv" "../Logs/Results/operators_local_search_e.csv"
	python3 process.py "../Logs/results_operators_local_search_n.csv" "../Logs/Results/operators_local_search_n.csv"
	echo "local search"

	python3 process.py "../Logs/results_path_e.csv" "../Logs/Results/path_e.csv"
	python3 process.py "../Logs/results_path_n.csv" "../Logs/Results/path_n.csv"
	echo "path"

	echo "Ok"
}

joinTables() {
	python3 joinTables.py "../Logs/Results/memplas_e.csv" "../Logs/Results/memplas_path_e.csv" "../Logs/Results/operators_local_search_e.csv" "../Logs/Results/path_e.csv" "../expected.csv" "../Logs/Results/together_e.csv"
}

generateTables() {
	echo "Generate Tables"
	python3 generateTable.py "../Logs/Results/together_e.csv" "../Logs/Results/tex/together_e.tex" "Resultados nas instâncias euclidianas" "resultadosEuclidianas"
	echo "Ok"
}

joinTables
generateTables
