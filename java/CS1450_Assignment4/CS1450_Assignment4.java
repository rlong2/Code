/*
*  This program reads a text file and displays information about a 
*  railroad yard and train system. 
*
*  Example file:
*  3                      <-- number of trains
*  1 8172 BNSF 40  Denver
*  2 6242 CSX  130 Chicago
*  4 9107 BNSF 30  Cincinnati
*
*  The values in each line represent:
*  engine number, track number, company, number of cars, and destination 
*
*/

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.Scanner;

public class CS1450_Assignment4
{
	public static void main(String[] args) throws IOException
	{
		final String TRAINS_FILE_NAME = "sortingYardTrains.txt";
		File trainsFileName = new File(TRAINS_FILE_NAME);
		Scanner trainsFile = new Scanner (trainsFileName);

		int numberTracks = trainsFile.nextInt();
		
		RailroadYard railroadYard = new RailroadYard(numberTracks + 1);

		// Set up sorting yard tracks with trains
		System.out.println("\nLoading trains onto tracks in sorting yard...\n");
		System.out.println("-------------------------------------------------------------------------------------");
		System.out.printf("%36s\t%s\t\t%s\t%s\n", "Engine", "Company", "Rail Cars", "Destination");
		System.out.println("-------------------------------------------------------------------------------------");

		// Create the train objects from the details provided in the file
		while (trainsFile.hasNext())
		{
			int trackNumber = trainsFile.nextInt();
			int engineNumber = trainsFile.nextInt();
			String company = trainsFile.next();
			int numberCars = trainsFile.nextInt();
			String destCity = (trainsFile.nextLine()).trim();

			Train train = new Train(engineNumber, company, numberCars, destCity);

			// Move train to its correct track in sorting yard
			railroadYard.addTrainToSortingYard(trackNumber, train);

			System.out.print("Loading sorting track " + trackNumber + ": ");
			System.out.println(train.print());
		}

		trainsFile.close();

		// Print an outbound report for all trains in the railroad yard
		printOutboundReport(railroadYard);
		

	} // main

	// Methods
	// Display a report for each outbound train
	public static void printOutboundReport (RailroadYard yard)
	{
		// Store the outbound report for each train in the sorting yard
		ArrayList<OutboundReport> outboundReports = new ArrayList<>();

		for (int trackNumber = 0; trackNumber < yard.getNumberTracks(); trackNumber++)
		{
			Train train = yard.getNextTrainInSortingYard();

			if (train != null)
			{
				int engineNumber = train.getEngineNumber();
				int numberCars = train.getNumberRailCars();
				String destinationCity = train.getDestinationCity();

				OutboundReport report = new OutboundReport(trackNumber, engineNumber, numberCars, destinationCity);
				outboundReports.add(report);
			}
		}

		Collections.sort(outboundReports);

		System.out.println("\n\n**********************************************************************");
		System.out.println("\t\t\tOutbound Report");
		System.out.println("\t\tOrdered by Max number of rail cars:");
		System.out.println("\n**********************************************************************");

		System.out.printf("Sorting Track\tEngine\t\tRail Cars\tDeparting To\n");
		System.out.println("----------------------------------------------------------------------");

		Iterator<OutboundReport> iterator = outboundReports.iterator();
		while (iterator.hasNext())
		{
			OutboundReport currentReport = iterator.next();
			System.out.println(currentReport.print());
		}
		
	} // printOutboundReport

} // CS1450_Assignment4

// Interface
interface Printable
{ public String print(); }

// Classes

// Represents the outbound report for a specific train
class OutboundReport implements Printable, Comparable<OutboundReport>
{
	private int trackNumber;
	private int engineNumber;
	private int numberRailCars;
	private String destinationCity;

	public OutboundReport (int trackNumber, int engineNumber, int numberRailCars, String destinationCity)
	{
		this.trackNumber = trackNumber;
		this.engineNumber = engineNumber;
		this.numberRailCars = numberRailCars;
		this.destinationCity = destinationCity;
	}
	
	@Override // Turn train outbound report into a printable string
	public String print()
	{
		return String.format("%2d\t\t%-4d\t\t%-3d\t\t%-10s", trackNumber, engineNumber, numberRailCars, destinationCity);
	}

	@Override // Comparing 2 outbound reports
	public int compareTo(OutboundReport record)
	{
		if (this.numberRailCars < record.numberRailCars)
			return -1;
		else if (this.numberRailCars > record.numberRailCars)
			return 1;
		else
			return 0;
	}
} // OutboundReport

// Represents a railroad yard for sorting, loading, and unloading cars
class RailroadYard
{
	private int numberTracks;
	private int currentTrack;
	private Train[] sortingYard; // An array of trains where the array slot number
								 // represents the sorting track number
	public RailroadYard (int numberTracks)
	{
		this.numberTracks = numberTracks;
		this.currentTrack = 0;
		sortingYard = new Train[numberTracks]; // Railroad Yard contains a sorting yard
												// with a certain number of tracks.
												// There may or may not be a train on the tracks.
	}

	// Getters
	public int getNumberTracks() { return numberTracks; }

	// Adding a train to a specific track in the sorting yard
	public void addTrainToSortingYard (int trackNumber, Train train)
	{
		sortingYard[trackNumber] = train;
	}
	
	// Return the next train in the tracks array.
	// This method is called repeatedly to print trains in the sorting yard
	public Train getNextTrainInSortingYard()
	{
		Train currentTrain = sortingYard[currentTrack];
		currentTrack++;

		return currentTrain;
	}

} // RailroadYard	 


class Train implements Printable
{
	private int engineNumber;
	private String company;
	private int numberRailCars;
	private String destinationCity;

	// Create a train
	public Train (int engineNumber, String company, int numberRailCars, String destinationCity)
	{
		this.engineNumber = engineNumber;
		this.company = company;
		this.numberRailCars = numberRailCars;	
		this.destinationCity = destinationCity;
	}

	// Getters
	public int getEngineNumber() { return engineNumber; }
	public String getCompany() { return company; }
	public int getNumberRailCars() { return numberRailCars; }
	public String getDestinationCity() { return destinationCity; }
	
	@Override 
	public String print()
	{
		return String.format("%9d\t%-5s\t\t%-3d\t\t%-15s",
							 engineNumber,
							 company,
							 numberRailCars,
							 destinationCity);
	}

} // Train
