#ifndef VALIDATE_H_
#define VALIDATE_H_

#include <string>
#include <stdexcept>
#include <vector>

#include "../GLOBAL.h"
#include "../model/Solution.h"
#include "Prints.h"

void isOk( Solution mySolution );
void checkPopulation( vector< Solution > population );


#endif /* VALIDATE_H_ */
