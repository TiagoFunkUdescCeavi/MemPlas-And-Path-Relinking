#include "Solution.h"

#include "../utils/Prints.h"

Solution::Solution(){

}

Solution::Solution( int maxSizeSolution ){
	this->maxSize = maxSizeSolution;
	this->cities.reserve( maxSizeSolution );
	this->cars.reserve( maxSizeSolution );
}

Solution::~Solution(){
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
		for( int i = 0; i < this->size-1; i++ ){
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
	for( int i = 0; i < this->size; i++ ){
		if( i != this->size-1 || (i == this->size-1 && this->cities[ i ] != 0) ){
			this->satisfaction += bonus_satisfaction_GLOBAL[ cities[ i ] ];
		}
	}
}

void Solution::addEnd( int city, int car ){
	if( this->size == this->maxSize ){
		throw runtime_error( "Attempting to add to a full solution" );
	}
	this->cities.push_back( city );
	this->cars.push_back( car );
	this->size++;
	this->calculatedFitness = false;
}

void Solution::removeIndex( int index ){
	if( index < 0 || index >= this->size ){
		throw runtime_error( "Index for city/car pair removal in solution is not valid. " );
	}
	this->cities.erase( this->cities.begin() + index );
	this->cars.erase( this->cars.begin() + index );
	this->size--;
	this->calculatedFitness = false;
}

void Solution::addCityAt( int index, int city ){
	if( index < 0 || index >= this->size ){
		throw runtime_error( "Invalid index to add city.\n" );
	}
	this->cities.insert( this->cities.begin() + index, city );
	this->cars.insert( this->cars.begin() + index, cars[index] );
	this->size++;
	this->calculatedFitness = false;
}

void Solution::addCityAndCarAt( int index, int city, int car ){
	if( index < 0 || index >= this->size ){
		throw runtime_error( "Invalid index to add car.\n" );
	}
	this->cities.insert( this->cities.begin() + index, city );
	this->cars.insert( this->cars.begin() + index, car );
	this->size++;
	this->calculatedFitness = false;
}

void Solution::insertCityAt( int index, int city ){
	if( index < 0 || index > this->size ){
		throw runtime_error( "Invalid index to insert city.\n" );
	}
	this->cities[ index ] = city;
	this->calculatedFitness = false;
}

void Solution::insertCarAt( int index, int car ){
	if( index < 0 || index > this->size ){
		throw runtime_error( "Invalid index to insert car.\n" );
	}
	this->cars[ index ] = car;
	this->calculatedFitness = false;
}

int Solution::getSize(){
	return this->size;
}

int Solution::getFitness(){
	return this->fitness;
}

int Solution::getSatisfaction(){
	return this->satisfaction;
}

Solution Solution::copy(){
	Solution s( numberCities_GLOBAL+1 );

	s.calculatedFitness = this->calculatedFitness;
	s.size = this->size;
	s.maxSize = this->maxSize;
	s.fitness = this->fitness;
	s.satisfaction = this->satisfaction;
	s.cities = vector< int >( this->cities );
	s.cars = vector< int >( this->cars );

	return s;
}

string Solution::toString(){
	string s = ">";
	string s2 = "*";
	for( int i = 0; i < size; i++ ){
		s += to_string( cities[i] ) + "\t";
		s2 += to_string( cars[i] ) + "\t";
	}
	return s + "\n" + s2;
}
