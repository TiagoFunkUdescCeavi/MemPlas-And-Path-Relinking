#include <bits/stdc++.h>

#include "MultiOperatorsLocalSearch.h"

vector< Solution* > removeSaving( vector< Solution* > population ){
	bool go_ahead;
	int minCity, posMin;
	Solution* dad = 0;
	Solution* sol = 0;
	vector< Solution* > newPopulation( population.size() );

	for( int i = 0; i < (int) population.size(); i++ ){
		go_ahead = true;
		sol = population[ i ];
		dad = sol->copy();

		while( go_ahead ){
			minCity = INT_MAX;
			posMin = -1;

			for( int j = 1; j < sol->position-1; j++ ){
				if( sol->cities[ j ] == -1 ){
					break;
				} else if( bonus_satisfaction_GLOBAL[ sol->cities[ j ] ] < minCity ){
					minCity = bonus_satisfaction_GLOBAL[ sol->cities[ j ] ];
					posMin = j;
				}
			}

			sol->calculeSatisfaction();

			if( sol->satisfaction-bonus_satisfaction_GLOBAL[ minCity ]
						< minimal_satisfaction_GLOBAL*satisfaction_total_GLOBAL ){
				go_ahead = false;
			}else {
				sol->removeIndex( posMin );
			}
		}

		sol->calculeFitness();
		dad->calculeFitness();

		if( sol->fitness < dad->fitness ){
			newPopulation[i] = sol;
		}else{
			newPopulation[i] = dad;
		}
	}
	return newPopulation;
}

vector< Solution* > invertSolution( vector< Solution* > population ){
	Solution* dad = 0;
	Solution* sol = 0;
	vector< Solution* > newPopulation( population.size() );

	for( int i = 0; i < (int) population.size(); i++ ){
		dad = population[ i ];
		sol = new Solution( dad->sizeSolution );

		for( int j = dad->position-1; j >= 0; j-- ){
			if( dad->cars[ j ] != dad->cars[ j-1 ] && j != 0 ){
				sol->addEnd( dad->cities[ j ], dad->cars[ j-1 ] );
			}else{
				sol->addEnd( dad->cities[ j ], dad->cars[ j ] );
			}
		}

		sol->calculeFitness();
		dad->calculeFitness();

		if( sol->fitness < dad->fitness ){
			newPopulation[i] = sol;
		}else{
			newPopulation[i] = dad;
		}
	}
	return newPopulation;
}

vector< Solution* > invertSavingCity( vector< Solution* > population ){
	vector< Solution* > sol;
	sol = population;

	return sol;
}

vector< Solution* > replaceSavingCity( vector< Solution* > population ){
	vector< Solution* > sol;
	sol = population;

	return sol;
}

vector< Solution* > replaceSavingCar( vector< Solution* > population ){
	vector< Solution* > sol;
	sol = population;

	return sol;
}

vector< Solution* > operator_2opt( vector< Solution* > population ){
	vector< Solution* > sol;
	sol = population;

	return sol;
}

vector< Solution* > multiOperatorsLocalSearch( vector< Solution* > population){
	vector< Solution* > sol;
	sol = removeSaving( population );
	sol = invertSolution( sol );
//	sol = invertSavingCity( sol );
//	sol = replaceSavingCity( sol );
//	sol = replaceSavingCar( sol );
//	sol = operator_2opt( sol );
	return sol;
}
