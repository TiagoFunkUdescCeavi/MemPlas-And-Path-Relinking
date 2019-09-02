#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "../utils/Validate.h"
#include "GenerateInitialPopulation.h"
#include "MultiOperatorsLocalSearch.h"
#include "Selections.h"
#include "Crossover.h"
#include "Plasmideo.h"

void lets_go(int sizePopulation, int sizePlasmideo, double cross, double elite, int limitIterations );

#endif /* ALGORITHM_H_ */
