/**
 * 
 */
package edu.snu.csne.p;

import java.util.ArrayList;
import java.util.Random;

/**
 * @author kodie
 *
 */
public class Util 
{
	public ArrayList<Citizen> Builder()
	{
		int size = 10;
		ArrayList<Citizen> geneArray = new ArrayList<Citizen>();
		
		for(int i = 0; i < size; i++)
		{
			Citizen x = new Citizen();
			geneArray.add(x);
		}
		for(int i = 0; i < size; i++)
		{
			randmoize(geneArray.get(i));
//			for(int j = 0; j < geneArray.get(i).getGenes().length; j++)
//			{
//				System.out.print(geneArray.get(i).getGenes()[j]);
//			}
//			System.out.println("\n");
		}
		
		geneArray = fitness(geneArray);
		roulette(geneArray);
		
		return geneArray;
	}
	
	public void randmoize(Citizen genes)
	{
		Random rand = new Random();
		int index, bool;
		byte[] here = genes.getGenes();
		for(int i = 0; i < here.length; i++)
		{
			index = rand.nextInt((7-0+1) + 0);
			bool = rand.nextInt((1-0+1) + 0);
			if(bool == 1)
			{
				here[index] = 1;
			}
			else
			{
				here[index] = 0;
			}
		}
		genes.setGenes(here);
	}
	
	public ArrayList<Citizen> fitness(ArrayList<Citizen> genes)
	{
	    for(int i = 0; i < genes.size(); i++)
	    {
    		byte[] here = genes.get( i ).getGenes();
    		int fitness = 0;
    		for(int j = 0; j < here.length; j++)
    		{
    			if(here[j] == 1)
    			{
    				fitness++;
    			}
    		}
    		genes.get(i).setFitness(fitness);
	    }
	    
	    return genes;
	}
	
	public void roulette(ArrayList<Citizen> geneArray)
	{
		int totalFitness = totalFitness(geneArray);
		for(int i = 0; i < geneArray.size(); i++)
		{
			if(geneArray.get(i).getFitness() == 0)
			{
				geneArray.get(i).setRoulette(0);
			}
			else
			{
				geneArray.get(i).setRoulette(geneArray.get(i).getFitness()/totalFitness);
			}
		}
	}
	
	public int totalFitness(ArrayList<Citizen> geneArray)
	{
		int totalFitness = 0;
		Citizen here = geneArray.get(0);
		for(int i = 0; i < geneArray.size(); i++)
		{
			totalFitness += here.getFitness();
			here = geneArray.get( i );
		}
		

		
		return totalFitness;
	}
	
	public Citizen crossover(Citizen father, Citizen mother, int bool)
	{
		Citizen son = new Citizen();
		
		for(int i = 0; i < father.getGenes().length; i++)
		{
			if(bool == 0)
			{
				if(i < 5)
				{
					son.getGenes()[i] = father.getGenes()[i];
				}
				else
				{
					son.getGenes()[i] = mother.getGenes()[i];
				}
			}
			else
			{
				if(i < 5)
				{
					son.getGenes()[i] = mother.getGenes()[i];
				}
				else
				{
					son.getGenes()[i] = father.getGenes()[i];
				}
			}
			
		}
		
		return son;
	}
	
	public Citizen rouletteWheel(ArrayList<Citizen> geneArray)
	{
		Random rand = new Random();
		int index = 0;
		double maxFitness = totalFitness(geneArray);
		for(int i = 0; i < geneArray.size(); i++)
		{
			if(rand.nextDouble() <= (geneArray.get(i).getFitness()/maxFitness))
			{
				index = i;
			}
		}
		
		return geneArray.get(index);
	}
	
	public void mutate(Citizen son)
	{
		int check = 0, index = (int)(son.getGenes().length * Math.random());
		check = son.getGenes()[index];
		if(check == 0)
		{
			son.getGenes()[index] = 1;
		}
		else
		{
			son.getGenes()[index] = 0;
		}
	}
	
}