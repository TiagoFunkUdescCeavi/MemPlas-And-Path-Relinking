#include "Prints.h"

// 0 para dados da instâncias
// 1 para log dentro da função lets_go
// 2 para log dentro de cada método
int debugLevel = 1;

void myPrint( string s, int level, bool newLine ){
	if( debugLevel >= level){
		cout << s;
		if( newLine ){
			cout << endl;
		}
	}
}

void myPrint( const char *text, int level, bool newLine ){
	if( debugLevel >= level){
		cout << text;
		if( newLine ){
			cout << endl;
		}
	}
}

void myPrint( int i, int level, bool newLine ){
	if( debugLevel >= level){
		cout << i;
		if( newLine ){
			cout << endl;
		}
	}
}

void myPrint( double d, int level, bool newLine ){
	if( debugLevel >= level){
		cout << d;
		if( newLine ){
			cout << endl;
		}
	}
}



