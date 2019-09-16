#include <iostream>
#include <string>

#include "Algorithm.h"

using namespace std;

void lets_go(int sizePopulation, int sizePlasmideo, double cross, double elite, int limitIterations ){

	vector< Solution > population;
	vector< Solution > elitePopulation;
	vector< Solution > selection;
	vector< Solution > offspring;

	myPrint( "generation of population:", 1 );
	population = generateInitialPopulation( sizePopulation );
	checkPopulation( population );
	myPrint( "ok" , 1 );

	myPrint( "multi operator local search:", 1 );
	population = multiOperatorsLocalSearch( population );
	checkPopulation( population );
	myPrint( "ok" , 1 );

	myPrint( "select elite:", 1 );
	elitePopulation = selectElite( elite, population );
	checkPopulation( elitePopulation );
	myPrint( "ok" , 1 );

	for ( int i = 0; i < limitIterations; i++ ){
		if( i % 10 != 0 ){
			myPrint( to_string(i) + "-crossover:", 1 );
			selection = selectPopulation( cross, population );
			offspring = crossover( selection );
			myPrint( "ok", 1 );
		}else{
			myPrint( to_string(i) + "-plasmid: ", 1 );
			selection = selectPopulation( elite, population );
			offspring = plasmid( selection, sizePlasmideo, elitePopulation );
			myPrint( "ok", 1 );
		}

		myPrint( to_string(i) + "-restoring operations: ", 1 );
		offspring = restoringOperations( offspring );
		checkPopulation( offspring );
		myPrint( "ok", 1 );

		myPrint( to_string(i) + "-multi operator local search: ", 1 );
		offspring = multiOperatorsLocalSearch( offspring );
		checkPopulation( population );
		myPrint( "ok" , 1 );

		myPrint( to_string(i) + "-binary tournament: ", 1 );
		population = binaryTournament( population, offspring );
		checkPopulation( population );
		myPrint( "ok" , 1 );

		myPrint( to_string(i) + "-select elite: ", 1 );
		elitePopulation = selectElite( elite, population );
		checkPopulation( population );
		myPrint( "ok", 1 );
	}

	Solution sol = selectBetter( population );
//	myPrint( satisfaction_total_GLOBAL, 0 );
//	myPrint( sol.satisfaction, 0 );
	myPrint( sol.toString(), 0 );
	myPrint( sol.fitness, 0 );
}

