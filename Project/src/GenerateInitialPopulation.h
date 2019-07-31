#ifndef SRC_GENERATEINITIALPOPULATION_H_
#define SRC_GENERATEINITIALPOPULATION_H_

#include <stdexcept>

#include "Solution.h"
#include "GLOBAL.h"
#include "utils.h"

vector< int > initAndShuffle( int vectorSize, bool hasCities );
int selectCityWithHeuristic( int car, int cityInit, vector< int > citiesNotVisited );

vector< Solution* > generateInitialPopulation( int sizePopulation ){
	bool firstCity;
	int count, pos;
	int myCar, destinyCity, nextCity;
	Solution* mySolution = 0;
	vector< int > carsNotUsed;
	vector< int > citiesNotVisited;
	vector< Solution* > population( sizePopulation );

	for( int i = 0; i < sizePopulation; i++ ){
		myPrint( i, true );
		firstCity = true;
		count = 0;
		carsNotUsed = initAndShuffle( numberCars_GLOBAL, false );
		citiesNotVisited = initAndShuffle( numberCities_GLOBAL, true );
		mySolution = new Solution( numberCities_GLOBAL );

		do{
			myCar = carsNotUsed[ 0 ];
			if( carsNotUsed.size() != 1 ){
				carsNotUsed.erase( carsNotUsed.begin() + 0 );
			}

			destinyCity = citiesNotVisited[ 0 ];

			do{
				if( firstCity ){
					nextCity = 0;
					firstCity = false;
				}else{
					pos = selectCityWithHeuristic( myCar, nextCity, citiesNotVisited );
					nextCity = citiesNotVisited[ pos ];
					citiesNotVisited.erase( citiesNotVisited.begin() + pos );
				}

				mySolution->cars[ count ] = myCar;
				mySolution->cities[ count ] = nextCity;
				count++;
//				myPrint( mySolution->toString(), true );
			}while( destinyCity != nextCity );

			mySolution->calculeFitness();
		}while( mySolution->fitness < 0.8*satisfaction_total_GLOBAL );

		population[ i ] = mySolution;
		myPrint( mySolution->toString(), true );
	}
	for( int i = 0; i < (int) population.size(); i++ ){
		if( population[ i ] != 0 ){
			population[ i ]->calculeFitness();
		}
	}
	myPrint( "Ok", true );
	return population;
}

vector< int > initAndShuffle( int vectorSize, bool hasCities ){
	int aux = 0;
	int number = 0;
	vector< int > myVector( hasCities ? vectorSize-1 : vectorSize );
	for( int i = 0; i < (int) myVector.size(); i++ ){
		if( hasCities ){
			myVector[ i ] = i+1;
		}else{
			myVector[ i ] = i;
		}
	}
	for( int i = 0; i < (int) myVector.size(); i++ ){
		number = rand() % myVector.size();
		aux = myVector[ i ];
		myVector[ i ] = myVector[ number ];
		myVector[ number ] = aux;
	}
	return myVector;
}

int selectCityWithHeuristic( int car, int cityInit, vector< int > citiesNotVisited ){
	int value, min = 999999, pos = 0;
	for( int i = 0; i < (int) citiesNotVisited.size(); i++ ){
		value = cars_GLOBAL[ car ].edge_weigth[ cityInit ][ citiesNotVisited[ i ] ];
		if( min > value && value != 0 ){
			min = value;
			pos = i;
		}
	}
	return pos;
}

#endif /* SRC_GENERATEINITIALPOPULATION_H_ */
