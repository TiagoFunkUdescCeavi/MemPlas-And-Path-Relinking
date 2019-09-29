#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <string>
#include <stdexcept>
#include <vector>

#include "../GLOBAL.h"

using namespace std;

class Solution{
private:
	bool calculatedFitness = false;

	int size = 0;
	int maxSize = 0;
	int fitness = 0;
	int satisfaction = 0;

public:
	vector< int > cities;
	vector< int > cars;

	Solution();
	Solution( int maxSizeSolution );
	~Solution();

	void calculeFitness();
	void calculeSatisfaction();

	void addEnd( int city, int car );
	void removeIndex( int index );
	void addCityAt( int index, int city );
	void addCityAndCarAt( int index, int city, int car );
	void insertCityAt( int index, int city );
	void insertCarAt( int index, int car );

	int getSize();
	int getFitness();
	int getSatisfaction();

	Solution copy();
	string toString();

};

#endif /* SOLUTION_H_ */
