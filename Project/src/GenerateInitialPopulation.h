#ifndef SRC_GENERATEINITIALPOPULATION_H_
#define SRC_GENERATEINITIALPOPULATION_H_

#include <vector>

#include "Solution.h"
#include "GLOBAL.h"

vector< Solution* > generateInitialPopulation( int sizePopulation );
vector< int > initAndShuffle( int vectorSize, bool hasCities );
int selectCityWithHeuristic( int car, int cityInit, vector< int > citiesNotVisited );

#endif /* SRC_GENERATEINITIALPOPULATION_H_ */
