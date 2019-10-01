import pandas as pd

state_of_art = pd.read_csv('../expected.csv')
print( state_of_art.head() )

results = pd.read_csv('../Logs/results.csv')
print( results.head() )

shallow_now = pd.merge(results, state_of_art, how ='inner', on ='instance')
print( shallow_now )

group = results.groupby(['instance']).get_group('AfricaSul11e')
print( group['result'].mean() )