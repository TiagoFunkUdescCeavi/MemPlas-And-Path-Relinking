import pandas as pd

state_of_art = pd.read_csv('../expected.csv')
print( state_of_art.head() )

results = pd.read_csv('../Logs/results.csv')
print( results.head() )
