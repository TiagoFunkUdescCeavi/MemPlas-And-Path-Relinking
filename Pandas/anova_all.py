import sys
import pandas as pd
import numpy as np
import scipy.stats as stats
from statsmodels.stats.multicomp import pairwise_tukeyhsd
from statsmodels.stats.multicomp import MultiComparison

data1 = pd.read_csv( sys.argv[1] )
data2 = pd.read_csv( sys.argv[2] )
data3 = pd.read_csv( sys.argv[3] )
data4 = pd.read_csv( sys.argv[4] )

together = pd.concat([data1, data2, data3, data4 ])

groups = together.groupby(["instance",'strategy'])

other_groups = together.groupby(["instance"])

instances = together["instance"].unique()
algorithms = together["strategy"].unique()

for inst in instances:
    fvalue, pvalue = stats.f_oneway( 
        groups.get_group( (inst,"m") )["result"], 
        groups.get_group( (inst,"pr") )["result"], 
        groups.get_group((inst,"mpr"))["result"],
        groups.get_group((inst,"ols"))["result"] 
    )
    print( inst+";"+str(round(pvalue,4)) )

    if pvalue < 0.05:
        mc = MultiComparison( other_groups.get_group(inst)["result"], other_groups.get_group(inst)["strategy"] )
        mc_results = mc.tukeyhsd()
        print(mc_results.summary())