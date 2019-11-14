import pandas as pd

def joinTables( file_best, file_output, *datas ):
    together = pd.read_csv( file_best )

    for d in datas:
        together = pd.merge(together, d, how ='inner', on ='instance')
    
    cols = ["Instâncias","Melhor"]
    for i in range( 0, len( datas ) ):
        cols.append( "Média" )
        cols.append( "Melhor")
    
    together.columns = cols
    return together