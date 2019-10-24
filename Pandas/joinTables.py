import sys
import pandas as pd

f1 = sys.argv[1]
f2 = sys.argv[2]
f3 = sys.argv[3]
f4 = sys.argv[4]
best = sys.argv[5]
out = sys.argv[6]

t1 =  pd.read_csv( f1 )
t2 =  pd.read_csv( f2 )
t3 =  pd.read_csv( f3 )
t4 =  pd.read_csv( f4 )

best = pd.read_csv(best)

together = pd.merge(best, t1, how ='inner', on ='instance')
together = pd.merge(together, t2, how ='inner', on ='instance')
together = pd.merge(together, t3, how ='inner', on ='instance')
together = pd.merge(together, t4, how ='inner', on ='instance')
together.columns = ['instance', 'best','average','minimal','average','minimal','average','minimal','average','minimal']

csv = together.to_csv( out, index=False, float_format='%.1f' )
