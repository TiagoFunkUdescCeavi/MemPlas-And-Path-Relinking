#ifndef SRC_ALGORITHM_H_
#define SRC_ALGORITHM_H_

#include "Validate.h"

#include "GenerateInitialPopulation.h"
#include "MultiOperatorsLocalSearch.h"

void lets_go(int sizePopulation, int sizePlasmideo, double cross, double elite, int limitIterations ){

	int numberIterations = 0;
	vector< Solution* > population;
	vector< Solution* > elitePopulation;
	vector< Solution* > selection;
	vector< Solution* > offspring;

	myPrint( "generation of population: ", true );
	population = generateInitialPopulation( sizePopulation );
	checkPopulation( population );
	myPrint( "ok" , true );

	myPrint( "multi operator local search: ", true );
	population = multiOperatorsLocalSearch( population );
	myPrint( "ok" , true );
	myPrint( "check population: ", true );
	checkPopulation( population );
	myPrint( "ok" , true );
}

#endif /* SRC_ALGORITHM_H_ */
