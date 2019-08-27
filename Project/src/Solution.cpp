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
	int previous_car = 0;
	int rent_city = 0;
	int weigth = -1, rate = -1;
	Car* myCar = 0;
	for( int i = 0; i < this->position-1; i++ ){
		myCar = cars_GLOBAL[ this->cars[ i ] ];
		weigth = myCar->edge_weigth[ this->cities[ i ] ][ this->cities[ i+1 ] ];
		this->fitness += weigth;
		if( previous_car != this->cars[ i+1 ] ){
			rate = myCar->return_rate[ rent_city ][ this->cities[ i+1 ] ];
			this->fitness += rate;
			previous_car = this->cars[ i+1 ];
			rent_city = this->cities[ i+1 ];
		}
	}
	rate = myCar->return_rate[ rent_city ][ 0 ];
	this->fitness += rate;
}

void Solution::calculeSatisfaction(){
	this->satisfaction = 0;
	for( int i = 0; i < this->position-1; i++ ){
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

Solution* Solution::copy(){
	Solution* s = new Solution( this->sizeSolution );
	s->position = this->position;
	s->fitness = this->fitness;
	s->satisfaction = this->satisfaction;
	s->sizeSolution = this->sizeSolution;

	for( int i = 0; i < this->sizeSolution; i++ ){
		s->cities[ i ] = this->cities[ i ];
	}
	for( int i = 0; i < this->sizeSolution; i++ ){
		s->cars[ i ] = this->cars[ i ];
	}

	return s;
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
