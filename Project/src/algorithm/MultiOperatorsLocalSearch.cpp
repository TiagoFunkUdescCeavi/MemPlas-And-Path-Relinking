#include "MultiOperatorsLocalSearch.h"

#include <bits/stdc++.h>

#include "../utils/Prints.h"
#include "../utils/Validate.h"

vector< Solution > removeSaving( vector< Solution > population ){
	bool go_ahead;
	int posMin, minCitySatisfaction;
	Solution son( numberCities_GLOBAL+1 );
	Solution dad( numberCities_GLOBAL+1 );
	vector< Solution > newPopulation( population.size() );

	for( int i = 0; i < (int) population.size(); i++ ){
		go_ahead = true;
		son = population[i].copy();
		dad = son.copy();

		while( go_ahead ){
			posMin = -1;
			minCitySatisfaction = INT_MAX;

			for( int j = 1; j < son.getSize()-1; j++ ){
				if( son.cities[ j ] == -1 ){
					break;
				} else if( bonus_satisfaction_GLOBAL[ son.cities[ j ] ] < minCitySatisfaction ){
					minCitySatisfaction = bonus_satisfaction_GLOBAL[ son.cities[ j ] ];
					posMin = j;
				}
			}

			son.calculeSatisfaction();
			dad.calculeFitness();
			son.calculeSatisfaction();

			if( son.getSatisfaction() - minCitySatisfaction
						< minimal_satisfaction_GLOBAL*satisfaction_total_GLOBAL ){
				go_ahead = false;
			}else {
				son.removeIndex( posMin );
			}
		}

		son.calculeFitness();
		dad.calculeFitness();

		if( son.getFitness() < dad.getFitness() ){
			newPopulation[i] = son;
		}else{
			newPopulation[i] = dad;
		}
	}
	return newPopulation;
}

vector< Solution > invertSolution( vector< Solution > population ){
	Solution son( numberCities_GLOBAL+1 );
	Solution dad( numberCities_GLOBAL+1 );
	vector< Solution > newPopulation( population.size() );

	for( int i = 0; i < (int) population.size(); i++ ){
		dad = population[ i ].copy();
		son = Solution( dad.getSize() );

		for( int j = dad.getSize()-1; j >= 0; j-- ){
			if( dad.cars[ j ] != dad.cars[ j-1 ] && j != 0 ){
				son.addEnd( dad.cities[ j ], dad.cars[ j-1 ] );
			}else{
				son.addEnd( dad.cities[ j ], dad.cars[ j ] );
			}
		}

		son.calculeFitness();
		dad.calculeFitness();

		if( son.getFitness() < dad.getFitness() ){
			newPopulation[i] = son;
		}else{
			newPopulation[i] = dad;
		}
	}
	return newPopulation;
}

vector< Solution > insertSavingCity( vector< Solution > population ){
	bool visitedCities[ numberCities_GLOBAL ];
	Solution son( numberCities_GLOBAL+1 );
	Solution better( numberCities_GLOBAL+1 );
	vector< Solution > newPopulation( population.size() );

	for( int i = 0; i < (int) population.size(); i++ ){
		son = population[ i ].copy();
		better = son.copy();

		for( int j = 0; j < numberCities_GLOBAL; j++ ){
			visitedCities[ j ] = false;
		}
		for( int j = 0; j < son.getSize(); j++ ){
			visitedCities[ son.cities[ j ] ] = true;
		}
		for( int j = 0; j < numberCities_GLOBAL; j++ ){
			if( !visitedCities[ j ] ){

				for( int k = 1; k < son.getSize()-1; k++ ){
					son.addCityAt( k, j );

					son.calculeSatisfaction();
					son.calculeFitness();
					better.calculeFitness();

					if( son.getSatisfaction() >= minimal_satisfaction_GLOBAL*satisfaction_total_GLOBAL ){
						if( son.getFitness() < better.getFitness() ){
							better = son.copy();
						}
					}
					son.removeIndex( k );
				}
			}
		}
		newPopulation[i] = better;
	}
	return newPopulation;
}

vector< Solution > replaceSavingCity( vector< Solution > population ){
	int oldCity = -1;
	bool visitedCities[ numberCities_GLOBAL ];
	Solution son( numberCities_GLOBAL+1 );
	Solution better( numberCities_GLOBAL+1 );
	vector< Solution > newPopulation( population.size() );

	for( int i = 0; i < (int) population.size(); i++ ){
		son = population[ i ].copy();
		better = son.copy();

		for( int j = 0; j < numberCities_GLOBAL; j++ ){
			visitedCities[ j ] = false;
		}
		for( int j = 0; j < son.getSize(); j++ ){
			visitedCities[ son.cities[ j ] ] = true;
		}
		for( int j = 0; j < numberCities_GLOBAL; j++ ){
			if( !visitedCities[ j ] ){

				for( int k = 1; k < son.getSize()-1; k++ ){
					oldCity = son.cities[ k ];
					son.insertCityAt( k, j );

					son.calculeSatisfaction();
					son.calculeFitness();
					better.calculeFitness();

					if( son.getSatisfaction() >= minimal_satisfaction_GLOBAL*satisfaction_total_GLOBAL ){
						if( son.getFitness() < better.getFitness() ){
							better = son;
						}
					}
					son.insertCityAt( k, oldCity );
				}
			}
		}
		newPopulation[i] = better;
	}
	return newPopulation;
}

vector< Solution > replaceSavingCar( vector< Solution > population ){
	bool usedCars[ numberCars_GLOBAL ];
	Solution better( numberCities_GLOBAL+1 );
	Solution actual( numberCities_GLOBAL+1 );
	vector< Solution > newPopulation( population.size() );

	for( int i = 0; i < (int) population.size(); i++ ){
		better = population[ i ].copy();
		actual = better.copy();

		for( int j = 0; j < numberCars_GLOBAL; j++ ){
			usedCars[ j ] = false;
		}
		for( int j = 0; j < actual.getSize(); j++ ){
			usedCars[ actual.cars[ j ] ] = true;
		}
		for( int j = 0; j < numberCars_GLOBAL; j++ ){
			if( !usedCars[ j ] ){

				for( int k = 0; k < actual.getSize(); k++ ){
					actual.insertCarAt( k, j );
					usedCars[j] = true;

					actual.calculeSatisfaction();
					actual.calculeFitness();
					better.calculeFitness();

					if( actual.getSatisfaction() >= minimal_satisfaction_GLOBAL*satisfaction_total_GLOBAL ){
						if( actual.getFitness() < better.getFitness() ){
							better = actual.copy();
						}
					}
				}
			}
		}
		newPopulation[i] = better;
	}
	return newPopulation;
}

vector< Solution > operator_2opt( vector< Solution > population ){
	Solution backup( numberCities_GLOBAL+1 );
	Solution better( numberCities_GLOBAL+1 );
	Solution actual( numberCities_GLOBAL+1 );
	vector< int > myVector( numberCities_GLOBAL+1 );
	vector< Solution > newPopulation( population.size() );

	for( int i = 0; i < (int) population.size(); i++ ){
		actual = population[ i ].copy();
		better = actual.copy();
		backup = actual.copy();

		for( int j = 1; j < actual.getSize()-2; j++ ){
//			myPrint( to_string(i)+"-"+to_string(j), 1 );
			myVector.clear();

			myVector.push_back( actual.cities[ 0 ] );
			for( int k = j+1; k < actual.getSize()-1; k++ ){
				myVector.push_back(  actual.cities[ k ] );
			}

			for( int k = 1; k <= j; k++ ){
				myVector.push_back( actual.cities[ k ] );
			}

			myVector.push_back( actual.cities[ actual.getSize()-1 ] );
			myVector.push_back( actual.cities[ actual.getSize() ] );
			actual.cities = myVector;
//			for( int k = 0; k < numberCities_GLOBAL+1; k++ ){
//				actual.cities[k] = myVector[k];
//			}
			actual.calculeFitness();
			better.calculeFitness();

			if( actual.getFitness() < better.getFitness() ){
				better = actual;
			}
			actual = backup;
		}
		newPopulation[ i ] = better;
	}
	return newPopulation;
}

vector< Solution > multiOperatorsLocalSearch( vector< Solution > population){
	vector< Solution > sol = population;
	myPrint( "removeSaving", 1 );
	sol = removeSaving( sol );
	myPrint( "invertSolution", 1 );
	sol = invertSolution( sol );
	myPrint( "insertSavingCity", 1 );
	sol = insertSavingCity( sol );
	myPrint( "replaceSavingCity", 1 );
	sol = replaceSavingCity( sol );
	myPrint( "replaceSavingCar", 1 );
	sol = replaceSavingCar( sol );
	myPrint( "operator_2opt", 1 );
	sol = operator_2opt( sol );
	myPrint( "multiOperatorsLocalSearch done", 1 );
	return sol;
}
