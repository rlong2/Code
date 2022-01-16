/* Ryan Long
 * 11/24/2020
 * CS 4100 - Compilers taught by Albert Brouillette
 * Compilers Project Part 4: Code Generation
 * 
 * This program generates code.
 * 
 * *****************************************************
 *                NAVIGATION:                          *
 *                                                     *
 * *****************************************************
 */

import java.io.*;
import java.util.*;

/////////////
// Classes //
/////////////

// class G holds global variables with getters and setters
class G {
	
	// Global ReserveTable
	private static ReserveTable R = new ReserveTable();
	public static ReserveTable GetR() { return R; }
	public static void SetR(ReserveTable r) { R = r; }
	
	// Global Symbol Table
	private static SymbolTable S = new SymbolTable();
	public static SymbolTable GetS() { return S; }
	public static void SetS(SymbolTable s) { S = s; }
	
	// Global Quad Table
	private static NewQuadTable Q = new NewQuadTable();
	public static NewQuadTable GetQ() { return Q; }
	public static void SetQ(NewQuadTable q) { Q = q; }
	
	// verbose prints token and lexeme through GetNextToken function if set to true
	private static boolean verbose;			
	public static boolean getVerbose() { return verbose; }
	public static void setVerbose(boolean value) { verbose = value; }
	
	// echoOn prints token and lexeme information
	private static boolean echoOn;			
	public static boolean getEchoOn() { return echoOn; }
	public static void setEchoOn(boolean value) { echoOn = value; }
	
	// myFile points to the file to read from
	private static File myFile;
	public static File GetMyFile() { return myFile; }
	public static void SetMyFile(String filename) { 
		myFile = new File(filename);
	} 
	
	// Global scanner 
	private static Scanner scanner;	
	public static Scanner GetScanner() { return scanner; }
	public static void SetScanner(File filename) throws FileNotFoundException { 
		
		System.out.println("Running Code Generation on " + G.GetMyFile());
		System.out.println("----------------------------------------------------------------------");
		
		// Display header for Lexeme, token code, etc
		System.out.printf("%-30s %2s %10s %12s %n", "Lexeme", "Token Code", "Mnemonic", "ST Index");
		System.out.println("----------------------------------------------------------------------");
		scanner = new Scanner(G.GetMyFile());
	} 
	
	// Get line
	private static String line;
	public static String GetLine() { return line; }
	public static void SetLine(String str) { line = str; }
	
	// Get line number
	private static int lineCount = 0;
	public static int GetLineCount() { return lineCount; }
	public static void SetLineCount(int count) { lineCount = count; }
	
	// tracking char indexes
	private static int globI = 0;
	public static int GetGI() { return globI; }
	public static void SetGI(int index) { globI = index; }
	
	// Global token 
	private static String token = "init";
	public static String GetToken() { return token; }
	public static void SetToken(String t) { token = t; }
	
	// Global token code
	private static int tokenCode = 0;
	public static int GetCode() { return tokenCode; }
	public static void SetCode(int code) { tokenCode = code; }
	
	// prevCh tracks the previous char when iterating through a string
	private static char prevCh = '\0';
	public static char GetPrevCh() { return prevCh; }
	public static void SetPrevCh(char pch) { prevCh = pch; }
	
	// usePrev does not iterate past current char if set to true
	private static boolean usePrev = false;		
	public static boolean GetUsePrev() { return usePrev; }
	public static void SetUsePrev(boolean value) { usePrev = value; }
	
	// foundLabel is true if the current token is $LABEL
	private static boolean foundLabel = false;		
	public static boolean GetFoundLabel() { return foundLabel; }
	public static void SetFoundLabel(boolean value) { foundLabel = value; }
	
	// foundError is true if the compiler catches an error.
	// This variable is used with Resync() 
	private static boolean foundError = false;		
	public static boolean GetFoundError() { return foundError; }
	public static void SetFoundError(boolean value) { foundError = value; }
	
	// compiledWithoutError informs the user if the program compiled with or without errors
	private static boolean compiledWithoutError = true;		
	public static boolean GetCompWithoutError() { return compiledWithoutError; }
	public static void SetCompWithoutError(boolean value) { compiledWithoutError = value; }
	
	// Tells nonterminal methods if we are syncing up with proper non-terminal
	private static boolean resyncing = false;		
	public static boolean GetResyncing() { return resyncing; }
	public static void SetResyncing(boolean value) { resyncing = value; }
	
	// inBlockBody is used to see if variables have been declared before entering into block body
	private static boolean inBlockBody = false;		
	public static boolean GetInBlockBody() { return inBlockBody; }
	public static void SetInBlockBody(boolean value) { inBlockBody = value; }
	
	// doNotPrint is used to suppress output of invalid tokens when Resync() finds them.
	private static boolean doNotPrint = false;
	public static boolean GetDoNotPrint() { return doNotPrint; }
	public static void SetDoNotPrint(boolean value) { doNotPrint = value; }
	
	// Tracks if end of file has been reached
	private static boolean EndOfFile = false;
	public static boolean GetEnd() { return EndOfFile; }
	public static void SetEnd(boolean value) { EndOfFile = value; }

} // G

// NewQuadTable adds functionality for adding quads, printing quads, etc
class NewQuadTable {
	  
	  static List<int[]> quadArr = new ArrayList<>();

	  public void AddQuad(int opcode, int op1, int op2, int op3) {
	      //System.out.println("adding quad...");
	      quadArr.add(new int[] {opcode, op1, op2, op3});
	  }
	  
	  //Returns the data for the opcode and three operands located at index
		public static int[] GetQuad(int index) {
			return quadArr.get(index);	
		}
		
	   public void PrintQuads() {
		   System.out.println("======== Quad Table contents ========");
		   System.out.println("Opcode | op1  | op2 |  op3");
		   System.out.println("--------------------------");
	    	
	       for (int[] arr : quadArr) {
	    	   int j = 0;
	           for(int i = 0; i < arr.length; i++) {
	        	   if (j == 0 || j % 4 == 0) {
	        		   System.out.print(G.GetR().LookupQuad(arr[i]) + "\t"); // prints "MOV", etc
	        	   } else {
	        		   System.out.print(arr[i] + "\t");					  // prints 5,3, etc
	        	   }
	        	   j++;
	            }
	            System.out.println();
	        }
	    }
	   
	    public void InterpretQuads() {
			int pc = 0;
            int[] quadRow;
        	boolean stopFlag = false;
        	String instruction;			// The Opcode (MOV, ADD, etc)
		   
		   System.out.println("\nRunning Program...");
		   
		   while (pc < quadArr.size()) {
			   String pcPadded = String.format("%03d", pc);
			   System.out.printf("PC = %s:", pcPadded);
			   
			   quadRow = G.GetQ().GetQuad(pc);
			   int q1, q2, q3;
			   
			   for (int i = 0; i < quadRow.length; i++) {  // Loop through the current quadcode row 
					instruction = G.GetR().LookupQuad(quadRow[i]);
					
					if (i == 0) {
						System.out.print(" " + instruction + "\t"); // Print the Opcode
						System.out.print(quadRow[1] + "\t" + quadRow[2] + "\t" + quadRow[3]);	
					
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
						case "DIV": // Compute op1 value / op2 value, place result into op3 value
							System.out.println("\t----> set symbol '" + G.GetS().symbList.get(q3).getName() +
							           "' value to " + G.GetS().LookupIndex(q1) + " / " + G.GetS().LookupIndex(q2));
										G.GetS().symbList.get(q3).setIntValue(G.GetS().LookupIndex(q1) / G.GetS().LookupIndex(q2));
							break;
						case "MUL": // Compute op1 * op2, place result into op3
							System.out.println("\t----> set symbol '" + G.GetS().symbList.get(q3).getName() +
							           "' value to " + G.GetS().LookupIndex(q1) + " * " + G.GetS().LookupIndex(q2));
										G.GetS().symbList.get(q3).setIntValue(G.GetS().LookupIndex(q1) * G.GetS().LookupIndex(q2));
							break;
						case "SUB": // Compute op1 - op2, place result into op3
							System.out.println("\t----> set symbol '" + G.GetS().symbList.get(q3).getName() +
							           "' value to " + G.GetS().LookupIndex(q1) + " - " + G.GetS().LookupIndex(q2));
										G.GetS().symbList.get(q3).setIntValue(G.GetS().LookupIndex(q1) - G.GetS().LookupIndex(q2));
							break;
						case "ADD": // Compute op1 + op2, place result into op3											
							System.out.println("\t----> set symbol '" + G.GetS().symbList.get(q3).getName() +
					           "' value to " + G.GetS().LookupIndex(q1) + " + " + G.GetS().LookupIndex(q2));
								G.GetS().symbList.get(q3).setIntValue(G.GetS().LookupIndex(q1) + G.GetS().LookupIndex(q2));
							break;
					/*
						// DATA STORAGE
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
								System.out.print("\t-----> " + S.GetSymbol(q1).getIntValue() + " < 0, branch to pc " + q3);
								pc = q3 - 1;
							}
							else
								System.out.print("\t-----> " + S.GetSymbol(q1).getIntValue() + " not < 0, continue");
							break;
						case "BR": // Set program counter equal to op3
							System.out.print("\t-----> Unconditional Branch, setting pc to " + q3);
							pc = q3 - 1;
							break;
			
						// UTILITY
						case "PRINT": // Write Symbol Table name and value of op1		
							System.out.println("Summation is " + S.GetSymbol(q3).getIntValue());
							break;
			*/
						case "MOV": // Copy op1 into op3
							System.out.println("\t----> set symbol '" + G.GetS().symbList.get(q1).getName() +
									           "' value to " + G.GetS().LookupIndex(q3));
							G.GetS().symbList.get(q1).setIntValue(G.GetS().LookupIndex(q3));
							break;
							
						default:
							break;
						} // case
					} // if i == 0
			   } // for
			   
			   pc += 1;
		   } // while
		   
		   System.out.print("\t-----> No more quads to interpret, Program Terminated\n\n");
		   
	   } // InterpretQuads
} // NewQuadTable

// ReserveTable holds a list of reserved words for the language (case independent).
// As tokens are retrieved, the ReserveTable is checked to see if the token resides there.
// If it does, the token is assigned the corresponding token code.
class ReserveTable {

	HashMap<Integer, String> resWord;
	HashMap<Integer, String> otherTokens;
	HashMap<Integer, String> mnemonics;
	HashMap<Integer, String> quadTbl;

	public ReserveTable() {

		// resWords holds PL20 reserved words for the language.
		// otherTokens holds other important tokens for the language, mostly operators
		// mnemonics holds token codes and corresponding 4-char mnemonics
		// TODO: quadTbl holds the values corresponding to instructions (5 is MOV, etc)
		resWord = new HashMap<Integer, String>();
		otherTokens = new HashMap<Integer, String>();
		mnemonics = new HashMap<Integer, String>();
		quadTbl = new HashMap<Integer, String>();

		 resWord.put(0, "GOTO"); resWord.put(1, "INTEGER"); resWord.put(2, "TO");
		 resWord.put(3, "DO"); resWord.put(4, "IF"); resWord.put(5, "THEN");
		 resWord.put(6, "ELSE"); resWord.put(7, "FOR"); resWord.put(8, "OF");
		 resWord.put(9, "WRITELN"); resWord.put(10, "READLN"); resWord.put(11, "BEGIN");
		 resWord.put(12, "END"); resWord.put(13, "VAR"); resWord.put(14, "WHILE");
		 resWord.put(15, "UNIT"); resWord.put(16, "LABEL"); resWord.put(17, "REPEAT");
		 resWord.put(18, "UNTIL"); resWord.put(19, "PROCEDURE"); resWord.put(20, "DOWNTO");
		 resWord.put(21, "FUNCTION"); resWord.put(22, "RETURN"); resWord.put(23, "REAL");
		 resWord.put(24, "STRING"); resWord.put(25, "ARRAY"); resWord.put(99, "UNKN");
		
		 otherTokens.put(30, "/"); otherTokens.put(31, "*"); otherTokens.put(32, "+");
		 otherTokens.put(33, "-"); otherTokens.put(34, "("); otherTokens.put(35, ")");
		 otherTokens.put(36, ";"); otherTokens.put(37, ":="); otherTokens.put(38, ">");
		 otherTokens.put(39, "<"); otherTokens.put(40, ">="); otherTokens.put(41, "<=");
		 otherTokens.put(42, "="); otherTokens.put(43, "<>"); otherTokens.put(44, ",");
		 otherTokens.put(45, "["); otherTokens.put(46, "]"); otherTokens.put(47, ":");
		 otherTokens.put(48, ".");  otherTokens.put(99, "UNKN");
		 
		 mnemonics.put(0, "GOTO");  mnemonics.put(1, "INTR");  mnemonics.put(2, "TO  ");
		 mnemonics.put(3, "DO  ");  mnemonics.put(4, "IF  ");  mnemonics.put(5, "THEN");
		 mnemonics.put(6, "ELSE");  mnemonics.put(7, "FOR ");  mnemonics.put(8, "OF  ");
		 mnemonics.put(9, "WTLN");  mnemonics.put(10, "RDLN"); mnemonics.put(11, "BGIN");
		 mnemonics.put(12, "END "); mnemonics.put(13, "VAR "); mnemonics.put(14, "WHIL");
		 mnemonics.put(15, "UNIT"); mnemonics.put(16, "LABL"); mnemonics.put(17, "REPT");
		 mnemonics.put(18, "UNTL"); mnemonics.put(19, "PROC"); mnemonics.put(20, "DNTO");
		 mnemonics.put(21, "FUNC"); mnemonics.put(22, "RTRN"); mnemonics.put(23, "REAL");
		 mnemonics.put(24, "STRG"); mnemonics.put(25, "ARAY");
		
		 mnemonics.put(30, "DIV "); mnemonics.put(31, "MUL "); mnemonics.put(32, "PLUS");
		 mnemonics.put(33, "MINU"); mnemonics.put(34, "LPRN"); mnemonics.put(35, "RPRN");
		 mnemonics.put(36, "SEMI"); mnemonics.put(37, "ASGN"); mnemonics.put(38, "GTR ");
		 mnemonics.put(39, "LESS"); mnemonics.put(40, "GTRE"); mnemonics.put(41, "LESE");
		 mnemonics.put(42, "EQL "); mnemonics.put(43, "LTGT"); mnemonics.put(44, "COMA");
		 mnemonics.put(45, "LBKT"); mnemonics.put(46, "RBKT"); mnemonics.put(47, "COLN");
		 mnemonics.put(48, "PERD");  		
		 
		 mnemonics.put(50, "IDEN"); mnemonics.put(51, "INT "); mnemonics.put(52, "FLOT");
		 mnemonics.put(53, "STRI"); mnemonics.put(99, "UNKN"); 
		 
		 quadTbl.put(0, "STOP");   quadTbl.put(1, "DIV");    quadTbl.put(2, "MUL"); quadTbl.put(3, "SUB"); quadTbl.put(4, "ADD");
		 quadTbl.put(5, "MOV");    quadTbl.put(6, "STI");    quadTbl.put(7, "LDI"); quadTbl.put(8, "BNZ"); quadTbl.put(9, "BNP");
		 quadTbl.put(10, "BNN");   quadTbl.put(11, "BZ");    quadTbl.put(12, "BP"); quadTbl.put(13, "BN"); quadTbl.put(14, "BR");
		 quadTbl.put(15, "BINDR"); quadTbl.put(16, "PRINT");
	}
	
	// LookupIdentifierName checks if the Identifier token exists as a reserve word in the Reserve Table.
	// If the token exists in the table, the token code is returned.
	// If the token does not exist in the table, token code 50 is returned to designate an Identifier.
	public int LookupIdentifierName(String name) {
		Set<Map.Entry<Integer, String>> entries = resWord.entrySet();
		Iterator<Map.Entry<Integer, String>> itr = entries.iterator();
		Map.Entry<Integer, String> entry = null;
		while (itr.hasNext()) {
			entry = itr.next();
			if (name.equalsIgnoreCase(entry.getValue())) {
				return entry.getKey();
			}
		}
		return 50;
	}
	
	// LookupOtherName checks if the token exists as an 'other token' in the otherToken Reserve Table.
	// If the token does not exist in the table, token code 99 is returned to designate it as 'Unknown'.
	public int LookupOtherName(String name) {
		Set<Map.Entry<Integer, String>> entries = otherTokens.entrySet();
		Iterator<Map.Entry<Integer, String>> itr = entries.iterator();
		Map.Entry<Integer, String> entry = null;
		while (itr.hasNext()) {
			entry = itr.next();
			if (name.equalsIgnoreCase(entry.getValue())) {
				return entry.getKey();
			}
		}
		return 99;
	}
	
	// LookupMnemonic finds the corresponding mnemonic for the given token code.
	// If the token code is not found, the mnemonic 'UNKN' is returned.
	public String LookupMnemonic(int tokenCode) {
		Set<Map.Entry<Integer, String>> entries = mnemonics.entrySet();
		Iterator<Map.Entry<Integer, String>> itr = entries.iterator();
		Map.Entry<Integer, String> entry = null;
		while (itr.hasNext()) {
			entry = itr.next();
			if (tokenCode == entry.getKey()) {
				return entry.getValue();
			}
		}
		return "UNKN";
	}
	
	// LookupQuad returns the correct value for a key. ie, 5 finds "MOV"
	public String LookupQuad(int tokenCode) {
		Set<Map.Entry<Integer, String>> entries = quadTbl.entrySet();
		Iterator<Map.Entry<Integer, String>> itr = entries.iterator();
		Map.Entry<Integer, String> entry = null;
		while (itr.hasNext()) {
			entry = itr.next();
			if (tokenCode == entry.getKey()) {
				return entry.getValue();
			}
		}
		return "UNKN";
	}
	
	// LookupQuadInt returns the correct key from a value. ie, "MOV" returns 5
	public int LookupQuadInt(String code) {
		Set<Map.Entry<Integer, String>> entries = quadTbl.entrySet();
		Iterator<Map.Entry<Integer, String>> itr = entries.iterator();
		Map.Entry<Integer, String> entry = null;
		while (itr.hasNext()) {
			entry = itr.next();
			if (code == entry.getValue()) {
				return entry.getKey();
			}
		}
		return -1;
	}
	
	// Look up token code given a mnemonic
	public int LookupTokenCode(String name) {
		Set<Map.Entry<Integer, String>> entries = mnemonics.entrySet();
		Iterator<Map.Entry<Integer, String>> itr = entries.iterator();
		Map.Entry<Integer, String> entry = null;
		while (itr.hasNext()) {
			entry = itr.next();
			if (name.equalsIgnoreCase(entry.getValue())) {
				return entry.getKey();
			}
		}
		return 99;
	}
	
/*	public void PrintReserveTable() {
		
		System.out.println("\n======== Reserve Table Contents for Quads ========");
		Set<Map.Entry<Integer, String>> entries = quadTbl.entrySet();
		Iterator<Map.Entry<Integer, String>> itr = entries.iterator();
		Map.Entry<Integer, String> entry = null;
		while (itr.hasNext()) {
			entry = itr.next();
			System.out.println(entry.getKey() + "\t" + entry.getValue());
		}
		System.out.println();
	}
	*/
}

// SymbolTable holds Symbol objects in an ArrayList. 
//If a token is an identifier (but not a reserved word)
// or the token is a number, it is added to the Symbol Table.
class SymbolTable {
	
	ArrayList<Symbol> symbList = new ArrayList<Symbol>();
	
	// Constructor to form an empty SymbolTable
	public SymbolTable() {}
	
	// AddSymbol adds a Symbol to the SymbolTable. One of these three Add functions
	// is called depending on the type of Symbol's value (String, integer, or float)
	public int AddSymbol(String symbol, String kind, int type, String value) {
		symbList.add(new Symbol(symbol, kind, type, value));
		return symbList.size() - 1;
	}
	public int AddSymbol(String symbol, String kind, int type, int value) {
		symbList.add(new Symbol(symbol, kind, type, value));
		return symbList.size() - 1;
	}
	public int AddSymbol(String symbol, String kind, int type, double value) {
		symbList.add(new Symbol(symbol, kind, type, value));
		return symbList.size() - 1;
	}
	
	// LookupSymbol is used to output the return index of symbol table if it exists, else -1 is returned.
	public int LookupSymbol(String symbol) {
		for (int i = 0; i < symbList.size(); i++) {
			if (symbList.get(i).getName().equals(symbol))
				return i;
		}
		return -1;
	}
	
	// TODO:
	// Get value of val at given index
	public int LookupIndex(int index) {
		return symbList.get(index).getIntValue();
	}
	
	public void UpdateValue(int left, int right) {
		
		// if int
		G.GetS().symbList.get(left).setIntValue(G.GetS().LookupIndex(right));
		
		// if double
		//G.GetS().symbList.get(left).setDoubleValue(G.GetS().LookupIndex(right));
	}

	
	// IsLabel says if symbol is a LABEL (true) or VAR (false)
	public boolean IsLabel(String symbol) {
		for (int i = 0; i < symbList.size(); i++) {
			String uppserSymbol = symbol.toUpperCase();
			if (symbList.get(i).getName().toUpperCase().equals(uppserSymbol)) {
				if (symbList.get(i).getKind() == "Label" | 
					symbList.get(i).getKind() == "Lused") {
					return true;
				}
			}
		}
		return false;
	}
	
	// InSymbolTable returns true if the token lexeme is already in the symbol table.
	// This avoids duplicate entries in the Symbol Table.
	public boolean InSymbolTable(String symbol) {
		for (int i = 0; i < symbList.size(); i++) {
			String upperSymbol = symbol.toUpperCase();
			if (symbList.get(i).getName().toUpperCase().equals(upperSymbol)) {

				if (symbList.get(i).getKind().contains("Label")) {
					System.out.println(symbList.get(i).getName() + " is " + symbList.get(i).getKind());
					symbList.get(i).setKind("Lused");
				}
				return true;
			}
		}
		return false;
	}
	
	// This function finds and flags unused labels before exiting the program
	public void FlagUnusedLabels() {
		for (int i = 0; i < symbList.size(); i++) {
			
			String symb = symbList.get(i).getName();
			
			if (symbList.get(i).getKind().contains("Label")) {
				System.out.println("\n~~~ Warning! " + symb + " is an unused label! ~~~");
			}
		}
	}
	
	// PrintSymbolTable prints the Symbol Table in neat columns,
	// displaying the token's lexeme, kind, type, and value.
	public void PrintSymbolTable() {
		System.out.println("\n\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		System.out.println("|                                 Symbol Table                                       |");       
		System.out.println(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		System.out.printf("%-30s %-12s %-11s %s %n", "Lexeme", "Kind", "Type", "Value                        |");
		System.out.println("-------------------------------------------------------------------------------------");
		
		// Iterate over each item in the Symbol Table and call Symbol's overloaded toString method.
		for (int i = 0; i < symbList.size(); i++) {
			System.out.println(symbList.get(i)); 
		}
		System.out.println("-------------------------------------------------------------------------------------");
	}
	
	public int LookupStIndex(String token) {
		
		for (int i = 0; i < G.GetS().symbList.size(); i++) {
			if (token.equalsIgnoreCase(G.GetS().symbList.get(i).getName())) {
				//System.out.println("token " + token + " is at index " + i);
				return i;
			}
		}
		System.out.println("token " + token + " not found in Symbol Table, returning -1");
		return -1;
	}
}

// Symbol class creates Symbol objects that essentially act as memory for the computer.
// Tokens belong in the Symbol Table if (a) the token is an identifier but not a reserved word,
// (b) the token is a numeric constant (integer or float).
class Symbol {
	private String name;		// lexeme (token name)
	private String kind;		// LABEL, VARIABLE or CONST
	private int type;			// int, float, or string
	private String stringValue;	// value for String type
	private int intValue;		// value for int type
	private double doubleValue;	// value for double type
	
	// Each Symbol's value can be either a String, int, or double,
	// so each possibility has a constructor.
	public Symbol(String name, String kind, int type, String value) {		// String value
		this.name = name;
		this.kind = kind;
		this.type = type;
		stringValue = value;
	}
	
	public Symbol(String name, String kind, int type, int value) { 		// int value
		this.name = name;
		this.kind = kind;
		this.type = type;
		intValue = value;
	}
	
	public Symbol(String name, String kind, int type, double value) {		// double value
		this.name = name;
		this.kind = kind;
		this.type = type;
		doubleValue = value;
	}
	
	// Getters
	public String getName() { return name; }
	public String getKind() { return kind; }
	public int getType() { return type; }
	public String getStringValue() { return stringValue; }
	public int getIntValue() { return intValue; }
	public double getDoubleValue() { return doubleValue; }
	
	// Setters
	public void setKind(String kind) { this.kind = kind; }
	public void setType(int type) { this.type = type; }
	public void setStringValue(String value) { stringValue = value; }
	public void setIntValue(int value) { intValue = value; }
	public void setDoubleValue(double value) { doubleValue = value; }
	
	@Override
	public String toString() {
		
		/* Type 0 means String value (for VAR Identifier)
		 * Type 1 means int value    (for CONST int)
		 * Type 2 means doublevalue  (for CONST double)
		 * Type 3 means String value (for CONST String)
		 * 
		 * Kind 0 means VAR
		 * Kind 1 means CONST
		 * Kind 2 means LABEL
		 */
		
		String str = new String();
		int padding = 85;
		
		// TODO: fix printing of values
		switch(type) {
		case 0:
			str = String.format("%" + -30 + "s", name);
			str += String.format("%" + 5 + "s", kind);
			str += String.format("%" + 14 + "s", "STRING");
			str += String.format("%" + 8 + "s", intValue);
			str = String.format("%1$-" + padding + "s", str);
			str += "|";
			return str;
		case 1:
			str = String.format("%" + -30 + "s", name);
			str += String.format("%" + 5 + "s", kind);
			str += String.format("%" + 11 + "s", "INT");
			str += "          " + intValue;
			str = String.format("%1$-" + padding + "s", str);
			str += "|";
			return str; 
		case 2:
			str = String.format("%" + -30 + "s", name);
			str += String.format("%" + 5 + "s", kind);
			str += String.format("%" + 13 + "s", "FLOAT");
			str += "        " + doubleValue;
			str = String.format("%1$-" + padding + "s", str);
			str += "|";
			return str; 
		case 3:
			str = String.format("%" + -30 + "s", name);
			str += String.format("%" + 5 + "s", kind);
			str += String.format("%" + 14 + "s", "STRING");
			str += "       " + stringValue;
			str = String.format("%1$-" + padding + "s", str);
			str += "|";
			return str; 
		default:
			return "DNE";
		}
	}
} // Symbol

public class Pt_4 {

//////////////
//Functions //
//////////////

// GetNextChar feeds chars to GetNextToken so tokens can be assembled. 
// GetNext char gets Strings from GetNextLine.
// A global index is used to determine where in the line the GetNextToken function has reached.
// If the end of the current line has been reached, GetNextChar calls GetNextLine and the index is set to 0.
// If the current line still needs to be parsed for tokens, index tracks the characters.
public static char GetNextChar() {
	 if (G.GetGI() == 0) {				 		// Start of line
		 G.SetLine(GetNextLine());

		 if (G.GetLine().isEmpty()) {		 	// Blank line
			 return '\0';
		 }
		 int tempI = G.GetGI();
		 G.SetGI(G.GetGI() + 1); 				// Increment globI by 1
		 return G.GetLine().charAt(tempI);
	 }
	 else if (G.GetGI() == G.GetLine().length()) {	// End of the line has been reached
		 G.SetGI(0);
		 return 0;
	 }
	 else if (G.GetGI() > 0) {					// Current line still needs to be parsed for tokens
			 int tempI = G.GetGI();
			 G.SetGI(G.GetGI() + 1);
			 return G.GetLine().charAt(tempI);
	 }
	 else {										// Default: continue to parse current line	
		 return G.GetLine().charAt(G.GetGI());		
	 }
}

// GetNextLine gets the next line in the file and feeds it to GetNextChar as a String.
// If echoOn is true, the line is printed before being parsed into tokens.
public static String GetNextLine() {	
	if (G.GetEnd())
		return "";
	
	// Nicely display line contents
	G.SetLineCount(G.GetLineCount() + 1);
	if (G.GetLineCount() > 1)
		System.out.println();
	
	G.SetLine(G.GetScanner().nextLine());
	
	if (G.getEchoOn()) {		// If echoOn is true, print the line
		System.out.println("Line " + G.GetLineCount() + ": " + G.GetLine());
	}

	// End of file is reached. GetNextChar will parse the remaining String and exit
	if (G.GetScanner().hasNext() == false)
		G.SetEnd(true);
	return G.GetLine();
}

// GetNextToken calls GetNextChar repeatedly until a token is built.
public static String GetNextToken() {

	int maxIdenLength = 30;
	int maxNumLength = 16;
	
	// Create a new token, set initial value to an empty string
	G.SetToken("");
	
	char ch = '\0';
	
	while (G.GetToken() != null) {
		
		if (G.GetGI() > 0 && G.GetUsePrev() == true) {	// Use the previous token and reset boolean usePrev
			G.SetGI(G.GetGI() - 1);						// Decrement globI by 1
			G.SetUsePrev(false);
		}
		
		ch = GetNextChar(); 
		
	   while (Character.isWhitespace(ch)) {			// Eat whitespace
		   ch = GetNextChar(); 
	   }
	   if (Character.isLetter(ch)) {				// Create an Identifier Token
		   G.SetCode(50);
			
			while (Character.isLetterOrDigit(ch)
					|| ch == '_'
					|| ch == '$') {
				G.SetToken(G.GetToken() + ch);
				G.SetPrevCh(ch);
				ch = GetNextChar();
				if (!Character.isLetterOrDigit(ch)) {	//ch not letter or digit. Grab previous token and return it
					G.SetUsePrev(true);;
				}
			}
			if (G.GetToken().length() > maxIdenLength) {
				G.SetToken(G.GetToken().substring(0, 30));
				System.out.println("~~~ Warning, token exceeds length " + maxIdenLength 
						           + "! The token has been truncated. ~~~");
			}
			
			// If the token is a reserved word, PrintToken prints the token code and it does not go in symbol table
			if (G.GetCode() == 50 && G.GetR().LookupIdentifierName(G.GetToken()) != 50) { // match in ReserveTable
				G.SetCode(G.GetR().LookupIdentifierName(G.GetToken()));
			} else {
				
				// If the lexeme is not in the symbol table, add it
				if (G.GetS().InSymbolTable(G.GetToken()) == false) {
					
					if (G.GetInBlockBody() == true) {
						System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
						System.out.println("Warning! " + G.GetToken() + " is not in symbol table!");
						System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
					}
					
					
					// Check if the kind is VAR or LABEL
					if (G.GetFoundLabel()) {
						G.GetS().AddSymbol(G.GetToken(), "Label", 0, 0);		// Add Identifier w/kind LABEL to Symbol Table
					} else {
						
						if (G.GetCode() == G.GetR().LookupTokenCode("STRI"))
							G.GetS().AddSymbol(G.GetToken(), "Con", 0, 0);		// Add String constant to Symbol Table
						else
							G.GetS().AddSymbol(G.GetToken(), "Var", 0, 0);		// Add variable to Symbol Table

					}
				}
			}
			PrintToken(G.GetToken(), G.GetCode());
			// TODO: Make sure token is used correctly
			//System.out.println("MADE TOKEN " + G.GetToken());
			return G.GetToken();
		}
		else if (Character.isDigit(ch)) {		// Create a Digit Token (integer or float)
			G.SetCode(51);
			boolean dotFound = false;
			
			while (Character.isDigit(ch)) {
				G.SetToken(G.GetToken() + ch);;
				G.SetPrevCh(ch);
				ch = GetNextChar();		
				if (!Character.isDigit(ch)) {
					G.SetUsePrev(true);
				}

				if (ch == '.' && dotFound == false) {   // Create a Float token if . is found
					G.SetCode(52);
					dotFound = true;
					G.SetToken(G.GetToken() + ch);;
					ch = GetNextChar();	
				}
				if (G.GetCode() == 52) {
					while (Character.isDigit(ch)) {
						G.SetToken(G.GetToken() + ch);;
						ch = GetNextChar();		
					}
					if (ch == 'e' || ch == 'E') {
						G.SetToken(G.GetToken() + ch);;
						ch = GetNextChar();	
						if (ch == '+' || ch == '-') {
							G.SetToken(G.GetToken() + ch);;
							ch = GetNextChar();	
						}
					}
					while (Character.isDigit(ch)) {
						G.SetToken(G.GetToken() + ch);;
						ch = GetNextChar();	
					}
					if (G.GetToken().length() > maxNumLength) { // convert float length to string
						G.SetToken(G.GetToken().substring(0, maxNumLength));
						System.out.println("~~~ Warning, token exceeds length " + maxNumLength + "! "
										     + "The token has been truncated. ~~~");
					}
					if (!Character.isLetterOrDigit(ch)) {
						G.SetUsePrev(true);					// ch not letter or digit, grab previous char
					}
					
					double tokenToDouble = Float.parseFloat(G.GetToken()); // convert String to float value
					
					if (G.GetS().InSymbolTable(G.GetToken()) == false)
						G.GetS().AddSymbol(G.GetToken(), "Const", 2, tokenToDouble);
					PrintToken(G.GetToken(), G.GetCode());
					return G.GetToken(); 									// return float
				}
			}
			if (G.GetToken().length() > maxNumLength) {					// truncate int if needed
				System.out.println("~~~ Warning, token exceeds length " + maxNumLength + "! "
								     + "The token has been truncated. ~~~");
				G.SetToken(G.GetToken().substring(0, maxNumLength));
				
				int tokenToInt = Integer.MAX_VALUE;					// set integer to max value
				
				if (G.GetS().InSymbolTable(G.GetToken()) == false)
					G.GetS().AddSymbol(G.GetToken(), "Const", 1, tokenToInt);
				PrintToken(G.GetToken(), G.GetCode());
				return G.GetToken();
			}
			
			int tokenToInt = Integer.parseInt(G.GetToken());
			
			if (G.GetS().InSymbolTable(G.GetToken()) == false)
				G.GetS().AddSymbol(G.GetToken(), "Const", 1, tokenToInt);
			PrintToken(G.GetToken(), G.GetCode());
			return G.GetToken(); 									// return int
		}
		else if (ch == '\"') {										// Create a String Token, stripping quotes
			ch = GetNextChar();										
			while (ch != '\"') {
				G.SetToken(G.GetToken() + ch);;
				ch = GetNextChar();	
				if (ch == '\"') {									// String: Set token code to 53
					G.SetCode(53);
					
					// Add string constant to symbol table
					if (G.GetS().InSymbolTable(G.GetToken()) == false) {
						G.GetS().AddSymbol(G.GetToken(), "Const", 3, G.GetToken());
					}
					PrintToken(G.GetToken(), G.GetCode());
					return G.GetToken();
				} else if (ch == '\0') {
					// If terminating " not found by new line, throw an error
					System.out.println("*** Error: No terminating quote found before end of string! ***");
					return " ";
				}
			}
		}
		else if (ch == '\0' && G.GetEnd() == true) {
			break;
		}
		else if (ch == '\0') {						// If token is still null, continue checking
		}
		else if (ch == '{' || ch == '(') {			// Create Comment Token
			if (ch == '{') {
				ch = GetNextChar();					// Catch matching }
				while (ch != '}') {
					ch = GetNextChar();	
				}
				ch = GetNextChar();	
				continue;
			}
			else if (ch == '(') {
				G.SetPrevCh(ch);
				ch = GetNextChar();	
				if (ch == '*') {
					while (ch != ')') {
						ch = GetNextChar();
						if (ch == '\0' && G.GetEnd() == true) {
							System.out.println("~~~ Warning: Unterminated comment before end of file! ~~~");
							break;
						}
					}
					continue;
				} else { 					// ( is not followed by *, not a comment
					G.SetToken(G.GetToken() + G.GetPrevCh());
					G.SetUsePrev(true);
					G.SetCode(G.GetR().LookupOtherName(G.GetToken()));
					PrintToken(G.GetToken(), G.GetCode());
					return G.GetToken();
				}
			}
		}
		else if (ch == '>' || ch == '<') {		// check if token is >=, <=, or ==
				G.SetPrevCh(ch);
				G.SetToken(G.GetToken() + ch);;
				ch = GetNextChar();	
				if (ch == '=') {
					G.SetToken(G.GetToken() + ch);;
					G.SetCode(G.GetR().LookupOtherName(G.GetToken()));
					PrintToken(G.GetToken(), G.GetCode());
					return G.GetToken();
				}
				else if (G.GetPrevCh() == '<' && ch == '>') {
					G.SetToken(G.GetToken() + ch);;
					G.SetCode(G.GetR().LookupOtherName(G.GetToken()));
					PrintToken(G.GetToken(), G.GetCode());
					return G.GetToken();
				} else { 						// > not followed by ==
					G.SetCode(G.GetR().LookupOtherName(G.GetToken()));
					G.SetUsePrev(true);
					PrintToken(G.GetToken(), G.GetCode());
					return G.GetToken();
				}
		}
		else if (ch == ':') {					// Create a : token
			G.SetToken(G.GetToken() + ch);;
			G.SetUsePrev(false);
			ch = GetNextChar();	
			if (ch == '=') {					// Create a := token
				G.SetToken(G.GetToken() + ch);;
				G.SetCode(G.GetR().LookupOtherName(G.GetToken()));
				PrintToken(G.GetToken(), G.GetCode());
				return G.GetToken();
			}
			else {
				G.SetCode(G.GetR().LookupOtherName(G.GetToken()));
				G.SetUsePrev(true);
			    PrintToken(G.GetToken(), G.GetCode());
				return G.GetToken();
			}
		} 
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {	// create an operator token
			G.SetToken(G.GetToken() + ch);;
			G.SetCode(G.GetR().LookupOtherName(G.GetToken()));
			PrintToken(G.GetToken(), G.GetCode());
			return G.GetToken();
		}
		else { 								// if trailing ) is found, not a comment
			if (ch == ')') {
				G.SetToken(G.GetToken() + ch);;
				G.SetCode(G.GetR().LookupOtherName(G.GetToken()));
				PrintToken(G.GetToken(), G.GetCode());
				return G.GetToken();
			}
			G.SetToken(G.GetToken() + ch);;
			G.SetCode(G.GetR().LookupOtherName(G.GetToken()));
			PrintToken(G.GetToken(), G.GetCode());
			return G.GetToken();
		}
	}

	// End of file reached
	G.SetEnd(true);
	return G.GetToken();
}

// PrintToken prints each token's (1) lexeme, (2) token code, 
// (3) The proper 4-character mnemonic from the Reserve Table,
// and (4) For identifiers and literals added to the Symbol table,
// the corresponding Symbol Table index.
public static void PrintToken(String token, int tokenCode) {

	String str = new String();
	String type = G.GetR().LookupMnemonic(tokenCode);
	
	// If the token is an Identifier and NOT in ReserveTable, put it in Symbol Table
	// All int or float tokens go into ReserveTable
	
	if (token.length() > 0 && G.getVerbose() == true && G.GetDoNotPrint() == false) {
		// Print the Token Information
		str = String.format("%" + -30 + "s", token);
		str += String.format("%" + 3 + "s", tokenCode);
		str += String.format("%" + 15 + "s", type);
		
		// See if the lexeme exists in the symbol table
		int symbolIndex = G.GetS().LookupSymbol(G.GetToken());
		if (symbolIndex != -1)
			str += String.format("%" + 12 + "s", symbolIndex);
		else
			str += String.format("%" + 12 + "s", "-");
		System.out.println(str);
	}
}

/////////////////////////
// Method_Nonterminals //
/////////////////////////

// Resynch continues parsing the file after finding an error
// by calling GNT until a token is found that could be the start of a statement.
public static void Resync() {
	
	while (G.GetFoundError() == true) {
		G.SetDoNotPrint(true);
		
		// eat tokens until a new line is reached
		int freshLine = G.GetLineCount() + 1;
		
		while (G.GetLineCount() < freshLine) {
			G.SetToken(GetNextToken());
		}

		//  If token is the start of <statement>, set foundError to false
		if (
			//G.GetS().InSymbolTable(G.GetToken()) && G.GetS().IsLabel(G.GetToken()) |
			G.GetCode() == G.GetR().LookupTokenCode("IDEN")  |   // variable
			G.GetCode() == G.GetR().LookupTokenCode("BGIN")  | // possible block-body
			G.GetCode() == G.GetR().LookupTokenCode("IF  ")  |
			G.GetCode() == G.GetR().LookupTokenCode("WHIL")  |
			G.GetCode() == G.GetR().LookupTokenCode("REPT")  |
			G.GetCode() == G.GetR().LookupTokenCode("FOR ")  |
			G.GetCode() == G.GetR().LookupTokenCode("GOTO")  |
			G.GetCode() == G.GetR().LookupTokenCode("WTLN")) {
			
			// Valid token found, resume printing and call Statement() to resume compilation
			G.SetDoNotPrint(false);
			G.SetFoundError(false);
			
			System.out.println("Found a potentially valid token: " + G.GetToken());
			
			G.SetResyncing(true);
			Statement_Nonterm();
		
		// else If token is not good...
		} else {
		
			if (G.GetToken().length() == 0) {
				System.out.println("\n***** [Alert!] " +  G.GetMyFile() + " has compilation errors to be fixed! *****");
				G.GetS().FlagUnusedLabels();
				G.GetS().PrintSymbolTable();
				System.exit(1);
			}
			// Found invalid token, re-looping through while statement
		}

		// Expect . to complete program
		G.SetToken(GetNextToken());
			
			if (G.GetCode() == G.GetR().LookupTokenCode("PERD")) { 
				G.SetToken(GetNextToken());
				
				if (G.GetToken().length() == 0) {
					System.out.println("\n***** [Alert!] " +  G.GetMyFile() + " has compilation errors to be fixed! *****");
					
					G.GetS().FlagUnusedLabels();
					G.GetS().PrintSymbolTable();
					System.exit(1);	
				}
		} else {
			continue;
		}
	} // while FoundError == true
}

public static void Error(String expectedToken) {
	
	G.SetFoundError(true);
	G.SetCompWithoutError(false);  // informs user that the program compiled with at least 1 error
	
	System.out.println("----------------------------------------------------------------------");
	System.out.println("*** " + G.GetMyFile() + " has a syntax error on line " + G.GetLineCount() + " ***");
	System.out.println(G.GetLine());

	if (G.GetToken().length() == 0) {
		System.out.println("Expected " + expectedToken + ", but end of file has been reached.");
	} else {
		System.out.println("Expected " + expectedToken + ", got " + G.GetToken());
		System.out.println("Skipping ahead to next valid statement...");
	}
	
	Resync();
}

public static void Debug(boolean entering, String name) {
	if (G.getVerbose() == true) {
		if (entering == true)
			System.out.println("Entering " + name);
		else 
			System.out.println("Exiting " + name);
	}
}

public static int Program_Nonterm() {
		Debug(true, "Program");
		if (G.GetCode() == G.GetR().LookupTokenCode("UNIT")) {
			G.SetToken(GetNextToken());
			
			Prog_Identifier_Nonterm();
				
			if (G.GetCode() == G.GetR().LookupTokenCode("SEMI")) { 
				G.SetToken(GetNextToken());
	
				Block_Nonterm();
					
				if (G.GetCode() == G.GetR().LookupTokenCode("PERD")) {
					G.SetToken(GetNextToken());
	
				} else {
					Error(".");
				}
			} else {
				Error(";");
			}
	    } else {
	    	Error("UNIT");
		}
		
		Debug(false, "Program");
		
		if (G.GetCompWithoutError() == true)
			System.out.println("\n~~ Congratulations, " + G.GetMyFile() + " compiled without errors! ~~");
		else {
			System.out.println("\n***** [Alert!] " +  G.GetMyFile() + " has compilation errors to be fixed! *****");
		
		}
		//System.out.println("in Program, " + G.GetToken() + " is at index FOO");
			return -1;
}

public static int Block_Nonterm() {

	Debug(true, "Block");
		
	if (G.GetCode() == G.GetR().LookupTokenCode("LABL")) {
		Label_Dec_Nonterm();
	}
			
	while (G.GetCode() == G.GetR().LookupTokenCode("VAR ")) {
		Var_Dec_Sec_NonTerm();
	}
			
	Block_Body_Nonterm();
				
	Debug(false, "Block");
	//System.out.println("in Block, " + G.GetToken() + " is at index FOO");
	return -1;
}

public static int Block_Body_Nonterm() {

	G.SetInBlockBody(true);
		
	Debug(true, "Block Body");
		
	if (G.GetCode() == G.GetR().LookupTokenCode("BGIN")) { 
		G.SetToken(GetNextToken());
	
		do {			
			if (G.GetCode() == G.GetR().LookupTokenCode("SEMI")) {
				G.SetToken(GetNextToken());
			}
			Statement_Nonterm();
		} while (G.GetCode() == G.GetR().LookupTokenCode("SEMI"));
			
		if (G.GetCode() == G.GetR().LookupTokenCode("END ")) { 
			G.SetToken(GetNextToken());
		} else {
			Error("END or ; <statement>");
		}
	} else {
		Error("BEGIN");
	}
		
	Debug(false, "Block Body");
	//System.out.println("in Block-Body, " + G.GetToken() + " is at index FOO");
	return 1;
}


public static int Label_Dec_Nonterm() {
	
	Debug(true, "label declaration");
	
	if (G.GetCode() == G.GetR().LookupTokenCode("LABL")) { 
		G.SetFoundLabel(true);
		G.SetToken(GetNextToken());
		G.SetFoundLabel(false);
		
		if (G.GetCode() == G.GetR().LookupTokenCode("IDEN")) { 
			G.SetToken(GetNextToken());

			// 0+ , IDEN
			while (G.GetCode() == G.GetR().LookupTokenCode("COMA")) {
				G.SetFoundLabel(true);
				G.SetToken(GetNextToken());

				if (G.GetCode() == G.GetR().LookupTokenCode("IDEN")) { 
					G.SetToken(GetNextToken());
					G.SetFoundLabel(false);
				} else {
					Error("identifier");
				}
			}
			
			if (G.GetCode() == G.GetR().LookupTokenCode("SEMI")) { 
				G.SetToken(GetNextToken());
			} else {
				Error(";");
			}
		} else {
			Error("identifier");
		}
	} else {
		Error("LABEL");
	}
	
	Debug(false, "label declaration");
	//System.out.println("in label declaration, " + G.GetToken() + " is at index FOO");
	return -1;
}

public static int Prog_Identifier_Nonterm() {
	Debug(true, "prog-identifier");
	Identifier_Nonterm();
	Debug(false, "prog-identifier");
	//System.out.println("in prog-identifier, " + G.GetToken() + " is at index FOO");
	return -1;
}

public static int Var_Dec_Sec_NonTerm() {
	Debug(true, "variable-dec-sec");
	if (G.GetCode() == G.GetR().LookupTokenCode("VAR ")) {
		G.SetToken(GetNextToken());
		
		Var_Declar_Nonterm();
		
	} else {
		Error("VAR");
	}
	Debug(false, "variable-dec-sec");
	//System.out.println("in variable declar sec, " + G.GetToken() + " is at index FOO");
	return 1;
}

// 1 or more variables can be declared
public static int Var_Declar_Nonterm() {
	Debug(true, "variable-declaration");
	
	// Ensure token is identifier before moving to while loop to catch errors.
	if (G.GetCode() == G.GetR().LookupTokenCode("IDEN")) {
		
		while (G.GetCode() == G.GetR().LookupTokenCode("IDEN")) {
			G.SetToken(GetNextToken());
		
			// 0 or more '$COMMA identifier'
			while (G.GetCode() == G.GetR().LookupTokenCode("COMA")) {
				G.SetToken(GetNextToken());
				Identifier_Nonterm();
			}
			
			if (G.GetCode() == G.GetR().LookupTokenCode("COLN")) {
			
				G.SetToken(GetNextToken());
				Type_Nonterm();
			
				if (G.GetCode() == G.GetR().LookupTokenCode("SEMI")) {
					G.SetToken(GetNextToken());
					// if identifier is grabbed, keep looping
					
				} else {
					Error(";");
				}
			} else {
				Error(",");
			}
		}
	} else {
		Error("identifier");
	}
	
	Debug(false, "variable-declaration");
	//System.out.println("in variable declaration, " + G.GetToken() + " is at index FOO");
	return 1;
}


// TODO: assign values, example: a := 42
public static int Statement_Nonterm() {
	
	int left, right = 0;
	
	Debug(true, "statement");
	
	while (G.GetS().InSymbolTable(G.GetToken()) && G.GetS().IsLabel(G.GetToken())) {

		// In while loop, is a label
		G.SetToken(GetNextToken());
		
		if (G.GetCode() == G.GetR().LookupTokenCode("COLN")) {
			G.SetToken(GetNextToken());
		} else {
			Error(":");
		}
	}
	
	// TODO: left returns ST index for IDEN
	// At least one of the following:
	// <variable> $ASSIGN (<simple expression> | <string constant>)
	if (G.GetCode() == G.GetR().LookupTokenCode("IDEN")) {
		
		left = Variable_Nonterm(); //  'left' returns current token ST index
		//System.out.println("** LEFT RETURNS " + left + " **");
		
		// Exactly one of the following:
		if (G.GetCode() == G.GetR().LookupTokenCode("ASGN")) {
			G.SetToken(GetNextToken());
			
			// simple expression...
			if (G.GetCode() == G.GetR().LookupTokenCode("PLUS") |
			    G.GetCode() == G.GetR().LookupTokenCode("MINU") |
			    G.GetCode() == G.GetR().LookupTokenCode("INT ") |
			    G.GetCode() == G.GetR().LookupTokenCode("FLOT") |
			    G.GetCode() == G.GetR().LookupTokenCode("IDEN") |
			    G.GetCode() == G.GetR().LookupTokenCode("LPRN")) {
				
				//right = G.GetS().LookupStIndex(G.GetToken());			// get result index
				//System.out.println("** RIGHT RETURNS " + right + " **");
				// have right return current token ST index
				right = Simple_Exp_Nonterm();
				
				//System.out.println("Copy value of right into left");
				//System.out.println("Value at index " + left + " is " + G.GetS().LookupIndex(left));
				//System.out.println("Value at index " + right + " is " + G.GetS().LookupIndex(right));
				
				// TODO : Generate Quad code
				G.GetQ().AddQuad(5, left, 0, right);
				
				
			
			// ...or string constant
			} else if (G.GetCode() == G.GetR().LookupTokenCode("STRI")) {
				String_Const_Nonterm();
			}
			
			else {
				Error("simple expression or string constant");
			}
		} else {
			Error(":=");
		}
	
	// block-body
	} else if (G.GetCode() == G.GetR().LookupTokenCode("BGIN")) {
		Block_Body_Nonterm();
	}
	
	// IF THEN [ELSE]
	else if (G.GetCode() == G.GetR().LookupTokenCode("IF  ")) {
		G.SetToken(GetNextToken());
		Relexp_Nonterm();
		
		if (G.GetCode() == G.GetR().LookupTokenCode("THEN")) {
			G.SetToken(GetNextToken());
			Statement_Nonterm();
			
			if (G.GetCode() == G.GetR().LookupTokenCode("ELSE")) {
				G.SetToken(GetNextToken());
				Statement_Nonterm();
			}
		} else {
			Error("THEN");
		}	
	}
	
	// WHILE DO
	else if (G.GetCode() == G.GetR().LookupTokenCode("WHIL")) {
		G.SetToken(GetNextToken());
		Relexp_Nonterm();
		
		if (G.GetCode() == G.GetR().LookupTokenCode("DO  ")) {
			G.SetToken(GetNextToken());
			Statement_Nonterm();
		} else {
			Error("DO");
		}
	}
	
	// REPEAT UNTIL
	else if (G.GetCode() == G.GetR().LookupTokenCode("REPT")) {
		G.SetToken(GetNextToken());
		Statement_Nonterm();

		if (G.GetCode() == G.GetR().LookupTokenCode("UNTL")) {
			G.SetToken(GetNextToken());
			Relexp_Nonterm();
		} else {
			Error("UNTIL");
		}
	}
	
	// FOR ASSIGN TO DO
	else if (G.GetCode() == G.GetR().LookupTokenCode("FOR ")) {
		G.SetToken(GetNextToken());
		Variable_Nonterm();
		
		if (G.GetCode() == G.GetR().LookupTokenCode("ASGN")) {
			G.SetToken(GetNextToken());
			Simple_Exp_Nonterm();
			
			if (G.GetCode() == G.GetR().LookupTokenCode("TO  ")) {
				G.SetToken(GetNextToken());
				Simple_Exp_Nonterm();
				
				if (G.GetCode() == G.GetR().LookupTokenCode("DO  ")) { 
					G.SetToken(GetNextToken());
					Statement_Nonterm();
				} else {
					Error("DO");
				}
			} else {
				Error("TO");
			}
		} else {
			Error(":=");
		}
	}
	
	// GOTO
	else if (G.GetCode() == G.GetR().LookupTokenCode("GOTO")) {
		G.SetToken(GetNextToken());
		Label_Nonterm();
	}
	
	// WRITELN
	else if (G.GetCode() == G.GetR().LookupTokenCode("WTLN")) {
		G.SetToken(GetNextToken());
		
		if (G.GetCode() == G.GetR().LookupTokenCode("LPRN")) {
			G.SetToken(GetNextToken());
			//sim exp | iden| str const )
			if (G.GetCode() == G.GetR().LookupTokenCode("PLUS") |
				G.GetCode() == G.GetR().LookupTokenCode("MINU")	|
				G.GetCode() == G.GetR().LookupTokenCode("INT ")	|
				G.GetCode() == G.GetR().LookupTokenCode("FLOT")	|
				G.GetCode() == G.GetR().LookupTokenCode("LPRN")	|
				G.GetCode() == G.GetR().LookupTokenCode("IDEN")) {
				G.SetToken(GetNextToken());
			} 
			else if (G.GetCode() == G.GetR().LookupTokenCode("IDEN")) {
				G.SetToken(GetNextToken());
			} 
			else if (G.GetCode() == G.GetR().LookupTokenCode("STRI")) {
				G.SetToken(GetNextToken());
			}
			else {
				Error("simple expression, identifier, or string constant");
			}
		} else {
			Error("(");
		}
		
		if (G.GetCode() == G.GetR().LookupTokenCode("RPRN")) {
			G.SetToken(GetNextToken());
	
		} else {
			Error(")");
		}
	}
	else {
		Error("statement");
	}
	
	Debug(false, "statement");
	//System.out.println("in Statement, " + G.GetToken() + " is at index FOO");
	return -1;
}

// Variable now returns ST index
public static int Variable_Nonterm() {
	Debug(true, "variable");
	
	int retVal = G.GetS().LookupStIndex(G.GetToken());
	
	//System.out.println("** In Variable_Nonterm, CURRENT TOKEN IS " + G.GetToken());
	//System.out.println("Its ST index is " + G.GetS().LookupStIndex(G.GetToken()));
	
	Identifier_Nonterm();
	
	// optional $LBKT <simple expression> $RBKT
	if (G.GetCode() == G.GetR().LookupTokenCode("LBKT")) {
		G.SetToken(GetNextToken());
		Simple_Exp_Nonterm();
		
		if (G.GetCode() == G.GetR().LookupTokenCode("RBKT")) {
			G.SetToken(GetNextToken());
		} else {
			Error("]");
		}
	}

	Debug(false, "variable");
	// TODO: change return value to ST index of this variable
	//System.out.println("** In Variable_Nonterm, CURRENT TOKEN IS " + G.GetToken());
	return retVal;
}

public static int Label_Nonterm() {
	Debug(true, "label");
	
	// Confirm that the identifier has been declared as type 'label'
	// to differentiate from a variable in Statement_Nonterm()
	Identifier_Nonterm();
	
	Debug(false, "label");
	//System.out.println("in label, " + G.GetToken() + " is at index FOO");
	return -1;
}
public static int Relexp_Nonterm() {
	Debug(true, "rel expression");
	
	Simple_Exp_Nonterm();
	Relop_Nonterm();
	Simple_Exp_Nonterm();
	
	Debug(false, "rel expression");
	//System.out.println("in rel expression, " + G.GetToken() + " is at index FOO");
	return 1;
}

public static int Relop_Nonterm() {
	Debug(true, "relop");
	if (G.GetCode() == G.GetR().LookupTokenCode("EQL ") | 
	    G.GetCode() == G.GetR().LookupTokenCode("LESS") |
	    G.GetCode() == G.GetR().LookupTokenCode("GTR ") |
	    G.GetCode() == G.GetR().LookupTokenCode("LTGT") |
	    G.GetCode() == G.GetR().LookupTokenCode("LESE") |
	    G.GetCode() == G.GetR().LookupTokenCode("GTRE")) {

		G.SetToken(GetNextToken());
	
	} else {
		Error("relation operator");
	}
	
	Debug(false, "relop");
	//System.out.println("in relop, " + G.GetToken() + " is at index FOO");
	return 1;
}

// TODO:
public static int Simple_Exp_Nonterm() {
	Debug(true, "simple expression");
	
	int left, right, signVal = 0, temp, opCode;
	
	// Optional sign
	if (G.GetCode() == G.GetR().LookupTokenCode("PLUS") ||
	   (G.GetCode() == G.GetR().LookupTokenCode("MINU"))) {
		signVal = Sign_Nonterm();
	}
	
	left = Term_Nonterm();
	
	// If a negative sign is found, make the current token negative
	if (signVal == -1) {
		G.GetQ().AddQuad(G.GetR().LookupQuadInt("MUL"), 0, left, left); 
	}
	// TODO: set quadcode values for the opcode (adding or subtracting)
	while (G.GetCode() == G.GetR().LookupTokenCode("PLUS") ||
		  (G.GetCode() == G.GetR().LookupTokenCode("MINU"))) {

		if (G.GetCode() == G.GetR().LookupTokenCode("PLUS")) {
			opCode = G.GetR().LookupQuadInt("ADD");
		} else {
			opCode = G.GetR().LookupQuadInt("SUB");
		}
		
		Addop_Nonterm();
		
		right = Term_Nonterm();
		temp = GenSymbol(); 
		G.GetQ().AddQuad(opCode, left, right, temp);
		left = temp;
	}
	
	Debug(false, "simple expression");

	return left;
}

// GenSymbol adds a specially-named temp variable to the symbol table and returns its index
public static int tempCount = 0;
public static int GenSymbol() {
	tempCount++;
	String tempName = "#TEMP_" + String.valueOf((tempCount));
	G.GetS().AddSymbol(tempName, "Var", 1, 0);
	int retVal = G.GetS().LookupStIndex(tempName);
	return retVal;
}

public static int Addop_Nonterm() {
	Debug(true, "addop");
	
	int retVal = G.GetS().LookupStIndex(G.GetToken());
	
	if (G.GetCode() == G.GetR().LookupTokenCode("PLUS") ||
	   (G.GetCode() == G.GetR().LookupTokenCode("MINU"))) {
		G.SetToken(GetNextToken());
		
		retVal = G.GetS().LookupStIndex(G.GetToken());
		
		System.out.println("** In addOp_Nonterm IF statement, CURRENT TOKEN IS " + G.GetToken());
		System.out.println("Its ST index is " + G.GetS().LookupStIndex(G.GetToken()));
	} else {
		Error("+ or -");
	}
	Debug(false, "addop");
	//System.out.println("in addop, " + G.GetToken() + " is at index FOO");
	return retVal;
}

public static int Sign_Nonterm() {
	Debug(true, "sign");
	
	int retVal = 0;
	
	System.out.println("** In Sign_Nonterm, CURRENT TOKEN IS " + G.GetToken());
	
	if (G.GetCode() == G.GetR().LookupTokenCode("PLUS")) {
		retVal = 1;
		G.SetToken(GetNextToken());
	}
	else if (G.GetCode() == G.GetR().LookupTokenCode("MINU")) {
		retVal = -1;
		G.SetToken(GetNextToken());
	}
	else {
		Error("+ or -");
	}
	Debug(false, "sign");
	System.out.println("Sign is returning " + retVal);
	return retVal;
}

public static int Term_Nonterm() {
	Debug(true, "term");
	
	int left, right, temp, opCode;
	
	int retVal = G.GetS().LookupStIndex(G.GetToken());
	
	left = Factor_Nonterm();
	System.out.println("LEFT = factor returns " + left);
	
	while (G.GetCode() == G.GetR().LookupTokenCode("MUL ") ||
		  (G.GetCode() == G.GetR().LookupTokenCode("DIV "))) {
		
		if (G.GetCode() == G.GetR().LookupTokenCode("MUL ")) {
			opCode = G.GetR().LookupQuadInt("MUL");
		} else {
			opCode = G.GetR().LookupQuadInt("DIV");
		}
		
		Mulop_Nonterm();
		
		right = Factor_Nonterm();
		temp = GenSymbol();
		G.GetQ().AddQuad(opCode, left, right, temp);
		left = temp;
	}
	Debug(false, "term");
	
	return left;
}

public static int Mulop_Nonterm() {
	Debug(true, "mulop");
	if (G.GetCode() == G.GetR().LookupTokenCode("MUL ") ||
	   (G.GetCode() == G.GetR().LookupTokenCode("DIV "))) {
		G.SetToken(GetNextToken());
	} else {
		Error("* or /");
	}
	Debug(false, "mulop");
	//System.out.println("in mulop, " + G.GetToken() + " is at index FOO");
	return -1;
}

public static int Factor_Nonterm() {
	Debug(true, "Factor");
	
	int left, right, signVal;
	
	int retVal = G.GetS().LookupStIndex(G.GetToken());
	left = right = retVal;
	
	if (G.GetCode() == G.GetR().LookupTokenCode("IDEN")) {    
		left = Variable_Nonterm();
		
	} else if (G.GetCode() == G.GetR().LookupTokenCode("FLOT") ||    
			   G.GetCode() == G.GetR().LookupTokenCode("INT ")) { 
		left = Unsigned_Const_Nonterm();
		
	} else if (G.GetCode() == G.GetR().LookupTokenCode("LPRN")) {
		G.SetToken(GetNextToken());
		right = Simple_Exp_Nonterm();
		
		if (G.GetCode() == G.GetR().LookupTokenCode("RPRN")) {
			G.SetToken(GetNextToken());
		} else {
			Error(")");
		}
		// TODO: Add logic to check for negative sign (-)
		
	//} else if (G.GetCode() == G.GetR().LookupTokenCode("MINU")){
		// If a negative sign is found, make the current token negative
		//G.SetToken(GetNextToken());
	//	left = G.GetS().LookupStIndex(G.GetToken());
	//	System.out.println("LEFT INDEX is " + left);
	//	G.GetQ().AddQuad(G.GetR().LookupQuadInt("MUL"), 0, 3, 3);
		
		//}
	} else { 
		Error("float, int, or identifier");
	}
	Debug(false, "Factor");
	
	return right;
}

public static int Type_Nonterm() {
	Debug(true, "type");
	
	if (G.GetCode() == G.GetR().LookupTokenCode("INTR") |
	   (G.GetCode() == G.GetR().LookupTokenCode("REAL") |
	   (G.GetCode() == G.GetR().LookupTokenCode("STRG")))) {
		Simple_Type_Nonterm();
		
	} else if (G.GetCode() == G.GetR().LookupTokenCode("ARAY")) {
		G.SetToken(GetNextToken());
		
		if (G.GetCode() == G.GetR().LookupTokenCode("LBKT")) {
			G.SetToken(GetNextToken());
			
			if (G.GetCode() == G.GetR().LookupTokenCode("INT ")) { 
				G.SetToken(GetNextToken());
				
				if (G.GetCode() == G.GetR().LookupTokenCode("RBKT")) {
					G.SetToken(GetNextToken());
					
					if (G.GetCode() == G.GetR().LookupTokenCode("OF  ")) {
						G.SetToken(GetNextToken());
						
						if (G.GetCode() == G.GetR().LookupTokenCode("INT ")) {
							G.SetToken(GetNextToken());
						} else {
							Error("integer");
						}
					} else {
						Error("OF");
					}
				} else {
					Error("[");
				}
			} else {
				Error("INTTYPE");
			}
		} else {
			Error("[");
		}
	} else {
		Error("INTEGER, REAL, STRING, or ARRAY");
	}
	
	Debug(false, "type");
	//System.out.println("in type, " + G.GetToken() + " is at index FOO");
	return -1;
}

public static int Simple_Type_Nonterm() {
	Debug(true, "simple type");
	if (G.GetCode() == G.GetR().LookupTokenCode("INTR")) {   
		G.SetToken(GetNextToken());
	} else if (G.GetCode() == G.GetR().LookupTokenCode("REAL")) {   
		G.SetToken(GetNextToken());
	} else if (G.GetCode() == G.GetR().LookupTokenCode("STRG")) {  
		G.SetToken(GetNextToken());
	} else {
		Error("INTEGER, FLOAT, or string");
	}
	Debug(false, "simple type");
	//System.out.println("in simple type, " + G.GetToken() + " is at index FOO");
	return -1;
}

public static int Constant_Nonterm() {
	Debug(true, "constant");
	
	if (G.GetCode() == G.GetR().LookupTokenCode("PLUS") |
	   G.GetCode() == G.GetR().LookupTokenCode("MINU")) {    
		Sign_Nonterm();
	} 
		
	Unsigned_Const_Nonterm();
	
	Debug(false, "constant");
	//System.out.println("in Constant, " + G.GetToken() + " is at index FOO");
	return -1;
}

public static int Unsigned_Const_Nonterm() {
	Debug(true, "Unsigned Constant");
	Unsigned_Num_Nonterm();
	Debug(false, "Unsigned Constant");
	//System.out.println("in Unsigned Constant, " + G.GetToken() + " is at index FOO");
	return -1;
}

public static int Unsigned_Num_Nonterm() {
	Debug(true, "Unsigned Number");
	
	if (G.GetCode() == G.GetR().LookupTokenCode("FLOT") ||
		G.GetCode() == G.GetR().LookupTokenCode("INT ")) {
		G.SetToken(GetNextToken());
	} else {
		Error("float or int");
	}
	Debug(false, "Unsigned Number");
	//System.out.println("in Unsigned Number, " + G.GetToken() + " is at index FOO");
	return -1;
}

public static int Identifier_Nonterm() {
	Debug(true, "identifier");
	
	if (G.GetCode() == G.GetR().LookupTokenCode("IDEN")) {
		G.SetToken(GetNextToken());
	} else {
		Error("identifier");
	}
	Debug(false, "identifier");
	//System.out.println("in Identifier, " + G.GetToken() + " is at index FOO");
	return -1;
}

public static int String_Const_Nonterm() {
	Debug(true, "String Constant");
	
	if (G.GetCode() == G.GetR().LookupTokenCode("STRI")) {
		G.SetToken(GetNextToken());
	} else {
		Error("string type");
	}
	
	Debug(false, "String Constant");
	//dsasdffdsafdsfdsafadSystem.out.println("in String Constant, " + G.GetToken() + " is at index FOO");
	return -1;
}

//////////
// Main //
//////////

// TODO
	public static void main(String[] args) throws FileNotFoundException {
		
		// Add a Minus 1 and Plus 1 value to the symbol table
		G.GetS().AddSymbol("MINUS_1_INDEX", "Const", 1, -1);
		G.GetS().AddSymbol("PLUS_1_INDEX", "Const", 1, 1);

		
		// Set echoOn to true to display source lines
		G.setEchoOn(true);
		
		// Set verbose to true to display token and lexeme information
		G.setVerbose(true);
		 
		// Prepare a file to be read
		G.SetMyFile("test.txt");
		
		G.SetScanner(G.GetMyFile());
		
		// Get the first token
		G.SetToken(GetNextToken());
		
		// Send the token through the syntax analyzer
		Program_Nonterm();
		
		// Close the scanner
		G.GetScanner().close();
		
		G.GetS().FlagUnusedLabels();
		
		// New functionality... quads!
		// Quads should be generated when parsing statements
		// TODO: When is this addQuad called?
		//G.GetQ().AddQuad(4, 2, 3, 1);  // (st index 1 val + st index 2 val), put that value into st index3 
		//G.GetQ().AddQuad(4, 1, 1, 1);
		
		G.GetQ().InterpretQuads();
		
		G.GetS().PrintSymbolTable();
		
		
	} // main
} // Pt_4