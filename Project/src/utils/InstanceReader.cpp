#include "InstanceReader.h"

#include "math.h"

struct Ponto{
	double x, y;
};

int ** createMatrix( int a, int b ){
	int **m = new int*[a];
	for( int i = 0; i < a; i++ ){
		m[i] = new int[b];
	}
	return m;
}

void readInstanceNotEuclidean( string file ){
	int cities, cars;
	int satisfaction_sum;
	int* vector;
	int** matrix;
	string aux;
	ifstream arq( file.c_str(), ios::in );

	if( !arq ){
		string s = "Error on open file: " + file;
		throw runtime_error( s );
	}

	while( arq >> aux ){
		if( aux == "DIMENSION" ){
			arq >> aux;
			arq >> aux;
			cities = stoi( aux );
		}
		if( aux == "CARS_NUMBER" ){
			arq >> aux;
			arq >> aux;
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
		matrix = new int*[ cities ];
		for( int i = 0; i < cities; i++ ){
			matrix[ i ] = new int[ cities ];
		}

		arq >> aux;
		for( int i = 0; i < cities; i++ ){
			for( int j = 0; j < cities; j++ ){
				arq >> matrix[ i ][ j ];
			}
		}

		cars_GLOBAL[ car ] = new Car();
		cars_GLOBAL[ car ]->dimension = cities;
		cars_GLOBAL[ car ]->edge_weigth = matrix;
	}

	arq >> aux;
	for( int car = 0; car < cars; car++ ){
		matrix = new int*[ cities ];
		for( int i = 0; i < cities; i++ ){
			matrix[ i ] = new int[ cities ];
		}

		arq >> aux;
		for( int i = 0; i < cities; i++ ){
			for( int j = 0; j < cities; j++ ){
				arq >> matrix[ i ][ j ];
			}
		}

		cars_GLOBAL[ car ]->return_rate = matrix;
	}

	arq >> aux;
	vector = new int[ cities ];
	satisfaction_sum = 0;
	for( int i = 0; i < cities; i++ ){
		arq >> vector[ i ];
		satisfaction_sum += vector[ i ];
	}

	bonus_satisfaction_GLOBAL = vector;
	satisfaction_total_GLOBAL = satisfaction_sum;

	arq >> aux;
	if( aux != "EOF" ){
		string s = "Read of file has incorrect: " + file;
		throw runtime_error( s );
	}
}

void readInstanceEuclidean( string fileName ){
	int auxInt = -1;
	int cities = -1, cars = -1;
	int sum_satisfaction = 0;
	int *vector = 0;
	int *satisfaction = 0;
	int **dist = 0;
	int **cost = 0;
	int **rate = 0;
	Ponto *points = 0;
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
		cars_GLOBAL[i] = new Car();
		cars_GLOBAL[i]->dimension = cities;
	}

	// Inciando os vetores
	vector = new int[ cities ];
	satisfaction = new int[ cities ];
	points = new Ponto[ cities ];

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

	// EDGE_WEIGHT_SECTION
	fileReader >> aux;

	for( int i = 0; i < cars; i++ ){
		fileReader >> aux;
		cost = createMatrix( cities, cities );

		for( int j = 0; j < cities; j++ ){
			fileReader >> aux;
			vector[i] = stoi( aux );
		}

		for( int j = 0; j < cities; j++ ){
			for( int k = j; k < cities; k++ ){
				if( i == j ){
					cost[i][j] = 0;
				} else {
					cost[j][k] = ((vector[j]*2+vector[k]*3)/3);
					cost[k][j] = cost[j][k];
				}
			}
		}
		cars_GLOBAL[i]->edge_weigth = cost;
	}

	// RETURN_RATE_SECTION
	fileReader >> aux;

	for( int i = 0; i < cars; i++ ){
		// numbers of car
		fileReader >> aux;
		rate = createMatrix( cities, cities );

		for( int j = 0; j < cities; j++ ){
			fileReader >> aux;
			vector[i] = stoi( aux );
		}

		for( int j = 0; j < cities; j++ ){
			for( int k = 0; k < cities; k++ ){
				if( i == j ){
					rate[i][j] = 0;
				} else {
					rate[j][k] = ((vector[j]*3+vector[k]*4)/3);
				}
			}
		}
		cars_GLOBAL[i]->return_rate = rate;
	}

	fileReader >> aux;
	if( aux != "EOF" ){
		string s = "Read of file has incorrect: " + fileName;
		throw runtime_error( s );
	}

}

void readInstance( string file ){
	char type = ' ';
	for( int i = file.size()-1; i >= 0; i-- ){
		if( file[i] == '.' && file[i-1] == 'n' ){
			type = 'n';
		}
		if( file[i] == '.' && file[i-1] == 'e' ){
			type = 'e';
		}
	}

	switch (type){
		case 'n': readInstanceNotEuclidean( file ); break;
		case 'e': readInstanceEuclidean( file ); break;
		default: throw runtime_error( "Type of instance not found");
	}
}







