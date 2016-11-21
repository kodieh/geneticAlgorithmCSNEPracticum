/*
 * citizen.h
 *
 *  Created on: Nov 13, 2016
 *      Author: Kodie h
 */

#ifndef CITIZEN_H_
#define CITIZEN_H_

/*Citizen struct for Genetic Algorithm
 * containing int fitness of the individual
 * citizne and a char array of the individual
 * genes of the individual.
*/
struct citizen
{
	int fitness;
	char genes[8];
};



#endif /* CITIZEN_H_ */
