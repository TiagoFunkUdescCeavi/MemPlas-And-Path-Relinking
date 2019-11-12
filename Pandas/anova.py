import sys
import pandas as pd
import numpy as np
import scipy.stats as stats
import matplotlib.pyplot as plt

data1 = pd.read_csv( sys.argv[1] )
data2 = pd.read_csv( sys.argv[2] )
data3 = pd.read_csv( sys.argv[3] )
data4 = pd.read_csv( sys.argv[4] )
data5 = pd.read_csv( sys.argv[5] )
data6 = pd.read_csv( sys.argv[6] )
data7 = pd.read_csv( sys.argv[7] )
name_fig = sys.argv[8]

together = pd.concat([data1, data2, data3, data4, data5, data6, data7 ])

groups = together.groupby(['strategy'])

data = pd.DataFrame(groups.get_group("m")["result"])
data["x"] = groups.get_group("pr")["result"]
data["y"] = groups.get_group("mpr")["result"]
data["z"] = groups.get_group("ols")["result"]
data["a"] = groups.get_group("om")["result"]
data["b"] = groups.get_group("opr")["result"]
data["c"] = groups.get_group("ompr")["result"]
data.columns = ["P", "PR", "P + PR","BL", "OM", "OPR", "OMPR"]
plot = data.boxplot(column=["P", "PR", "P + PR","BL", "OM", "OPR", "OMPR"], grid=False )
# plot.set_title("Boxplot dos resultados para cada algoritmo")
plt.ylabel("Qualidade da melhor solução")
plt.xlabel("Algoritmos")
# plt.figure(figsize=(15,4))
fig = plot.get_figure()
fig.savefig(name_fig+".pdf")

fvalue, pvalue = stats.f_oneway( 
    groups.get_group("m")["result"], groups.get_group("pr")["result"],
    groups.get_group("mpr")["result"], groups.get_group("ols")["result"],
    groups.get_group("om")["result"], groups.get_group("opr")["result"],
    groups.get_group("ompr")["result"] )
# print( fvalue )
print( pvalue )
