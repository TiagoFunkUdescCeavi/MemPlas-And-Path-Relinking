#ifndef SRC_VALIDATE_H_
#define SRC_VALIDATE_H_

#include <string>
#include <stdexcept>
#include <vector>

#include "Solution.h"
#include "GLOBAL.h"
#include "utils.h"

bool isOk( Solution* mySolution );

bool checkPopulation( vector< Solution* > population ){
	int count = 0;
	for( int i = 0; i < (int) population.size(); i++ ){
		try{
			isOk( population[ i ] );
		} catch (exception &e) {
			count++;
			myPrint( i, true );
			myPrint( e.what(), true );
//			return false;
		}
	}
	return true;
}

bool isOk( Solution* mySolution ){
//	myPrint( mySolution->toString(), true );
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

#endif /* SRC_VALIDATE_H_ */
