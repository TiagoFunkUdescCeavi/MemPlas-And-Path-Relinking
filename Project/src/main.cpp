#include <iostream>
#include <string>
#include <cstdlib>

#include "utils/InstanceReader.h"
#include "utils/Argumentsreader.h"
#include "algorithm/Algorithm.h"

#include "algorithm/PathRelinking.h"

using namespace std;

int main( int argc, char* argv[] ){

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

	srand( 0 );
//	myPrint( "My Seed: " + to_string( seed ), 0 );

	try{
		myPrint( "instance read:", 1 );
		readInstance( file );
		myPrint( "ok", 1 );

//		Solution s1( 10+1 );
//		s1.addEnd(0,1);
//		s1.addEnd(4,1);
//		s1.addEnd(8,3);
//		s1.addEnd(5,3);
//		s1.addEnd(6,3);
//		s1.addEnd(0,3);
//
//		Solution s2( 10+1 );
//		s2.addEnd(0,2);
//		s2.addEnd(2,2);
//		s2.addEnd(7,2);
//		s2.addEnd(6,3);
//		s2.addEnd(4,3);
//		s2.addEnd(3,3);
//		s2.addEnd(0,3);
//
//		Solution r = startToEnd( s1, s2 );
//		myPrint( ">>>>>>>>>>>>\n" + r.toString(), 0 );

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
