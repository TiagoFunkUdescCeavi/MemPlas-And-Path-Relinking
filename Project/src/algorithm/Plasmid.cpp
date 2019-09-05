#include "Plasmid.h"

#include "../utils/Prints.h"

vector< Solution* > plasmid( vector< Solution* > population, int sizePlas, vector< Solution* > elite ){
	int numberOfSolutions = elite.size();
	int randomNumber = -1;
//	int *plasCities = 0, *plasCars = 0;
	Solution *sElite = 0, *sNormal = 0;
	Solution *newSol = 0, *better = 0;
	vector< Solution* > offspring( numberOfSolutions );

	for( int i = 0; i < numberOfSolutions; i++ ){
		sElite = elite[i];
		sNormal = population[i];
		better = 0;

		randomNumber = ( rand() % (sElite->position-sizePlas-1) ) + 1;

//		plasCities = new int[ sizePlas ];
//		plasCars = new int[ sizePlas ];
//		for( int j = randomNumber; j < ( randomNumber + sizePlas ); j++ ){
//			plasCities[ j ] = sElite->cities[ j ];
//			plasCars[ j ] = sElite->cars[ j ];
//		}

		newSol = new Solution( sElite->sizeSolution );

		for( int j = 0; j < sNormal->position; j++ ){
			if( j == randomNumber ){
				for(int k = 0; k < sizePlas; k++ ){
					newSol->addEnd( sElite->cities[ k ], sElite->cars[ k ] );
					j++;
				}
				j--;
			}else{
				newSol->addEnd( sNormal->cities[j], sNormal->cars[j] );
			}
		}
		offspring[i] = better;
	}

	return offspring;
}
