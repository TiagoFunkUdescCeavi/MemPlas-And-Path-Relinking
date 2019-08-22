#include "utils.h"

void myPrint( string s, bool newLine ){
	cout << s;
	if( newLine ){
		cout << endl;
	}
}

void myPrint( const char * text, bool newLine ){
	cout << text;
	if( newLine ){
		cout << endl;
	}
}

void myPrint( int i, bool newLine ){
	cout << i;
	if( newLine ){
		cout << endl;
	}
}

void myPrint( double d, bool newLine ){
	cout << d;
	if( newLine ){
		cout << endl;
	}
}
