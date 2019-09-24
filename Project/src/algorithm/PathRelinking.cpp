#include "PathRelinking.h"

#include "../utils/SortingMethods.h"
#include "../utils/Prints.h"

Solution startToEnd( Solution initial, Solution goal ){
	Solution better = goal;

	initial.calculeFitness();
	goal.calculeFitness();
	if( initial.fitness < goal.fitness ){
		better = initial;
	}else{
		better = goal;
	}

	for( int i = 0; i < initial.position-1; i++ ){
		myPrint( to_string( i ), 0, true );
		myPrint( goal.toString(), 0 );

		goal.insertCityAt( i, initial.cities[i] );
		goal.insertCarAt( i, initial.cars[i] );

		goal.calculeFitness();

		if( goal.fitness >= minimal_satisfaction_GLOBAL*satisfaction_total_GLOBAL &&
				goal.fitness < better.fitness ){
			better = goal;
		}
	}
	return better;
}

vector< Solution > startToEndBackward( vector< Solution > elite ){
	vector< Solution > newSolution( elite.size() );

	elite = quicksort( elite );
	newSolution[0] = elite[0];

	for( int i = 1; i < elite.size(); i++ ){
		newSolution[i] = startToEnd( elite[0], elite[i] );
	}
	return newSolution;
}

vector< Solution > pathRelinking( vector< Solution > elite, string strategy ){
	if( strategy == "stef" ){

	}else if( strategy == "steb" ){
		return startToEndBackward( elite );
	}else if( strategy == "etsf" ){

	}else if( strategy == "etsb" ){

	}else if( strategy == "rf" ){

	}else if( strategy == "rb" ){

	}
	throw runtime_error( "Invalid strategy for path relinking: " + strategy );
}
