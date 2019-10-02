#include "PathRelinking.h"

#include "../utils/SortingMethods.h"
#include "../utils/Prints.h"
#include "../utils/Validate.h"

Solution startToEnd( Solution initial, Solution goal ){
	Solution better = goal;

	initial.calculeFitness();
	goal.calculeFitness();
	if( initial.getFitness() < goal.getFitness() ){
		better = initial.copy();
	}else{
		better = goal.copy();
	}

	for( int i = 0; i < initial.getSize(); i++ ){

		if( i < goal.getSize()-1 ){
			goal.insertCityAt( i, initial.cities[i] );
			goal.insertCarAt( i, initial.cars[i] );
		}else{
			goal.addCityAndCarAt( i, initial.cities[i], initial.cars[i] );
		}

		if( isValid( goal ) ){
			goal.calculeFitness();

			if( goal.getFitness() >= minimal_satisfaction_GLOBAL*satisfaction_total_GLOBAL &&
					goal.getFitness() < better.getFitness() ){
				better = goal.copy();
			}
		}
	}
	return better;
}

Solution endToStart( Solution initial, Solution goal ){
	int size = initial.getSize() <= goal.getSize() ? initial.getSize() : goal.getSize();
	Solution better = goal;

	initial.calculeFitness();
	goal.calculeFitness();
	if( initial.getFitness() < goal.getFitness() ){
		better = initial.copy();
	}else{
		better = goal.copy();
	}

	for( int i =size-1; i >= 0; i-- ){

		if( i < goal.getSize()-1 ){
			goal.insertCityAt( i, initial.cities[i] );
			goal.insertCarAt( i, initial.cars[i] );
		}else{
			goal.addCityAndCarAt( i, initial.cities[i], initial.cars[i] );
		}

		if( isValid( goal ) ){
			goal.calculeFitness();

			if( goal.getFitness() >= minimal_satisfaction_GLOBAL*satisfaction_total_GLOBAL &&
					goal.getFitness() < better.getFitness() ){
				better = goal.copy();
			}
		}
	}
	return better;
}

Solution random( Solution initial, Solution goal ){
	int size = initial.getSize() <= goal.getSize() ? initial.getSize() : goal.getSize();
	int aux = 0, randomNumber = 0;
	int indexes[ size ];
	Solution better = goal;

	initial.calculeFitness();
	goal.calculeFitness();
	if( initial.getFitness() < goal.getFitness() ){
		better = initial.copy();
	}else{
		better = goal.copy();
	}

	for( int i = 0; i < size; i++ ){
		indexes[i] = i;
	}
	for( int i = 0; i < size; i++ ){
		randomNumber = rand() % initial.getSize();
		aux = indexes[ randomNumber ];
		indexes[ randomNumber ] = indexes[ i ];
		indexes[ i ] = aux;
	}

	for( int i = 0; i < size; i++ ){

		if( indexes[ i ] < goal.getSize()-1 ){
			goal.insertCityAt( indexes[ i ], initial.cities[ indexes[ i ] ] );
			goal.insertCarAt( indexes[ i ], initial.cars[ indexes[ i ] ] );
		}else{
			goal.addCityAndCarAt( indexes[ i ], initial.cities[i], initial.cars[ indexes[ i ] ] );
		}

		if( isValid( goal ) ){
			goal.calculeFitness();

			if( goal.getFitness() >= minimal_satisfaction_GLOBAL*satisfaction_total_GLOBAL &&
					goal.getFitness() < better.getFitness() ){
				better = goal.copy();
			}
		}
	}
	return better;
}

Solution selector( Solution s1, Solution s2, string intermediaryStrategy, bool betterForWorse ){
	Solution newSolution( numberCities_GLOBAL+1 );
	if( intermediaryStrategy == "stef" || intermediaryStrategy == "steb"){
		if( betterForWorse ){
			newSolution = startToEnd( s1, s2 ).copy();
		}else{
			newSolution = startToEnd( s2, s1 ).copy();
		}
	}else if( intermediaryStrategy == "etsf" || intermediaryStrategy == "etsb" ){
		if( betterForWorse ){
			newSolution = endToStart( s1, s2 ).copy();
		}else{
			newSolution = endToStart( s2, s1 ).copy();
		}
	}else if( intermediaryStrategy == "rf" || intermediaryStrategy == "rb"){
		if( betterForWorse ){
			newSolution = random( s1, s2 ).copy();
		}else{
			newSolution = random( s2, s1 ).copy();
		}
	}
	return newSolution;
}

vector< Solution > pathRelinking( vector< Solution > elite, string selectionStrategy, string intermediaryStrategy ){
	bool betterForWorse = intermediaryStrategy == "stef" ||
			intermediaryStrategy == "etsf" ||
			intermediaryStrategy == "rf";
	Solution newSolution( numberCities_GLOBAL+1 );

	for( unsigned int i = 1; i < elite.size(); i++ ){
		elite = quicksort( elite );
		newSolution = selector( elite[0], elite[i], intermediaryStrategy, betterForWorse );
		newSolution.calculeFitness();
		for( unsigned int j = 0; j < elite.size(); j++ ){
			elite[i].calculeFitness();
			int a, b;
			a = elite[j].getFitness();
			b = newSolution.getFitness();
			if( a > b ){
				elite[i] = newSolution;
				break;
			}
		}
	}
	return elite;
}
