#include "SortingMethods.h"

vector< Solution > quicksort( vector< Solution > values, int begin, int end){
	Solution aux( numberCities_GLOBAL+1 );
	Solution pivo( numberCities_GLOBAL+1 );
	int i, j;
	i = begin;
	j = end-1;
	pivo = values[ (begin + end) / 2 ];
	while(i <= j){
		while(values[i].getFitness() < pivo.getFitness() && i < end){
			i++;
		}
		while(values[j].getFitness() > pivo.getFitness() && j > begin){
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

vector< Solution > quicksort( vector< Solution > population ){
	for( int i = 0; i < (int) population.size(); i++ ){
		population[i].calculeFitness();
	}
	return quicksort( population, 0, (int) population.size() );
}

vector< Pair > quicksort( vector< Pair > values, int begin, int end){
	Pair aux;
	Pair pivo;
	int i, j;
	i = begin;
	j = end-1;
	pivo = values[ (begin + end) / 2 ];
	while(i <= j){
		while(values[i].value < pivo.value && i < end){
			i++;
		}
		while(values[j].value > pivo.value && j > begin){
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

vector< Pair > quicksort( vector< Pair > values ){
	return quicksort( values, 0, (int) values.size() );
}
