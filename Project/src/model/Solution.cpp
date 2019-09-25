#include "Solution.h"

#include "../utils/Prints.h"

Solution::Solution(){
}

Solution::Solution( int sizeSolution ){
	this->sizeSolution = sizeSolution;
	cities = new int[ sizeSolution ];
	cars = new int[ sizeSolution ];
	for( int i = 0; i < sizeSolution; i++ ){
		cities[ i ] = -1;
		cars[ i ] = -1;
	}
}

Solution::~Solution(){
//	delete [] cities;
//	delete [] cars;
}

void Solution::calculeFitness(){
	if( !calculatedFitness ){
		this->fitness = 0;
		int previous_car = 0, actual_car = 0;
		int rent_city = 0, actual_city = 0;
		int weigth = 0, rate = 0;
		Car myCar;

		rent_city = this->cities[0];
		previous_car = this->cars[0];
		for( int i = 0; i < this->position-1; i++ ){
			actual_city = this->cities[i];
			actual_car = this->cars[ i ];
			myCar = cars_GLOBAL[ actual_car ];

			weigth = myCar.edge_weigth[ actual_city ][ this->cities[ i+1 ] ];
			this->fitness += weigth;
			if( previous_car != actual_car ){
				myCar = cars_GLOBAL[ previous_car ];
				rate = myCar.return_rate[ rent_city ][ actual_city ];
				this->fitness += rate;
				previous_car = actual_car;
				rent_city = actual_city;
			}
		}

		myCar = cars_GLOBAL[ previous_car ];
		rate = myCar.return_rate[ rent_city ][ 0 ];
		this->fitness += rate;
		this->calculatedFitness = true;
	}
}

void Solution::calculeSatisfaction(){
	this->satisfaction = 0;
	for( int i = 0; i < this->position; i++ ){
		if( i != this->position-1 || (i == this->position-1 && this->cities[ i ] != 0) ){
			this->satisfaction += bonus_satisfaction_GLOBAL[ cities[ i ] ];
		}
	}
}

void Solution::addEnd( int city, int car ){
	if( this->position == this->sizeSolution ){
		throw runtime_error( "Attempting to add to a full solution" );
	}
	this->cities[ position ] = city;
	this->cars[ position ] = car;
	this->position++;
	this->calculatedFitness = false;
}

void Solution::removeIndex( int index ){
	if( index < 0 || index > this->sizeSolution-1 ){
		throw runtime_error( "Index for city/car pair removal in solution is not valid. " );
	}
	if( index == this->sizeSolution-1 && this->position == this->sizeSolution ){
		this->cities[ index ] = -1;
		this->cars[ index  ] = -1;
		this->position--;
		this->calculatedFitness = false;
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
		this->calculatedFitness = false;
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
		this->calculatedFitness = false;
	}
}

void Solution::addCityAt( int index, int city ){
	if( index < 0 || index >= this->position ){
		throw runtime_error( "Invalid index to add city.\n" );
	}
	if( index == this->position ){
		this->cities[ index ] = city;
	}else{
		for( int i = this->position; i >= 0; i-- ){
			if( i > index ){
				this->cities[ i+1 ] = this->cities[ i ];
				this->cars[ i+1 ] = this->cars[ i ];
			}else if( i == index ){
				this->cities[ i+1 ] = this->cities[ i ];
				this->cars[ i+1 ] = this->cars[ i ];
				this->cities[ i ] = city;
				break;
			}
		}
	}
	this->position++;
	this->calculatedFitness = false;
}

void Solution::addCityAndCarAt( int index, int city, int car ){
	if( index < 0 || index >= this->position ){
		throw runtime_error( "Invalid index to add car.\n" );
	}
	if( index == this->position ){
		this->cars[ index ] = car;
	}else{
		for( int i = this->position; i >= 0; i-- ){
			if( i > index ){
				this->cities[ i+1 ] = this->cities[ i ];
				this->cars[ i+1 ] = this->cars[ i ];
			}else if( i == index ){
				this->cities[ i+1 ] = this->cities[ i ];
				this->cars[ i+1 ] = this->cars[ i ];
				this->cities[ i ] = city;
				this->cars[ i ] = car;
				break;
			}
		}
	}
	this->position++;
	this->calculatedFitness = false;
}

void Solution::insertCityAt( int index, int city ){
	if( index < 0 || index > this->position ){
		throw runtime_error( "Invalid index to insert city.\n" );
	}
	this->cities[ index ] = city;
	this->calculatedFitness = false;
}

void Solution::insertCarAt( int index, int car ){
	if( index < 0 || index > this->position ){
		throw runtime_error( "Invalid index to insert car.\n" );
	}
	this->cars[ index ] = car;
	this->calculatedFitness = false;
}

Solution Solution::copy(){
	Solution s;

	s.sizeSolution = this->sizeSolution;
	s.cities = new int[ s.sizeSolution ];
	s.cars = new int[ s.sizeSolution ];
	s.position = this->position;
	s.fitness = this->fitness;
	s.satisfaction = this->satisfaction;
	s.sizeSolution = this->sizeSolution;
	s.calculatedFitness = false;

	for( int i = 0; i < sizeSolution; i++ ){
		s.cities[ i ] = this->cities[ i ];
		s.cars[ i ] = this->cars[ i ];
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
	return s + "\n" + s2;
}
