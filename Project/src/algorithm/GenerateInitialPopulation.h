#ifndef GENERATEINITIALPOPULATION_H_
#define GENERATEINITIALPOPULATION_H_

#include <vector>

#include "../GLOBAL.h"
#include "../model/Solution.h"

vector< Solution* > generateInitialPopulation( int sizePopulation );
vector< int > initAndShuffle( int vectorSize, bool hasCities );
int selectCityWithHeuristic( int car, int cityInit, vector< int > citiesNotVisited );

#endif /* GENERATEINITIALPOPULATION_H_ */
