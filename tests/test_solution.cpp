#include "catch.hpp"
#include "../Project/src/Solution.h"

TEST_CASE( "setup solution" ){
	const int SIZE = 4;

	Solution* sol = new Solution( SIZE );

	REQUIRE( sol->sizeSolution == SIZE );
	REQUIRE( sol->fitness == 0 );
	REQUIRE( sol->satisfaction == 0 );

	for( int i = 0; i < SIZE; i++ ){
		REQUIRE( sol->cities[ i ] == -1 );
	}
	for( int i = 0; i < SIZE; i++ ){
		REQUIRE( sol->cars[ i ] == -1 );
	}
}

TEST_CASE( "addEnd" ){
	const int SIZE = 3;

	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );

	REQUIRE( sol->cars[ 0 ] == 1 );
	REQUIRE( sol->cars[ 1 ] == -1 );
	REQUIRE( sol->cars[ 2 ] == -1 );

	REQUIRE( sol->cities[ 0 ] == 1 );
	REQUIRE( sol->cities[ 1 ] == -1 );
	REQUIRE( sol->cities[ 2 ] == -1 );

	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	REQUIRE( sol->cars[ 0 ] == 1 );
	REQUIRE( sol->cars[ 1 ] == 2 );
	REQUIRE( sol->cars[ 2 ] == 3 );

	REQUIRE( sol->cities[ 0 ] == 1 );
	REQUIRE( sol->cities[ 1 ] == 2 );
	REQUIRE( sol->cities[ 2 ] == 3 );
}

TEST_CASE( "removeIndex" ){
	const int SIZE = 3;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	sol->removeIndex( 0 );

	REQUIRE( sol->cars[ 0 ] == 2 );
	REQUIRE( sol->cars[ 1 ] == 3 );
	REQUIRE( sol->cars[ 2 ] == -1 );

	REQUIRE( sol->cities[ 0 ] == 2 );
	REQUIRE( sol->cities[ 1 ] == 3 );
	REQUIRE( sol->cities[ 2 ] == -1 );
}
