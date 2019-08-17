#ifndef SRC_GLOBAL_H_
#define SRC_GLOBAL_H_

#include <vector>

#include "Car.h"

using namespace std;

int numberCars_GLOBAL;
int numberCities_GLOBAL;

vector< Car* > cars_GLOBAL;
int* bonus_satisfaction_GLOBAL;
int satisfaction_total_GLOBAL;

double minimal_satisfaction_GLOBAL = 0.8;

#endif /* SRC_GLOBAL_H_ */
