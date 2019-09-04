#include "Selections.h"

vector< Solution* > quicksort(vector< Solution* > values, int begin, int end){
	Solution* aux = 0;
	Solution* pivo = 0;
	int i, j;
	i = begin;
	j = end-1;
	pivo = values[ (begin + end) / 2 ];
	while(i <= j){
		while(values[i]->fitness < pivo->fitness && i < end){
			i++;
		}
		while(values[j]->fitness > pivo->fitness && j > begin){
			j--;
		}
		if(i <= j){
			aux = values[i];
			values[i] = values[j];
			values[j] = aux;
			i++;
			j--;
		}
	}
	if(j > begin){
		values = quicksort(values, begin, j+1);
	}
	if(i < end){
		values = quicksort(values, i, end);
	}
	return values;
}

vector< Solution* > quicksort( vector< Solution* > population ){
	for( int i = 0; i < (int) population.size(); i++ ){
		population[i]->calculeFitness();
	}
	return quicksort( population, 0, (int) population.size() );
}

vector< Solution* > selectElite( double elite, vector< Solution* > population ){
	int numberOfSolutions = population.size() * elite;
	numberOfSolutions = numberOfSolutions % 2 == 1 ? numberOfSolutions+1 : numberOfSolutions;
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
	numberOfSolutions = numberOfSolutions % 2 == 1 ? numberOfSolutions+1 : numberOfSolutions;
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
