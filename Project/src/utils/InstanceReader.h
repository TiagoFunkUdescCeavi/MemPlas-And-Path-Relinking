#ifndef INSTANCEREADER_H_
#define INSTANCEREADER_H_

#include <iostream>
#include <fstream>
#include <stdexcept>

#include "../GLOBAL.h"
#include "Prints.h"

using namespace std;

void readInstanceNotEuclidean( string file );
void readInstanceEuclidean( string file );
void readInstance( string file );

#endif /* INSTANCEREADER_H_ */
