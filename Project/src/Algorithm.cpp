#include "Algorithm.h"

#include "Validate.h"

#include "GenerateInitialPopulation.h"
#include "MultiOperatorsLocalSearch.h"
#include "Selections.h"

void lets_go(int sizePopulation, int sizePlasmideo, double cross, double elite, int limitIterations ){

//	limitIterations = 1;

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
	checkPopulation( population );
	myPrint( "ok" , true );

	myPrint( "select elite: ", true );
	elitePopulation = selectElite( elite, population );
	myPrint( "ok" , true );

	while( numberIterations < limitIterations ){

		myPrint( "select", true );
		selection = selectForCrossover( elite, population );
		checkPopulation( population );
		myPrint( "ok", true );

		if( numberIterations % 10 != 0 ){

		}else{

		}

		numberIterations++;
	}

}

