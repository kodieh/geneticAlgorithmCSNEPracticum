/**
 * 
 */
package edu.snu.csne.p;

/**
 * @author kodie
 *
 */
public class Citizen 
{
	int size = 8;
	byte[] genes;
	int fitness;
	double roulette;
	
	public Citizen()
	{
		genes = new byte[size];
		for(int i = 0; i < genes.length; i++)
		{
			genes[i] = 0;
		}
		fitness = 0;
		roulette = 0;
	}
	
	public void setGenes(byte[] newGenes)
	{
		genes = newGenes;
	}

	public byte[] getGenes()
	{
		return genes;
	}
	
	public void setFitness(int newFitness)
	{
		fitness = newFitness;
	}
	
	public int getFitness()
	{
		return fitness;
	}
	
	public void setRoulette(double i)
	{
		roulette = i;
	}
	
	public double getRoulette()
	{
		return roulette;
	}
}
