#ifndef SRC_GLOBAL_H_
#define SRC_GLOBAL_H_

#include <vector>

#include "model/Car.h"

using namespace std;

extern int numberCars_GLOBAL;
extern int numberCities_GLOBAL;

extern vector< Car > cars_GLOBAL;
extern int* bonus_satisfaction_GLOBAL;
extern int satisfaction_total_GLOBAL;

extern double minimal_satisfaction_GLOBAL;

#endif /* SRC_GLOBAL_H_ */
