//Way 5: charAt(int indexNumber)
// Returns the character existing at the specified index, indexNumber in the given string.
// If the specified index number does not exist in the string, the method throws an unchecked exception, StringIndexOutOfBoundsException. 

// Java Program to Illustrate to Find a Character 
// in the String 

// Importing required classes 
import java.io.*; 

// Main class 
class GFG { 

	// Main driver method 
	public static void main(String[] args) 
	{ 

		// String in which a character to be searched. 
		String str 
			= "GeeksforGeeks is a computer science portal"; 

		// Returns index of first occurrence of character. 
		int firstIndex = str.indexOf('s'); 
		System.out.println("First occurrence of char 's'"
						+ " is found at : "
						+ firstIndex); 

		// Returns index of last occurrence specified 
		// character. 
		int lastIndex = str.lastIndexOf('s'); 
		System.out.println("Last occurrence of char 's' is"
						+ " found at : " + lastIndex); 

		// Index of the first occurrence of specified char 
		// after the specified index if found. 
		int first_in = str.indexOf('s', 10); 
		System.out.println("First occurrence of char 's'"
						+ " after index 10 : "
						+ first_in); 

		int last_in = str.lastIndexOf('s', 20); 
		System.out.println("Last occurrence of char 's'"
						+ " after index 20 is : "
						+ last_in); 

		// gives ASCII value of character at location 20 
		int char_at = str.charAt(20); 
		System.out.println("Character at location 20: "
						+ char_at); 

		// Note: If we uncomment it will throw 
		// StringIndexOutOfBoundsException 
		// char_at = str.charAt(50); 
	} 
}


//  Way 6: Searching Substring in the String

// The methods used for searching a character in the string which are mentioned above can also be used for searching the substring in the string. 
// Java Program to illustrate to Find a Substring 
// in the String 

// Importing required classes 
import java.io.*; 

// Main class 
class GFG { 

	// Main driver method 
	public static void main(String[] args) 
	{ 

		// A string in which a substring 
		// is to be searched 
		String str 
			= "GeeksforGeeks is a computer science portal"; 

		// Returns index of first occurrence of substring 
		int firstIndex = str.indexOf("Geeks"); 

		System.out.println("First occurrence of char Geeks"
						+ " is found at : "
						+ firstIndex); 

		// Returns index of last occurrence 
		int lastIndex = str.lastIndexOf("Geeks"); 
		System.out.println( 
			"Last occurrence of char Geeks is"
			+ " found at : " + lastIndex); 

		// Index of the first occurrence 
		// after the specified index if found 
		int first_in = str.indexOf("Geeks", 10); 
		System.out.println("First occurrence of char Geeks"
						+ " after index 10 : "
						+ first_in); 

		int last_in = str.lastIndexOf("Geeks", 20); 
		System.out.println("Last occurrence of char Geeks "
						+ "after index 20 is : "
						+ last_in); 
	} 
}



//


// Way 7: contains(CharSequence seq): It returns true if the string contains the specified sequence of char values otherwise returns false. 
//   Its parameters specify the sequence of characters to be searched and throw NullPointerException if seq is null. 

// Java Program to Illustrate How to Find a Substring 
// in the String using contains() Method 

// Importing required classes 
import java.io.*; 
import java.lang.*; 

// Class 
class GFG { 

	// Main driver method 
	public static void main(String[] args) 
	{ 
		// String in which substring 
		// to be searched 
		String test = "software"; 

		CharSequence seq = "soft"; 
		boolean bool = test.contains(seq); 
		System.out.println("Found soft?: " + bool); 

		// Returns true substring if found. 
		boolean seqFound = test.contains("war"); 
		System.out.println("Found war? " + seqFound); 

		// Returns true substring if found 
		// otherwise return false 
		boolean sqFound = test.contains("wr"); 
		System.out.println("Found wr?: " + sqFound); 
	} 
}


// Way 8: Matching String Start and End 

// boolean startsWith(String str): Returns true if the string str exists at the starting of the given string, else false.
// boolean startsWith(String str, int indexNum): Returns true if the string str exists at the starting of the index indexNum in the given string, else false.
// boolean endsWith(String str): Returns true if the string str exists at the ending of the given string, else false.



// Java Program to Match ofstart and endof a Substring 

// Importing required classes 
import java.io.*; 

// Main class 
class GFG { 

	// Main driver method 
	public static void main(String[] args) 
	{ 
		// Input string in which substring 
		// is to be searched 
		String str 
			= "GeeksforGeeks is a computer science portal"; 

		// Print and display commands 
		System.out.println(str.startsWith("Geek")); 
		System.out.println(str.startsWith("is", 14)); 
		System.out.println(str.endsWith("port")); 
	} 
}





