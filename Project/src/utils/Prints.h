#ifndef PRINTS_H_
#define PRINTS_H_

#include <iostream>
#include <string>

using namespace std;

void myPrint( string s, bool newLine );
void myPrint( const char * text, bool newLine );
void myPrint( int i, bool newLine );
void myPrint( double d, bool newLine );

void printVector( int *values, int size );


#endif /* PRINTS_H_ */
