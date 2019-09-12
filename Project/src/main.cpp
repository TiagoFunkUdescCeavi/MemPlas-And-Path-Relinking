#include <iostream>
#include <string>
#include <cstdlib>

#include "utils/InstanceReader.h"
#include "algorithm/Algorithm.h"

#include "algorithm/RestoringOperations.h"

#include "algorithm/RestoringOperations.h"

using namespace std;

int main( int argc, char* argv[] ){
//	for( int i = 0; i < argc; i++ ){
//		cout << argv[i] << endl;
//	}
	myPrint( "parameters:", 1 );
	int seed = stoi( argv[ 1 ] );
	string file = argv[ 2 ];
	int sizePopulation = stoi( argv[ 3 ] );
	int sizePlasmideo = stoi( argv[ 4 ] );
	double cross = stod( argv[ 5 ] );
	double elite = stod( argv[ 6 ] );
	int limitIterations = stoi( argv[ 7 ] );
	myPrint( "ok:", 1 );

	srand( seed );
//	myPrint( "My Seed: " + to_string( seed ), 0 );

	try{
		myPrint( "instance read:", 1 );
		readInstance( file );
		myPrint( "ok", 1 );

//		vector< Solution > population(1);
//		Solution s1( 10+1 );
//		s1.addEnd(0,0);
//		s1.addEnd(3,0);
//		s1.addEnd(1,0);
//		s1.addEnd(3,2);
//		s1.addEnd(7,2);
//		s1.addEnd(0,2);
//		population[0] = s1;
//		checkPopulation( population );

		lets_go( sizePopulation, sizePlasmideo, cross, elite, limitIterations );

	} catch (exception &e) {
		cout << e.what() << endl;
		return 1;
	}
	myPrint( "end of execution", 1 );
	return 0;
}
