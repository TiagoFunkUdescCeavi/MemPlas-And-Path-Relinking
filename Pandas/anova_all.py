import pandas as pd
import scipy.stats as stats
from statsmodels.stats.multicomp import MultiComparison

def anova_all( type, file_output, *datas ):
    together = pd.DataFrame()
    for d in datas:
        together = pd.concat( [together, d] )
    
    groups = together.groupby(['strategy'])
    
    fvalue, pvalue = stats.f_oneway(
        # groups.get_group("m")["result"],
        # groups.get_group("pr")["result"],
        # groups.get_group("mpr")["result"],
        # groups.get_group("ols")["result"],
        groups.get_group("om")["result"],
        groups.get_group("opr")["result"],
        groups.get_group("ompr")["result"]
    )
    
    f = open( file_output, "a" )
    f.write( type + ":" + str( pvalue ) + "\n" )

    if pvalue < 0.05:
        mc = MultiComparison(
            together["result"],
            together["strategy"]
        )
        mc_results = mc.tukeyhsd()
        print( str( round( pvalue, 4 ) ), file=f )
        print( mc_results, file=f )

