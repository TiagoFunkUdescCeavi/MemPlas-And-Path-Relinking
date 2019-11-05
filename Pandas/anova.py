import sys
import pandas as pd
import numpy as np
import scipy.stats as stats
import matplotlib.pyplot as plt

data1 = pd.read_csv( sys.argv[1] )
data2 = pd.read_csv( sys.argv[2] )
data3 = pd.read_csv( sys.argv[3] )
data4 = pd.read_csv( sys.argv[4] )
name_fig = sys.argv[5]

together = pd.concat([data1, data2, data3, data4 ])

groups = together.groupby(['strategy'])

data = pd.DataFrame(groups.get_group("m")["result"])
data["x"] = groups.get_group("pr")["result"]
data["y"] = groups.get_group("mpr")["result"]
data["z"] = groups.get_group("ols")["result"]
data.columns = ["Plasmídeo", "Path Relinking", "Plasmídeo + Path R.","Buscas Locais"]
plot = data.boxplot(column=["Plasmídeo", "Path Relinking", "Plasmídeo + Path R.","Buscas Locais"], grid=False)
# plot.set_title("Boxplot dos resultados para cada algoritmo")
plt.ylabel("Qualidade da melhor solução")
plt.xlabel("Algoritmos")
fig = plot.get_figure()
fig.savefig(name_fig+".pdf")

fvalue, pvalue = stats.f_oneway( groups.get_group("m")["result"], groups.get_group("pr")["result"], groups.get_group("mpr")["result"], groups.get_group("ols")["result"] )
# print( fvalue )
print( pvalue )
