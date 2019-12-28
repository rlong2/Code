/*
* This program reads a formatted characters.txt file to create characters
* and print their attributes using polymorphism.
*
* Example characters.txt file:
* 3           <-- array size
* h Larry     <-- Character type Hero, named Larry
* v Bob		  <-- Villian, named Bob
* m Foo       <-- Monster, named Foo
* r Bar       <-- Robot, named Bar
*
*/

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class CS1450_Assignment2
{
	public static void main(String[] args) throws IOException
	{
		final String FILE_NAME = "characters.txt";

		File inputFileName = new File(FILE_NAME);
	
		Scanner inputFile = new Scanner (inputFileName);
		int numCharacters = inputFile.nextInt();

		Character[] characters = new Character[numCharacters];

		for (int i = 0; i < numCharacters; i++)
		{
			// Read Character type and name
			String type = inputFile.next();
			String name = inputFile.nextLine();

			// Create the character object
			switch (type)
			{
				case "h": characters[i] = new Hero (name); break;
				case "v": characters[i] = new Villain (name); break;
				case "r": characters[i] = new Robot (name); break;
				case "m": characters[i] = new Monster (name); break;
			}
		}

		// Have each character in the array display its type and an interesting fact
		System.out.printf("\n%s\t\t%s\t\t%s\n", "Character Name", "Type", "Statement");
		System.out.println("-----------------------------------------------------------------------");

		for (int i = 0; i < characters.length; i++)
		{
			System.out.printf ("%-15s\t\t", characters[i].getName());
			System.out.printf ("%s\t\t", characters[i].getType());
			System.out.printf ("%s\t\t", characters[i].speak());
			System.out.println();
		}

		System.out.println();
		inputFile.close();

	} // main

} // CS1450_Assignment2

class Character
{
	private String name;
	private String type;

	// Constructor
	public Character (String name, String type)
	{
		this.name = name;
		this.type = type;
	}

	// Getters and setters
	public String getName() { return name;}
	public String getType() { return type;}

	// Make Character speak
	public String speak() { return "Generic Character"; }

} // Character

class Hero extends Character
{
	// Construct a hero with a specific name
	public Hero (String name)
	{
		super (name, "Hero");
	}

	@Override // Make Hero speak
	public String speak()
	{
		return "To the rescue! Kapow! Boom! Pow!";
	}
}

class Villain extends Character
{
	// Construct a villain with a specific name
	public Villain (String name)
	{
		super (name, "Villain");
	}

	@Override // Make Villain speak
	public String speak()
	{
		return "Yarrrrr! I am eeevillllll!";
	}
} // Villain

class Robot extends Character
{
	// Construct a robot with a specific name
	public Robot (String name)
	{
		super (name, "Robot");
	}

	@Override // Make Robot speak
	public String speak()
	{
		return "Beep Bzzzt Bleep Bewp! BZZzzzzt!";
	}
} // Robot

class Monster extends Character
{
	// Construct a monster with a specific name
	public Monster (String name)
	{
		super (name, "Monster");
	}

	@Override // Make monster speak
	public String speak()
	{
		return "Gwaaar! Rawr! Braaaarrrr!";
	}
} // Monster
