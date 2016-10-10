/**
 * 
 */
package edu.snu.csne.p;

import java.util.ArrayList;
import java.util.Random;

import edu.snu.csne.p.Util;

/**
 * @author kodie
 *
 */
public class GeneticAlgorithm 
{
	/**
	 * @param args
	 */
	public static void main(String[] args)
	{
		Random rand = new Random();
		int bool = 0, totalFitness = 0, maxFitness = 80, size = 10;
		ArrayList<Citizen> geneArray = new ArrayList<Citizen>();
		ArrayList<Citizen> nextPop = new ArrayList<Citizen>(size);
		Citizen father, mother, son;
		int loop = 0;
		Util build = new Util();

		geneArray = build.Builder();
		
		while(totalFitness != maxFitness)
		{
		    
			for(int i = 0; i < size; i++)
			{			
				bool = rand.nextInt((0-0+1) + 0);
				father = build.rouletteWheel(geneArray);
				geneArray.remove( father );
				mother = build.rouletteWheel(geneArray);
				geneArray.add( father );
				son = build.crossover(father, mother, bool);
				geneArray.set(i, son);
			}
			
			geneArray.set(geneArray.size()-1, build.rouletteWheel(geneArray));
			
			geneArray = build.fitness(geneArray);
			
			build.mutate(geneArray.get((int) (nextPop.size()*Math.random())));
			
			totalFitness = build.totalFitness(geneArray);
			
			System.out.println(totalFitness);
			
			loop++;
		}
		System.out.println("Finished at " + loop + " generations.");
	}
}