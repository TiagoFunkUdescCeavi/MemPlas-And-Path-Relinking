import sys
import pandas as pd

# Leio o arquivo com os dados
# "../Logs/results_memplas.csv"
data = pd.read_csv( sys.argv[1] )
# print( '>>>>>>>>> Data' )
# print( data )

# Leio o arquivo com os valores de melhor solução.
best = pd.read_csv("../expected.csv")
# print( '>>>>>>>>> Best' )
# print( best )

# # Junto os dados com as melhores soluções
together = pd.merge(data, best, how ='inner', on ='instance')
# print( '>>>>>>>>> Together' )
# print( together )

# # Calculo uma nova coluna com o valor da diferença entre o valor e a melhor solução.
together['difference'] = together['result']-together['state_of_art'];
# print( '>>>>>>>>> Together' )
# print( together )

# # defino a função que vai indicar que o valor é igual a melhor solução.
def count_equal_best(difference):
    if difference == 0:
        return 1
    else:
        return 0

# # Aplico a função anterior e crio uma nova coluna para salvar esse valor.
together['number_bests'] = together.apply(lambda x:count_equal_best(x['difference']),axis=1)
# print( '>>>>>>>>> Together' )
# print( together )

# # Separo por grupos
groups = together.groupby(['instance'])

# # Calculo as medias dos grupos
average = groups['result'].mean().reset_index()
average.columns = ['instance','average']
# print( '>>>>>>>>> Average' )
# print( average )

time_average = groups['time'].mean().reset_index()
time_average.columns = ['instance','time_average']
# print( '>>>>>>>>> time average' )
# print( time_average )

# # Encontro o menor valor dos grupos
minimun = groups['result'].min().reset_index()
minimun.columns = ['instance','minimal']
# print( '>>>>>>>>> Minimun' )
# print( minimun )

# # Calculo quantas vezes o grupo chegou no resultado.
number_bests = groups['number_bests'].sum().reset_index()
number_bests.columns = ['instance','bests']
# print( '>>>>>>>>> number_bests' )
# print( number_bests )

# # Junto a média e os valores minimos
final = pd.merge(average, minimun, how ='inner', on ='instance')
# print( '>>>>>>>>> Final' )
# print( final )

# # Junto a média e os valores minimos com o número de melhores resultados
final = pd.merge(final, number_bests, how ='inner', on ='instance')
# print( '>>>>>>>>> Final' )
# print( final )

# # Junto com os melhores valores.
final = pd.merge(best, final, how ='inner', on ='instance')

# # Junto com a média de tempo.
final = pd.merge(final, time_average, how ='inner', on ='instance')
final = final.round(3)
# print( '>>>>>>>>> Final' )
# print( final )

csv = final.to_csv( sys.argv[2], index=False, float_format='%.3f' )
