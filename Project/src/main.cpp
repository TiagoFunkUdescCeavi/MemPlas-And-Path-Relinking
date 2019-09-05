#include <iostream>
#include <string>
#include <cstdlib>

#include "utils/InstanceReader.h"
#include "algorithm/Algorithm.h"

#include "algorithm/RestoringOperations.h"

using namespace std;

int main( int argc, char* argv[] ){

	cout << "parameters:" << endl;
	string file = argv[ 1 ];
	int sizePopulation = stoi( argv[ 2 ] );
	int sizePlasmideo = stoi( argv[ 3 ] );
	double cross = stod( argv[ 4 ] );
	double elite = stod( argv[ 5 ] );
	int limitIterations = stoi( argv[ 6 ] );
	cout << "ok" << endl;

	srand( 0 );

	try{
		cout << "instance read:" << endl;
		readInstance( file );
		cout << "ok" << endl;

		numberCities_GLOBAL = 5;
		vector< Solution * > population(1);
		Solution *s1 = new Solution( 9 );
		s1->addEnd(0,1);
		s1->addEnd(1,1);
		s1->addEnd(1,1);
		s1->addEnd(1,1);
		s1->addEnd(1,1);
		s1->addEnd(1,1);
		s1->addEnd(1,1);
		s1->addEnd(1,1);
		s1->addEnd(0,1);
		population[0] = s1;
		restoringOperations( population );

//		lets_go( sizePopulation, sizePlasmideo, cross, elite, limitIterations );
	} catch (exception &e) {
		cout << e.what() << endl;
		return 1;
	}
	cout << "end of execution" << endl;
	return 0;
}
