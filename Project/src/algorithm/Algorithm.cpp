#include <iostream>

#include "Algorithm.h"

void lets_go(int sizePopulation, int sizePlasmideo, double cross, double elite, int limitIterations ){

	vector< Solution* > population;
	vector< Solution* > elitePopulation;
	vector< Solution* > selection;
	vector< Solution* > offspring;

	myPrint( "generation of population: ", true );
	population = generateInitialPopulation( sizePopulation );
	checkPopulation( population );
	std::cout << satisfaction_total_GLOBAL << std::endl;
	std::cout << selectBetter( population )->fitness << std::endl;
	myPrint( "ok" , true );

	myPrint( "multi operator local search: ", true );
	population = multiOperatorsLocalSearch( population );
	checkPopulation( population );
	myPrint( "ok" , true );

	myPrint( "select elite: ", true );
	elitePopulation = selectElite( elite, population );
	myPrint( "ok" , true );

	for ( int i = 0; i < limitIterations; i++ ){
		if( i % 10 != 0 ){
			myPrint( i, false );
			myPrint( "-crossover: ", true );
			selection = selectPopulation( cross, population );
			offspring = crossover( selection );
			myPrint( "ok", true );
		}else{
			myPrint( i, false );
			myPrint( "-plasmid: ", true );
			selection = selectPopulation( elite, population );
			offspring = plasmid( selection, sizePlasmideo, elitePopulation );
			myPrint( "ok", true );
		}

		myPrint( i, false );
		myPrint( "-restoring operations: ", true );
		offspring = restoringOperations( offspring );
		checkPopulation( offspring );
		myPrint( "ok", true );

		myPrint( i, false );
		myPrint( "-multi operator local search: ", true );
		population = multiOperatorsLocalSearch( population );
		checkPopulation( population );
		myPrint( "ok" , true );

		myPrint( i, false );
		myPrint( "-binary tournament: ", true );
		population = binaryTournament( population, offspring );
		checkPopulation( population );
		myPrint( "ok" , true );

		myPrint( i, false );
		myPrint( "-select elite: ", true );
		elitePopulation = selectElite( elite, population );
		myPrint( "ok", true );
	}

	std::cout << selectBetter( population )->fitness << std::endl;
}

