#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

struct Tuple{
	string name;
	int expected = -1;
	int obtained = -1;
};

vector< Tuple > tuples;

void find( string name, int value, bool expected ){
	bool finded = false;
	for( int i = 0; i < (int) tuples.size(); i++ ){
		if( name == tuples[i].name ){
			if( expected ){
				tuples[i].expected = value;
			}else{
				tuples[i].obtained = value;
			}
			finded = true;
			break;
		}
	}
	if( !finded ){
		Tuple t;
		t.name = name;
		if( expected ){
			t.expected = value;
		}else{
			t.obtained = value;
		}
		tuples.push_back( t );
	}
}

void printVector(){
	Tuple t;
	cout << "<<<<<<<<<<<<<<<<<<<" << endl;
	for( int i = 0; i < (int) tuples.size(); i++ ){
		t = tuples[i];
		cout << "Instance: " << t.name << "\t\tExpected: " << t.expected << "\tObtained: " << t.obtained << endl;
	}
	cout << "********************" << endl;
}

void readExpected( string fileName ){
	int expected;
	string name;
	ifstream fileReader( fileName.c_str(), ios::in );

	if( !fileReader ){
		string s = "Error on open file: " + fileName;
		throw runtime_error( s );
	}

	do{
		fileReader >> name;
		fileReader >> expected;
		find( name, expected, true );
	}while( !fileReader.eof() );
}

void readObtained( string fileName ){
	int obtained;
	string name;
	ifstream fileReader( fileName.c_str(), ios::in );

	if( !fileReader ){
		string s = "Error on open file: " + fileName;
		throw runtime_error( s );
	}

	do{
		fileReader >> name;
		fileReader >> obtained;
		find( name, obtained, false );
	}while( !fileReader.eof() );
}

int main( int argc, char* argv[] ){
	string fileExpected = argv[1];
	string fileObtained = argv[2];

	readExpected( fileExpected );
//	printVector();
	readObtained( fileObtained );

	printVector();
	return 0;
}
