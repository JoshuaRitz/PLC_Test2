package PLC_Test2;
import java.util.*;
import java.io.*;

public class frontcToJava2 {
	/* Global declarations */
	/* Variables */
	static int charClass;
	static char lexeme[] = new char[100];
	static char nextChar;
	static int lexLen;
	static int token;
	static int nextToken;
	static File input_file;
	static FileReader filereader;
	
	/* Character classes */
	static final int LETTER = 0;
	static final int DIGIT = 1;
	static final int UNKNOWN = 99;
	
	/* Token codes */
	static final int INT_LIT = 10;
	static final int IDENT = 11;
	static final int ASSIGN_OP = 20;
	static final int ADD_OP = 21;
	static final int SUB_OP = 22;
	static final int MULT_OP = 23;
	static final int DIV_OP = 24;
	static final int LEFT_PAREN = 25;
	static final int RIGHT_PAREN = 26;
	static final int MOD_OP = 27;
	
	/* loopup - a function to lookup operators and parentheses
	 * and return the token */
	static void lookup(char ch) {
		switch(ch) {
		
		case '(':
			addChar();
			nextToken = LEFT_PAREN;
			break;
			
		case ')':
			addChar();
			nextToken = RIGHT_PAREN;
			break;
			
		case '+':
			addChar();
			nextToken = ADD_OP;
			break;
			
		case '-':
			addChar();
			nextToken = SUB_OP;
			break;
			
		case '*':
			addChar();
			nextToken = MULT_OP;
			break;
			
		case '/':
			addChar();
			nextToken = DIV_OP;
			break;
			
		case '%':
			addChar();
			nextToken = MOD_OP;
			break;	
			
			default:
				addChar();
				nextToken = -1;
				lexeme[0] = 'E';
				lexeme[1] = 'O';
				lexeme[2] = 'F';
				lexeme[3] = 0;
				break;
		}
	}
	
	/* addChar - a function to add nextChar to lexeme */
	static void addChar() {
		if(lexLen <= 98) {
			lexeme[lexLen++] = nextChar;
			lexeme[lexLen] = 0;
		} else {
			System.out.println("Error - lexeme is too long");
		}
	}
	
	/* getChar - a function to get the next character of
	 * input and determine its character class */
	static void getChar() throws IOException {
		nextChar = (char)filereader.read();
		if(nextChar != 0) {
			if(Character.isLetterOrDigit(nextChar)) {
				charClass = LETTER;
			} else if(Character.isDigit(nextChar)) {
				charClass = DIGIT;
			} else {
				charClass = UNKNOWN;
			}
		} else {
			charClass = -1;
		}
	}
	
	/* getNonBlank - a function to call getChar until it
	 * returns a non-whitespace character */
	static void getNonBlank() throws IOException {
		while(Character.isWhitespace(nextChar)) {
			getChar();
		}
	}
	
	/* lex - a simple lexical analyzer for arithmetic expressions */
	static int lex() throws IOException {
		lexLen = 0;
		getNonBlank();
		switch(charClass) {
		
		/* Parse identifiers */
		case LETTER:
			addChar();
			getChar();
			while(charClass == LETTER || charClass == DIGIT) {
				addChar();
				getChar();
			}
		nextToken = IDENT;
		break;
		
		/* Parse integer literals */
		case DIGIT:
			addChar();
			getChar();
			while(charClass == DIGIT) {
				addChar();
				getChar();
			}
			nextToken = INT_LIT;
			break;
		
		/* Parse Parentheses and operators */
		case UNKNOWN:
			lookup(nextChar);
			getChar();
			break;
		
		/* EOF */
		default:
			nextToken = -1;
			lexeme[0] = 'E';
			lexeme[1] = 'O';
			lexeme[2] = 'F';
			lexeme[3] = 0;
			break;
		}
		System.out.print("Next token is: " + nextToken + " Next lexeme is: "/* + lexeme[0] */);
		for(int i = 0; i < lexeme.length; i++) { 
			System.out.print(lexeme[i]);
		}
		System.out.println();
		return nextToken;
	}
	
	/* expr
	 Parses strings in the language generated by the rule:
	 <expr> -> <term> {(+ | -) <term>}
	 */
	static void expr() throws IOException {
		 System.out.print("Enter <expr>\n");
		/* Parse the first term */
		 term();
		/* As long as the next token is + or -, get
		 the next token and parse the next term */
		 while (nextToken == ADD_OP || nextToken == SUB_OP) {
			 lex();
			 term();
		 }
		 System.out.print("Exit <expr>\n");
	}

	/* error
	 Parses strings in the language generated by the rule:
	 rule not found
	 */
	static void error() throws IOException {
		System.out.print("Error - Symbol not found\n");
	}
	
	/* term
	 Parses strings in the language generated by the rule:
	 <term> -> <factor> {(* | /) <factor>}
	 */
	static void term() throws IOException {
		 System.out.print("Enter <term>\n");
		/* Parse the first factor */
		 factor();
		/* As long as the next token is * or /, get the
		 next token and parse the next factor */
		 while (nextToken == MULT_OP || nextToken == DIV_OP || nextToken == MOD_OP) {
			 lex();
			 factor();
		 }
		 System.out.print("Exit <term>\n");
	}

	/* factor
	 Parses strings in the language generated by the rule:
	 <factor> -> id | int_constant | ( <expr> )
	 */
	static void factor() throws IOException {
		 System.out.print("Enter <factor>\n");
		/* Determine which RHS */
		 if (nextToken == IDENT || nextToken == INT_LIT)
			/* Get the next token */
			 lex();
			/* If the RHS is ( <expr> ), call lex to pass over the
			 left parenthesis, call expr, and check for the right
			 parenthesis */
		 else { if (nextToken == LEFT_PAREN) {
			 lex();
			 expr();
			 if (nextToken == RIGHT_PAREN)
			 	lex();
			 else
			 	error();
			 }
			/* It was not an id, an integer literal, or a left
			 parenthesis */
			 else
			 error();
		 }
		 System.out.print("Exit <factor>\n");
	}



	/****

	Trace of the parse of (sum + 47) / total:
	Next token is: 25, Next lexeme is (
	Enter <expr>
	Enter <term>
	Enter <factor>
	Next token is: 11, Next lexeme is sum
	Enter <expr>
	Enter <term>
	Enter <factor>
	Next token is: 21, Next lexeme is +
	Exit <factor>
	Exit <term>
	Next token is: 10, Next lexeme is 47
	Enter <term>
	Enter <factor>
	Next token is: 26, Next lexeme is )
	Exit <factor>
	Exit <term>
	Exit <expr>
	Next token is: 24, Next lexeme is /
	Exit <factor>
	Next token is: 11, Next lexeme is total
	Enter <factor>
	Next token is: -1, Next lexeme is EOF
	Exit <factor>
	Exit <term>
	Exit <expr>

	****/
	
	public static void main(String[]args) throws FileNotFoundException, IOException {
		/* Open the input data file and process its contents */
		input_file = new File("lexTester.txt"); 
		filereader = new FileReader(input_file);
		getChar();
		do{
			lex();
			expr();
		} while(nextToken != -1);
	    	System.out.println("End of parse!");
	}
}