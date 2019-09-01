
#ifndef SRC_SELECTELITE_H
#define SRC_SELECTELITE_H_

#include <vector>

#include "../model/Solution.h"
#include "../utils/utils.h"

vector< Solution* > selectElite( double elite, vector< Solution* > population );
vector< Solution* > selectForCrossover( double size, vector< Solution* > population );

#endif /* SRC_SELECTELITE_H_ */
