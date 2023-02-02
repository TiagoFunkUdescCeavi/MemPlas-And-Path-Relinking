#include "../utils/Validate.h"
#include "gtest.h"
#include "../GLOBAL.h"

#include <vector>

TEST( , IS_OK_1 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	Solution sol( 5 );
	sol.addEnd( 0,1 );
	sol.addEnd( 1,1 );
	sol.addEnd( 2,1 );
	sol.addEnd( 3,2 );
	sol.addEnd( 0,2 );

	try{
		isOk( sol );

	}catch( exception &e ){
		FAIL();
	}
}

TEST( , IS_OK_2 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	Solution sol( 5 );
	sol.addEnd( 0,1 );
	sol.addEnd( 1,1 );
	sol.addEnd( 2,1 );
	sol.addEnd( 3,1 );
	sol.addEnd( 0,1 );

	try{
		isOk( sol );
	}catch( exception &e ){
		FAIL();
	}
}

TEST( , IS_OK_3 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	Solution sol( 5 );
	sol.addEnd( 0,1 );
	sol.addEnd( 2,1 );
	sol.addEnd( 3,1 );
	sol.addEnd( 0,1 );

	try{
		isOk( sol );
	}catch( exception &e ){
		FAIL();
	}
}

TEST( , IS_OK_4 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	Solution sol( 5 );
	sol.addEnd( 0,1 );
	sol.addEnd( 2,1 );
	sol.addEnd( 0,1 );

	try{
		isOk( sol );
	}catch( exception &e ){
		FAIL();
	}
}

TEST( , IS_OK_FAIL_01 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// Not starting in the correct city, that city 0
	Solution sol( 5 );
	sol.addEnd( 2,1 );
	sol.addEnd( 3,1 );
	sol.addEnd( 4,1 );
	sol.addEnd( 1,1 );
	sol.addEnd( 0,1 );

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "The first city in a solution must always be equal to 0.\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_02 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// It's repeating the city one after another
	Solution sol( 5 );
	sol.addEnd( 0,1 );
	sol.addEnd( 2,1 );
	sol.addEnd( 2,1 );
	sol.addEnd( 3,2 );
	sol.addEnd( 0,2 );

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Solution is invalid: city sequence is repeated\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_03 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// It is repeating the city in an interspersed way
	Solution sol( 5 );
	sol.addEnd( 0,1 );
	sol.addEnd( 2,1 );
	sol.addEnd( 3,1 );
	sol.addEnd( 2,2 );
	sol.addEnd( 0,2 );

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Solution is invalid: city sequence is repeated\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_04 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// Is repeating the car intercalately
	Solution sol( 5 );
	sol.addEnd( 0,1 );
	sol.addEnd( 2,1 );
	sol.addEnd( 3,2 );
	sol.addEnd( 1,2 );
	sol.addEnd( 0,1 );

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Solution is invalid: cars sequence is repeated\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_05 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// All values are null
	Solution sol( 5 );
	sol.addEnd( -1,-1 );
	sol.addEnd( -1,-1 );
	sol.addEnd( -1,-1 );
	sol.addEnd( -1,-1 );
	sol.addEnd( -1,-1 );

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "The first city in a solution must always be equal to 0.\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_06 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// All values are null, although values still exist after the number -1.
	Solution sol( 5 );
	sol.addEnd( -1,-1 );
	sol.addEnd( 2,1 );
	sol.addEnd( 3,1 );
	sol.addEnd( 4,1 );
	sol.addEnd( 5,1 );

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "The first city in a solution must always be equal to 0.\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_07 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// Has only one city before value -1.
	Solution sol( 5 );
	sol.addEnd( 0,0 );

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Solution has only one city.\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_08 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// Solution has only two cities, but ends up in the correct city
	Solution sol( 5 );
	sol.addEnd( 0,0 );
	sol.addEnd( 1,1 );

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Solution has only two cities.\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_09 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// Solution has only two cities
	Solution sol( 5 );
	sol.addEnd( 0,2 );
	sol.addEnd( 1,1 );

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Solution has only two cities.\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_10 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// Starts in the correct city, but does not end in it.
	Solution sol( 5 );
	sol.addEnd( 0,0 );
	sol.addEnd( 1,1 );
	sol.addEnd( 3,1 );
	sol.addEnd( 4,1 );
	sol.addEnd( 2,1 );

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "The final city in a solution must always be equal to 0.\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_11 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// You are using a city that does not exist
	Solution sol( 5 );
	sol.addEnd( 0,0 );
	sol.addEnd( 1,1 );
	sol.addEnd( 3,1 );
	sol.addEnd( 5,1 );
	sol.addEnd( 0,1 );
	sol.cities = vector< int >( {0,1,3,5,0} );
	sol.cars = vector< int >( {0,1,1,1,1} );

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Invalid value for city: 5.\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_12 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 2;

	// You're using a car that doesn't exist
	Solution sol( 5 );
	sol.addEnd( 0,0 );
	sol.addEnd( 1,1 );
	sol.addEnd( 3,1 );
	sol.addEnd( 2,1 );
	sol.addEnd( 0,2 );

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Invalid value for car: 2.\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_13 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// All values are null
	Solution sol( 5 );

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Solution is null.\n", exc.what() );
	}
}
