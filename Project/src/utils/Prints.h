#ifndef PRINTS_H_
#define PRINTS_H_

#include <iostream>
#include <string>

using namespace std;

void myPrint( string s, int level, bool newLine = true );
void myPrint( const char *text, int level, bool newLine = true );
void myPrint( int i, int level, bool newLine = true );
void myPrint( double d, int level, bool newLine = true );

#endif /* PRINTS_H_ */
