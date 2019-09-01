#ifndef VALIDATE_H_
#define VALIDATE_H_

#include <string>
#include <stdexcept>
#include <vector>

#include "../GLOBAL.h"
#include "../model/Solution.h"
#include "utils.h"

bool isOk( Solution* mySolution );
void checkPopulation( vector< Solution* > population );

int findFinalPosition( Solution* sol );
void checkStartAndEnd( Solution* sol, int finalPosition );
void checkCitiesAndCars( Solution* sol, int finalPosition );
void checkRepetition( Solution* sol, int finalPosition );


#endif /* VALIDATE_H_ */
