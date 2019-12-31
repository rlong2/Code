/* This program reads from birds.txt and groups birds into categories.
*  Information about the birds is then printed to the user.
*
*  The file is formatted so that the first line is the number of birds.
*  The next line specifies the bird type, name, run speed, swim speed, and fly altitude
*  An int of 0 signifies that the bird does not have that attribute.
*
*  The birds are grouped into the following categories:
*  Birds that cannot run
*  Birds that cannot swim
*  Birds that cannot fly
*  Birds that can run, swim, and fly
* 
*  Each type of bird has an interesting fact that is printed along with its run/swim/fly speed
*/

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class CS1450_Assignment3
{
	public static void main(String[] args) throws IOException 
	{	
    	final String FILE_NAME = "birds.txt";
		File fileName = new File(FILE_NAME);

		Scanner birdFile = new Scanner (fileName);
		int numBirds = birdFile.nextInt();			// Get number of birds

		// Create array to store birds
		Bird[] birds = new Bird[numBirds];

		// Create bird objects by reading the lines in the file
		for (int i = 0; i < birds.length; i++)
		{
			String typeOfBird = birdFile.next();
			String name = birdFile.next();
			int runSpeed = birdFile.nextInt();
			int swimSpeed = birdFile.nextInt();
			int flyAltitude = birdFile.nextInt();
		
			switch (typeOfBird)
			{
				case "d": birds[i] = new Duck (name, runSpeed, swimSpeed, flyAltitude); break;
				case "h": birds[i] = new Hummingbird (name, flyAltitude); break;
				case "l": birds[i] = new Loon (name, swimSpeed, flyAltitude); break;
				case "o": birds[i] = new Ostrich (name, runSpeed, swimSpeed); break;
				case "p": birds[i] = new Penguin (name, runSpeed, swimSpeed); break;
				case "s": birds[i] = new SootyTern (name, runSpeed, flyAltitude); break;
			}
		}

		birdFile.close();

		// Find and print birds that cannot fly
		System.out.println("\nBirds that cannot fly:");
		System.out.println("------------------------");
		ArrayList<Bird> cannotFly = findCannotFly(birds);

		for (int i = 0; i < cannotFly.size(); i++)
		{
			System.out.println (cannotFly.get(i).getName() + " is a " +
								cannotFly.get(i).getType() + " and cannot fly");
			System.out.println (cannotFly.get(i).interestingFact());
			System.out.println();
		}

		// Find and print birds that cannot run
		System.out.println("\nBirds that cannot run:");
		System.out.println("------------------------");
		ArrayList<Bird> cannotRun = findCannotRun(birds);

		for (int i = 0; i < cannotRun.size(); i++)
		{
			System.out.println (cannotRun.get(i).getName() + " is a " +
								cannotRun.get(i).getType() + " and cannot run");
			System.out.println (cannotRun.get(i).interestingFact());
			System.out.println();
		}

		// Find and print birds that cannot swim
		System.out.println("\nBirds that cannot swim:");
		System.out.println("------------------------");
		ArrayList<Bird> cannotSwim = findCannotSwim(birds);

		for (int i = 0; i < cannotSwim.size(); i++)
		{
			System.out.println (cannotSwim.get(i).getName() + " is a " +
								cannotSwim.get(i).getType() + " and cannot swim");
			System.out.println (cannotSwim.get(i).interestingFact());
			System.out.println();
		}

		// Find and print birds that can run, swim, and fly!
		// We need to cast because the interfaces are not provided in Bird
		System.out.println("\nBirds that can run, swim, and fly:");
		System.out.println("------------------------");
		ArrayList<Bird> runSwimFly = findRunSwimFly(birds);

		for (int i = 0; i < runSwimFly.size(); i++)
		{
			System.out.println (runSwimFly.get(i).getName() + " is a " +
								runSwimFly.get(i).getType() + " and can do it all");
			
			System.out.println ("Running at " + ((Runner)runSwimFly.get(i)).run() + " mph");
			System.out.println ("Swimming at " + ((Swimmer)runSwimFly.get(i)).swim() + " mph");
			System.out.println ("Flying at " + ((Flyer)runSwimFly.get(i)).fly() + " feet in elevation");
			System.out.println (runSwimFly.get(i).interestingFact());
			System.out.println();
		}


	} // main	

// Methods to find birds that cannot run/swim/fly:
// If a bird is not in a specific interface, it does not have that attribute
public static ArrayList<Bird> findCannotFly (Bird[] birds)
{
	ArrayList<Bird> cannotFly = new ArrayList<>();
	
	for (int i = 0; i < birds.length; i++)
	{
		if (!(birds[i] instanceof Flyer))
			cannotFly.add(birds[i]);
	}
	return cannotFly;
}

public static ArrayList<Bird> findCannotRun (Bird[] birds)
{
	ArrayList<Bird> cannotRun = new ArrayList<>();
	
	for (int i = 0; i < birds.length; i++)
	{
		if (!(birds[i] instanceof Runner))
			cannotRun.add(birds[i]);
	}
	return cannotRun;
}

public static ArrayList<Bird> findCannotSwim (Bird[] birds)
{
	ArrayList<Bird> cannotSwim = new ArrayList<>();
	
	for (int i = 0; i < birds.length; i++)
	{
		if (!(birds[i] instanceof Swimmer))
			cannotSwim.add(birds[i]);
	}
	return cannotSwim;
}

public static ArrayList<Bird> findRunSwimFly (Bird[] birds)
{
	ArrayList<Bird> runSwimFly = new ArrayList<>();
	
	for (int i = 0; i < birds.length; i++)
	{
		if ((birds[i] instanceof Runner) && (birds[i] instanceof Swimmer) && (birds[i] instanceof Flyer))
			runSwimFly.add(birds[i]);
	}
	return runSwimFly;
}

} // CS1450_Assignment3

// Interfaces:
// Speed that bird can run/swim/fly
interface Runner  { public int run();  }
interface Swimmer { public int swim(); }
interface Flyer   { public int fly();  }



// Bird Classes
abstract class Bird
{
	private String name;
	private String type;

	// Getters
	public String getName() { return name; }
	public String getType() { return type; }

	// Setters
	public void setName (String name) { this.name = name; }
	public void setType (String type) { this.type = type; }

	// Return an interesting bird fact!
	public abstract String interestingFact();

} // Bird

class Duck extends Bird implements Runner, Swimmer, Flyer
{
    private int runSpeed;
	private int swimSpeed;
	private int flyAltitude;

	public Duck (String name, int runSpeed, int swimSpeed, int flyAltitude)
	{
		setName(name);
		setType("Duck");
		this.runSpeed = runSpeed;
		this.swimSpeed = swimSpeed;
		this.flyAltitude = flyAltitude;
	}

	@Override // Implement run/swim/fly/interesting fact method
	public int run() { return runSpeed; }
	
	@Override
	public int swim() { return swimSpeed; }

	@Override
	public int fly() { return flyAltitude; }

	@Override
	public String interestingFact()
	{
		return "Ducks are large chickens in disguise!";
	}
} // Duck

class Hummingbird extends Bird implements Flyer
{
	private int flyAltitude;

	public Hummingbird (String name, int flyAltitude)
	{
		setName(name);
		setType("Hummingbird");
		this.flyAltitude = flyAltitude;
	}

	@Override // Implement run/swim/fly/interesting fact method
	public int fly() { return flyAltitude; }

	@Override
	public String interestingFact()
	{
		return "Hummingbirds weigh less than a dime!";
	}
} // Hummingbird

class Loon extends Bird implements Swimmer, Flyer
{
	private int swimSpeed;
	private int flyAltitude;

	public Loon (String name, int swimSpeed, int flyAltitude)
	{
		setName(name);
		setType("Loon");
		this.swimSpeed = swimSpeed;
		this.flyAltitude = flyAltitude;
	}

	@Override
	public int swim() { return swimSpeed; }

	@Override
	public int fly() { return flyAltitude; }

	@Override
	public String interestingFact()
	{
		return "Loons are Canada's currency!";
	}
}  // Loon

class Ostrich extends Bird implements Runner, Swimmer
{
    private int runSpeed;
	private int swimSpeed;

	public Ostrich (String name, int runSpeed, int swimSpeed)
	{
		setName(name);
		setType("Ostrich");
		this.runSpeed = runSpeed;
		this.swimSpeed = swimSpeed;
	}

	@Override // Implement run/swim/fly/interesting fact method
	public int run() { return runSpeed; }
	
	@Override
	public int swim() { return swimSpeed; }

	@Override
	public String interestingFact()
	{
		return "Ostriches are basically dinosaurs!";
	}
} // Ostrich

class Penguin extends Bird implements Runner, Swimmer
{
    private int runSpeed;
	private int swimSpeed;

	public Penguin (String name, int runSpeed, int swimSpeed)
	{
		setName(name);
		setType("Penguin");
		this.runSpeed = runSpeed;
		this.swimSpeed = swimSpeed;
	}

	@Override // Implement run/swim/fly/interesting fact method
	public int run() { return runSpeed; }
	
	@Override
	public int swim() { return swimSpeed; }

	@Override
	public String interestingFact()
	{
		return "Tux the penguin invented GNU/inux!";
	}
} // Penguin

class SootyTern extends Bird implements Runner, Flyer
{
    private int runSpeed;
	private int flyAltitude;

	public SootyTern (String name, int runSpeed, int flyAltitude)
	{
		setName(name);
		setType("SootyTern");
		this.runSpeed = runSpeed;
		this.flyAltitude = flyAltitude;
	}

	@Override // Implement run/swim/fly/interesting fact method
	public int run() { return runSpeed; }
	
	@Override
	public int fly() { return flyAltitude; }

	@Override
	public String interestingFact()
	{
		return "Most SootyTerns love to sweep chimneys!";
	}
} // SootyTern
