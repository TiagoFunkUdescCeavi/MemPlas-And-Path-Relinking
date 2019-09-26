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
	myPrint( "Init Inicial\n" + initial.toString(), 0 );
	myPrint( "Init Better\n" + better.toString(), 0 );

	for( int i = 0; i < initial.position; i++ ){
//		myPrint( "Initial\n" + initial.toString(), 0 );
//		myPrint( "Goal\n" + goal.toString(), 0 );
//		myPrint( "Better\n" + better.toString(), 0 );

		if( i < goal.position-1 ){
			goal.insertCityAt( i, initial.cities[i] );
			goal.insertCarAt( i, initial.cars[i] );
		}else{
			goal.addCityAndCarAt( i, initial.cities[i], initial.cars[i] );
		}

		if( isValid( goal ) ){
			goal.calculeFitness();

			if( goal.fitness >= minimal_satisfaction_GLOBAL*satisfaction_total_GLOBAL &&
					goal.fitness < better.fitness ){
				better = goal.copy();
				myPrint( "Trocou", 0 );
			}
		}
	}
	myPrint( "Return Inicial\n" + initial.toString(), 0 );
	myPrint( "Return Better\n" + better.toString(), 0 );
	string s = ">";
	string s2 = "*";
	return better;
}

vector< Solution > startToEndBackward( vector< Solution > elite ){
	Solution newSolution;

	for( unsigned int i = 1; i < elite.size(); i++ ){
		elite = quicksort( elite );
		newSolution = startToEnd( elite[0], elite[i] ).copy();
		myPrint( "Return Inicial\n" + newSolution.toString(), 0 );
		newSolution.calculeFitness();
		for( unsigned int j = 0; j < elite.size(); j++ ){
			elite[i].calculeFitness();
			int a, b;
			a = elite[j].fitness;
			b = newSolution.fitness;
			if( a > b ){
				elite[i] = newSolution;
				break;
			}
		}
	}
	return elite;
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
