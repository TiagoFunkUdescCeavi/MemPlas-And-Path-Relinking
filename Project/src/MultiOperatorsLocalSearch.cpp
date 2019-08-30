#include <bits/stdc++.h>

#include "MultiOperatorsLocalSearch.h"

vector< Solution* > removeSaving( vector< Solution* > population ){
	bool go_ahead;
	int minCity, posMin;
	Solution* dad = 0;
	Solution* son = 0;
	vector< Solution* > newPopulation( population.size() );

	for( int i = 0; i < (int) population.size(); i++ ){
		go_ahead = true;
		son = population[ i ];
		dad = son->copy();

		while( go_ahead ){
			minCity = INT_MAX;
			posMin = -1;

			for( int j = 1; j < son->position-1; j++ ){
				if( son->cities[ j ] == -1 ){
					break;
				} else if( bonus_satisfaction_GLOBAL[ son->cities[ j ] ] < minCity ){
					minCity = bonus_satisfaction_GLOBAL[ son->cities[ j ] ];
					posMin = j;
				}
			}

			son->calculeSatisfaction();

			if( son->satisfaction-bonus_satisfaction_GLOBAL[ minCity ]
						< minimal_satisfaction_GLOBAL*satisfaction_total_GLOBAL ){
				go_ahead = false;
			}else {
				son->removeIndex( posMin );
			}
		}

		son->calculeFitness();
		dad->calculeFitness();

		if( son->fitness < dad->fitness ){
			newPopulation[i] = son;
		}else{
			newPopulation[i] = dad;
		}
	}
	return newPopulation;
}

vector< Solution* > invertSolution( vector< Solution* > population ){
	Solution* dad = 0;
	Solution* son = 0;
	vector< Solution* > newPopulation( population.size() );

	for( int i = 0; i < (int) population.size(); i++ ){
		dad = population[ i ];
		son = new Solution( dad->sizeSolution );

		for( int j = dad->position-1; j >= 0; j-- ){
			if( dad->cars[ j ] != dad->cars[ j-1 ] && j != 0 ){
				son->addEnd( dad->cities[ j ], dad->cars[ j-1 ] );
			}else{
				son->addEnd( dad->cities[ j ], dad->cars[ j ] );
			}
		}

		son->calculeFitness();
		dad->calculeFitness();

		if( son->fitness < dad->fitness ){
			newPopulation[i] = son;
		}else{
			newPopulation[i] = dad;
		}
	}
	return newPopulation;
}

vector< Solution* > insertSavingCity( vector< Solution* > population ){
	bool* visitedCities = 0;
	Solution* dad = 0;
	Solution* son = 0;
	vector< Solution* > newPopulation( population.size() );

	for( int i = 0; i < (int) population.size(); i++ ){
		son = population[ i ];
		dad = son->copy();

		visitedCities = new bool[ numberCities_GLOBAL ];
		for( int j = 0; j < numberCities_GLOBAL; j++ ){
			visitedCities[ j ] = false;
		}
		for( int j = 0; j < son->position; j++ ){
			visitedCities[ son->cities[ j ] ] = true;
		}
		for( int j = 0; j < numberCities_GLOBAL; j++ ){
			if( !visitedCities[ j ] ){

				for( int k = 1; k < son->position-1; k++ ){
					son->addCityAt( k, j );

					son->calculeFitness();
					dad->calculeFitness();

					if( son->fitness < dad->fitness ){
						dad = son->copy();
					}
					son->removeIndex( k );
				}
			}
		}
		newPopulation[i] = dad;
	}
	return newPopulation;
}

vector< Solution* > replaceSavingCity( vector< Solution* > population ){
	int oldCity = -1;
	bool* visitedCities = 0;
	Solution* dad = 0;
	Solution* son = 0;
	vector< Solution* > newPopulation( population.size() );

	for( int i = 0; i < (int) population.size(); i++ ){
		son = population[ i ];
		dad = son->copy();

		visitedCities = new bool[ numberCities_GLOBAL ];
		for( int j = 0; j < numberCities_GLOBAL; j++ ){
			visitedCities[ j ] = false;
		}
		for( int j = 0; j < son->position; j++ ){
			visitedCities[ son->cities[ j ] ] = true;
		}
		for( int j = 0; j < numberCities_GLOBAL; j++ ){
			if( !visitedCities[ j ] ){

				for( int k = 1; k < son->position-1; k++ ){
					oldCity = son->cities[ k ];
					son->insertCityAt( k, j );

					son->calculeFitness();
					dad->calculeFitness();

					if( son->fitness < dad->fitness ){
						dad = son->copy();
					}
					son->insertCityAt( k, oldCity );
				}
			}
		}
		newPopulation[i] = dad;
	}
	return newPopulation;
}

vector< Solution* > replaceSavingCar( vector< Solution* > population ){
	bool* usedCars = 0;
	Solution* backup = 0;
	Solution* better = 0;
	Solution* actual = 0;
	vector< Solution* > newPopulation( population.size() );

	for( int i = 0; i < (int) population.size(); i++ ){
		better = population[ i ];
		actual = better->copy();
		backup = better->copy();

		usedCars = new bool[ numberCars_GLOBAL ];
		for( int j = 0; j < numberCars_GLOBAL; j++ ){
			usedCars[ j ] = false;
		}
		for( int j = 0; j < actual->position; j++ ){
			usedCars[ actual->cars[ j ] ] = true;
		}
		for( int j = 0; j < numberCars_GLOBAL; j++ ){
			if( !usedCars[ j ] ){

				actual = backup->copy();
				for( int k = 0; k < actual->position; k++ ){
					actual->insertCarAt( k, j );

					actual->calculeFitness();
					better->calculeFitness();

					if( actual->fitness < better->fitness ){
						better = actual->copy();
					}
				}
			}
		}
		newPopulation[i] = better;
	}

	return newPopulation;
}

void printVetor( int size, int* vetor ){
	for( int i = 0; i < size; i++ ){
		myPrint( vetor[ i ], false );
		myPrint( ", ", false );
	}
	myPrint( "", true );
}

vector< Solution* > operator_2opt( vector< Solution* > population ){
	int count = -1;
	int* myVector = 0;
	Solution* backup = 0;
	Solution* better = 0;
	Solution* actual = 0;
	vector< Solution* > newPopulation( population.size() );

	for( int i = 0; i < (int) population.size(); i++ ){
		actual = population[ i ];
		better = actual->copy();
		backup = actual->copy();
		myVector = new int[ actual->sizeSolution ];

		for( int j = 1; j < actual->position-2; j++ ){
			count = 0;

			myVector[ count++ ] = actual->cities[ 0 ];
			for( int k = j+1; k < actual->position-1; k++ ){
				myVector[ count++ ] = actual->cities[ k ];
			}

			for( int k = 1; k <= j; k++ ){
				myVector[ count++ ] = actual->cities[ k ];
			}

			myVector[ count++ ] = actual->cities[ actual->position-1 ];
			myVector[ count++ ] = actual->cities[ actual->position ];

			actual->cities = myVector;
			actual->calculeFitness();
			better->calculeFitness();

			if( actual->fitness < better->fitness ){
				better = actual->copy();
			}
			actual = backup->copy();
		}

		newPopulation[ i ] = better;
	}

	return newPopulation;
}

vector< Solution* > multiOperatorsLocalSearch( vector< Solution* > population){
	vector< Solution* > sol;
	sol = removeSaving( population );
	sol = invertSolution( sol );
	sol = insertSavingCity( sol );
	sol = replaceSavingCity( sol );
	sol = replaceSavingCar( sol );
	sol = operator_2opt( sol );
	return sol;
}
