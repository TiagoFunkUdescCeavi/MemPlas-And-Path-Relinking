#ifndef SRC_ALGORITHM_H_
#define SRC_ALGORITHM_H_

#include "Validate.h"

#include "GenerateInitialPopulation.h"
#include "MultiOperatorsLocalSearch.h"

void lets_go(int sizePopulation, int sizePlasmideo, double cross, double elite, int limitIterations ){

	bool test;
	int numberIterations = 0;
	vector< Solution* > population;
	vector< Solution* > elitePopulation;
	vector< Solution* > selection;
	vector< Solution* > offspring;

	numberIterations++;
	population = generateInitialPopulation( sizePopulation );
	test = checkPopulation( population );

	population = multiOperatorsLocalSearch( population );
	test = checkPopulation( population );
}

#endif /* SRC_ALGORITHM_H_ */
