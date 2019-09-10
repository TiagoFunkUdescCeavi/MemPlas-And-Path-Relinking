#include <iostream>

#include "MyClass.h"

using namespace std;

int main( int argc, char* argv[] ){
//	const int SIZE = 2;
//	int ***abc = new int**[SIZE];
//	for( int i = 0; i < SIZE; i++ ){
//		abc[i] = new int*[SIZE];
//		for( int j = 0; j < SIZE; j++ ){
//			abc[i][j] = new int[SIZE];
//		}
//	}

	MyClass *mc = 0;
	for( int i = 0; i < 1000000; i++ ){
//		cout << i << endl;
		delete mc;
		mc = new MyClass( 1000 );
	}
	return 0;
}
