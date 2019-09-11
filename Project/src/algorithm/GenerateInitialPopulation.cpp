#include "GenerateInitialPopulation.h"

#include <stdexcept>
#include <bits/stdc++.h>

#include "../utils/Prints.h"

vector< Solution > generateInitialPopulation( int sizePopulation ){
	bool firstCity;
	int pos;
	int myCar, destinyCity, nextCity;
	Solution mySolution;
	vector< int > carsNotUsed;
	vector< int > citiesNotVisited;
	vector< Solution > population( sizePopulation );

	for( int i = 0; i < sizePopulation; i++ ){
		firstCity = true;
		carsNotUsed = initAndShuffle( numberCars_GLOBAL, false );
		citiesNotVisited = initAndShuffle( numberCities_GLOBAL, true );
		mySolution = Solution( numberCities_GLOBAL+1 );

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
				mySolution.addEnd( nextCity, myCar );
			}while( destinyCity != nextCity );

			mySolution.calculeSatisfaction();
		}while( mySolution.satisfaction < minimal_satisfaction_GLOBAL*satisfaction_total_GLOBAL );

		mySolution.addEnd( 0, myCar );

		population[ i ] = mySolution.copy();
	}

	for( int i = 0; i < sizePopulation; i++ ){
		population[ i ].calculeSatisfaction();
		population[ i ].calculeFitness();
	}
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
	int value, min = INT_MAX, pos = 0;
	for( int i = 0; i < (int) citiesNotVisited.size(); i++ ){
		value = cars_GLOBAL[ car ].edge_weigth[ cityInit ][ citiesNotVisited[ i ] ];
		if( min > value && value != 0 ){
			min = value;
			pos = i;
		}
	}
	return pos;
}
