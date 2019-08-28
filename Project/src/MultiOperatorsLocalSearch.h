#ifndef SRC_MULTIOPERATORSLOCALSEARCH_H_
#define SRC_MULTIOPERATORSLOCALSEARCH_H_

#include <vector>

#include "Solution.h"

vector< Solution* > removeSaving( vector< Solution* > population );
vector< Solution* > invertSolution( vector< Solution* > population );
vector< Solution* > invertSavingCity( vector< Solution* > population );
vector< Solution* > replaceSavingCity( vector< Solution* > population );
vector< Solution* > replaceSavingCar( vector< Solution* > population );
vector< Solution* > operator_2opt( vector< Solution* > population );

vector< Solution* > multiOperatorsLocalSearch( vector< Solution* > population);

#endif /* SRC_MULTIOPERATORSLOCALSEARCH_H_ */
