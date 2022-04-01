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
/* q0 = 0
 * qsa = 1
 * q0q1 = 2
 * qt = 3
 * qs = 4
 * qy = 5
 * q0qy = 6
 * qc = 7
 * q0q1 = 8
 */
  int state = 0;
  int charpos = 0;
  /* replace the following todo the word dfa */
  
  while (s[charpos] != '\0') 
    {
      cout << "Char is: " << s[charpos] << endl;
      cout << "State is: " << state << endl;
      cout << endl;
      // From q0
      if (state == 0 && (s[charpos] == 'a' && s[charpos] == 'e' && s[charpos] == 'i' && s[charpos] == 'o' && s[charpos] == 'u')){
      state = 8;
      }else if (state == 0 && (s[charpos] == 'd' && s[charpos] == 'w' && s[charpos] == 'z' && s[charpos] == 'y' && s[charpos] == 'j')){
      state = 1;
      }else if (state == 0 && (s[charpos] == 'b' && s[charpos] == 'g' && s[charpos] == 'h' && s[charpos] == 'k' && s[charpos] == 'm'
            && s[charpos] == 'n' && s[charpos] == 'p' && s[charpos] == 'r')){
      state = 5;
      }else if (state == 0 && s[charpos] == 'c'){
      state = 7;
      }else if (state == 0 && s[charpos] == 't'){
      state = 3;
      }else if (state == 0 && s[charpos] == 's'){
      state = 4;
      // From qsa
      }else if (state == 1 && (s[charpos] == 'a' && s[charpos] == 'e' && s[charpos] == 'i' && s[charpos] == 'o' && s[charpos] == 'u')){
      state = 8;
      // From qy
      }else if (state == 5 && (s[charpos] == 'a' && s[charpos] == 'e' && s[charpos] == 'i' && s[charpos] == 'o' && s[charpos] == 'u')){
      state = 8;
      }else if (state == 5 && s[charpos] == 'y'){
      state = 1;
      // From qt
      }else if (state == 3 && s[charpos] == 's'){
      state = 1;
      }else if (state == 3 && (s[charpos] == 'a' && s[charpos] == 'e' && s[charpos] == 'i' && s[charpos] == 'o' && s[charpos] == 'u')){
      state = 8;
      // From qs
      }else if (state == 4 && s[charpos] == 'h'){
      state = 1;
      }else if (state == 4 && (s[charpos] == 'a' && s[charpos] == 'e' && s[charpos] == 'i' && s[charpos] == 'o' && s[charpos] == 'u')){
      state = 8;
      // From qc
      }else if (state == 5 && s[charpos] == 'h'){
      state = 1;
      // From q0q1
      }else if (state == 8 && (s[charpos] == 'a' && s[charpos] == 'e' && s[charpos] == 'i' && s[charpos] == 'o' && s[charpos] == 'u')){
      state = 8;
      }else if (state == 8 && s[charpos] == 'n'){
      state = 6;
      }else if (state == 8 && (s[charpos] == 'd' && s[charpos] == 'w' && s[charpos] == 'z' && s[charpos] == 'y' && s[charpos] == 'j')){
      state = 1;
      }else if (state == 8 && s[charpos] == 'c'){
      state = 7;
      }else if (state == 8 && s[charpos] == 't'){
      state = 3;
      }else if (state == 8 && s[charpos] == 's'){
      state = 4;
      //else if (state == 8 && s[charpos] == 'h')
      //state =;
      // From q0qy  
      }else if (state == 6 && (s[charpos] == 'a' && s[charpos] == 'e' && s[charpos] == 'i' && s[charpos] == 'o' && s[charpos] == 'u')){
      state = 8; 
      }else if (state == 6 && (s[charpos] == 'd' && s[charpos] == 'w' && s[charpos] == 'z' && s[charpos] == 'y' && s[charpos] == 'j')){
      state = 1;
      }else if (state == 6 && (s[charpos] == 'b' && s[charpos] == 'g' && s[charpos] == 'h' && s[charpos] == 'k' && s[charpos] == 'm'
            && s[charpos] == 'n' && s[charpos] == 'p' && s[charpos] == 'r')){
      state = 5;
      }else if (state == 6 && s[charpos] == 'c'){
      state = 7;
      }else if (state == 6 && s[charpos] == 't'){
      state = 3;
      }else if (state == 6 && s[charpos] == 's'){
      state = 4;
      }else{
	      return(false);
      }
      charpos++;
    }//end of while

  if (state == 0 || state == 2 || state == 8) return(true);  // end in a final state
   else return(false);
}

// PERIOD DFA 
// Done by: Stephen Merten
bool period (string s)
{  
  if(s.size() > 1){
    return false;
  }else if(s != "."){
    return false;
  }else{
    return true;
  }
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

  fin >> w;  // grab next word from input file
  cout << "THIS IS THE WORD" << w << endl;
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
    if(w[w.size()-1] == 'I' || w[w.size()-1] == 'E'){
        tt = WORD2;
      }else if(w[w.size()-1] == 'n' || w[w.size()-1] == 'a' || w[w.size()-1] == 'e' || w[w.size()-1] == 'i' || w[w.size()-1] == 'o' || w[w.size()-1] == 'u'){
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

