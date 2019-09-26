#include "Validate.h"

void verifyQuota( Solution sol ){
	if( sol.satisfaction < minimal_satisfaction_GLOBAL*satisfaction_total_GLOBAL ){
		string s = "Quota value is less than the minimum allowed.\nSatisfaction of Solution: "
				+ to_string( sol.satisfaction )
				+ "\tMinimal satisfaction: "
				+ to_string( minimal_satisfaction_GLOBAL*satisfaction_total_GLOBAL );
		throw runtime_error( s );
	}
}

int findFinalPosition( Solution sol ){
	int finalPosition = -1;

	for( int i = 0; i < sol.sizeSolution; i++ ){
		if( sol.cities[ i ] == -1 && sol.cars[ i ] != -1 ){
			string s = "The cities vector ends before the cars vector.\n";
			throw runtime_error( s );
		}
		if( sol.cars[ i ] == -1 && sol.cities[ i ] != -1 ){
			string s = "The cars vector ends before the cities vector.\n";
			throw runtime_error( s );
		}
		if( sol.cities[ i ] == -1 && sol.cars[ i ] == -1 ){
			finalPosition = i;
			break;
		}
	}
	if( finalPosition == -1 ){
		finalPosition = sol.sizeSolution;
	}

	return finalPosition;
}

void checkStartAndEnd( Solution sol, int finalPosition ){
	if( finalPosition == 0 ){
		string s = "Solution is null.\n";
		throw runtime_error( s );
	}
	if( finalPosition == 1 ){
		string s = "Solution has only one city.\n";
		throw runtime_error( s );
	}
	if( finalPosition == 2 ){
		string s = "Solution has only two cities.\n";
		throw runtime_error( s );
	}
	if( sol.cities[ 0 ] != 0 ){
		string s = "The first city in a solution must always be equal to 0.\n";
		throw runtime_error( s );
	}
	if( sol.cities[ finalPosition-1 ] != 0 ){
		string s = "The final city in a solution must always be equal to 0.\n";
		throw runtime_error( s );
	}
}

void checkCitiesAndCars( Solution sol, int finalPosition ){
	for( int i = 0; i < finalPosition; i++ ){
		if( sol.cities[ i ] < -1 || sol.cities[ i ] >= numberCities_GLOBAL ){
			string s = "Invalid value for city: " + to_string( sol.cities[i] ) + ".\n";
			throw runtime_error( s );
		}
		if( sol.cars[ i ] < -1 || sol.cars[ i ] >= numberCars_GLOBAL ){
			string s = "Invalid value for car: " + to_string( sol.cars[i] ) + ".\n";
			throw runtime_error( s );
		}
	}
}

void checkRepetition( Solution sol, int finalPosition ){
	int actualCity = -1;
	int lastCar = -1, actualCar = -1;
	int usedCars[ numberCars_GLOBAL ];
	int usedCities[ numberCities_GLOBAL ];

	for( int i = 0; i < numberCars_GLOBAL; i++ ){
		usedCars[ i ] = 0;
	}
	for( int i = 0; i < numberCities_GLOBAL; i++ ){
		usedCities[ i ] = 0;
	}

	for( int i = 0; i < finalPosition; i++ ){
		actualCar = sol.cars[ i ];
		actualCity = sol.cities[ i ];
		if( lastCar != actualCar && usedCars[ actualCar ] == 1 ){
			string s = "Solution is invalid: cars sequence is repeated\n";
			throw runtime_error( s );
		}else if( lastCar != actualCar ){
			usedCars[ actualCar ]++;
		}
		if( actualCity == 0 && usedCities[ 0 ] == 2 ){
			string s = "Solution is invalid: city 0 has been used more than once\n";
			throw runtime_error( s );
		}else if( actualCity != 0 && usedCities[ actualCity ] == 1 ){
			string s = "Solution is invalid: city sequence is repeated\n";
			throw runtime_error( s );
		}else{
			usedCities[ actualCity ]++;
		}
		lastCar = actualCar;
	}
}

void isOk( Solution sol ) throw (runtime_error) {
	int finalPosition = -1;
	finalPosition = findFinalPosition( sol );
	checkStartAndEnd( sol, finalPosition );
	checkCitiesAndCars( sol, finalPosition );
	checkRepetition( sol, finalPosition );
}

void checkPopulation( vector< Solution > population ){
	for( int i = 0; i < (int) population.size(); i++ ){
		try{
			isOk( population[ i ] );
			population[i].calculeSatisfaction();
			verifyQuota( population[i] );
		} catch (exception &e) {
			myPrint( i, 0 );
			myPrint( e.what(), 0 );
			myPrint( population[i].toString(), 0 );
			exit( 1 );
		}
	}
}

bool isValid( Solution mySolution ){
	try{
		isOk( mySolution );
		return true;
	}catch( runtime_error &e ){
		return false;
	}
}
