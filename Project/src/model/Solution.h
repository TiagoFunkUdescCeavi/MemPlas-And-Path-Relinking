#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <string>
#include <stdexcept>

#include "../GLOBAL.h"

using namespace std;

class Solution{
private:
	bool calculatedFitness = false;

public:
	int sizeSolution = 0;
	int* cities = 0;
	int* cars = 0;
	int fitness = 0;
	int satisfaction = 0;
	int position = 0;

	Solution( int sizeSolution );
	void calculeFitness();
	void calculeSatisfaction();

	void addEnd( int city, int car );
	void removeIndex( int index );
	void addCityAt( int index, int city );
	void insertCityAt( int index, int city );
	void insertCarAt( int index, int car );

	Solution* copy();
	string toString();

};

#endif /* SOLUTION_H_ */
