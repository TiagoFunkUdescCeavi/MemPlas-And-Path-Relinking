#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "../utils/Validate.h"
#include "../utils/Prints.h"
#include "GenerateInitialPopulation.h"
#include "MultiOperatorsLocalSearch.h"
#include "Selections.h"
#include "Crossover.h"
#include "Plasmid.h"
#include "RestoringOperations.h"
#include "BinaryTournament.h"

class Algorithm {
private:
	int sizePopulation;
	int sizePlasmideo;
	double cross;
	double elite;
	int limitIterations;
	string strategy;

	vector< Solution > population;
	vector< Solution > elitePopulation;
	vector< Solution > selection;
	vector< Solution > offspring;


public:
	void lets_go( int sizePopulation, int sizePlasmideo, double cross, double elite, int limitIterations );
};

#endif /* ALGORITHM_H_ */
