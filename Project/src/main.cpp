
#include <iostream>
#include <string>
#include <cstdlib>

#include "InstanceReader.h"
#include "Algorithm.h"

using namespace std;
//
//#define CATCH_CONFIG_RUNNER
//#include "tests/catch.hpp"
//
//int main( int argc, char* argv[] ){
//	Catch::Session().run( 1, argv );
//	return 0;
//}

int main( int argc, char* argv[] ){

	const int SIZE = 3;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	sol->removeIndex( 0 );

	string file = argv[ 1 ];
	int sizePopulation = stoi( argv[ 2 ] );
	int sizePlasmideo = stoi( argv[ 3 ] );
	double cross = stod( argv[ 4 ] );
	double elite = stod( argv[ 5 ] );
	int limitIterations = stoi( argv[ 6 ] );

	srand( 0 );

	try{
		readInstance( file );
		lets_go( sizePopulation, sizePlasmideo, cross, elite, limitIterations );
		cout << "ok" << endl;
	} catch (exception &e) {
		cout << e.what() << endl;
		return 1;
	}
	return 0;
}
