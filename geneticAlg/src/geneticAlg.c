/*
 ============================================================================
 Name        : geneticAlg.c
 Author      : kodieh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "citizen.h"


//initialization of related functions
int fitness(struct citizen *stu);
int selectFirst(struct citizen *stu, int);
int selectSecond(struct citizen *stu, int, int);
struct citizen crossover(struct citizen, struct citizen, int);
int cloning(struct citizen *stu);
struct citizen mutate(struct citizen);

int main(void)
{
	time_t t;
	srand((unsigned) time(&t));

	int i, j, popSize = 10, geneSize = 8, random, generation = 0;

	int totalFitness, MAX = 80;

	int father, mother, bool, clone;

	struct citizen holder;
	struct citizen population[10];
	struct citizen newPop[10];

	//initialize the populatyion with random genes.
	for(i = 0; i < popSize; i++)
	{
		for(j = 0; j < geneSize; j++)
		{
			population[i].genes[j] = rand() % 2;
		}
	}

	//calculate fitness
	totalFitness = fitness(population);

	//while max fitness is not met
	while(totalFitness != MAX)
	{
		//for loop to breed 10 new citizens
		for(i = 0; i < 10; i++)
		{
			father = selectFirst(population, totalFitness);
			mother = selectSecond(population, father, totalFitness);
			bool = rand() % 2;
			holder = crossover(population[father], population[mother], bool);
			newPop[i] = holder;
		}
		//picking a clone.
		clone = cloning(population);
		newPop[popSize-1] = population[clone];

		//copy the new population onto the old population.
		memcpy(population, newPop, sizeof(newPop));

		//randomly pick one to mutate.
		random = (rand() % 10);
		holder = population[random];
		holder = mutate(holder);

		//put it back in.
		population[random] = holder;

		//recount the total fitness as well as write the indivudals fitness
		totalFitness = fitness(population);
		//increase the generation.
		generation++;
	}

	printf("Finished in %d number of generations", generation);

	return 1;
}
