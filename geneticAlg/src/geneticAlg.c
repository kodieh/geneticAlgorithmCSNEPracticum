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
	for(i = 0; i < popSize; i++)
	{
		for(j = 0; j < geneSize; j++)
		{
			population[i].genes[j] = rand() % 2;
		}
	}

	totalFitness = fitness(population);

	while(totalFitness != MAX)
	{
		for(i = 0; i < 10; i++)
		{
			father = selectFirst(population, totalFitness);
			mother = selectSecond(population, father, totalFitness);
			bool = rand() % 2;
			holder = crossover(population[father], population[mother], bool);
			newPop[i] = holder;
		}
		clone = cloning(population);
		newPop[popSize-1] = population[clone];
		memcpy(population, newPop, sizeof(newPop));
		random = (rand() % 10);
		holder = population[random];
		holder = mutate(holder);
		population[random] = holder;

		totalFitness = fitness(population);
		generation++;
	}

	printf("Finished in %d number of generations", generation);

	return 1;
}
