#include "Prints.h"

bool debug = false;

void myPrint( string s, bool newLine ){
	if( debug ){
		cout << s;
		if( newLine ){
			cout << endl;
		}
	}
}

void myPrint( const char * text, bool newLine ){
	if( debug ){
		cout << text;
		if( newLine ){
			cout << endl;
		}
	}
}

void myPrint( int i, bool newLine ){
	if( debug ){
		cout << i;
		if( newLine ){
			cout << endl;
		}
	}
}

void myPrint( double d, bool newLine ){
	if( debug ){
		cout << d;
		if( newLine ){
			cout << endl;
		}
	}
}

void printVector( int *values, int size ){
	for( int i = 0; i < size; i++ ){
		myPrint( values[i], false );
		myPrint( ", ", false );
	}
	myPrint( "", true );
}


