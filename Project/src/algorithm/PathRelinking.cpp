#include "PathRelinking.h"

#include "../utils/SortingMethods.h"
#include "../utils/Prints.h"
#include "../utils/Validate.h"

Solution startToEnd( Solution initial, Solution goal ){
	Solution better = goal;

	initial.calculeFitness();
	goal.calculeFitness();
	if( initial.fitness < goal.fitness ){
		better = initial.copy();
	}else{
		better = goal.copy();
	}

	for( int i = 0; i < initial.position; i++ ){
//		myPrint( to_string( i ), 0, true );
//		myPrint( goal.toString(), 0 );

		if( i < goal.position-1 ){
			goal.insertCityAt( i, initial.cities[i] );
			goal.insertCarAt( i, initial.cars[i] );
		}else{
			goal.addCityAndCarAt( i, initial.cities[i], initial.cars[i] );
		}

		try{
			isOk( goal );

			goal.calculeFitness();

			if( goal.fitness >= minimal_satisfaction_GLOBAL*satisfaction_total_GLOBAL &&
					goal.fitness < better.fitness ){
				better = goal.copy();
			}
//			myPrint( goal.toString() + "\n", 0 );
		}catch(runtime_error &e){
//			myPrint( "Erro", 0 );
//			myPrint( e.what(), 0 );
//			myPrint( goal.toString() + "\n", 0 );
			// do nothing
		}
//		myPrint( ">>>>\n" + better.toString() + "\n", 0 );
	}
	return better;
}

vector< Solution > startToEndBackward( vector< Solution > elite ){
	vector< Solution > newSolution( elite.size() );

	elite = quicksort( elite );
	newSolution[0] = elite[0];

	for( unsigned int i = 1; i < elite.size(); i++ ){
		newSolution[i] = startToEnd( elite[0], elite[i] );
	}
	return newSolution;
}

vector< Solution > pathRelinking( vector< Solution > elite, string selectionStrategy, string intermediaryStrategy ){
	if( intermediaryStrategy == "stef" ){

	}else if( intermediaryStrategy == "steb" ){
		return startToEndBackward( elite );
	}else if( intermediaryStrategy == "etsf" ){

	}else if( intermediaryStrategy == "etsb" ){

	}else if( intermediaryStrategy == "rf" ){

	}else if( intermediaryStrategy == "rb" ){

	}
	throw runtime_error( "Invalid strategy for path relinking: " + intermediaryStrategy );
}
