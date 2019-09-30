#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

#include "utils/InstanceReader.h"
#include "utils/Argumentsreader.h"
#include "algorithm/Algorithm.h"

#include "algorithm/PathRelinking.h"

using namespace std;

int main( int argc, char* argv[] ){

	clock_t initialTime = 0, finalTime = 0;
	initialTime = clock();

	myPrint( "parameters:", 1 );
	ArgumentReader arg( argc, argv );
	string file = arg.getValue( "--file" );
	int sizePopulation = stoi( arg.getValue( "--sizePopulation" ) );
	double sizePlasmideo = stod( arg.getValue( "--sizePlasmideo" ) );
	double cross = stod( arg.getValue( "--cross" ) );
	double elite = stod( arg.getValue( "--elite" ) );
	int limitIterations = stoi( arg.getValue( "--limitIterations" ) );
	string strategy = arg.getValue( "--strategy" );
	string selectionStrategy = arg.getValue( "--selectionStrategy" );
	string intermediaryStrategy = arg.getValue( "--intermediaryStrategy" );
	myPrint( "ok:", 1 );

	Solution best;

	srand( 0 );

	try{
		myPrint( "instance read:", 1 );
		readInstance( file );
		myPrint( "ok", 1 );

		Algorithm a( strategy, sizePopulation, elite, limitIterations,
					 sizePlasmideo, cross, selectionStrategy, intermediaryStrategy);
		best = a.lets_go();

	} catch (exception &e) {
		cout << e.what() << endl;
		return 1;
	}
	myPrint( "end of execution", 1 );

	finalTime = clock();
	clock_t time = ( (finalTime - initialTime) / (double) CLOCKS_PER_SEC ) * 1000;
	myPrint( file + "," + strategy + "," + to_string( best.getFitness() ) + "," + to_string( time ), 0, true );
	return 0;
}
