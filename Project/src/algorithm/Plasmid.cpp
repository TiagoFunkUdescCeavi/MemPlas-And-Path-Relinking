#include "Plasmid.h"

#include "../utils/Prints.h"

vector< Solution > plasmid( vector< Solution > population, int sizePlas, vector< Solution > elite ){
	int numberOfSolutions = elite.size();
	int randomNumber = -1;
//	int *plasCities = 0, *plasCars = 0;
	Solution sElite;
	Solution sNormal;
	Solution newSol;
	Solution better;
	vector< Solution > offspring( numberOfSolutions );

	for( int i = 0; i < numberOfSolutions; i++ ){
		sElite = elite[i];
		sNormal = population[i];
		better = 0;

		randomNumber = ( (sElite.position <= sNormal.position) ? sElite.position-1 : sNormal.position-1 );
		randomNumber = ( rand() % (randomNumber-sizePlas-1) );

//		plasCities = new int[ sizePlas ];
//		plasCars = new int[ sizePlas ];
//		for( int j = randomNumber; j < ( randomNumber + sizePlas ); j++ ){
//			plasCities[ j ] = sElite->cities[ j ];
//			plasCars[ j ] = sElite->cars[ j ];
//		}

		newSol = Solution( sElite.sizeSolution );

		for( int j = 0; j < sNormal.position; j++ ){
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
