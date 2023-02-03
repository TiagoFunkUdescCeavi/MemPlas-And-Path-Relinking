#include "InstanceReader.h"

#include "math.h"
#include <iostream>

using namespace std;

struct Point{
	double x, y;
};

int **createMatrix( int a, int b ){
	int **m = new int*[a];
	for( int i = 0; i < a; i++ ){
		m[i] = new int[b];
	}
	return m;
}

void readInstanceNotEuclidean( string fileName ){
	int cities = 0, cars = 0;
	int satisfaction_sum;
	int *vector;
	int **matrix;
	string aux;
	ifstream file( fileName.c_str(), ios::in );

	if( !file ){
		string s = "Error on open file: " + fileName;
		throw runtime_error( s );
	}

	while( file >> aux ){
		if( aux == "DIMENSION" ){
			file >> aux;
			file >> aux;
			cities = stoi( aux );
		}
		if( aux == "CARS_NUMBER" ){
			file >> aux;
			file >> aux;
			cars = stoi( aux );
		}
		if( aux == "EDGE_WEIGHT_SECTION" ){
			break;
		}
	}

	numberCars_GLOBAL = cars;
	numberCities_GLOBAL = cities;
	cars_GLOBAL.resize( cars );

	for( int car = 0; car < cars; car++ ){
		matrix = createMatrix( cities, cities );

		file >> aux;
		for( int i = 0; i < cities; i++ ){
			for( int j = 0; j < cities; j++ ){
				file >> matrix[ i ][ j ];
			}
		}

		cars_GLOBAL[ car ].dimension = cities;
		cars_GLOBAL[ car ].edge_weigth = matrix;
	}

	file >> aux;
	for( int car = 0; car < cars; car++ ){
		matrix = createMatrix( cities, cities );

		file >> aux;
		for( int i = 0; i < cities; i++ ){
			for( int j = 0; j < cities; j++ ){
				file >> matrix[ i ][ j ];
			}
		}

		cars_GLOBAL[ car ].return_rate = matrix;
	}

	file >> aux;
	vector = new int[ cities ];
	satisfaction_sum = 0;
	for( int i = 0; i < cities; i++ ){
		file >> vector[ i ];
		satisfaction_sum += vector[ i ];
	}

	bonus_satisfaction_GLOBAL = vector;
	satisfaction_total_GLOBAL = satisfaction_sum;

	file >> aux;
	if( aux != "EOF" ){
		string s = "Read of file has incorrect: " + fileName;
		throw runtime_error( s );
	}
}

void readInstanceEuclidean( string fileName ){
	int cities = -1, cars = -1;
	int sum_satisfaction = 0;
	int *vector = 0;
	int *satisfaction = 0;
	int **dist = 0;
	int **cost = 0;
	int **rate = 0;
	Point *points = 0;
	string aux;
	ifstream fileReader( fileName.c_str(), ios::in );

	if( !fileReader ){
		string s = "Error on open file: " + fileName;
		throw runtime_error( s );
	}

	while( fileReader >> aux ){
		if( aux == "DIMENSION" ){
			fileReader >> aux;
			fileReader >> aux;
			cities = stoi( aux );
		}
		if( aux == "CARS_NUMBER" ){
			fileReader >> aux;
			fileReader >> aux;
			cars = stoi( aux );
		}
		if( aux == "NODE_COORD_SECTION" ){
			break;
		}
	}

	// Variáveis globais
	numberCars_GLOBAL = cars;
	numberCities_GLOBAL = cities;
	cars_GLOBAL.resize( cars );
	for( int i = 0; i < cars; i++ ){
		cars_GLOBAL[i].dimension = cities;
	}

	// Inciando os vetores
	vector = new int[ cities ];
	satisfaction = new int[ cities ];
	points = new Point[ cities ];

	// Iniciando a matriz de distâncias
	dist = createMatrix( cities, cities );

	for( int i = 0; i < cities; i++ ){
		// number of city
		fileReader >> aux;

		fileReader >> aux;
		points[ i ].x = stod( aux );

		fileReader >> aux;
		points[ i ].y = stod( aux );

		fileReader >> aux;
		satisfaction[ i ] = stod( aux );
	}

	bonus_satisfaction_GLOBAL = satisfaction;
	sum_satisfaction = 0;
	for( int i = 0; i < cities; i++ ){
		sum_satisfaction += satisfaction[ i ];
	}
	satisfaction_total_GLOBAL = sum_satisfaction;

	for( int i = 0; i < cities; i++ ){
		for( int j = i; j < cities; j++ ){
			if( i == j ){
				dist[i][j] = 0;
			}else{
				dist[i][j] = (int) (sqrt(pow((points[i].x-points[j].x), 2) + pow((points[i].y-points[j].y), 2)));
				dist[j][i] = dist[i][j];
			}
		}
	}

//	myPrint( "Distâncias", 0 );
//	for( int a = 0; a < cities; a++ ){
//		for( int b = 0; b < cities; b++ ){
//			myPrint( to_string( dist[a][b] ) + " ", 0, false );
//		}
//		myPrint( "", 0 );
//	}

	// EDGE_WEIGHT_SECTION
	fileReader >> aux;

	for( int h = 0; h < cars; h++ ){
		// numbers of car
		fileReader >> aux;
		cost = createMatrix( cities, cities );

		for( int i = 0; i < cities; i++ ){
			fileReader >> aux;
			vector[i] = stoi( aux );
		}

		for( int i = 0; i < cities; i++ ){
			for( int j = i; j < cities; j++ ){
				if( i == j ){
					cost[i][j] = 0;
				} else {
					cost[i][j] = ((vector[i]*2+vector[j]*3)/3)+(dist[i][j]);
//					cost[i][j] = ((vector[i]*2+vector[j]*3)/3);
					cost[j][i] = cost[i][j];
				}
			}
		}
		cars_GLOBAL[h].edge_weigth = cost;

//		myPrint( "Custos", 0 );
//		for( int a = 0; a < cities; a++ ){
//			for( int b = 0; b < cities; b++ ){
//				myPrint( to_string( cost[a][b] ) + "\t", 0, false );
//			}
//			myPrint( "", 0 );
//		}
	}

	// RETURN_RATE_SECTION
	fileReader >> aux;

	for( int h = 0; h < cars; h++ ){
		// numbers of car
		fileReader >> aux;
		rate = createMatrix( cities, cities );

		for( int i = 0; i < cities; i++ ){
			fileReader >> aux;
			vector[i] = stoi( aux );
		}

		for( int i = 0; i < cities; i++ ){
			for( int j = 0; j < cities; j++ ){
				if( i == j ){
					rate[i][j] = 0;
				} else {
					for (int k=0; k < cities; k++){
						rate[i][j] = ((vector[i]*3+vector[j])*4)/2;
					}
//					rate[i][j] = ((vector[i]*3+vector[j]*4)/2);
				}
			}
		}
		cars_GLOBAL[h].return_rate = rate;

//		myPrint( "Multas", 0 );
//		for( int a = 0; a < cities; a++ ){
//			for( int b = 0; b < cities; b++ ){
//				myPrint( to_string( rate[a][b] ) + "\t", 0, false );
//			}
//			myPrint( "", 0 );
//		}
	}

	fileReader >> aux;
	if( aux != "EOF" ){
		string s = "Read of file has incorrect: " + fileName;
		throw runtime_error( s );
	}

	delete[] points;
	delete[] vector;
	for( int i = 0; i < cities; i++ ){
		delete[] dist[i];
	}
	delete[] dist;
}

void readInstance( string file ){
	char type = ' ';
	for( int i = file.size()-1; i >= 0; i-- ){
		if( file[i] == '.' && file[i-1] == 'n' ){
			type = 'n';
			break;
		}
		if( file[i] == '.' && file[i-1] == 'e' ){
			type = 'e';
			break;
		}
	}

	switch (type){
		case 'n': readInstanceNotEuclidean( file ); break;
		case 'e': readInstanceEuclidean( file ); break;
		default: throw runtime_error( "Type of instance not found");
	}
}







