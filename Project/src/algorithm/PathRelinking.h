#ifndef PATHRELINKING_H_
#define PATHRELINKING_H_

#include <vector>

#include "../model/Solution.h"

using namespace std;

Solution startToEnd( Solution initial, Solution goal );

vector< Solution > pathRelinking( vector< Solution > elite, string selectionStrategy, string intermediaryStrategy );

#endif /* PATHRELINKING_H_ */
