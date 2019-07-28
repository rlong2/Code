/* Ryan Long
 * CS 1450 001 - Data Structures and Algorithms - Fall 2018
 * This program generates and displays an array of 25 random numbers ranged 0 - 99, 
 * calculates the sum, average, median, and mode of the array, then sorts the array 
 * from lowest to highest and outputs the result to a file in the current directory.
 * The file is then read and displayed by the program.
*/
import java.util.Arrays;
import java.io.FileNotFoundException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

class assignment1{

	// Code begins
	public static void main(String[] args) throws FileNotFoundException, Exception {

		//Prints random array
		int[] array = new int[25];
		print(array); 
		
		//Sums the array
		System.out.println("\nSum        = " + sum(array)); 
		
		//Averages the array
		System.out.println("Average    = " + average(array));
		
		// Calculates median of array
		System.out.println("Median     = " + median(array));
		
		//Calculates mode of array
		System.out.println("Mode value = " + mode(array)); 
		
		//Outputs the array to assignment1.txt in current directory
		write(array);
		
		// Reads data from assignment1.txt in current directory
		read(array);
	}// end main
	
	// Prints randomly generated array
	public static void print (int[] array) {
		System.out.println("Random values stored in an array");
		 for(int i = 0; i < array.length; i++) {
		      array[i] = (int)(Math.random()*100);
		      System.out.println(array[i]);
		  } 
		}
	
	// Calculates total sum of array
	public static int sum (int[] array) {
		 int sum = 0;
		for (int element: array) {
			sum = sum + element; 
		  	}
		  	return sum; 
		}
	
	// Calculates average of array
	public static double average(int[] array) {
		double average = 0;
		 average = (sum(array) / 25.0);	
		 return average;
		}
	
	 // Calculates median of array
	public static int median(int[] array) {
    Arrays.sort(array);
    	int median = 0;
    if ((array.length & 1) == 0 ) {
        median = (array[(25/2)] + array[(25/2)]) / 2;  // Averages the 2 middle integers
    } else {
        median = array[25/2];	// Uses middle integer
    }
    return median;
	} 
	
	// Calculates mode of array
	public static String mode (int[] array) {
		int element = 0;
		int count = 0;
		for (int i = 0; i < array.length; i++) {
			int tempElement = array[i];
			int tempCount = 0;
			for(int j = 0; j < array.length; j++)
				if(array[j] == tempElement)
				tempCount++;
			if (tempCount > count){
				element = tempElement;
				count = tempCount;
				}
		}
			return (element + " which occured " + count + " times");
	} 
	
	// Sorts and outputs the array integers from lowest to highest
		public static int[] write (int[] array) throws FileNotFoundException{
			java.io.File file = new java.io.File("assignment1.txt");
			java.io.PrintWriter output = new java.io.PrintWriter(file);
			int[] newArray = new int[25];
			int i;
			for (i = 0; i < 25; i++){
				newArray [i] = array [i]; 
				Arrays.sort(array);	
				output.println(array[i]);   
			}
			output.close();
			return newArray; 
		}
		
	// Reads data from assignment1.txt in current directory
		public static int[] read (int[] array) throws IOException{
			FileReader file = new FileReader("assignment1.txt");
			BufferedReader reader = new BufferedReader(file);
			String text = "\nRandom values stored in file in increasing order";
			String line = reader.readLine();
			while(line != null) {
				text += "\n" + line;
				line = reader.readLine();
			} reader.close();
			System.out.println(text);
			return array;
		}
	
}//class
