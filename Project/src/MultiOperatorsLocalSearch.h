#ifndef SRC_MULTIOPERATORSLOCALSEARCH_H_
#define SRC_MULTIOPERATORSLOCALSEARCH_H_

#include <bits/stdc++.h>

vector< Solution* > removeSaving( vector< Solution* > population ){
	bool go_ahead;
	int minCity, posMin;
	Solution* ind;
	vector< Solution* > sol;
	sol = population;

	for( int i = 0; i < (int) sol.size(); i++ ){
		go_ahead = true;
		ind = sol[ i ];

		while( go_ahead ){
			minCity = INT_MAX;
			posMin = -1;

			for( int j = 0; j < ind->sizeSolution; j++ ){
				if( ind->cities[ j ] == -1 ){
					break;
				} else if( bonus_satisfaction_GLOBAL[ ind->cities[ j ] ] < minCity ){
					minCity = bonus_satisfaction_GLOBAL[ ind->cities[ j ] ];
					posMin = j;
				}
			}

			ind->calculeFitness();

			if( ind->fitness-bonus_satisfaction_GLOBAL[ minCity ]
						< minimal_satisfaction_GLOBAL*satisfaction_total_GLOBAL ){
				go_ahead = false;
			}else {
				ind->removeIndex( posMin );
			}
		}
	}

	return sol;
}

vector< Solution* > invertSolution( vector< Solution* > population ){
	vector< Solution* > sol;
	sol = population;

	return sol;
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
	sol = population;
	sol = removeSaving( sol );
	sol = invertSolution( sol );
	sol = invertSavingCity( sol );
	sol = replaceSavingCity( sol );
	sol = replaceSavingCar( sol );
	sol = operator_2opt( sol );
	return sol;
}

#endif /* SRC_MULTIOPERATORSLOCALSEARCH_H_ */
