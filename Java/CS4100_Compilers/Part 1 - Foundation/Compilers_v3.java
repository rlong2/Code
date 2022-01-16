/* 
 * Ryan Long
 * CS 4100 Compiler Project Part 1: Foundations
 * 9/18/2020
 * 
 * This project creates a SYmbol Table, Quad Table, and Reserve Table
 * and uses them to carry out instructions through an interpreter
 * and generate output for a Factorial(10) and Summation(10) function.
 * A traceOn boolean is used to trace output if desired.
 */

import java.util.ArrayList;
import java.util.List;
import java.util.*;

////////////
//Classes /
//////////
class Symbol {

	private String name;
	private int kind;

	private String stringValue;
	private int intValue;
	private double doubleValue;

// Overloaded Symbol objects for int, double, or String values
	public Symbol(String name, int kind, String value) {
		this.name = name;
		this.kind = kind;
		stringValue = value;
	}

	public Symbol(String name, int kind, int value) {
		this.name = name;
		this.kind = kind;
		intValue = value;
	}

	public Symbol(String name, int kind, double value) {
		this.name = name;
		this.kind = kind;
		doubleValue = value;
	}

// Getters
	public String getName() { return name; }
	public int getKind() { return kind; }

// Overloaded Getters to return a specific value type
	public String getStringValue() { return stringValue; }
	public int getIntValue() { return intValue; }
	public double getDoubleValue() { return doubleValue; }

// Setters
	public void setName(String name) { stringValue = name; }
	public void setKind(int kind) { this.kind = kind; }
	public void setStringValue(String value) { stringValue = value; }
	public void setIntValue(int value) { intValue = value; }
	public void setDoubleValue(double value) { doubleValue = value; }

@Override
	public String toString() {
	switch(kind) {
		case 0:
			return name + "\t" + kind + "\t" + stringValue;
		case 1:
			return name + "\t" + kind + "\t" + intValue;
		case 2:
			return name + "\t" + kind + " \t" + stringValue;
		default:
			return "DNE";
		}
	} 
} // class Symbol

class SymbolTable {

	ArrayList<Symbol> symbList = new ArrayList<Symbol>();

// Constructor that builds an empty Symbol Table
// Format is (name, kind, value)
// kind 0 is String value, 1 is int value, 2 is double value
	public SymbolTable() {
	}

//Adds symbol with given kind and value (name) to the symbol table, 
//automatically setting the correct data_type, and returns to
//the index where the symbol was located.
//If symbol is already in table, make no change, return to index where symbol was found.
	public int AddSymbol(String symbol, int kind, String value) {
		symbList.add(new Symbol(symbol, kind, value));
		return symbList.size() - 1; 
	}

	public int AddSymbol(String symbol, int kind, int value) {
		symbList.add(new Symbol(symbol, kind, value));
		return symbList.size() - 1;
	}

	public int AddSymbol(String symbol, int kind, double value) {
		symbList.add(new Symbol(symbol, kind, value));
		return symbList.size() - 1; 
	}

//Returns the index where symbol is found, or -1 if not in table
	public int LookupSymbol(String symbol) {
		for (int i = 0; i < symbList.size(); i++) {
			if (symbList.get(i).getName() == symbol)
				return i;
		}
		return -1;
	}

//Return kind, data type, and value fields stored at index
	public Symbol GetSymbol(int index) {
		return symbList.get(index);
	}

//Set appropriate fields at slot indicated by index
	public void UpdateSymbol(int index, int kind, int value) {
		GetSymbol(index).setIntValue(value);
	}

	public void UpdateSymbol(int index, int kind, double value) {
		GetSymbol(index).setDoubleValue(value);
	}

	public void UpdateSymbol(int index, int kind, String value) {
		GetSymbol(index).setStringValue(value);
	}

//Prints the utilized rows of the symbol table in a neat tabular format,
//showing only the value fields which is active for that row
	public void PrintSymbolTable() {
		System.out.println("\n======== Initial Symbol Table Contents ========");
		System.out.println("Name  | Kind  | Value");

		for (int i = 0; i < symbList.size(); i++)
			System.out.println(symbList.get(i));	// call to toString method
	}
} 

// TODO:
class NewQuadTable {
	  
	  List<int[]> quadArr = new ArrayList<>();

	  public void AddQuad(int opcode, int op1, int op2, int op3) {
	      //System.out.println("adding quad...");
	      quadArr.add(new int[] {opcode, op1, op2, op3});
	  }
	  
	    public void PrintQuad() {
	        for (int[] arr : quadArr) {
	            for(int i = 0; i < arr.length; i++) {
	                System.out.print(arr[i] + " ");
	            }
	            System.out.println();
	        }
	    }
} // NewQuadTable


//QuadTable creates a new, empty QuadTable ready for data to be added, with the specified number of rows (size)
class QuadTable {

	static int[][] quadArr;

	public void Initialize(int rows, ReserveTable ResTbl) {
		int cols = 4;
		quadArr = new int[rows][cols];

//populate arrray with -1 values
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				quadArr[i][j] = -1;
	}

//Return the int index of the next open slot in QuadTable.
	public int NextQuad() {
		for (int i = 0; i < quadArr.length; i++) {
			if (quadArr[i][0] == -1) {
				return i;
			}
		}
		//else, array is full
		return 0;
	}

//Expands the active length of the QuadTable by adding a new row
//at the NextQuad slot, with the parameter sent as the new contents,
//and increments the NextQuad counter to the next available (empty) index
	public void AddQuad(int opcode, int op1, int op2, int op3, int next) {
		quadArr[next][0] = opcode;
		quadArr[next][1] = op1;
		quadArr[next][2] = op2;
		quadArr[next][3] = op3;
	}

//Returns the data for the opcode and three operands located at index
	public static int[] GetQuad(int index) {
		int[] quadRow = quadArr[index];
		return quadRow;	
	}

//Changes the contents of the existing quad at index.
//Used only when backfilling jump addresses later during code generation
	public void SetQuad(int index, int opcode, int op1, int op2, int op3) {
	}

//Returns the mnemonic string ('ADD', 'PRINT', etc) associated with the opcode parameter. 
	public String GetMnemonic(int opcode, ReserveTable ResTbl) {
		return ResTbl.LookupCode(opcode);
	}

//Prints the currently used contents of the Quad table in neat tabular format
	public void PrintQuadTable(ReserveTable ResTbl) {
		int firstColIndex = 0;
		System.out.println("\n======== Quad Table contents ========");
		System.out.println("Opcode | op1  | op2 |  op3");
		System.out.println("--------------------------");

		for (int i = 0; i < quadArr.length; i++) { // Loop through rows
			for (int j = 0; j < quadArr[i].length; j++) { // Loop through elements in the row

				// Determine if Opcode ([0][0], [1][0], [2][0], [3][0], etc)
				if (i == firstColIndex) {
					System.out.print(ResTbl.LookupCode(quadArr[i][j]) + "\t "); // If in the first column, print the Opcode string																		
					firstColIndex++;
				} else 
					System.out.print(quadArr[i][j] + "\t"); // Else, print the op1, op2, or op3 value
			} // inner for
			System.out.println();
		} // outer for
	}
}

//ReserveTable is a lookup table ADT used for the opcode lookup, and later in the compiler,
//a separate instance will hold the reserved word list for the language. 
//Each indexed entry is a pair consisting of a name string and integer code.
//The table as we use it is static, and initialized once at the start of the program,
//and then only used for lookups later on
class ReserveTable {

	ArrayList<String> resArr;

	//Constructor, as needed
	ReserveTable() {
		resArr = new ArrayList<>();
	}

//Returns the index of the row where the data was placed, just adds to end of list
	public int Add(String name, int code) {
		resArr.add(name);
		resArr.set(code, name);
		return code;
	}

//Returns the code associated with name if name is in the table, else return -1
	public int LookupName(String name) {
		for (int i = 0; i < resArr.size(); i++) {
			if (resArr.get(i) == name) {
				return i;
			}
		}
		return -1;
	}

//Returns the associated name if code is there, else return an empty string 
	public String LookupCode(int code) {
		if (code <= resArr.size()) 
			return resArr.get(code);
		return "";
	}

//Prints the currently used contents of the Reserve table in neat tabular format
	public void PrintReserveTable() {
		System.out.println("\n======== Reserve Table Contents ========");
		for (int i = 0; i < (resArr.size() - 1); i++) {
			System.out.print(i + " " + resArr.get(i) + ", ");
	
			if (i == 8)					// Split the printout into 2 rows
				System.out.println();
		}
		System.out.println(resArr.size() - 1 + " " + resArr.get(resArr.size() - 1));  // Print last item without a comma
	}
}


public class Compilers_v3 {
/////////////
//Functions /
/////////////
	// TODO:

public static void InterpretQuads(QuadTable Q, ReserveTable ResTbl, SymbolTable S, boolean traceOn) {

	int pc = 0;
	final int MAXQUAD = 1000;
	int[] quadRow;
	boolean stopFlag = false;
	String instruction;			// The Opcode (MOV, ADD, etc)

	if (traceOn) System.out.println("\nRunning Summation(10) with trace enabled:"); /* Set to Summation when running Summation function*/
	else System.out.println("\nRunning Summation(10) without trace:"); /* Set to Summation when running Summation function*/

	while (pc < MAXQUAD) {
		String pcPadded = String.format("%03d", pc);
		if (traceOn) System.out.printf("\nPC = %s:", pcPadded);

		quadRow = (Q.GetQuad(pc));
		int q1, q2, q3;
	
		for (int i = 0; i < quadRow.length; i++) {  // Loop through the current quadcode row 
			instruction = Q.GetMnemonic(quadRow[i], ResTbl);
    
			if (i == 0) {
				if (traceOn) System.out.print(" " + instruction + "\t"); // Print the Opcode
				if (traceOn) System.out.print(quadRow[1] + "\s" + quadRow[2] + "\s" + quadRow[3]);	
			
				q1 = quadRow[1];	// Assign each element in the row to a variable for greater readability
				q2 = quadRow[2];	
				q3 = quadRow[3];
    		
				// Instructions for instructions
				switch (instruction) {
			
				// TERMINATE
				case "STOP":			// If STOP call is found, halt the while loop after printing the remaining 0 0 0 opcodes
					stopFlag = true; 
					break;
			
					// MATH
				case "DIV": // Compute op1 / op2, place result into op3
					S.UpdateSymbol(q1, 0, S.GetSymbol(q2).getIntValue() / S.GetSymbol(q1).getIntValue());	
					if (traceOn) printMath(q1, S);
					break;
				case "MUL": // Compute op1 * op2, place result into op3
					S.UpdateSymbol(q1, 0, S.GetSymbol(q2).getIntValue() * S.GetSymbol(q1).getIntValue());	
					if (traceOn) printMath(q1, S);
					break;
				case "SUB": // Compute op1 - op2, place result into op3
					S.UpdateSymbol(q3, 0, S.GetSymbol(q1).getIntValue() - S.GetSymbol(q2).getIntValue());
					if (traceOn) printMath(q3,S);
					break;
				case "ADD": // Compute op1 + op2, place result into op3											
					S.UpdateSymbol(q1, 0, S.GetSymbol(q2).getIntValue() + S.GetSymbol(q3).getIntValue());
					if (traceOn) printMath(q1, S);
					break;

				// DATA STORAGE
				case "MOV": // Copy op1 into op3						
					S.UpdateSymbol(q3, 0, S.GetSymbol(q1).getIntValue());
					if (traceOn) printMov(q3, S);
					break;
				case "STI": // Copy op1 into op2 + offset op3						
					S.UpdateSymbol(q1, 0, S.GetSymbol(q2 + q3).getIntValue());
					break;
				case "LDI": // Copy op1 + offset op2 into op3						
					S.UpdateSymbol(q3, 0, S.GetSymbol(q1 + q2).getIntValue());
					break;
			
				// BRANCH INSTRUCTIONS
				case "BNZ": // if op1 not 0, pc = op3
					if (S.GetSymbol(q1).getIntValue() != 0) 
						pc = q3 - 1;
					break;
				case "BNP": // if op1 less or equal to 0, pc = op3
					if (S.GetSymbol(q1).getIntValue() <= 0) 
						pc = q3 - 1;
					break;
				case "BNN": // if op1 greater or equal to 0, pc = op3
					if (S.GetSymbol(q1).getIntValue() >= 0) 
						pc = q3 - 1;
					break;
				case "BZ": // if op1 is 0, pc = op3
					if (S.GetSymbol(q1).getIntValue() == 0) 
						pc = q3 - 1;
					break;
				case "BP": // if op1 is greater than 0, pc = op3
					if (S.GetSymbol(q1).getIntValue() > 0) 
						pc = q3 - 1;
					break;
				case "BN": // If op1 < 0, set program counter equal to op3
					if (S.GetSymbol(q1).getIntValue() < 0) {
						if (traceOn) System.out.print("\t-----> " + S.GetSymbol(q1).getIntValue() + " < 0, branch to pc " + q3);
						pc = q3 - 1;
					}
					else
						if (traceOn) System.out.print("\t-----> " + S.GetSymbol(q1).getIntValue() + " not < 0, continue");
					break;
				case "BR": // Set program counter equal to op3
					if (traceOn) System.out.print("\t-----> Unconditional Branch, setting pc to " + q3);
					pc = q3 - 1;
					break;
	
				// UTILITY
				case "PRINT": // Write Symbol Table name and value of op1		
					if (traceOn) System.out.print("\t****** Summation is " + S.GetSymbol(q3).getIntValue() + " ******");
					else System.out.println("Summation is " + S.GetSymbol(q3).getIntValue());
					break;
	
				default:
					break;
				} // case
			} // if i == 0
	    } // for
    
		if (stopFlag == true)
			break;
	    pc += 1;
	} // while
	
	if (traceOn) System.out.print("\t-----> Program Terminated\n\n");
}  

public static void BuildQuads(ReserveTable ResTbl, QuadTable Q) {

	//Populate Reserve Table
	ResTbl.Add("STOP", 0);   ResTbl.Add("DIV", 1); ResTbl.Add("MUL", 2); ResTbl.Add("SUB", 3); ResTbl.Add("ADD", 4);
	ResTbl.Add("MOV", 5);    ResTbl.Add("STI", 6); ResTbl.Add("LDI", 7); ResTbl.Add("BNZ", 8); ResTbl.Add("BNP", 9);
	ResTbl.Add("BNN", 10);   ResTbl.Add("BZ", 11); ResTbl.Add("BP", 12); ResTbl.Add("BN", 13); ResTbl.Add("BR", 14);
	ResTbl.Add("BINDR", 15); ResTbl.Add("PRINT", 16);
	
	ResTbl.PrintReserveTable();
	
	//Populate Quad Table
	int quadTableSize = 11;
	Q.Initialize(quadTableSize, ResTbl); // create QuadTable with <size> rows
	
	Q.AddQuad(5, 4, 0, 0, Q.NextQuad());
	Q.AddQuad(5, 5, 0, 1, Q.NextQuad());
	Q.AddQuad(5, 5, 0, 2, Q.NextQuad());
	Q.AddQuad(3, 0, 2, 6, Q.NextQuad());
	Q.AddQuad(13, 6, 0, 8, Q.NextQuad()); 
	Q.AddQuad(2, 1, 2, 1, Q.NextQuad());   /* Set first value to 2 (MUL) for Factorial, 4 (ADD) for Summation*/
	Q.AddQuad(4, 2, 5, 2, Q.NextQuad());
	Q.AddQuad(14, 0, 0, 3, Q.NextQuad());
	Q.AddQuad(5, 1, 0, 3, Q.NextQuad()); 
	//Q.AddQuad(3, 3, 5, 3, Q.NextQuad()); /* Subtract 1 from final result for Summation*/
	Q.AddQuad(16, 0, 0, 3, Q.NextQuad());  
	Q.AddQuad(0, 0, 0, 0, Q.NextQuad());
	
	Q.PrintQuadTable(ResTbl);
}

public static void BuildSymbolTable(SymbolTable S) {
	
	S.AddSymbol("n", 1, 0);
	S.AddSymbol("prod", 1, 0);		
	S.AddSymbol("count", 1, 0);		
	S.AddSymbol("fact", 1, 0);
	S.AddSymbol("10", 1, 10);			/* Change this value to set n */
	S.AddSymbol("1", 1, 1);				
	S.AddSymbol("temp", 1, 0); 			
	S.AddSymbol("sub", 1, 2); 			/* Exists to determine correct value of Summation*/
	
	S.PrintSymbolTable();
}

//printMath and other print<Foo> functions are called if traceOn is true,
//and exist to keep the interpreter free of excess clutter
public static void printMath(int q1, SymbolTable S) {
System.out.print("\t-----> " + S.GetSymbol(q1).getName() + " set to " + S.symbList.get(q1).getIntValue());
}

public static void printMov(int q3, SymbolTable S) {
System.out.print("\t-----> " + S.GetSymbol(q3).getName() + " set to " + S.symbList.get(q3).getIntValue());
}	

//////////
// MAIN //
//////////
	// TODO
	public static void main(String[] args) {
	
		boolean traceOn = true;
		
		// Create a Reserve Table, Symbol Table, and Quad Table
		ReserveTable ResTbl = new ReserveTable();
		QuadTable Q = new QuadTable();
		SymbolTable S = new SymbolTable();
		
		BuildSymbolTable(S); // Allocate Symbols to the SymbolTable and print them
		
		BuildQuads(ResTbl, Q); // Build the QuadTable and print it
		
		// Run the interpreter with traceOn, showing step-by-step instructions
		InterpretQuads(Q, ResTbl, S, traceOn);

		// Run the interpreter without traceOn, only printing the final output
		InterpretQuads(Q, ResTbl, S, traceOn = false);
		
		System.out.println("\n\n");
		NewQuadTable Q_Tbl = new NewQuadTable();
		
		Q_Tbl.AddQuad(1,2,3,4);
		Q_Tbl.AddQuad(5,4,3,2);
		
		System.out.println("Arraylist contains "
		+ Q_Tbl.quadArr.size()
		+ " quadcodes");
		
		System.out.println("Printing Quads in quadtable");
        Q_Tbl.PrintQuad();
        
	} // main
} // Compilers_v3

