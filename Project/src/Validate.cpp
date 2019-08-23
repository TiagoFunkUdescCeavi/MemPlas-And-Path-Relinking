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
	if( mySolution->cities[ 0 ] != 1 ){
		string s = "The first city in a solution must always be equal to 1\n" + mySolution->toString() + "\n";
		throw runtime_error( s );
	}
	int nextCity = -1;
	int lastCar = -1, nextCar = -1;
	bool cars[ numberCars_GLOBAL ];
	bool cities[ numberCities_GLOBAL ];

	for( int i = 0; i < numberCars_GLOBAL; i++ ){
		cars[ i ] = false;
	}
	for( int i = 0; i < numberCities_GLOBAL; i++ ){
		cities[ i ] = false;
	}

	for( int i = 0; i < mySolution->sizeSolution; i++ ){
		if( mySolution->cars[ i ] == -1 ){
			break;
		}
		nextCar = mySolution->cars[ i ];
		nextCity = mySolution->cities[ i ];
		if( cars[ nextCar ] && lastCar != nextCar ){
			string s = "Solution is invalid: cars sequence is invalid\n" + mySolution->toString() + "\n";
			throw runtime_error( s );
		}else{
			cars[ nextCar ] = true;
		}
		if( cities[ nextCity ] ){
			string s = "Solution is invalid: cities sequence is invalid\n" + mySolution->toString() + "\n";
			throw runtime_error( s );
		}else{
			cities[ nextCity ] = true;
		}
		lastCar = nextCar;
	}
	return true;
}
