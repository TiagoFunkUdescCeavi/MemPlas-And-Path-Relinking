#include "gtest/gtest.h"

#include "../src/Solution.h"

TEST( , SETUP_SOLUTION) {

	const int SIZE = 4;
	Solution* sol = new Solution( SIZE );

	EXPECT_EQ( sol->sizeSolution, SIZE );
	EXPECT_EQ( sol->fitness, 0 );
	EXPECT_EQ( sol->satisfaction, 0 );

	for( int i = 0; i < SIZE; i++ ){
		EXPECT_EQ( sol->cities[ i ], -1 ) << "Solution cities did not initialize correctly " << i;
	}
	for( int i = 0; i < SIZE; i++ ){
		EXPECT_EQ( sol->cars[ i ], -1 ) << "Solution cars did not initialize correctly " << i;
	}
}

TEST( , ADD_END) {
	const int SIZE = 3;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );

	EXPECT_EQ( sol->cars[ 0 ], 1 );
	EXPECT_EQ( sol->cars[ 1 ], -1 );
	EXPECT_EQ( sol->cars[ 2 ], -1 );

	EXPECT_EQ( sol->cities[ 0 ], 1 );
	EXPECT_EQ( sol->cities[ 1 ], -1 );
	EXPECT_EQ( sol->cities[ 2 ], -1 );

	sol->addEnd( 2, 2 );

	EXPECT_EQ( sol->cars[ 0 ], 1 );
	EXPECT_EQ( sol->cars[ 1 ], 2 );
	EXPECT_EQ( sol->cars[ 2 ], -1 );

	EXPECT_EQ( sol->cities[ 0 ], 1 );
	EXPECT_EQ( sol->cities[ 1 ], 2 );
	EXPECT_EQ( sol->cities[ 2 ], -1 );

	sol->addEnd( 3, 3 );

	EXPECT_EQ( sol->cars[ 0 ], 1 );
	EXPECT_EQ( sol->cars[ 1 ], 2 );
	EXPECT_EQ( sol->cars[ 2 ], 3 );

	EXPECT_EQ( sol->cities[ 0 ], 1 );
	EXPECT_EQ( sol->cities[ 1 ], 2 );
	EXPECT_EQ( sol->cities[ 2 ], 3 );
}

TEST( , ADD_END_FAIL ){
	const int SIZE = 3;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	ASSERT_THROW( sol->addEnd( 4, 4 ), runtime_error );

	EXPECT_EQ( sol->cars[ 0 ], 1 );
	EXPECT_EQ( sol->cars[ 1 ], 2 );
	EXPECT_EQ( sol->cars[ 2 ], 3 );

	EXPECT_EQ( sol->cities[ 0 ], 1 );
	EXPECT_EQ( sol->cities[ 1 ], 2 );
	EXPECT_EQ( sol->cities[ 2 ], 3 );
}

TEST( , REMOVE_INDEX_1 ){
	const int SIZE = 3;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	sol->removeIndex( 1 );

	EXPECT_EQ( sol->cars[ 0 ], 1 );
	EXPECT_EQ( sol->cars[ 1 ], 3 );
	EXPECT_EQ( sol->cars[ 2 ], -1 );

	EXPECT_EQ( sol->cities[ 0 ], 1 );
	EXPECT_EQ( sol->cities[ 1 ], 3 );
	EXPECT_EQ( sol->cities[ 2 ], -1 );
}

TEST( , REMOVE_INDEX_2 ){
	const int SIZE = 4;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	sol->removeIndex( 1 );

	EXPECT_EQ( sol->cars[ 0 ], 1 );
	EXPECT_EQ( sol->cars[ 1 ], 3 );
	EXPECT_EQ( sol->cars[ 2 ], -1 );
	EXPECT_EQ( sol->cars[ 3 ], -1 );

	EXPECT_EQ( sol->cities[ 0 ], 1 );
	EXPECT_EQ( sol->cities[ 1 ], 3 );
	EXPECT_EQ( sol->cities[ 2 ], -1 );
	EXPECT_EQ( sol->cities[ 3 ], -1 );
}

TEST( , REMOVE_INDEX_3 ){
	const int SIZE = 3;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	sol->removeIndex( 0 );

	EXPECT_EQ( sol->cars[ 0 ], 2 );
	EXPECT_EQ( sol->cars[ 1 ], 3 );
	EXPECT_EQ( sol->cars[ 2 ], -1 );

	EXPECT_EQ( sol->cities[ 0 ], 2 );
	EXPECT_EQ( sol->cities[ 1 ], 3 );
	EXPECT_EQ( sol->cities[ 2 ], -1 );
}

TEST( , REMOVE_INDEX_4 ){
	const int SIZE = 3;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	sol->removeIndex( 2 );

	EXPECT_EQ( sol->cars[ 0 ], 1 );
	EXPECT_EQ( sol->cars[ 1 ], 2 );
	EXPECT_EQ( sol->cars[ 2 ], -1 );

	EXPECT_EQ( sol->cities[ 0 ], 1 );
	EXPECT_EQ( sol->cities[ 1 ], 2 );
	EXPECT_EQ( sol->cities[ 2 ], -1 );
}

TEST( , REMOVE_INDEX_5 ){
	const int SIZE = 4;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );

	sol->removeIndex( 2 );

	EXPECT_EQ( sol->cars[ 0 ], 1 );
	EXPECT_EQ( sol->cars[ 1 ], 2 );
	EXPECT_EQ( sol->cars[ 2 ], -1 );
	EXPECT_EQ( sol->cars[ 3 ], -1 );

	EXPECT_EQ( sol->cities[ 0 ], 1 );
	EXPECT_EQ( sol->cities[ 1 ], 2 );
	EXPECT_EQ( sol->cities[ 2 ], -1 );
	EXPECT_EQ( sol->cities[ 3 ], -1 );
}

TEST( , REMOVE_INDEX_FAIL ){
	const int SIZE = 3;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	ASSERT_THROW( sol->removeIndex( 3 ), runtime_error );

	EXPECT_EQ( sol->cars[ 0 ], 1 );
	EXPECT_EQ( sol->cars[ 1 ], 2 );
	EXPECT_EQ( sol->cars[ 2 ], 3 );

	EXPECT_EQ( sol->cities[ 0 ], 1 );
	EXPECT_EQ( sol->cities[ 1 ], 2 );
	EXPECT_EQ( sol->cities[ 2 ], 3 );
}
