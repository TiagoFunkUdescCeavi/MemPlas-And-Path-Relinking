
#include <iostream>
#include <string>
#include <cstdlib>

#include "InstanceReader.h"
#include "Algorithm.h"

#include "MultiOperatorsLocalSearch.h"

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

//		vector< Solution* > population(1);
//		Solution* s = new Solution( 8 );
//		s->addEnd(0,0);
//		s->addEnd(1,0);
//		s->addEnd(2,1);
//		s->addEnd(3,1);
//		s->addEnd(4,2);
//		s->addEnd(5,2);
//		s->addEnd(0,2);
//		population[0] = s;
//		invertSolution(population);

		lets_go( sizePopulation, sizePlasmideo, cross, elite, limitIterations );
	} catch (exception &e) {
		cout << e.what() << endl;
		return 1;
	}
	cout << "end of execution" << endl;
	return 0;
}
