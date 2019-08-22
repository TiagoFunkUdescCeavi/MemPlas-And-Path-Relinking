#include "gtest/gtest.h"

#include "../src/Solution.h"

TEST(IntegerFunctionTest, SETUP_SOLUTION) {

	const int SIZE = 4;
	Solution* s = new Solution( SIZE );

	ASSERT_EQ( s->sizeSolution, SIZE );
	ASSERT_EQ( s->fitness, 1 );
	ASSERT_EQ( s->satisfaction, 0 );

	for( int i = 0; i < SIZE; i++ ){
		EXPECT_EQ( s->cities[ i ], -1 ) << "Solution cities did not initialize correctly " << i;
	}
	for( int i = 0; i < SIZE; i++ ){
		EXPECT_EQ( s->cars[ i ], -1 ) << "Solution cars did not initialize correctly " << i;
	}
}
