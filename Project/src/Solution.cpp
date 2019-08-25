#include "Solution.h"

Solution::Solution( int sizeSolution ){
	this->sizeSolution = sizeSolution;
	cities = new int[ sizeSolution ];
	cars = new int[ sizeSolution ];
	for( int i = 0; i < sizeSolution; i++ ){
		cities[ i ] = -1;
		cars[ i ] = -1;
	}
}

void Solution::calculeFitness(){
	this->fitness = 0;
	int previous_car = -1;
	Car* myCar = 0;
	for( int i = 0; i < this->sizeSolution-1; i++ ){
		if( cities[ i ] == -1 ){
			break;
		}
		if( i == 0 ){
			previous_car = this->cars[ i ];
		}
		myCar = cars_GLOBAL[ this->cars[ i ] ];
		this->fitness += myCar->edge_weigth[ this->cities[ i ] ][ this->cities[ i+1 ] ];
		this->fitness += myCar->return_rate[ previous_car ][ this->cities[ i+1 ] ];
		if( previous_car != this->cars[ i ] ){
			previous_car = this->cars[ i ];
		}
	}
}

void Solution::calculeSatisfaction(){
	this->satisfaction = 0;
	for( int i = 0; i < sizeSolution; i++ ){
		if( cities[ i ] == -1 ){
			break;
		}
		this->satisfaction += bonus_satisfaction_GLOBAL[ cities[ i ] ];
	}
}

void Solution::addEnd( int city, int car ){
	if( this->position == this->sizeSolution ){
		throw runtime_error( "Attempting to add to a full solution" );
	}
	this->cities[ position ] = city;
	this->cars[ position ] = car;
	this->position++;
}

void Solution::removeIndex( int index ){
	if( index < 0 || index > this->sizeSolution-1 ){
		throw runtime_error( "Index for city/car pair removal in solution is not valid. " );
	}
	if( index == this->sizeSolution-1 && this->position == this->sizeSolution ){
		this->cities[ index ] = -1;
		this->cars[ index  ] = -1;
		this->position--;
	}else if( this->position == this->sizeSolution && index < this->position ){
		for( int i = 0; i < this->sizeSolution; i++ ){
			if( i >= index ){
				this->cities[ i ] = this->cities[ i+1 ];
				this->cars[ i ] = this->cars[ i+1 ];
			}
		}
		this->cities[ this->sizeSolution-1 ] = -1;
		this->cars[ this->sizeSolution-1 ] = -1;
		this->position--;
	}else if( index < this->position ){
		for( int i = 0; i < this->sizeSolution; i++ ){
			if( i >= index ){
				this->cities[ i ] = this->cities[ i+1 ];
				this->cars[ i ] = this->cars[ i+1 ];
			}
			if( this->cities[ i ] == -1 ){
				break;
			}
		}
		this->position--;
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
