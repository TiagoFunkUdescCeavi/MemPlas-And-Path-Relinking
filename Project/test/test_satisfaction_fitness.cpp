#include "gtest/gtest.h"
#include "model/Solution.h"
#include "utils/InstanceReader.h"


TEST( , TEST_W1) {
	const char* file = "/home/tiago/Repositorios/Github/MemPlas-And-Path-Relinking/Instances/n/AfricaSul11n.pcar";

	try{
		readInstance( file );

		Solution* sol = new Solution( 11+1 );
		sol->addEnd(0,0);
		sol->addEnd(3,0);
		sol->addEnd(4,1);
		sol->addEnd(5,1);
		sol->addEnd(8,2);
		sol->addEnd(9,2);
		sol->addEnd(10,2);
		sol->addEnd(0,2);

		sol->calculeSatisfaction();
		EXPECT_EQ( sol->satisfaction, 458 );

		sol->calculeFitness();
		EXPECT_EQ( sol->fitness, 1221 );
	} catch (exception &e) {
		cout << e.what() << endl;
		FAIL();
	}
}

TEST( , TEST_W2 ) {
	try{
		bonus_satisfaction_GLOBAL = new int[5]{ 1, 2, 4, 8, 16 };

		Solution* sol = new Solution( 11+1 );
		sol->addEnd(0,0);
		sol->addEnd(2,0);
		sol->addEnd(3,1);
		sol->addEnd(4,1);
		sol->addEnd(0,2);

		sol->calculeSatisfaction();
		EXPECT_EQ( sol->satisfaction, 29 );

	} catch (exception &e) {
		cout << e.what() << endl;
		FAIL();
	}
}

TEST( , TEST_W3 ) {
	try{
		bonus_satisfaction_GLOBAL = new int[5]{ 1, 2, 4, 8, 16 };

		Solution* sol = new Solution( 11+1 );
		sol->addEnd(0,0);
		sol->addEnd(2,0);
		sol->addEnd(3,1);
		sol->addEnd(4,1);

		sol->calculeSatisfaction();
		EXPECT_EQ( sol->satisfaction, 29 );

	} catch (exception &e) {
		cout << e.what() << endl;
		FAIL();
	}
}
