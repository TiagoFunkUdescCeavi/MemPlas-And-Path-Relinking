#include "SortingMethods.h"

vector< Solution * > quicksort( vector< Solution * > values, int begin, int end){
	Solution *aux = 0;
	Solution *pivo = 0;
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

vector< Solution * > quicksort( vector< Solution * > population ){
	for( int i = 0; i < (int) population.size(); i++ ){
		population[i]->calculeFitness();
	}
	return quicksort( population, 0, (int) population.size() );
}

Pair * quicksort(Pair *values, int begin, int end){
	Pair aux;
	Pair pivo;
	int i, j;
	i = begin;
	j = end-1;
	pivo = values[ (begin + end) / 2 ];
	while(i <= j){
		while(values[i].frequency < pivo.frequency && i < end){
			i++;
		}
		while(values[j].frequency > pivo.frequency && j > begin){
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

Pair * quicksort( Pair *values, int size ){
	return quicksort( values, 0, size );
}
