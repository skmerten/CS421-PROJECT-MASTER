#include<iostream>
#include<fstream>
#include<string>

using namespace std;

/* Look for all **'s and complete them */

//=====================================================
// File scanner.cpp written by: Group Number: ** 
//=====================================================

// --------- Two DFAs ---------------------------------

// WORD DFA 
// Done by: **
// RE:   **
bool word (string s)
{

  int state = 0;
  int charpos = 0;

  // QUICK TEST OF SCANNER
  return true;

  /* replace the following todo the word dfa   
  
  while (s[charpos] != '\0') 
    {
      if (state == 0 && s[charpos] == 'a')
      state = 1;
      else
      if (state == 1 && s[charpos] == 'b')
      state = 2;
      else
      if (state == 2 && s[charpos] == 'b')
      state = 2;
      else
	  return(false);
      charpos++;
    }//end of while

  // where did I end up????
  if (state == 2) return(true);  // end in a final state
   else return(false);
 */
}

// PERIOD DFA 
// Done by: **
bool period (string s)
{  // complete this **
}

// ------ Three  Tables -------------------------------------

// TABLES Done by: Stephen Merten

// Dumping ALL token types from documentation here
enum tokentype {WORD, WORD1, WORD2, PERIOD, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR, EOFM, ERROR};
// Per instructions: this list of strings directly matches the above. I think We have freedom to change but for now i left it. ~ Stephen
string tokenName[30] = {"WORD", "WORD1", "WORD2", "PERIOD", "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR", "EOFM", "ERROR"}; 

// ** Need the reservedwords table to be set up here. 

/* I am setting this up like above:
 * reservedWords and reservedTokens will be of identical length. I plan to traverse the Words list for a match
 * grab the index of the match (if applicable) and then use that to access the corresponding token from the tokens list
 * ~ Stephen
*/
const int reservedWordCount = 18;
string reservedWords[reservedWordCount]= {"masu", "masen", "mashita", "masendeshita", "des", "deshita", "o", "we", "ni", "watashi", 
      "anata", "kare", "anojo", "sore", "mata", "soshite", "shikashi", "dakara"};
tokentype reservedTokens[reservedWordCount] = {VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, 
      PRONOUN, PRONOUN, PRONOUN, PRONOUN, CONNECTOR, CONNECTOR, CONNECTOR, CONNECTOR};

// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.

// ------------ Scanner and Driver ----------------------- 

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Stephen Merten
int scanner(tokentype& tt, string& w)
{ 
  // ** Grab the next word from the file via fin
  // 1. If it is eofm, return right now.    DONE ~ Stephen

  /*  **
  2. Call the token functions (word and period) 
     one after another (if-then-else).
     Generate a lexical error message if both DFAs failed.
     Let the tokentype be ERROR in that case.   DONE ~ Stephen

  3. If it was a word,
     check against the reservedwords list.
     If not reserved, tokentype is WORD1 or WORD2
     decided based on the last character. 

  4. Return the token type & string  (pass by reference)
  */

  cout << ".....Scanner was called..." << endl;

  fin >> w;  // grab next word from input file
  cout << ">>>>>Word is:" << w << endl;   

  if (w == "eofm"){                 // Check for EOF -> return if EOF
    tt = EOFM;
  }else if(word(w)){                // Check for WORD
    tt = WORD;
  } else if (period(w)){            // Check for PERIOD
    tt = PERIOD;
  } else //none of the FAs returned TRUE
    { cout << ">>>>>Lexical Error: The string is not in my language" << endl;
      tt = ERROR; }

  // If word check for word1 or word2
  if (tt == WORD){
    if(w[w.size()] == 'I' || w[w.size()-1] == 'E'){
        tt = WORD2;
      }else if(w[w.size()] == 'a' || w[w.size()-1] == 'e' || w[w.size()-1] == 'i' || w[w.size()-1] == 'o' || w[w.size()-1] == 'u'){
        tt = WORD1;
    }
    // Capture token for reserved word if present
    for(int i = 0; i < reservedWordCount; i++){
      if (w == reservedWords[i]){
        tt = reservedTokens[i];
      }
    }
  }
}//the end of scanner



// The temporary test driver to just call the scanner repeatedly  
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!! 
// Done by:  Louis
int main()
{
  tokentype thetype;
  string theword; 
  string filename;

  cout << "Enter the input file name: ";
  cin >> filename;

  fin.open(filename.c_str());

  // the loop continues until eofm is returned.
   while (true)
    {
       scanner(thetype, theword);  // call the scanner which sets
                                   // the arguments  
       if (theword == "eofm") break;  // stop now

       cout << "Type is:" << tokenName[thetype] << endl;
       cout << "Word is:" << theword << endl;   
    }

   cout << "End of file is encountered." << endl;
   fin.close();

}// end

