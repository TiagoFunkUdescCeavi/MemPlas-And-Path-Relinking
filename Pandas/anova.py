import sys
import pandas as pd
import numpy as np
import scipy.stats as stats

# data = pd.read_csv( "../Logs/test_anova.csv")
# plot = data.boxplot(column=['a', 'b', 'c', 'd'], grid=False)
# fig = plot.get_figure()
# fig.savefig("fig.pdf")
# fvalue, pvalue = stats.f_oneway( data["a"], data["b"], data["c"], data["d"] )
# print( fvalue )
# print( pvalue )

data1 = pd.read_csv( sys.argv[1] )
data2 = pd.read_csv( sys.argv[2] )
data3 = pd.read_csv( sys.argv[3] )
data4 = pd.read_csv( sys.argv[4] )

together = pd.concat([data1, data2, data3, data4 ])

groups = together.groupby(['strategy'])

data = pd.DataFrame(groups.get_group("m")["result"])
data["x"] = groups.get_group("pr")["result"]
data["y"] = groups.get_group("mpr")["result"]
data["z"] = groups.get_group("ols")["result"]
data.columns = ["Memplas", "Path Relinking", "Memplas + Path R.","Locals searchs"]
plot = data.boxplot(column=["Memplas", "Path Relinking", "Memplas + Path R.","Locals searchs"], grid=False)
fig = plot.get_figure()
fig.savefig("fig.pdf")

fvalue, pvalue = stats.f_oneway( groups.get_group("m")["result"], groups.get_group("pr")["result"], groups.get_group("mpr")["result"], groups.get_group("ols")["result"] )
print( fvalue )
print( pvalue )
