/* **************************************************** *
 *  Arquivo: carrega_problema.cpp	                          *
 *  Problema do Caixeiro Viajante com Aluguel de Carros       *
 *  Le arquivo de Inst�ncias, Calcula dist�ncias e monta GLPK * 
 *  Autor: Matheus Menezes                                    *
 *  Adaptado de Paulo Henrique Asconavieta					  *
 *  Orientador: Marco Cesar Goldbarg                          *
 *  Doutorado em Sistemas e Computacao # DIMAp/UFRN           *
 * ********************************************************** */
#include "monta_problema.h"

#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>
#include <string.h>
#include <math.h>
    
char nome[50];      // Nome do arquivo

struct ponto { double x, y; } *P; 		// pontos oriundos da instancia
void leInstancia(char *fname);
void imprimeProblema();

struct problema{
     int nCid;
     int nCar;         // nCid= numero de cidades (DIMENSION); nCar= numero de carros
     int **dist;       // Matriz de adjacencias (simetrica) do grafo de entrada
     long int ***cust; // Matrizes de custos de aluguel
     int ***taxa;      // Matrizes de taxas de retorno
}pr;


//********************************************************
void mainABC() {
    char nomeArq[100];
	int iCid;
    int nInstIni, nInstFim;
	
//   	switch (argc) {
//	   	case   1: nInstIni=201; nInstFim=202; break;						//Ex: back
//	   	case   2: nInstIni=atoi(argv[1]); nInstFim=nInstIni+1; break;		//Ex: back 201
//	   	case   3: nInstIni=atoi(argv[1]); nInstFim=atoi(argv[2]); break;	//Ex: back 201 203
//	   	default : nInstIni=0; nInstFim=0; break;
//   	}
//
//    if ((argc > 3) || (nInstIni>280) || (nInstFim>281) || (nInstIni >= nInstFim)) {
//    	printf("\nErro de Sintaxe!\nDigite: 'ag n1'\nn1=Numero da Instancia (1-280)\n");
//    	return(0);
//	}
//
//
//  	for (int i=nInstIni; i<nInstFim; i++) {		//1-201
    int value = 219;
	   	switch (value) {
			case   1: strcpy(nomeArq, "BrasilRJ14e"); break;
			case   2: strcpy(nomeArq, "BrasilRN16e"); break;

			case 101: strcpy(nomeArq, "BrasilRJ14n"); break;
			case 102: strcpy(nomeArq, "BrasilRN16n"); break;
			
	   		case 201: strcpy(nomeArq,"Afeganistao4e"); break;
	   		case 202: strcpy(nomeArq,"Mianmar5e"); break;
	   		case 203: strcpy(nomeArq,"Zambia6e"); break;
	   		case 204: strcpy(nomeArq,"Turquia7e"); break;
	   		case 205: strcpy(nomeArq,"Mocambique8e"); break;
	   		case 206: strcpy(nomeArq,"Nigeria9e"); break;	
	   		case 207: strcpy(nomeArq,"Mauritania10e"); break;
	   		case 208: strcpy(nomeArq,"Colombia11e"); break;
	   		case 209: strcpy(nomeArq,"Angola12e"); break;
	   		case 210: strcpy(nomeArq,"Peru13e"); break;
	   		case 211: strcpy(nomeArq,"Libia14e"); break;
	   		case 212: strcpy(nomeArq,"Congo15e"); break;
	   		case 213: strcpy(nomeArq,"Argentina16e"); break;
	   		case 214: strcpy(nomeArq,"EUA17e"); break;
	   		case 215: strcpy(nomeArq,"Chile6e"); break;
	   		case 216: strcpy(nomeArq,"Paquistao7e"); break;	
	   		case 217: strcpy(nomeArq,"Nanibia8e"); break;
	   		case 218: strcpy(nomeArq,"Tanzania9e"); break;
	   		case 219: strcpy(nomeArq,"e/Bolivia10e"); break;
	   		case 220: strcpy(nomeArq,"AfricaSul11e"); break;
	   		case 221: strcpy(nomeArq,"Niger12e"); break;
	   		case 222: strcpy(nomeArq,"Mongolia13e"); break;
	   		case 223: strcpy(nomeArq,"Indonesia14e"); break;
	   		case 224: strcpy(nomeArq,"Argelia15e"); break;
	   		case 225: strcpy(nomeArq,"India16e"); break;
	   		case 226: strcpy(nomeArq,"China17e"); break;
	   		case 227: strcpy(nomeArq,"Venezuela8e"); break;
	   		case 228: strcpy(nomeArq,"Egito9e"); break;
	   		case 229: strcpy(nomeArq,"Etiopia10e"); break;
	   		case 230: strcpy(nomeArq,"Mali11e"); break;
	   		case 231: strcpy(nomeArq,"Chade12e"); break;
	   		case 232: strcpy(nomeArq,"Ira13e"); break;
	   		case 233: strcpy(nomeArq,"Mexico14e"); break;
	   		case 234: strcpy(nomeArq,"Sudao15e"); break;
	   		case 235: strcpy(nomeArq,"Australia16e"); break;
	   		case 236: strcpy(nomeArq,"Canada17e"); break;
	   		case 237: strcpy(nomeArq,"Arabia14e"); break;
	   		case 238: strcpy(nomeArq,"Cazaquistao15e"); break;
	   		case 239: strcpy(nomeArq,"Brasil16e"); break;
	   		case 240: strcpy(nomeArq,"Russia17e"); break;
	   				   	
	   		case 241: strcpy(nomeArq,"Afeganistao4n"); break;
	   		case 242: strcpy(nomeArq,"Mianmar5n"); break;
	   		case 243: strcpy(nomeArq,"Zambia6n"); break;
	   		case 244: strcpy(nomeArq,"Turquia7n"); break;
	   		case 245: strcpy(nomeArq,"Mocambique8n"); break;
	   		case 246: strcpy(nomeArq,"Nigeria9n"); break;	
	   		case 247: strcpy(nomeArq,"Mauritania10n"); break;
	   		case 248: strcpy(nomeArq,"Colombia11n"); break;
	   		case 249: strcpy(nomeArq,"Angola12n"); break;
	   		case 250: strcpy(nomeArq,"Peru13n"); break;
	   		case 251: strcpy(nomeArq,"Libia14n"); break;
	   		case 252: strcpy(nomeArq,"Congo15n"); break;
	   		case 253: strcpy(nomeArq,"Argentina16n"); break;
	   		case 254: strcpy(nomeArq,"EUA17n"); break;
	   		case 255: strcpy(nomeArq,"Chile6n"); break;
	   		case 256: strcpy(nomeArq,"Paquistao7n"); break;	
	   		case 257: strcpy(nomeArq,"Nanibia8n"); break;
	   		case 258: strcpy(nomeArq,"Tanzania9n"); break;
	   		case 259: strcpy(nomeArq,"Bolivia10n"); break;
	   		case 260: strcpy(nomeArq,"AfricaSul11n"); break;
	   		case 261: strcpy(nomeArq,"Niger12n"); break;
	   		case 262: strcpy(nomeArq,"Mongolia13n"); break;
	   		case 263: strcpy(nomeArq,"Indonesia14n"); break;
	   		case 264: strcpy(nomeArq,"Argelia15n"); break;
	   		case 265: strcpy(nomeArq,"India16n"); break;
	   		case 266: strcpy(nomeArq,"China17n"); break;
	   		case 267: strcpy(nomeArq,"Venezuela8n"); break;
	   		case 268: strcpy(nomeArq,"Egito9n"); break;
	   		case 269: strcpy(nomeArq,"Etiopia10n"); break;
	   		case 270: strcpy(nomeArq,"Mali11n"); break;
	   		case 271: strcpy(nomeArq,"Chade12n"); break;
	   		case 272: strcpy(nomeArq,"Ira13n"); break;
	   		case 273: strcpy(nomeArq,"Mexico14n"); break;
	   		case 274: strcpy(nomeArq,"Sudao15n"); break;
	   		case 275: strcpy(nomeArq,"Australia16n"); break;
	   		case 276: strcpy(nomeArq,"Canada17n"); break;
	   		case 277: strcpy(nomeArq,"Arabia14n"); break;
	   		case 278: strcpy(nomeArq,"Cazaquistao15n"); break;
	   		case 279: strcpy(nomeArq,"Brasil16n"); break;
	   		case 280: strcpy(nomeArq,"Russia17n"); break;
	   		
		}
		leInstancia(nomeArq);
		imprimeProblema();
//    }
   
}




void leInstancia(char *fname)
{
  	double aux2;
  	FILE *stream;
	FILE *ptarq;
	char nome[100];      // Nome do arquivo
  	char buf[80];
	char tipo[10];			// tipo de instancia (EUC_2D ou EXPLICIT)  
	char formato[10];		// formato da instancia (FULL_MATRIX ou VECTOR)
     	
  	strcpy(nome, "/home/tiago/Repositorios/Github/MemPlas-And-Path-Relinking/Instances/");
	strcat(nome, fname);
	strcat(nome,".pcar");
  	strcpy(fname, nome);

  	  
  	/* abrir arquivo */
  	if ( (stream=fopen(fname,"r"))==NULL ) {
  		printf("N�o foi possivel abrir %s\n",fname);
  		//system("PAUSE");
  		exit(1);
  	}

  	/*numero de cidades e carros*/
  	while (strcmp(buf,"DIMENSION")!=0)
    fscanf(stream,"%s", &buf);
  	fscanf(stream,"%s", &buf);
  	fscanf(stream," %d", &pr.nCid);
  	fscanf(stream,"%s", &buf);
  	fscanf(stream,"%s", &buf);  
  	fscanf(stream," %d", &pr.nCar);
   
  	fscanf(stream,"%s", &buf);
  	fscanf(stream,"%s", &buf);  
  	fscanf(stream," %s", &tipo);
  	fscanf(stream,"%s", &buf);  
  	fscanf(stream,"%s", &buf);  
  	fscanf(stream," %s", &formato);

  	printf( "%4li\t\t%4li\n", pr.nCid, pr.nCar );
  	printf( "****************************\n");
	
	//Inicializa Matriz de Custos de Aluguel
	pr.cust = (long int***) malloc(sizeof(long int**)*pr.nCar);
  
	for (int h=0; h<pr.nCar; h++) {
	  	pr.cust[h]=(long int**)malloc(sizeof(long int*)*pr.nCid);
      	for (int i=0; i<pr.nCid; i++) {
           	pr.cust[h][i] = (long int*) malloc(sizeof(long int)*pr.nCid);
       	   	for(int j=0;j<pr.nCid;++j) 
       	   		pr.cust[h][i][j]=0;
    	}
  	}
  
	if (strcmp(formato,"FULL_MATRIX") ==0 ) {
  		while (strcmp(buf,"EDGE_WEIGHT_SECTION")!=0)
        	fscanf(stream,"%s", &buf);

		for (int h=0; h<pr.nCar; h++) {
			fscanf(stream,"%d", &buf);
			for (int i=0; i<pr.nCid; i++)
       			for (int j=0; j<pr.nCid; j++)
	           		fscanf(stream,"%li", &pr.cust[h][i][j]);
  		}
	}
	else {
  		if (!strcmp(tipo,"EUC_2D")) {
  			//Inicializa Matriz Sim�trica de Dist�ncias
  			pr.dist = (int**) malloc(sizeof(int*)*pr.nCid);
  			for (int i=0; i<pr.nCid; i++)
      			pr.dist[i] = (int*) malloc(sizeof(int)*pr.nCid);

  			while (strcmp(buf,"NODE_COORD_SECTION")!=0){
  				fscanf(stream,"%s", &buf);
  				printf( "%s\n", buf );
  			}

  			P = (ponto*) malloc(sizeof(ponto)*pr.nCid);
  
  			//Gera Matriz Sim�trica de Dist�ncias
  			for (int i=0; i<pr.nCid; i++){
  				fscanf(stream, "%lf", &aux2 );
  				printf( "%4lf\t", aux2 );

  				fscanf(stream, "%lf", &aux2 );
  				P[i].x = aux2;
  				printf( "%4lf\t", P[i].x );

  				fscanf(stream, "%lf", &aux2 );
  				P[i].y = aux2;
				printf( "%4lf\t", P[i].y );

				fscanf(stream, "%lf", &aux2 );
				printf( "%4lf\n", aux2 );
  			}

                          	  		   
  			for (int i=0; i<pr.nCid; i++)
       			for (int j=i; j<pr.nCid; j++)
           			if (i == j)
               			pr.dist[i][j] = 0;
           			else {
                 		pr.dist[i][j] = (int) (sqrt(pow((P[i].x-P[j].x), 2) + pow((P[i].y-P[j].y), 2)));
                 		pr.dist[j][i] = pr.dist[i][j];          
           			}
  	
  		//Gera Matriz de Custos de Aluguel
  		while (strcmp(buf,"EDGE_WEIGHT_SECTION")!=0)
        	fscanf(stream,"%s", &buf);
        
		// Com calculo baseado no vetor        
  		int vetor [pr.nCid];
  		for (int i=0; i<pr.nCid; i++) vetor[i]=0;
    
  		for (int h=0; h<pr.nCar; h++) {
    		fscanf(stream,"%s", &buf);

  			for (int i=0; i<pr.nCid; i++)
      			fscanf(stream, "%d", &vetor[i]);
          
  			for (int i=0; i<pr.nCid; i++)
       			for (int j=i; j<pr.nCid; j++)
           			if (i == j)
            			pr.cust[h][i][j] = 0;
           			else {
  						if (!strcmp(tipo,"EUC_2D"))
  							pr.cust[h][i][j] = (long int)((vetor[i]*2+vetor[j]*3)/3)+(pr.dist[i][j]);
  						else 
  							pr.cust[h][i][j] = (long int)((vetor[i]*2+vetor[j]*3)/3);
                		pr.cust[h][j][i] = pr.cust[h][i][j];
            		}  
  		}
	}
  
  	//Inicializa Matrizes de Taxas de Retorno
  	pr.taxa = (int***) malloc(sizeof(int**)*pr.nCar);
  
  	for (int h=0; h<pr.nCar; h++) {
	  	pr.taxa[h]=(int**)malloc(sizeof(int*)*pr.nCid);
      	for (int i=0; i<pr.nCid; i++) {
           	pr.taxa[h][i] = (int*) malloc(sizeof(int)*pr.nCid);
           	for(int j=0;j<pr.nCid;++j) 
           		pr.taxa[h][i][j]=0;
       	}
  	}
    
  	//Gera Matrizes de Taxas de Retorno
  	while (strcmp(buf,"RETURN_RATE_SECTION")!=0)
    	fscanf(stream,"%s", &buf);
    	
	if (strcmp(formato,"FULL_MATRIX") ==0 ) {
		for (int h=0; h<pr.nCar; h++) {
    		fscanf(stream,"%d", &buf);
  			for (int i=0; i<pr.nCid; i++)
       			for (int j=0; j<pr.nCid; j++)
	    	       	fscanf(stream,"%d", &pr.taxa[h][i][j]);
  	   	}
	}
  	else {
		// -------------------------- Com calculo        
  		int iVetorTaxas [pr.nCid];
  		for (int i=0; i<pr.nCid; i++) iVetorTaxas[i]=0;
    
  		for (int h=0; h<pr.nCar; h++) {
    		fscanf(stream,"%s", &buf);
  			for (int i=0; i<pr.nCid; i++)
      			fscanf(stream, "%d", &iVetorTaxas[i]);
          
  			for (int i=0; i<pr.nCid; i++)
       			for (int j=0; j<pr.nCid; j++)
           			if (i == j)
            			pr.taxa[h][i][j] = 0;
           			else {
	           			for (int k=0; k<pr.nCid; k++)
	           				pr.taxa[h][i][j] = ((iVetorTaxas[i]*3+iVetorTaxas[j])*4)/2;
            		    }   
  		             }
	 }//fim do else

//  	free (P);
//	fclose(ptarq);
//  	fclose(stream);
  	printf(">>>>>>>>>>>>>>>>>>>>>>>>\n");
}
}

void imprimeProblema(){
     	printf("Dados do Problema: \n");
  	printf("\t Cidades: \t %d \n",pr.nCid);
 	printf("\t Carros: \t %d \n",pr.nCar);
    printf("\t Matriz de Distancias:  \n\t");
    	for (int i=0; i<pr.nCid; i++) {
	   				for (int j=0; j<pr.nCid; j++){
        	    		printf(" %4d", pr.dist[i][j]);
                    }
        printf("\n \t");	   
       	}
       	
    printf("\n \t Matrizes de Custos:  \n\t");
    	for (int h=0; h<pr.nCar; h++) {
    		printf("\n Carro%d : \n \t", h+1);	
    		for (int i=0; i<pr.nCid; i++) {
    	   		for (int j=0; j<pr.nCid; j++) {
    	        	printf(" %4li", pr.cust[h][i][j]);
                 }
	   		    printf("\n \t");	   
             }
         printf("\n \t");	   
   		}
     printf("\n \t Matrizes de Taxas de Retorno:  \n\t");
    	for (int h=0; h<pr.nCar; h++) {
    		printf("\n Carro%d : \n \t", h+1);	
    		for (int i=0; i<pr.nCid; i++) {
    	   		for (int j=0; j<pr.nCid; j++) {
    	        	printf(" %4li", pr.taxa[h][i][j]);
                 }
	   		    printf("\n \t");	   
             }
         printf("\n \t");	   
   		}
       	
    //system("PAUSE");
}
//fim da leitura dos dados do problema
