#ifndef PLASMID_H_
#define PLASMID_H_

#include <vector>

#include "../model/Solution.h"

vector< Solution* > plasmid( vector< Solution* > population, int sizePlas, vector< Solution* > elite );

#endif /* PLASMID_H_ */
