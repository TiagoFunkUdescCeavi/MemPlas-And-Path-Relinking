import pandas as pd

# state_of_art = pd.read_csv('../expected.csv')

# results = pd.read_csv('../Logs/results.csv')

# together = pd.merge(results, state_of_art, how ='inner', on ='instance')

# groups = together.groupby(['instance'])

# average = groups.mean()
# print( average )

# Leio o arquivo com os dados
data = pd.read_csv("../Logs/backup/results_memplas_2_bkp.csv")
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

# # Encontro o menor valor dos grupos
minimun = groups['result'].min().reset_index()
minimun.columns = ['instance','min']
# print( '>>>>>>>>> Minimun' )
# print( minimun )

# # Calculo quantas vezes o grupo chegou no resultado.
number_bests = groups['number_bests'].sum().reset_index()
number_bests.columns = ['instance','n_b']
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

# # Junto com os valores.
final = pd.merge(best, final, how ='inner', on ='instance')
print( '>>>>>>>>> Final' )
print( final )
