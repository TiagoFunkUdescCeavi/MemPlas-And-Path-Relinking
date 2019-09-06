#ifndef RESTORINGOPERATIONS_H_
#define RESTORINGOPERATIONS_H_

#include <vector>

#include "../model/Solution.h"

Solution * removeErrors( Solution *sol );
Solution * insertCities( Solution *sol );
Solution * insertCars( Solution *sol );
Solution * checkQuota( Solution *sol );
vector< Solution * > restoringOperations( vector< Solution * > population );

#endif /* RESTORINGOPERATIONS_H_ */
