import re

def is_e( name ):
    if re.search("e$", name) and name != "att48Ae":
        return True
    else:
        return False

def is_n( name ):
    if re.search("n$", name) and name != "att48An":
        return True
    else:
        return False

def separate( data ):
    e = data[ data["instance"].apply( lambda x: is_e( x ) ) ]
    n = data[ data["instance"].apply( lambda x: is_n( x ) ) ]
    e = e.reset_index().drop( ["index"], axis=1 )
    n = n.reset_index().drop( ["index"], axis=1 )
    return e, n