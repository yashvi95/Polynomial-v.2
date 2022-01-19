#include <sstream>  // for istringstream
#include <iostream>
#include <vector>
#include <string>


using namespace std;

/** Function to split a string into tokens
    @param s The string that needs to be split into tokens.
    @param delimeter The character used to delimit/separate tokens.
    @return  A string vector containing the tokens in string s. */
    
vector<string> split( const string& s , char delimiter )
{
   vector<string> tokens;          // vector of tokens
   string token;                   // a single token
   istringstream tokenStream(s);   // an input string stream

   // Tokenize s by grabbing individual tokens
   while( getline( tokenStream , token , delimiter ) )
      tokens.push_back(token);    // add found token

   return tokens;
}