/*
 * util.c
 *
 *  Created on: Nov 13, 2016
 *      Author: Kodie h
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "citizen.h"


/*
 * fitness function to determine the fitness
 * of an individual citizen.
 */
int fitness(struct citizen population[10])
{
	int i, j, popSize = 10, geneSize = 8;
	int fitness = 0, totalFitness = 0;

	 //i loop loops through the population one at a time.
	for(i = 0; i < popSize; i++)
	{
		//j loop loops through the genes of a citizen.
		for(j = 0; j < geneSize; j++)
		{
			/*
			 * if the gene is equal to 1 increase the fitness
			 * of the individual. As well, increase the total
			 * fitness.
			 */
			if(population[i].genes[j] == 1)
			{
				fitness++;
				totalFitness++;
			}
		}
		//set the fitness inside the struct, return the fitness to 0.
		population[i].fitness = fitness;
		fitness = 0;
	}
	//return the total fitness to main.
	return totalFitness;
}

/*
 * function for selecting the first parent for breeding.
 */
int selectFirst(struct citizen population[10], int totFitness)
{
	time_t t;
	srand((unsigned) time(&t));
	int selected, i;

	//create a double for flyweight selection.
	double x = ((double)rand()/(double)RAND_MAX);
	double citNum;
	//for loop to loop through the population.
	for(i = 0; i < 10; i++)
	{
		//assign the number of the individual fitness divided by total fitness.
		citNum = (double)population[i].fitness/(double)totFitness;
		/*if the flyweight is less than or equal to the fitness division,
		*set selected as that individual for breeding.
		*/
		if(x <= citNum)
		{
			selected = i;
		}
		citNum = 0;
	}
	//return the selected individual
	return selected;
}

//Flyweight selection for the second parent, ensuring the first parent is not chosen twice.
int selectSecond(struct citizen population[10], int exception, int totFitness )
{
	time_t t;
	srand((unsigned) time(&t));
	int selected = 0, i;

	//create a double for flyweight selection.
	double x = ((double)rand()/(double)RAND_MAX);
	double citNum;

	//loop through the population, minus the last one.
	for(i = 0; i < 9; i++)
	{
		//divide the individual fitness by the totoal fitness
		citNum = (double)population[i].fitness/(double)totFitness;
		//if the flyweight is less than or equal to the fitness division
		if(x <= citNum)
		{
			//set that individual as selected.
			selected = i;
		}
	}

	//if the selected individual is the first parent
	if(i == exception)
	{
		//choose the left out parent.
		selected = 9;
		//if the last one is the first parent
		if(i == exception)
		{
			//randomly pick one
			selected = rand() % 9;
		}
	}

	return selected;
}


//Crossover function to breed parents.
struct citizen crossover(struct citizen father, struct citizen mother, int point)
{
	struct citizen new;
	int i;

	//for loop to loop over the genes of the parents
	for(i = 0; i < 8; i++)
	{
		//using a random number generated, choose which parents goes "first"
		if(point == 0)
		{
			//give the first four genes of the father
			if ( i < 5)
			{
				new.genes[i] = father.genes[i];
			}
			//give the last four genes of the mother
			else
			{
				new.genes[i] = mother.genes[i];
			}
		}
		else
		{
			//in reverse
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
	//return the new child
	return new;
}


//Cloning function to pick the most fit individual
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


//Function to mutate a random gene of a randomly selected citizen
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
