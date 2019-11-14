import pandas as pd
import numpy as np
import scipy.stats as stats
import matplotlib.pyplot as plt

def graphics( fig_name, *datas ):
    together = pd.DataFrame()
    for d in datas:
        together = pd.concat( [together, d] )
    
    groups = together.groupby(['strategy'])
    
    # data = pd.DataFrame(groups.get_group("m")["result"])
    # data["x"] = groups.get_group("pr")["result"]
    # data["y"] = groups.get_group("mpr")["result"]
    # data["z"] = groups.get_group("ols")["result"]
    data = pd.DataFrame(groups.get_group("om")["result"])
    data["b"] = groups.get_group("opr")["result"]
    data["c"] = groups.get_group("ompr")["result"]
    data.columns = [
    #    "M", "PR", "M + PR","BL",
        "OM", "OPR", "OMPR"
    ]
    plot = data.boxplot(column=[
    #    "M", "PR", "M + PR","BL", 
        "OM", "OPR", "OMPR"
    ], grid=False )
    
    plt.ylabel("Qualidade da melhor solução")
    plt.xlabel("Algoritmos")
    
    fig = plot.get_figure()
    fig.savefig(fig_name)

    plt.close()
