import pandas as pd
import numpy as np
import scipy.stats as stats
from statsmodels.stats.multicomp import pairwise_tukeyhsd
from statsmodels.stats.multicomp import MultiComparison

def anova_one_to_one( clear, file_anova, file_tukey, *datas ):
    together = pd.DataFrame()
    for d in datas:
        together = pd.concat( [together, d] )
    
    groups = together.groupby(["instance",'strategy'])
    
    other_groups = together.groupby(["instance"])
    
    instances = together["instance"].unique()

    if clear :
        fa = open( file_anova, "w")
        fa.write("")
        fa.close()
        
        ft = open( file_tukey, "w")
        ft.write("")
        ft.close()

    fa = open( file_anova, "w")
    ft = open( file_tukey, "a")
    
    for inst in instances:
        
        fvalue, pvalue = stats.f_oneway(
            # groups.get_group("m")["result"],
            # groups.get_group("pr")["result"],
            # groups.get_group("mpr")["result"],
            # groups.get_group("ols")["result"],
            groups.get_group( (inst,"om") )["result"],
            groups.get_group( (inst,"opr") )["result"],
            groups.get_group( (inst,"ompr") )["result"]
        )
        fa.write( inst + ";" + str( round( pvalue, 4 ) ) + "\n" )

        if pvalue < 0.05:
            mc = MultiComparison(
                other_groups.get_group(inst)["result"],
                other_groups.get_group(inst)["strategy"]
            )
            mc_results = mc.tukeyhsd()
            print( inst + ";" + str( round( pvalue, 4 ) ), file=ft )
            print( mc_results, file=ft )