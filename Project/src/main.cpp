#include <iostream>
#include <string>
#include <cstdlib>

#include "utils/InstanceReader.h"
#include "utils/Argumentsreader.h"
#include "algorithm/Algorithm.h"

#include "monta_problema.h"

using namespace std;

int main( int argc, char* argv[] ){

	myPrint( "parameters:", 1 );
	ArgumentReader arg( argc, argv );
	string file = arg.getValue( "--file" );
	int sizePopulation = stoi( arg.getValue( "--sizePopulation" ) );
	int sizePlasmideo = stoi( arg.getValue( "--sizePlasmideo" ) );
	double cross = stod( arg.getValue( "--cross" ) );
	double elite = stod( arg.getValue( "--elite" ) );
	int limitIterations = stoi( arg.getValue( "--limitIterations" ) );
	string strategy = arg.getValue( "--strategy" );
	string selectionStrategy = arg.getValue( "--selectionStrategy" );
	string intermediaryStrategy = arg.getValue( "--intermediaryStrategy" );
	myPrint( "ok:", 1 );

	srand( 0 );
//	myPrint( "My Seed: " + to_string( seed ), 0 );

	try{
		myPrint( "instance read:", 1 );
		readInstance( file );
		myPrint( "ok", 1 );

//		vector< Solution > population(1);
//		Solution s1( 10+1 );
//		s1.addEnd(0,0);
//		s1.addEnd(9,0);
//		s1.addEnd(3,1);
//		s1.addEnd(4,1);
//		s1.addEnd(10,1);
//		s1.addEnd(8,1);
//		s1.addEnd(0,1);
//		population[0] = s1;
//		checkPopulation( multiOperatorsLocalSearch( population ) );

		Algorithm a( strategy, sizePopulation, elite, limitIterations,
					 sizePlasmideo, cross, selectionStrategy, intermediaryStrategy);
		a.lets_go();

	} catch (exception &e) {
		cout << e.what() << endl;
		return 1;
	}
	myPrint( "end of execution", 1 );
	return 0;
}
