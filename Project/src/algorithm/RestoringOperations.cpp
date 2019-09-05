#include "RestoringOperations.h"

#include "../utils/Prints.h"
#include "../utils/SortingMethods.h"
#include "../model/Pair.h"

Pair *usedCars = 0;
Pair *usedCities = 0;

Solution * removeErrors( Solution *sol ){
	bool isRepeated = false;
	int actualCity = -1;
	int lastCar = -1, actualCar = -1;
	usedCars = new Pair[ numberCars_GLOBAL ];
	usedCities = new Pair[ numberCities_GLOBAL ];
	Solution *newSol = sol->copy();

	for( int i = 0; i < numberCities_GLOBAL; i++ ){
		usedCities[i].value = i;
	}
	for( int i = 0; i < numberCars_GLOBAL; i++ ){
		usedCars[i].value = i;
	}

	for( int i = 0; i < sol->position; i++ ){
		actualCar = sol->cars[ i ];
		actualCity = sol->cities[ i ];
		if( lastCar != actualCar && usedCars[ actualCar ].frequency == 1 ){
			newSol->insertCarAt( i, -2 );
			isRepeated = true;
		} else if( usedCars[ actualCar ].frequency == 1 && isRepeated ){
			newSol->insertCarAt( i, -2 );
		}else if( lastCar != actualCar ){
			usedCars[ actualCar ].frequency += 1;
			isRepeated = false;
		}
		if( actualCity != 0 && usedCities[ actualCity ].frequency == 1 ){
			newSol->insertCityAt( i, -2 );
		}else{
			usedCities[ actualCity ].frequency += 1;
		}
		lastCar = actualCar;
	}

	return newSol;
}

Solution * insertCities( Solution * sol ){
	int lastPosition = -1, aux = 0, randomNumber = 0;
	Pair pair;
	Solution *newSol = sol->copy();
	usedCities = quicksort( usedCities, numberCities_GLOBAL );
	for( int i = 0; i < numberCities_GLOBAL; i++ ){
		if( usedCities[i].frequency != 0 ){
			lastPosition = i;
			break;
		}
	}
	for( int i = 0; i < lastPosition; i++ ){
		randomNumber = rand() % lastPosition;
		pair = usedCities[ i ];
		usedCities[ i ] = usedCities[ randomNumber ];
		usedCities[ randomNumber ] = pair;
	}

	aux = 0;
	for( int i = 1; i < sol->position; i++ ){
		if( newSol->cities[i] == -2 ){
			if( aux == lastPosition ){
				newSol->removeIndex( i );
				i--;
			}else{
				newSol->insertCityAt( i, usedCities[aux].value );
				aux++;
			}
		}
	}
	return newSol;
}

Solution * insertCars( Solution * sol ){
	int lastCar = -1;
	Solution *newSol = sol->copy();

	for( int i = 0; i < newSol->position; i++ ){
		if( newSol->cars[i] == -2 ){
			newSol->insertCarAt( i, lastCar );
		}else{
			lastCar = newSol->cars[i];
		}
	}
	return newSol;
}

vector< Solution * > restoringOperations( vector< Solution * > population ){
	Solution *sol = 0;
	vector< Solution* > newPopulation( population.size() );
	for( int i = 0; i < (int) population.size(); i++ ){
		sol = removeErrors( population[ i ] );
		myPrint( sol->toString(), true );
		sol = insertCities( sol );
		myPrint( sol->toString(), true );
		sol = insertCars( sol );
		myPrint( sol->toString(), true );
	}
	return newPopulation;
}
