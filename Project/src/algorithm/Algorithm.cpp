#include "Algorithm.h"

void lets_go(int sizePopulation, int sizePlasmideo, double cross, double elite, int limitIterations ){

	int numberIterations = 1;
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

	while( numberIterations <= limitIterations ){

		if( numberIterations % 10 != 0 ){
			myPrint( numberIterations, false );
			myPrint( "-crossover: ", true );
			selection = selectPopulation( cross, population );
			offspring = crossover( selection );
			myPrint( "ok", true );
		}else{
			myPrint( numberIterations, false );
			myPrint( "-plasmid: ", true );
			selection = selectPopulation( elite, population );
			offspring = plasmid( selection, sizePlasmideo, elitePopulation );
			myPrint( "ok", true );
		}
		numberIterations++;
	}

}

