#include "gtest/gtest.h"

#include "../src/GLOBAL.h"
#include "../src/Validate.h"

TEST( , IS_OK_1 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,1,2,3,0};
	sol->cars = new int[5]{1,1,1,2,2};

	ASSERT_TRUE( isOk( sol ) );
}

TEST( , IS_OK_2 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,1,2,3,0};
	sol->cars = new int[5]{1,1,1,1,1};

	ASSERT_TRUE( isOk( sol ) );
}

TEST( , IS_OK_3 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,2,3,0,-1};
	sol->cars = new int[5]{1,1,1,1,-1};

	ASSERT_TRUE( isOk( sol ) );
}

TEST( , IS_OK_FAIL_1 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// Not starting in the correct city, that city 0
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{2,3,4,1,0};
	sol->cars = new int[5]{1,1,1,1,1};

	ASSERT_THROW( isOk( sol ), runtime_error );
}

TEST( , IS_OK_FAIL_2 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// It's repeating the city one after another
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,2,2,4,0};
	sol->cars = new int[5]{1,1,1,2,2};

	ASSERT_THROW( isOk( sol ), runtime_error );
}

TEST( , IS_OK_FAIL_3 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// It is repeating the city in an interspersed way
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,2,3,2,0};
	sol->cars = new int[5]{1,1,1,2,2};

	ASSERT_THROW( isOk( sol ), runtime_error );
}

TEST( , IS_OK_FAIL_4 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// Is repeating the car intercalately
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,2,3,5,0};
	sol->cars = new int[5]{1,1,2,2,1};

	ASSERT_THROW( isOk( sol ), runtime_error );
}

TEST( , IS_OK_FAIL_5 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// All values are null
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{-1,-1,-1,-1,-1};
	sol->cars = new int[5]{-1,-1,-1,-1,-1};

	ASSERT_THROW( isOk( sol ), runtime_error );
}

TEST( , IS_OK_FAIL_6 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// All values are null, although values still exist after the number -1.
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{-1,2,3,4,5};
		sol->cars = new int[5]{-1,1,1,1,1};

	ASSERT_THROW( isOk( sol ), runtime_error );
}

TEST( , IS_OK_FAIL_7 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// Has only one city before value -1.
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,-1,3,4,5};
		sol->cars = new int[5]{0,-1,1,1,1};

	ASSERT_THROW( isOk( sol ), runtime_error );
}


TEST( , IS_OK_FAIL_8 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// Starts in the correct city, but does not end in it.
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,1,3,4,2};
		sol->cars = new int[5]{0,1,1,1,1};

	ASSERT_THROW( isOk( sol ), runtime_error );
}

TEST( , IS_OK_FAIL_9 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// You are using a city that does not exist
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,1,3,5,0};
	sol->cars = new int[5]{0,1,1,1,1};

	ASSERT_THROW( isOk( sol ), runtime_error );
}

TEST( , IS_OK_FAIL_10 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// You're using a car that doesn't exist
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,1,3,2,0};
	sol->cars = new int[5]{0,1,1,1,2};

	ASSERT_THROW( isOk( sol ), runtime_error );
}
