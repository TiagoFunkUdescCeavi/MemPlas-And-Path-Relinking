#ifndef SRC_SELECTELITE_H
#define SRC_SELECTELITE_H_

#include <vector>

#include "Solution.h"
#include "utils.h"

vector< Solution* > selectElite( double elite, vector< Solution* > population );
vector< Solution* > selectForCrossover( double size, vector< Solution* > population );

#endif /* SRC_SELECTELITE_H_ */
