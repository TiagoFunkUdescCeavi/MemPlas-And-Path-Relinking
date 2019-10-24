import sys
import pandas as pd

fileInput = sys.argv[1]
fileOutput = sys.argv[2]

# Leio o arquivo com os dados
data = pd.read_csv( sys.argv[1] )

# Separo por grupos
groups = data.groupby(['instance'])

# # Calculo as medias dos grupos
average = groups['result'].mean().reset_index()
average.columns = ['instance','average']

# # Encontro o menor valor dos grupos
minimun = groups['result'].min().reset_index()
minimun.columns = ['instance','minimal']

# # Junto a média e os valores minimos
final = pd.merge(average, minimun, how ='inner', on ='instance')

# Realizo arrendondamento para três casas decimais
final = final.round(1)
# print( '>>>>>>>>> Final' )
# print( final )

csv = final.to_csv( sys.argv[2], index=False, float_format='%.1f' )
