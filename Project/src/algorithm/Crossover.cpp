#include "Crossover.h"

vector< Solution > crossover( 	vector< Solution > population ){
	int numberOfSolutions = population.size();
	int randomNumber = -1;
	Solution s1( numberCities_GLOBAL+1 );
	Solution s2( numberCities_GLOBAL+1 );
	Solution new1( numberCities_GLOBAL+1 );
	Solution new2( numberCities_GLOBAL+1 );
	vector< Solution > offspring( numberOfSolutions );

	for( int i = 0; i < numberOfSolutions; i += 2 ){
		s1 = population[i];
		s2 = population[i+1];
		new1 = Solution( s1.getSize() );
		new2 = Solution( s2.getSize() );
		randomNumber = ( (s1.getSize() <= s2.getSize()) ? s1.getSize()-1 : s2.getSize()-1 );
		randomNumber = rand() % randomNumber;
		if( randomNumber == 0 ) randomNumber++;

		for( int j = 0; j < randomNumber; j++ ){
			new1.addEnd( s1.cities[ j ], s1.cars[ j ] );
			new2.addEnd( s2.cities[ j ], s2.cars[ j ] );
		}
		for( int j = randomNumber; j < s2.getSize(); j++ ){
			new1.addEnd( s2.cities[ j ], s2.cars[ j ] );
		}
		for( int j = randomNumber; j < s1.getSize(); j++ ){
			new2.addEnd( s1.cities[ j ], s1.cars[ j ] );
		}

		offspring[ i ]   = new1;
		offspring[ i+1 ] = new2;
	}

	return offspring;
}
