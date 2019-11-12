import sys
import pandas as pd

f1 = sys.argv[1]
f2 = sys.argv[2]
f3 = sys.argv[3]
f4 = sys.argv[4]
f5 = sys.argv[5]
f6 = sys.argv[6]
f7 = sys.argv[7]
best = sys.argv[8]
out = sys.argv[9]

t1 =  pd.read_csv( f1 )
t2 =  pd.read_csv( f2 )
t3 =  pd.read_csv( f3 )
t4 =  pd.read_csv( f4 )
t5 =  pd.read_csv( f5 )
t6 =  pd.read_csv( f6 )
t7 =  pd.read_csv( f7 )

best = pd.read_csv(best)

together = pd.merge(best, t1, how ='inner', on ='instance')
together = pd.merge(together, t2, how ='inner', on ='instance')
together = pd.merge(together, t3, how ='inner', on ='instance')
together = pd.merge(together, t4, how ='inner', on ='instance')
together = pd.merge(together, t5, how ='inner', on ='instance')
together = pd.merge(together, t6, how ='inner', on ='instance')
together = pd.merge(together, t7, how ='inner', on ='instance')
together.columns = ['Instância', 'Melhor','Média','Melhor','Média','Melhor','Média','Melhor','Média','Melhor','Média','Melhor','Média','Melhor','Média','Melhor']

csv = together.to_csv( out, index=False, float_format='%.1f' )
