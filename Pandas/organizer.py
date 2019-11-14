import sys
import pandas as pd

import instance_separator
import process
import joinTables
import generateTable

fm = "../Logs/results_memplas.csv"
fpr = "../Logs/results_path.csv"
fmpr = "../Logs/results_memplas_path.csv"
fols = "../Logs/results_operators_local_search.csv"
fom = "../Logs/results_only_memplas.csv"
fopr = "../Logs/results_only_path.csv"
fompr = "../Logs/results_only_memplas_path.csv"

m_e, m_n = instance_separator.separate( pd.read_csv( fm ) )
pr_e, pr_n = instance_separator.separate( pd.read_csv( fpr ) )
mpr_e, mpr_n = instance_separator.separate( pd.read_csv( fmpr ) )
ols_e, ols_n = instance_separator.separate( pd.read_csv( fols ) )
om_e, om_n = instance_separator.separate( pd.read_csv( fom ) )
opr_e, opr_n = instance_separator.separate( pd.read_csv( fopr ) )
ompr_e, ompr_n = instance_separator.separate( pd.read_csv( fompr ) )

print( "instance separator")

p_m_e = process.process( m_e, "../Logs/Results/m_e.csv" )
p_m_n = process.process( m_n, "../Logs/Results/m_n.csv" )
p_pr_e = process.process( pr_e, "../Logs/Results/pr_e.csv" )
p_pr_n = process.process( pr_n, "../Logs/Results/pr_n.csv" )
p_mpr_e = process.process( mpr_e, "../Logs/Results/mpr_e.csv" )
p_mpr_n = process.process( mpr_n, "../Logs/Results/mpr_n.csv" )
p_ols_e = process.process( ols_e, "../Logs/Results/ols_e.csv" )
p_ols_n = process.process( ols_n, "../Logs/Results/ols_n.csv" )
p_om_e = process.process( om_e, "../Logs/Results/om_e.csv" )
p_om_n = process.process( om_n, "../Logs/Results/om_n.csv" )
p_opr_e = process.process( opr_e, "../Logs/Results/opr_e.csv" )
p_opr_n = process.process( opr_n, "../Logs/Results/opr_n.csv" )
p_ompr_e = process.process( ompr_e, "../Logs/Results/ompr_e.csv" )
p_ompr_n = process.process( ompr_n, "../Logs/Results/ompr_n.csv" )

print( "process" )


generateTable.generateTable(
    joinTables.joinTables( 
        "../expected.csv", "../Logs/Results/together_e.csv", 
        p_m_e, p_pr_e, p_mpr_e, p_ols_e, p_om_e, p_opr_e, p_ompr_e 
    ), 
    "Resultados nas instâncias euclidianas", 
    "resultadosEuclidianas", 
    "../Logs/Results/tex/together_e.tex"
)

generateTable.generateTable(
    joinTables.joinTables(
        "../expected.csv", "../Logs/Results/together_e.csv", 
        p_m_e, p_pr_e, p_mpr_e, p_ols_e, p_om_e, p_opr_e, p_ompr_e 
    ),
    "Resultados nas instâncias não euclidianas",
    "resultadosNaoEuclidianas",
    "../Logs/Results/tex/together_n.tex"
)
print( "Join tables and Generates tables")