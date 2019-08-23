#include "Validate.h"

bool checkPopulation( vector< Solution* > population ){
	int count = 0;
	for( int i = 0; i < (int) population.size(); i++ ){
		try{
			isOk( population[ i ] );
		} catch (exception &e) {
			count++;
			myPrint( e.what(), true );
//			return false;
		}
	}
	return true;
}

bool isOk( Solution* mySolution ){
	if( mySolution->cities[ 0 ] != 0 ){
		string s = "The first city in a solution must always be equal to 0.\n" + mySolution->toString() + "\n";
		throw runtime_error( s );
	}
	bool finalZero = false;
	int actualCity = -1;
	int lastCar = -1, actualCar = -1;
	bool usedCars[ numberCars_GLOBAL ];
	bool usedCities[ numberCities_GLOBAL ];

	for( int i = 0; i < numberCars_GLOBAL; i++ ){
		usedCars[ i ] = false;
	}
	for( int i = 0; i < numberCities_GLOBAL; i++ ){
		usedCities[ i ] = false;
	}

	for( int i = 0; i < mySolution->sizeSolution; i++ ){
		if( mySolution->cars[ i ] == -1 ){
			break;
		}
		actualCar = mySolution->cars[ i ];
		actualCity = mySolution->cities[ i ];
		if( lastCar != actualCar && usedCars[ actualCar ] ){
			string s = "Solution is invalid: cars sequence is invalid\n" + mySolution->toString() + "\n";
			throw runtime_error( s );
		}else{
			usedCars[ actualCar ] = true;
		}
		if( actualCity != 0 && i == mySolution->sizeSolution-1 ){
			string s = "The last city should be city 0.\n" + mySolution->toString() + "\n";
			throw runtime_error( s );
		}
		if( actualCity == 0 && i != 0 && i != mySolution->sizeSolution-1 && mySolution->cities[ i+1 ] != -1 ){
			string s = "When city 0 appears, it must be the end of the route.";
			s += " Therefore, the lower value -1 should appear next.\n" + mySolution->toString() + "\n";
			throw runtime_error( s );
		}
		if( usedCities[ actualCity ] && actualCity == 0 && finalZero){

		} else if( usedCities[ actualCity ] ){
			string s = "Solution is invalid: cities sequence is invalid\n" + mySolution->toString() + "\n";
			throw runtime_error( s );
		}else{
			usedCities[ actualCity ] = true;
		}
		lastCar = actualCar;
	}
	return true;
}
