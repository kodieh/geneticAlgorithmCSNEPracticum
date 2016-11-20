/*
 * util.c
 *
 *  Created on: Nov 13, 2016
 *      Author: Lynnh
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "citizen.h"



int fitness(struct citizen population[10])
{
	int i, j, popSize = 10, geneSize = 8;
	int fitness = 0, totalFitness = 0;

	for(i = 0; i < popSize; i++)
	{
		for(j = 0; j < geneSize; j++)
		{
			if(population[i].genes[j] == 1)
			{
				fitness++;
				totalFitness++;
			}
		}
		population[i].fitness = fitness;
		fitness = 0;
	}

	return totalFitness;
}

int selectFirst(struct citizen population[10], int totFitness)
{
	time_t t;
	srand((unsigned) time(&t));
	int selected, i;

	double x = ((double)rand()/(double)RAND_MAX);
	double citNum;
	for(i = 0; i < 10; i++)
	{
		citNum = (double)population[i].fitness/(double)totFitness;
		if(x <= citNum)
		{
			selected = i;
		}
		citNum = 0;
	}

	return selected;
}

int selectSecond(struct citizen population[10], int exception, int totFitness )
{
	time_t t;
	srand((unsigned) time(&t));
	int selected = 0, i;

	double x = ((double)rand()/(double)RAND_MAX);
	double citNum;
	for(i = 0; i < 9; i++)
	{
		citNum = (double)population[i].fitness/(double)totFitness;
		if(x <= citNum)
		{
			selected = i;
		}
	}

	if(i == exception)
	{
		selected = 9;
		if(i == exception)
		{
			selected = rand() % 9;
		}
	}

	return selected;
}

struct citizen crossover(struct citizen father, struct citizen mother, int point)
{
	struct citizen new;
	int i;

	for(i = 0; i < 8; i++)
	{
		if(point == 0)
		{
			if ( i < 5)
			{
				new.genes[i] = father.genes[i];
			}
			else
			{
				new.genes[i] = mother.genes[i];
			}
		}
		else
		{
			if ( i < 5)
			{
				new.genes[i] = mother.genes[i];
			}
			else
			{
				new.genes[i] = father.genes[i];
			}
		}
	}
	return new;
}

int cloning(struct citizen population[10])
{
	int clone = 0, topFit = 0, i;

	for(i = 0; i < 10; i++)
	{
		if(topFit < population[i].fitness)
		{
			topFit = population[i].fitness;
			clone = i;
		}
	}

	return clone;
}

struct citizen mutate(struct citizen citizen)
{
	time_t t;
	srand((unsigned) time(&t));
	int i = rand() % 8;
	if(citizen.genes[i] == 0)
	{
		citizen.genes[i] = 1;
	}
	else
	{
		citizen.genes[i] = 0;
	}
	return citizen;
}
