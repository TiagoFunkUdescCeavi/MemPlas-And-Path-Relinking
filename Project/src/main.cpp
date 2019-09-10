#include <iostream>
#include <string>
#include <cstdlib>

#include "utils/InstanceReader.h"
#include "algorithm/Algorithm.h"

#include "algorithm/RestoringOperations.h"

using namespace std;

int main( int argc, char* argv[] ){

	for( int i = 0; i < argc; i++ ){
		cout << argv[i] << endl;
	}
	myPrint( "parameters:", true );
	int seed = stoi( argv[ 1 ] );
	string file = argv[ 2 ];
	int sizePopulation = stoi( argv[ 3 ] );
	int sizePlasmideo = stoi( argv[ 4 ] );
	double cross = stod( argv[ 5 ] );
	double elite = stod( argv[ 6 ] );
	int limitIterations = stoi( argv[ 7 ] );
	myPrint( "ok:", true );

	srand( seed );
	cout << "My Seed: " << seed << endl;

	try{
		myPrint( "instance read:", true );
		readInstance( file );
		myPrint( "ok", true );

//		numberCities_GLOBAL = 5;
//		vector< Solution * > population(1);
//		Solution *s1 = new Solution( 9 );
//		s1->addEnd(0,1);
//		s1->addEnd(1,1);
//		s1->addEnd(1,1);
//		s1->addEnd(1,1);
//		s1->addEnd(1,1);
//		s1->addEnd(1,1);
//		s1->addEnd(1,1);
//		s1->addEnd(1,1);
//		s1->addEnd(0,1);
//		population[0] = s1;
//		restoringOperations( population );

		lets_go( sizePopulation, sizePlasmideo, cross, elite, limitIterations );

	} catch (exception &e) {
		cout << e.what() << endl;
		return 1;
	}
	myPrint( "end of execution", true );
	return 0;
}
