#!/bin/bash

echo $PWD

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
echo "Generate Tables "

python3 generateTable.py "../Logs/Results/memplas_e.csv" "../Logs/Results/tex/memplas_e.tex" "Resultados para o algoritmo memplas nas instâncias euclidianas" "resultadosMemplasEuclidianas"
python3 generateTable.py "../Logs/Results/memplas_n.csv" "../Logs/Results/tex/memplas_n.tex" "Resultados para o algoritmo memplas nas instâncias não euclidianas" "resultadosMemplasNaoEuclidianas"
echo "memplas"

python3 generateTable.py "../Logs/Results/memplas_path_e.csv" "../Logs/Results/tex/memplas_path_e.tex" "Resultados para o algoritmo memplas com \textit{Path Relinking} nas instâncias euclidianas" "resultadosMemplasPathEuclidianas"
python3 generateTable.py "../Logs/Results/memplas_path_n.csv" "../Logs/Results/tex/memplas_path_n.tex" "Resultados para o algoritmo memplas com \textit{Path Relinking} nas instâncias não euclidianas" "resultadosMemplasPathNaoEuclidianas"
echo "memplas and path"

python3 generateTable.py "../Logs/Results/operators_local_search_e.csv" "../Logs/Results/tex/operators_local_search_e.tex" "Resultados para o algoritmo apenas com as buscas locais nas instâncias euclidianas" "resultadosBuscasEuclidianas"
python3 generateTable.py "../Logs/Results/operators_local_search_n.csv" "../Logs/Results/tex/operators_local_search_n.tex" "Resultados para o algoritmo apenas com as buscas locais nas instâncias não euclidianas" "resultadosBuscasNaoEuclidianas"
echo "local search"

python3 generateTable.py "../Logs/Results/path_e.csv" "../Logs/Results/tex/path_e.tex" "Resultados para o algoritmo com \testit{Path Relinking} nas instâncias euclidianas" "resultadosPathEuclidianas"
python3 generateTable.py "../Logs/Results/path_e.csv" "../Logs/Results/tex/path_n.tex" "Resultados para o algoritmo com \testit{Path Relinking} nas instâncias Não euclidianas" "resultadosPathNaoEuclidianas"
echo "path"

echo "Ok"
