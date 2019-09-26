#include <iostream>
#include <string>

#include "Algorithm.h"

using namespace std;

Algorithm::Algorithm(
		string strategy, int sizePopulation, double elite, int limitIterations,
		double sizePlasmideo, double cross, string selectionStrategy, string intermediaryStrategy ){
	this->strategy = strategy;
	this->sizePopulation = sizePopulation;
	this->elite = elite;
	this->limitIterations = limitIterations;
	this->sizePlasmideo = sizePlasmideo;
	this->cross = cross;
	this->selectionStrategy = selectionStrategy;
	this->intermediaryStrategy = intermediaryStrategy;

}

void Algorithm::lets_go(){
	myPrint( "generation of population:", 1 );
	population = generateInitialPopulation( sizePopulation );
	checkPopulation( population );
	myPrint( "ok" , 1 );

	myPrint( "multi operator local search:", 1 );
	population = multiOperatorsLocalSearch( population );
	checkPopulation( population );
	myPrint( "ok" , 1 );

	myPrint( "select elite:", 1 );
	elitePopulation = selectElite( elite, population );
	checkPopulation( elitePopulation );
	myPrint( "ok" , 1 );

	for ( int i = 0; i < 1; i++ ){
		if( strategy == "m" ){
			applyMemplasAndCrossover( i );
		}else if( strategy == "mpr" ){
			applyMemplasAndCrossoverAndPathRelinking( i );
		}else if( strategy == "pr" ){
			applyPathRelinking( i );
		}

		myPrint( to_string(i) + "-multi operator local search: ", 1 );
		offspring = multiOperatorsLocalSearch( offspring );
		checkPopulation( population );
		myPrint( "ok" , 1 );

		myPrint( to_string(i) + "-binary tournament: ", 1 );
		population = binaryTournament( population, offspring );
		checkPopulation( population );
		myPrint( "ok" , 1 );

		myPrint( to_string(i) + "-select elite: ", 1 );
		elitePopulation = selectElite( elite, population );
		checkPopulation( population );
		myPrint( "ok", 1 );
	}

	Solution sol = selectBetter( population );
	myPrint( sol.fitness, 0 );
}

void Algorithm::applyMemplasAndCrossover( int interation ){
	if( interation % 10 != 0 ){
		myPrint( to_string( interation ) + "-crossover:", 1 );
		selection = selectPopulation( cross, population );
		offspring = crossover( selection );
		myPrint( "ok", 1 );
	}else{
		myPrint( to_string( interation ) + "-plasmid: ", 1 );
		selection = selectPopulation( elite, population );
		offspring = plasmid( selection, sizePlasmideo, elitePopulation );
		myPrint( "ok", 1 );
	}
	myPrint( to_string( interation ) + "-restoring operations: ", 1 );
	offspring = restoringOperations( offspring );
	checkPopulation( offspring );
	myPrint( "ok", 1 );
}

void Algorithm::applyMemplasAndCrossoverAndPathRelinking( int iteretion ){

}

void Algorithm::applyPathRelinking( int interation ){
	for( unsigned int i = 0; i < elitePopulation.size(); i++ ){
		elitePopulation[i].calculeFitness();
		myPrint( elitePopulation[i].fitness, 1 );
	}
	myPrint( to_string( interation ) + "-path relinking: ", 1 );
	offspring = pathRelinking( elitePopulation, selectionStrategy, intermediaryStrategy );
	checkPopulation( offspring );
	myPrint( "ok", 1 );
	for( unsigned int i = 0; i < offspring.size(); i++ ){
		offspring[i].calculeFitness();
		myPrint( offspring[i].fitness, 1 );
	}
}
