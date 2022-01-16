/* Ryan Long
 * 10/02/2020
 * CS 4100 - Compilers taught by Al Broulliette
 * Compilers Project Part Two: Lexical Analyzer
 * 
 * This program takes source code input from a file and parses it into tokens.
 */

import java.io.*;
import java.util.*;

/////////////
// Classes //
/////////////

// ReserveTable holds a list of reserved words for the language (case independent).
// As tokens are retrieved, the ReserveTable is checked to see if the token resides there.
// If it does, the token is assigned the corresponding token code.
class ReserveTable {

	HashMap<Integer, String> resWord;

	public ReserveTable() {

		resWord = new HashMap<Integer, String>();

		 // key 0 - 25: Reserved Words
		 // key 30 - 48, 99: Other Tokens
		 resWord.put(0, "GOTO"); resWord.put(1, "INTEGER"); resWord.put(2, "TO");
		 resWord.put(3, "DO"); resWord.put(4, "IF"); resWord.put(5, "THEN");
		 resWord.put(6, "ELSE"); resWord.put(7, "FOR"); resWord.put(8, "OF");
		 resWord.put(9, "WRITELN"); resWord.put(10, "READLN"); resWord.put(11, "BEGIN");
		 resWord.put(12, "END"); resWord.put(13, "VAR"); resWord.put(14, "WHILE");
		 resWord.put(15, "UNIT"); resWord.put(16, "LABEL"); resWord.put(17, "REPEAT");
		 resWord.put(18, "UNTIL"); resWord.put(19, "PROCEDURE"); resWord.put(20, "DOWNTO");
		 resWord.put(21, "FUNCTION"); resWord.put(22, "RETURN"); resWord.put(23, "REAL");
		 resWord.put(24, "STRING"); resWord.put(25, "ARRAY");
		
		 resWord.put(30, "/"); resWord.put(31, "*"); resWord.put(32, "+");
		 resWord.put(33, "-"); resWord.put(34, "("); resWord.put(35, ")");
		 resWord.put(36, ";"); resWord.put(37, ":="); resWord.put(38, ">");
		 resWord.put(39, "<"); resWord.put(40, ">="); resWord.put(41, "<=");
		 resWord.put(42, "="); resWord.put(43, "<>"); resWord.put(44, ",");
		 resWord.put(45, "["); resWord.put(46, "]"); resWord.put(47, ":");
		 resWord.put(48, "."); resWord.put(50, "IDEN"); resWord.put(51, "INT");
		 resWord.put(52, "FLOAT"); resWord.put(53, "STRING"); resWord.put(99, "?");
	}
}


// SymbolTable holds Symbol objects in an ArrayList
class SymbolTable {
	
	ArrayList<Symbol> symbList = new ArrayList<Symbol>();
	
	// Constructor to form an empty SymbolTable
	public SymbolTable() {
	}
	
	// Add a Symbol to the SymbolTable. One of these three Add functions
	// is called depending on the type of Symbol's value (String, int, or float)
	public int AddSymbol(String symbol, int kind, int type, String value) {
		symbList.add(new Symbol(symbol, kind, type, value));
		return symbList.size() - 1;
	}
	public int AddSymbol(String symbol, int kind, int type, int value) {
		symbList.add(new Symbol(symbol, kind, type, value));
		return symbList.size() - 1;
	}
	public int AddSymbol(String symbol, int kind, int type, double value) {
		symbList.add(new Symbol(symbol, kind, type, value));
		return symbList.size() - 1;
	}
	
	public void PrintSymbolTable() {
		System.out.println("\n=================== Symbol Table ====================");
		System.out.println("Lexeme\t\tKind\t\tType\t\tValue");
		System.out.println("-----------------------------------------------------");
		
		for (int i = 0; i < symbList.size(); i++) {
			//System.out.println("symbol " + i);
			System.out.println(symbList.get(i));
		}
		
	}
} // SymbolTable


// Symbol class creates Symbol objects that essentially act as memory for the computer.
// Tokens belong in the Symbol Table if (a) the token is an identifier but not a reserved word,
// (b) the token is a numeric constant (integer or float).
class Symbol {
	private String name;		// lexeme (token name)
	private int kind;			// VARIABLE or CONST
	private int type;			// int, float, or string
	private String stringValue;	// value for String type
	private int intValue;		// value for int type
	private double doubleValue;	// value for double type
	
	// Each Symbol has one of three types if it is a String, int, or double,
	// so there are three constructors
	public Symbol(String name, int kind, int type, String value) {	// String value
		this.name = name;
		this.kind = kind;
		this.type = type;
		stringValue = value;
	}
	
	public Symbol(String name, int kind, int type, int value) { 		// int value
		this.name = name;
		this.kind = kind;
		this.type = type;
		intValue = value;
	}
	
	public Symbol(String name, int kind, int type, double value) {	// double value
		this.name = name;
		this.kind = kind;
		this.type = type;
		doubleValue = value;
	}
/*	
	// Getters
	public String getName() { return name; }
	public int getKind() { return kind; }
	public int getType() { return type; }
	public String getStringValue() { return stringValue; }
	public int getIntValue() { return intValue; }
	public double getDoubleValue() { return doubleValue; }
	
	// Setters
	public void setKind(int kind) { this.kind = kind; }
	public void setType(int type) { this.type = type; }
	public void setStringValue(String value) { stringValue = value; }
	public void setIntValue(int value) { intValue = value; }
	public void setDoubleValue(double value) { doubleValue = value; }
	
	
	*/
	
	
	@Override
	public String toString() {
		
		/* Type 0 means String
		 * Type 1 means int
		 * Type 2 means double
		 */
		switch(type) {
		case 0:
			return name + "\t\t" + "VAR" + "\t\t" + "STRING" + "\t\t" + "0";
		case 1:
			return name + "\t\t" + "CONST" + "\t\t" + "INT" + "\t\t" + intValue;
		case 2:
			return name + "\t\t" + "CONST" + "\t\t" + "FLOAT" + "\t\t"+ doubleValue;
		default:
			return "DNE";
		}
	}
	
} // Symbol

public class Refactored_pt2 {

// global variables
static Scanner scanner;
static File myFile;
static boolean echoOn;
static String line;
static int globI = 0;
static boolean eol = false;
static int lineCount = 0;
static int tokenCode = 0;

// bools to account for token type
static boolean IsIdentifier;
static boolean IsReserved;
static boolean IsOther;

static boolean IsInteger;
static boolean IsFloat;
static boolean IsString;
static boolean IsComment;

static boolean EndOfFile = false;

static SymbolTable S = new SymbolTable();
static ReserveTable R = new ReserveTable();

//static String prev = "";
//static char ch = '\0';

static char prevCh = '\0';
static boolean usePrev = false;


//////////////
//Functions //
//////////////

// ResetTypes sets all boolean values regarding type to false.
// It is called before each token is created, and the correct type
// is set during the individual token's creation.
public static void ResetTypes() {
	IsIdentifier = false;
	IsReserved = false;
	IsOther = false;

	IsInteger = false;
	IsFloat = false;
	IsString = false;
	IsComment = false;
}

// GetNextChar feeds chars to GetNextToken so tokens can be assembled. 
// GetNext char gets Strings from GetNextLine.
// A global index is used to determine where in the line the GetNextToken function has reached.
// If the end of the current line has been reached, GetNextChar calls GetNextLine and the index is set to 0.
// If the current line still needs to be parsed for tokens, index tracks the characters.
public static char GetNextChar() {

	 if (globI == 0) {				 		// Start of line
		 line = GetNextLine();
		 if (line.isEmpty()) {		 		// Blank line
			 return '\0';
		 }
		 int tempI = globI;
		 globI++;
		 return line.charAt(tempI);
	 }
	 else if (globI == line.length()) {		// End of the line has been reached
		 globI = 0;
		 return 0;
	 }
	 else if (globI > 0) {					// Current line still needs to be parsed for tokens
		 if (usePrev == false) {
			 int tempI = globI;
			 globI++; // TODO
			 return line.charAt(tempI);
		 } else {
			 
			 globI--;
			 int tempI = globI;
			 //globI++; // TODO
			 return line.charAt(tempI);
		 }
	 }
	 else {
		 return line.charAt(globI);			// Default: continue to parse current line
	 }
}

// GetNextLine gets the next line in the file and feeds it to GetNextChar as a String.
// If echoOn is true, the line is printed before being parsed into tokens.
public static String GetNextLine() {	
	if (EndOfFile)
		return "";
	
	// Nicely display line contents
	lineCount++;
	if (lineCount > 1)
		System.out.println();
	
	line = scanner.nextLine();
	
	// If echoOn is true, print the line
	if (echoOn)
		System.out.println("Line " + lineCount + ": " + line);

	// End of file is reached. GetNextChar will parse the remaining String and exit");
	if (scanner.hasNext() == false)
		EndOfFile = true;

	return line;
}

// GetNextToken calls GetNextChar repeatedly until a token is built.
public static String GetNextToken() {

	int maxIdenLength = 30;
	int maxNumLength = 16;
	
	ResetTypes();
	String token = new String();
	char ch = '\0';
	
	//if (usePrev = true) {
	//	System.out.println("usePrev set to true, ch = [" + prev + "]");
	//	ch = prev;
	//} else {
	//	System.out.println("usePrev false, fetching next char");
	//}
	while (token != null) {
		//if (usePrev = false) { 
			ch = GetNextChar(); 
			System.out.println("Start of token. fetching [" + ch + "]");
		//}
		if (Character.isLetter(ch)) {			// Create an Identifier Token
			IsIdentifier = true;
			tokenCode = 50;
			
			while (Character.isLetterOrDigit(ch)
					|| ch == '_'
					|| ch == '$') {
				token += ch;
				prevCh = ch; 
				ch = GetNextChar();
				System.out.println("While ch is letter or digit... fetching " + ch);
				if (!Character.isLetterOrDigit(ch)) {
					System.out.println(ch + " is not letter or digit. Returning token and decrementing globI for next token");
					usePrev = true;
				}
			}
			if (token.length() > maxIdenLength) {
				token = token.substring(0, 30);
				System.out.println("Warning, token exceeds length " + maxIdenLength + "! The token has been truncated.");
			}
												// TODO: confirm Identifier is not a reserve word.
			S.AddSymbol(token, 0, 0, 0);		// Add Identifier to Symbol Table
			return token;
		}
		else if (Character.isDigit(ch)) {		// Create a Digit Token (integer or float)
			IsInteger = true;
			tokenCode = 51;
			boolean dotFound = false;
			
			while (Character.isDigit(ch)) {
				token += ch;
				ch = GetNextChar();				
				if (ch == '.' && dotFound == false) {  // Create a Float token if . is found
					dotFound = true;
					IsFloat = true;
					tokenCode = 52;
					IsInteger = false;
					token += ch;
					ch = GetNextChar();	
				}
				if (IsFloat) {
					while (Character.isDigit(ch)) {
						token += ch;
						ch = GetNextChar();		
					}
					if (ch == 'e' || ch == 'E') {
						token += ch;
						ch = GetNextChar();	
						if (ch == '+' || ch == '-') {
							token += ch;
							ch = GetNextChar();	
						}
					}
					while (Character.isDigit(ch)) {
						token += ch;
						ch = GetNextChar();	
					}
					if (token.length() > maxNumLength) {
						token = token.substring(0, 30);
						System.out.println("Warning, token exceeds length " + maxNumLength + "! The token has been truncated.");
					}
					double tokenToDouble = Float.parseFloat(token); // convert string to float value
					S.AddSymbol(token, 1, 2, tokenToDouble);
					return token; // return float
				}
			}
			if (token.length() > maxNumLength) {
				token = token.substring(0, 30);
				System.out.println("Warning, token exceeds length " + maxNumLength + "! The token has been truncated.");
			}
			int tokenToInt = Integer.parseInt(token);
			S.AddSymbol(token, 1, 1, tokenToInt);
			return token; // return int
		}
		else if (ch == '\"') {					// Create a String Token, stripping the quotation marks
			ch = GetNextChar();	
			while (ch != '\"') {
				token += ch;
				ch = GetNextChar();	
				if (ch == '\"') {
					IsString = true;
					tokenCode = 53;
					return token;
				}
			}
		}
		else if (ch == '\0' && EndOfFile == true) {
			break;
			//return token;
		}
		else if (ch == '\0') {						// If token is still null, continue checking
		}
		else if (ch == '{' || ch == '(') {			// Create Comment Token
			if (ch == '{') {
				ch = GetNextChar();	
				while (ch != '}') {
					ch = GetNextChar();	
					//if (Character.isWhitespace(ch)) {
						//break;
					//}
				}
				continue;
			}
			else if (ch == '(') {
				ch = GetNextChar();	
				if (ch == '*') {
					while (ch != ')') {
						ch = GetNextChar();	
						System.out.println("in while");
						//if (ch == '}') {
						//	System.out.println("Error: Can't mix comment styles");
						//}
					}
					System.out.println("foo");
					continue;
				}
			}
		}
		else if (Character.isWhitespace(ch)) {		// Eat whitespace
			continue;
		}
		else if (ch == ':') {						// Create a : token
			token += ch;
			ch = GetNextChar();	
			if (ch =='=') {							// :=
				token += ch;
				return token;
			}
		}
		else {
			tokenCode = 99;
			token += ch;
			return token;
		}
	}
	return token;
}

// PrintToken prints each token's (1) lexeme, (2) token code, 
// (3) The proper 4-character mnemonic from the Reserve Table,
// and (4) For identifiers and literals added to the Symbol table,
// the corresponding Symbol Table index.
public static void PrintToken(String token, int tokenCode) {
	// Set a token's type
	String type = new String();
	if (IsIdentifier) { type = "Identifier"; }
	else if (IsInteger) { type = "Integer"; }
	else if (IsFloat) { type = "Float"; }
	else if (IsString) { type = "String"; }
	else if (IsComment) { type = "Comment"; }
	else { type = "Unknown"; }
	
	// Check if token resides in the Symbol Table
	if (token.length() > 0) {
		System.out.printf("%-12s %-12s %6s %n", token, type, tokenCode);
	}
}

//////////
// Main //
//////////
	public static void main(String[] args) throws FileNotFoundException {
		
		 echoOn = true;
		 String token = "foo";
		
		// Prepare a file to be read
		myFile = new File("test.txt");
		 //myFile = new File("LexicalTestF20.txt");
		scanner = new Scanner(myFile);
		
		// While there are characters to read, parse the contents into tokens
		while (token.length() != 0) {
			token = GetNextToken();
			PrintToken(token, tokenCode);
		}

		scanner.close();
		
		// Print the Symbol Table
		S.PrintSymbolTable();
		
	} // main
} // Refactored_pt2
