import pandas as pd
import numpy as np
import scipy.stats as stats
import matplotlib.pyplot as plt

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
    
    file = open( file_output, "a" )
    file.write( type + ":" + str( pvalue ) + "\n" )

