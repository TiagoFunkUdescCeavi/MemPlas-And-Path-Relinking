#include "Prints.h"

// 0 para dados da instâncias
// 1 para log dentro da função lets_go
// 2 para log dentro de cada método
int debugLevel = 0;

void myPrint( string s, int level ){
	if( debugLevel >= level){
		cout << s << endl;
	}
}

void myPrint( const char *text, int level ){
	if( debugLevel >= level){
		cout << text << endl;
	}
}

void myPrint( int i, int level ){
	if( debugLevel >= level){
		cout << i << endl;
	}
}

void myPrint( double d, int level ){
	if( debugLevel >= level){
		cout << d << endl;
	}
}



