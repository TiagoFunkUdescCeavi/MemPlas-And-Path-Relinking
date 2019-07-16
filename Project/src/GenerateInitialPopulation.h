#ifndef SRC_GENERATEINITIALPOPULATION_H_
#define SRC_GENERATEINITIALPOPULATION_H_

#include "Solution.h"
#include "GLOBAL.h"
#include "utils.h"

vector< Solution* > generateInitialPopulation( int sizePopulation ){
	vector< Solution* > population( sizePopulation );

	for( int i = 0; i < sizePopulation; i++ ){
		int count = 0;
		int firstCar, firstCity, nextCity;
		bool* carsUsed = new bool[ numberCars_GLOBAL ];
		bool* citiesVisited = new bool[ numberCities_GLOBAL ];
		Solution* mySolution = new Solution( numberCities_GLOBAL );

		firstCar = rand() % numberCars_GLOBAL;
		carsUsed[ firstCar ] = true;
		firstCity = rand() % numberCities_GLOBAL;
		citiesVisited[ firstCity ] = true;

		mySolution->cars[ count ] = firstCar;
		mySolution->cities[ count ] = 1;
		count++;

		myPrint( mySolution->toString().c_str() );
		do{
			cars_GLOBAL[ firstCar ].edge_weigth[ firstCity ];
		}while( true );

		population[ i ] = mySolution;
		break;
	}

	for( int i = 0; i < (int) population.size(); i++ ){
		population[ i ]->calculeFitness();
	}
	return population;
}

#endif /* SRC_GENERATEINITIALPOPULATION_H_ */
