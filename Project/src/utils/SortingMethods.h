#ifndef SORTINGMETHODS_H_
#define SORTINGMETHODS_H_

#include <vector>

#include "../model/Solution.h"
#include "../model/Pair.h"

vector< Solution * > quicksort( vector< Solution * > population );
Pair * quicksort( Pair *values, int size );

#endif /* SORTINGMETHODS_H_ */
