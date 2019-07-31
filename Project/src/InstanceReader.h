#ifndef SRC_INSTANCEREADER_H_
#define SRC_INSTANCEREADER_H_

#include <iostream>
#include <fstream>
#include <stdexcept>

#include "GLOBAL.h"

using namespace std;

void readInstance( string file ){
	int cities, cars;
	int satisfaction_sum;
	int* vector;
	int** matrix;
	string aux;
	ifstream arq( file.c_str(), ios::in );

	if( !arq ){
		string s = "Error on open file: " + file;
		throw runtime_error( s );
	}

	while( arq >> aux ){
		if( aux == "DIMENSION" ){
			arq >> aux;
			arq >> aux;
			cities = stoi( aux );
		}
		if( aux == "CARS_NUMBER" ){
			arq >> aux;
			arq >> aux;
			cars = stoi( aux );
		}
		if( aux == "EDGE_WEIGHT_SECTION" ){
			break;
		}
	}

	numberCars_GLOBAL = cars;
	numberCities_GLOBAL = cities;
	cars_GLOBAL.resize( cars );

	for( int car = 0; car < cars; car++ ){
		matrix = new int*[ cities ];
		for( int i = 0; i < cities; i++ ){
			matrix[ i ] = new int[ cities ];
		}

		arq >> aux;
		for( int i = 0; i < cities; i++ ){
			for( int j = 0; j < cities; j++ ){
				arq >> matrix[ i ][ j ];
			}
		}

		cars_GLOBAL[ car ].dimension = cities;
		cars_GLOBAL[ car ].edge_weigth = matrix;
	}

	arq >> aux;
	for( int car = 0; car < cars; car++ ){
		matrix = new int*[ cities ];
		for( int i = 0; i < cities; i++ ){
			matrix[ i ] = new int[ cities ];
		}

		arq >> aux;
		for( int i = 0; i < cities; i++ ){
			for( int j = 0; j < cities; j++ ){
				arq >> matrix[ i ][ j ];
			}
		}

		cars_GLOBAL[ car ].return_rate = matrix;
	}

	arq >> aux;
	vector = new int[ cities ];
	satisfaction_sum = 0;
	for( int i = 0; i < cities; i++ ){
		arq >> vector[ i ];
		satisfaction_sum += vector[ i ];
	}

	bonus_satisfaction_GLOBAL = vector;
	satisfaction_total_GLOBAL = satisfaction_sum;

	arq >> aux;
	if( aux != "EOF" ){
		string s = "Read of file has incorrect: " + file;
		throw runtime_error( s );
	}
}

#endif /* SRC_INSTANCEREADER_H_ */
