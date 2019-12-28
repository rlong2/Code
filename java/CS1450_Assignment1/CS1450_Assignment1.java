/* 
* This program generates 25 random integers between 0 and 99 and stores them in an array.
* The program will display the values and compute the sum, average, median, and mode.
*
* The program then orders the array, writes it to a file, and reads the array from the file.
*/

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class CS1450_Assignment1 
{
	public static void main(String[] args) throws IOException
	{
		double sum = 0;
		double average;

		// Create an array
		final int NUM_VALUES = 25;
		final String FILE_NAME = "assignment1.txt";	

		int[] numArray = new int[NUM_VALUES];
		for (int i = 0; i < NUM_VALUES; i++)
			numArray[i] = (int)(Math.random() * 100);		// Generate random ints for array
		
		// Print the array, calculating the sum and average
		System.out.println("Here is the array:");
		for (int i = 0; i < numArray.length; i++)
		{	
			System.out.println (numArray[i]);
			sum = sum + numArray[i];	
		}

		// Print the sum and average
		average = sum / NUM_VALUES;
		System.out.println("\nSum = " + sum);
		System.out.println("Average = " + average);

		// Print the median from sorted array
		Arrays.sort(numArray);
		System.out.println("Median = " + numArray[NUM_VALUES / 2]);
		
		// Print the mode - the value occuring most in the array
		int currentValue = numArray[0];
		int count  = 1;
		int highestValue = currentValue;			// Value with the highest count
		int highestCount = count;					// How many times an int appears in the sorted array

		for (int i = 1; i < numArray.length; i++)
		{
			if (numArray[i] == currentValue)		// If the integer appears, add it to the count
			{
				count++;
			}	
			else 
			{
				if (count > highestCount)
				{
					highestCount = count;
					highestValue = currentValue;
				}

				currentValue = numArray[i];			// reset the count to 1 for the next int
				count = 1;
			}
		}

		System.out.println("Mode is " + highestValue + " which occurred " + highestCount + " times.");
				
		// Output the sorted array to a file
		System.out.println("\nOutputting the sorted array to " + FILE_NAME);
		File fileName = new File(FILE_NAME);
		
		PrintWriter resultsFile = new PrintWriter (fileName);
		
		for (int i = 0; i < numArray.length; i++)
			resultsFile.println(numArray[i]);

		resultsFile.close();

		System.out.println("Printing array from " + FILE_NAME);
		Scanner readFile = new Scanner (fileName);

		for (int i = 0; i < NUM_VALUES; i++)
			System.out.println(readFile.nextInt());

		readFile.close(); 
	}
}
