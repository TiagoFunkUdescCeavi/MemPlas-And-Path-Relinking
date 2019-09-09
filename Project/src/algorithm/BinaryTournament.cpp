#include "BinaryTournament.h"

vector< Solution * > binaryTournament( vector< Solution * > population, vector< Solution * > offspring ){
	int numRand = -1;
	Solution *a = 0, *b = 0, *aux = 0;
	vector< Solution * > newPopulation( population.size() );

	for( int i = 0; i < population.size(); i++ ){
		numRand = rand() % population.size();
		aux = population[ numRand ];
		population[ numRand ] = population[ i ];
		population[ i ] = aux;
	}
	for( int i = 0; i < offspring.size(); i++ ){
		numRand = rand() % offspring.size();
		aux = offspring[ numRand ];
		offspring[ numRand ] = offspring[ i ];
		offspring[ i ] = aux;
	}

	for( int i = 0; i < newPopulation.size(); i++ ){
		if( i < offspring.size() ){
			a = population[i];
			b = offspring[i];

			a->calculeFitness();
			b->calculeFitness();

			if( a->fitness <= b->fitness ){
				newPopulation[i] = a;
			}else{
				newPopulation[i] = b;
			}
		}else{
			newPopulation[i] = population[i];
		}
	}
	return newPopulation;
}
