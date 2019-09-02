#include "Crossover.h"

#include "../utils/utils.h"

vector< Solution* > crossover( 	vector< Solution* > population ){
	int numberOfSolutions = population.size();
	int randomNumber = -1;
	Solution *s1 = 0, *s2 = 0;
	Solution *new1 = 0, *new2 = 0;
	vector< Solution* > offspring( numberOfSolutions );

	for( int i = 0; i < numberOfSolutions; i += 2 ){
		s1 = population[i];
		s2 = population[i+1];
		new1 = new Solution( s1->sizeSolution );
		new2 = new Solution( s2->sizeSolution );
		randomNumber = ( (s1->position <= s2->position) ? s1->position-1 : s2->position-1 );
		randomNumber = rand() % randomNumber;
		if( randomNumber == 0 ) randomNumber++;

		for( int j = 0; j < randomNumber; j++ ){
			new1->addEnd( s1->cities[ j ], s1->cars[ j ] );
			new2->addEnd( s2->cities[ j ], s2->cars[ j ] );
		}
		for( int j = randomNumber; j < s2->position; j++ ){
			new1->addEnd( s2->cities[ j ], s2->cars[ j ] );
		}
		for( int j = randomNumber; j < s1->position; j++ ){
			new2->addEnd( s1->cities[ j ], s1->cars[ j ] );
		}

		offspring[ i ] = new1;
		offspring[ i+1 ] = new2;
	}

	return offspring;
}
