
#include <iostream>
#include <string>
#include <cstdlib>

#include "algorithm/Algorithm.h"
#include "algorithm/Selections.h"
#include "algorithm/Selections.h"
#include "utils/InstanceReader.h"

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

//		vector< Solution* > population(3);
//
//		Solution* s1 = new Solution( 3 );
//		s1->fitness = 3;
//		population[0] = s1;
//
//		Solution* s2 = new Solution( 3 );
//		s2->fitness = 1;
//		population[1] = s2;
//
//		Solution* s3 = new Solution( 3 );
//		s3->fitness = 2;
//		population[2] = s3;
//
//		selectElite( 1, population);

		lets_go( sizePopulation, sizePlasmideo, cross, elite, limitIterations );
	} catch (exception &e) {
		cout << e.what() << endl;
		return 1;
	}
	cout << "end of execution" << endl;
	return 0;
}
