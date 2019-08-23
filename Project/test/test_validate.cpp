#include "gtest/gtest.h"

#include "../src/GLOBAL.h"
#include "../src/Validate.h"

TEST( , IS_OK_1 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 2;

	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{1,2,3,4,5};
	sol->cars = new int[5]{1,1,1,2,2};

	ASSERT_TRUE( isOk( sol ) );
}

TEST( , IS_OK_2 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 2;

	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{1,2,3,4,5};
	sol->cars = new int[5]{1,1,1,1,1};

	ASSERT_TRUE( isOk( sol ) );
}

TEST( , IS_OK_3 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 2;

	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{1,2,3,-1,-1};
	sol->cars = new int[5]{1,1,1,-1,-1};

	ASSERT_TRUE( isOk( sol ) );
}

TEST( , IS_OK_FAIL_1 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 2;

	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{2,3,4,5,1};
	sol->cars = new int[5]{1,1,1,1,1};

	ASSERT_THROW( isOk( sol ), runtime_error );
}

TEST( , IS_OK_FAIL_2 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 2;

	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{1,2,2,4,5};
	sol->cars = new int[5]{1,1,1,2,2};

	ASSERT_THROW( isOk( sol ), runtime_error );
}

TEST( , IS_OK_FAIL_3 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 2;

	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{1,2,3,2,5};
	sol->cars = new int[5]{1,1,1,2,2};

	ASSERT_THROW( isOk( sol ), runtime_error );
}

TEST( , IS_OK_FAIL_4 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 2;

	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{1,2,3,4,5};
	sol->cars = new int[5]{1,1,2,2,1};

	ASSERT_THROW( isOk( sol ), runtime_error );
}

TEST( , IS_OK_FAIL_5 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 2;

	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{-1,-1,-1,-1,-1};
	sol->cars = new int[5]{-1,-1,-1,-1,-1};

	ASSERT_THROW( isOk( sol ), runtime_error );
}

TEST( , IS_OK_FAIL_6 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 2;

	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{-1,2,3,4,5};
		sol->cars = new int[5]{-1,1,1,1,1};

	ASSERT_THROW( isOk( sol ), runtime_error );
}

TEST( , IS_OK_FAIL_7 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 2;

	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{1,-1,3,4,5};
		sol->cars = new int[5]{1,-1,1,1,1};

	ASSERT_THROW( isOk( sol ), runtime_error );
}
