#ifndef SRC_ALGORITHM_H_
#define SRC_ALGORITHM_H_

#include "Validate.h"

#include "GenerateInitialPopulation.h"

void lets_go(int sizePopulation, int sizePlasmideo, double cross, double elite, int limitIterations ){

	int numberItetarions = 0;
	vector< Solution* > population;
	vector< Solution* > elitePopulation;
	vector< Solution* > selection;
	vector< Solution* > offspring;

	numberItetarions++;
	population = generateInitialPopulation( sizePopulation );

	bool test = checkPopulation( population );

}

#endif /* SRC_ALGORITHM_H_ */
