import pandas as pd

def process( data, fileOutput ):
    groups = data.groupby(['instance'])
    
    average = groups['result'].mean().reset_index()
    average.columns = ['instance','average']
    
    minimun = groups['result'].min().reset_index()
    minimun.columns = ['instance','minimal']
    
    final = pd.merge(average, minimun, how ='inner', on ='instance')
    
    final = final.round(1)

    return final
