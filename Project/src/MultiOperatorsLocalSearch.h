#ifndef SRC_MULTIOPERATORSLOCALSEARCH_H_
#define SRC_MULTIOPERATORSLOCALSEARCH_H_

#include <bits/stdc++.h>

vector< Solution* > removeSaving( vector< Solution* > population ){
	int minCity, posMin;
	Solution* ind = 0;
	vector< Solution* > sol;
	sol = population;
	for( int i = 0; i < (int) sol.size(); i++ ){
		ind = sol[ i ];

		while( ind->fitness > minimal_satisfaction_GLOBAL*satisfaction_total_GLOBAL ){
			minCity = -1;
			posMin = -1;
			for( int j = 0; j < ind->sizeSolution; j++ ){

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
