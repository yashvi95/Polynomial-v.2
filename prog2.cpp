#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "split.h"
#include "Node.h"
#include "LinkedPolynomial.h"
#include "PolynomialInterface.h"

using namespace std;

int main() {
   
    string input; // input string to hold 1 line from cin
    char delimiter = ' '; // what separates tokens in the input string
    vector<string> listOfTokens; // store tokens of input here  
    LinkedPolynomial poly, der;  //Declared 2 LinkedPolynomial Class objects, one to store poly, one to store derivative
 
    // Read in a string as a line of text from standard input.
    while(getline( cin ,input)){ 
       
        listOfTokens = split( input , delimiter ); //Use the split() function above to extract tokens
        
        unsigned exponentmax = listOfTokens.size()-1; //Variable to determine the exponent for each coefficient
             
        for(int i =listOfTokens.size()-1; i >= 0; i--) //Adding in Coeff and Exponent to corrsponding vector
              {
                //Converting string to double, inputting (coefficient & exponenet) term in polynomial. 
                double coeff = stod(listOfTokens.at(i));
                unsigned exponent = ((exponentmax-i));
                poly.addTerm(coeff, exponent);
		       } 
		 //Converting the polyomial to its derivative
		 der = poly.getDerivative();
        
        listOfTokens.clear(); //Clearing the the string vector, for next line of input, f(x)
        
        getline(cin , input); //Reading in the x values to solve polynomial for f(x)
        listOfTokens = split( input , delimiter );
        
             for(int i= 0; i<listOfTokens.size(); i++)
             {
               double f_x = stod(listOfTokens.at(i));    //converting f(x) values from string to double
               if(i!= 0 && i<listOfTokens.size()){
               cout<<" "<<"("<< poly.evaluate(f_x)<<","<< der.evaluate(f_x) << ")"; //evaluating f(x), for each input entered for its polynomial and derivative 
               }
               else
               cout<<"("<< poly.evaluate(f_x)<<","<< der.evaluate(f_x) << ")";  
             } 
       
        cout<<endl;
        
        poly.clear(); //clearing polynomial before next 2 lines of input
        
       
      } 

   return 0;
}