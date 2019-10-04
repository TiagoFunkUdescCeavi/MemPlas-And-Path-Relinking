import pandas as pd

# state_of_art = pd.read_csv('../expected.csv')

# results = pd.read_csv('../Logs/results.csv')

# together = pd.merge(results, state_of_art, how ='inner', on ='instance')

# groups = together.groupby(['instance'])

# average = groups.mean()
# print( average )


data = pd.read_csv("../Logs/test.csv")
print( data )
print( '>>>>>>>>>' )

groups = data.groupby(['key'])

average = groups['value'].mean().reset_index()
print( average )
print( '>>>>>>>>>' )

minimun = groups['value'].min().reset_index()
print( minimun )
print( '>>>>>>>>>' )

final = pd.merge(average, minimun, how ='inner', on ='key')
# final = pd.merge(final, data['key','best'], how ='inner', on ='key')
# final.columns = ['key','mean','min']
print( final )
print( '>>>>>>>>>' )