
#include <iostream>

#include "GLOBAL.h"
#include "InstanceReader.h"

using namespace std;

int main( int argc, char* argv[] ){
	file_GLOBAL = argv[ 1 ];

	readInstance( file_GLOBAL );

	Car c = cars_GLOBAL[ 0 ];
	cout << c.dimension << endl;

	for( int i = 0; i < numberCities_GLOBAL; i++ ){
		for( int j = 0; j < numberCities_GLOBAL; j++ ){
			cout << c.edge_weigth[ i ][ j ] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for( int i = 0; i < numberCities_GLOBAL; i++ ){
		for( int j = 0; j < numberCities_GLOBAL; j++ ){
			cout << c.return_rate[ i ][ j ] << " ";
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;
	for( int i = 0; i < numberCities_GLOBAL; i++ ){
		cout << bonus_satisfaction_GLOBAL[i] << " ";
	}
	cout << endl;
	return 0;
}
