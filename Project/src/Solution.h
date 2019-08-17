#ifndef SRC_SOLUTION_H_
#define SRC_SOLUTION_H_

#include <string>

#include "GLOBAL.h"
#include "utils.h"

using namespace std;

class Solution{
public:
	int sizeSolution = 0;
	int* cities = 0;
	int* cars = 0;
	int fitness = 0;
	int satisfaction = 0;

	Solution( int sizeSolution );
	void calculeFitness();
	void calculeSatisfaction();

	void addEnd( int city, int car );
	void removeIndex( int index );

	string toString();

};

Solution::Solution( int sizeSolution ){
	this->sizeSolution = sizeSolution;
	cities = new int[ sizeSolution ];
	cars = new int[ sizeSolution ];
	for( int i = 0; i < sizeSolution; i++ ){
		cars[ i ] = -1;
		cities[ i ] = -1;
	}
}

void Solution::calculeFitness(){
	fitness = 0;
	Car* myCar = 0;
	for( int i = 0; i < sizeSolution; i++ ){
		myCar = cars_GLOBAL[ cars[ i ] ];
		fitness += myCar->edge_weigth[ cities[ i ] ][ cities[ i+1 ] ];
		fitness += myCar->return_rate[ cities[ i ] ][ cities[ i+1 ] ];
	}
}

void Solution::calculeSatisfaction(){
	satisfaction = 0;
	for( int i = 0; i < sizeSolution; i++ ){
		if( cities[ i ] == -1 ){
			break;
		}
		satisfaction += bonus_satisfaction_GLOBAL[ cities[ i ] ];
	}
}

void Solution::addEnd( int city, int car ){
	for( int i = 0; i < sizeSolution; i++ ){
		if( cities[ i ] == -1 && cars[ i ] == -1 ){
			cities[ i ] = city;
			cars[ i ] = car;
			if( i != sizeSolution-1 ){
				cities[ i+1 ] = -1;
				cars[ i+1 ] = -1;
			}
			break;
		}
	}
}

void Solution::removeIndex( int index ){
	if( index < 0 || index >= this->sizeSolution ){
		throw runtime_error( "Index for city / car pair removal in solution is not valid. " );
	}
	if( index == this->sizeSolution-1){
		this->cities[ index ] = -1;
		this->cars[ index ] = -1;
	}
	for( int i = 0; i < this->sizeSolution-1; i++ ){
		if( i > index ){
			this->cities[ i-1 ] = this->cities[ i ];
			this->cars[ i-1 ] = this->cars[ i ];
			if( cities[ i ] == -1 ){
				break;
			}
		}
	}
}

string Solution::toString(){
	string s = ">";
	string s2 = "*";
	for( int i = 0; i < sizeSolution; i++ ){
		s += to_string( cities[i] ) + "\t";
		s2 += to_string( cars[i] ) + "\t";
	}
	return s + "\n" + s2 + "\n";
}

#endif /* SRC_SOLUTION_H_ */
