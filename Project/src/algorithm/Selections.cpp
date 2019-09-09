#include "Selections.h"
#include "../utils/SortingMethods.h"

vector< Solution* > selectElite( double elite, vector< Solution* > population ){
	int numberOfSolutions = population.size() * elite;
	numberOfSolutions =
		(numberOfSolutions % 2 == 1 || numberOfSolutions == 0 )
		? numberOfSolutions+1 : numberOfSolutions;
	vector< Solution* > populationElite( numberOfSolutions );
	population = quicksort( population );
	for( int i = 0; i < numberOfSolutions; i++ ){
		populationElite[ i ] = population[ i ]->copy();
	}
	return populationElite;
}

vector< Solution* > selectPopulation( double proportion, vector< Solution* > population ){
	int i = -1;
	int aux = -1, numRand = -1;
	int numberOfSolutions = proportion * population.size();
	numberOfSolutions =
		(numberOfSolutions % 2 == 1 || numberOfSolutions == 0 )
		? numberOfSolutions+1 : numberOfSolutions;
	int *myVector = new int[ numberOfSolutions ];
	vector< Solution* > selection( numberOfSolutions );

	for( i = 0; i < numberOfSolutions; i++ ){
		myVector[ i ] = i;
	}
	for( i = 0; i < numberOfSolutions; i++ ){
		numRand = rand() % numberOfSolutions;
		aux = myVector[ numRand ];
		myVector[ numRand ] = myVector[ i ];
		myVector[ i ] = aux;
	}
	for( i = 0; i < numberOfSolutions; i++ ){
		selection[ i ] = population[ myVector[ i ] ]->copy();
	}
	return selection;
}

Solution * selectBetter( vector< Solution * > population ){
	Solution * better = population[0];
	better->calculeFitness();
	for( int i = 1; i < population.size(); i++ ){
		population[i]->calculeFitness();
		if( better->fitness <= population[i]->fitness ){
			better = population[i];
		}
	}
	return better;
}
