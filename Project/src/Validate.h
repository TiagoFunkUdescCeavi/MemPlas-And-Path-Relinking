#ifndef SRC_VALIDATE_H_
#define SRC_VALIDATE_H_

#include <string>
#include <stdexcept>
#include <vector>

#include "Solution.h"
#include "GLOBAL.h"
#include "utils.h"

bool isOk( Solution* mySolution );
void checkPopulation( vector< Solution* > population );

#endif /* SRC_VALIDATE_H_ */
