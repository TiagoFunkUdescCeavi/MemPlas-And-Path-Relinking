#ifndef MULTIOPERATORSLOCALSEARCH_H_
#define MULTIOPERATORSLOCALSEARCH_H_

#include <vector>

#include "../model/Solution.h"

vector< Solution* > removeSaving( vector< Solution* > population );
vector< Solution* > invertSolution( vector< Solution* > population );
vector< Solution* > insertSavingCity( vector< Solution* > population );
vector< Solution* > replaceSavingCity( vector< Solution* > population );
vector< Solution* > replaceSavingCar( vector< Solution* > population );
vector< Solution* > operator_2opt( vector< Solution* > population );

vector< Solution* > multiOperatorsLocalSearch( vector< Solution* > population);

#endif /* MULTIOPERATORSLOCALSEARCH_H_ */
