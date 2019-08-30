#ifndef SRC_SOLUTION_H_
#define SRC_SOLUTION_H_

#include <string>

#include "GLOBAL.h"
#include "utils.h"

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

	Solution* copy();
	string toString();

};

#endif /* SRC_SOLUTION_H_ */
