#include "Plasmid.h"

#include "../utils/Prints.h"

vector< Solution > plasmid( vector< Solution > population, double sizePlas, vector< Solution > elite ){
	myPrint( "########", 2 );
	int numberOfSolutions = elite.size();
	int sizeSolution = -1;
	int randomNumber = -1;
	Solution sElite( numberCities_GLOBAL+1 );
	Solution sNormal( numberCities_GLOBAL+1 );
	Solution newSol( numberCities_GLOBAL+1 );
	Solution better( numberCities_GLOBAL+1 );
	vector< Solution > offspring( numberOfSolutions );

	for( int i = 0; i < numberOfSolutions; i++ ){
		sElite = elite[i];
		sNormal = population[i];
		better = Solution( numberCities_GLOBAL+1 );

		sizeSolution = ( (sElite.getSize() <= sNormal.getSize()) ? sElite.getSize()-1 : sNormal.getSize()-1 );
		randomNumber = sizeSolution * sizePlas;
		randomNumber = ( rand() % (sizeSolution-randomNumber) );


		newSol = Solution( numberCities_GLOBAL+1 );

		for( int j = 0; j < sNormal.getSize(); j++ ){
			if( j == randomNumber ){
				for(int k = 0; k < sizePlas; k++ ){
					newSol.addEnd( sElite.cities[ j ], sElite.cars[ j ] );
					j++;
				}
				j--;
			}else{
				newSol.addEnd( sNormal.cities[j], sNormal.cars[j] );
			}
		}
		offspring[i] = newSol;
	}

	return offspring;
}
