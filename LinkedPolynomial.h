///////////////////////////////////////////////////////////////
// In defining classes like this, we would normally separate //
// our .h header file from our .cpp implementation file.     //
// Unfortunately, due to restrictions in the zyLab platform  //
// in zyBooks, we will combine them all in this .h file.     //
///////////////////////////////////////////////////////////////

#ifndef LINKEDPOLYNOMIAL_H
#define LINKEDPOLYNOMIAL_H

#include "PolynomialInterface.h"
#include "Node.h"
#include "math.h"
#include <tuple>
#include <vector>
#include <iostream>
using namespace std;


//LinkedPolynomial Class inherited from PolynomialInterface class
//LinkedPolynomial Class will add terms to a linkedlist to make a polynomial
//This class will evaluate for each f(x) for polynomial, find its derivative
//Will also return highest degree of polynomial and if its constant of zero and print polynomial terms

class LinkedPolynomial : public PolynomialInterface
{
   
private:
      typedef tuple<double, unsigned> term;         //Declared a type tuple which stores coeff and exponent term
      term entry;                                   //Entry will store inputted coeff and expo in tuple and add it to linkedlist
      Node<term> *Poly = nullptr;                   //LinkedList Poly will store all the polynomial terms
      Node<double> *EvalPoly = nullptr;             //Linkedlist EvalPoly stores the f(x) evaluated values
public:
  
  //Default Constructor which will initialize polynomial to zero 
  LinkedPolynomial();
  //Destructor
  ~LinkedPolynomial();
  
 //Will add terms to the polynomial at the front of linked list or will add to existing term if it exists or to the middle or end accordingly   
 bool addTerm( double coefficient , unsigned exponent);
 
  //Will get the derivative of the polynomial and return it as LinkedPolynomial class object
 LinkedPolynomial getDerivative(); 
 
 //Will return true if the polynomial is constant zero  
 bool isZero() const;     
 
 //Will return the higest degree of the polynomial
 unsigned getDegree() const;
 
 //Will clear the polynomial       
 void clear();
 
//Will evaluate the polynomial for f(x) values provided
 double evaluate(double x);
 
//Will print the polynomial in a traditional sense with highest exponent term first to the constant  
 void print();
    
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Class Implementation///////////////////////////////////////////////////////


//Default Constructor which will initialize polynomial to zero 
 LinkedPolynomial::LinkedPolynomial(){                    
    entry = make_tuple(0,0);
    Node<term> *newNodePtr = new Node<term>(entry);
    newNodePtr->setNext(Poly);
    Poly = newNodePtr;
    }
  
  //Destructor
  LinkedPolynomial::~LinkedPolynomial(){
     clear();
  }
   
 //Will add terms to the polynomial at the front of linked list or will add to existing term if it exists or to the middle or end accordingly   
 bool LinkedPolynomial::addTerm( double coefficient , unsigned exponent){ 
       double coeff;
       unsigned expo;
       Node<term> *currPtr = Poly;

  if(Poly == nullptr && coefficient != 0){
      entry = make_tuple(coefficient, exponent);
      Node<term> *newNodePtr = new Node<term>(entry);
      newNodePtr->setNext(Poly);
      Poly = newNodePtr;  
      return true;
     }
   
  else 
   while(currPtr != nullptr && coefficient != 0){
     tie(coeff, expo) = currPtr->getItem();
    
    if(exponent == expo){
       coeff = coefficient + coeff;
        entry = make_tuple(coeff, exponent);
        Poly->setItem(entry);
        return true;
       }
           
    if(exponent > expo){
       entry = make_tuple(coefficient, exponent);
       Node<term> *newNodePtr = new Node<term>(entry);
       newNodePtr->setNext(Poly);
       Poly = newNodePtr;  
       return true;
       }       
    if(exponent < expo){
       tie(coeff, expo) = currPtr->getNext()->getItem(); 
       if(exponent == expo){
        coeff = coefficient + coeff;
        entry = make_tuple(coeff, exponent);
        currPtr = currPtr->getNext();
        currPtr->setItem(entry);
        return true;
       }
       if(exponent > expo){
          Poly = currPtr;
          currPtr = currPtr->getNext();
          entry = make_tuple(coefficient, exponent);
          Node<term> *newNodePtr = new Node<term>(entry);
          newNodePtr->setNext(currPtr);
          Poly->setNext(newNodePtr);
          return true;
       } 
    }   
          currPtr = currPtr->getNext();
   }
   }
  
  //Will get the derivative of the polynomial and return it as LinkedPolynomial class object
 LinkedPolynomial LinkedPolynomial::getDerivative(){ 
     LinkedPolynomial der;
     double coeff;
     unsigned expo;
     Node<term> *currPtr = Poly;
     while(currPtr != nullptr){
     tie(coeff, expo) = currPtr->getItem();
      if(expo == 0){
      }
      else{
        coeff = coeff*expo;
        der.entry = make_tuple(coeff, expo-1);
        Node<term> *newNodePtr = new Node<term>(der.entry);
        newNodePtr->setNext(der.Poly);
        der.Poly = newNodePtr;
      }
        currPtr = currPtr->getNext();
     } 
     return der;
  }
  
  //Will return true if the polynomial is constant zero  
  bool LinkedPolynomial::isZero() const{
       Node<term> *currNodePtr = Poly;
     if(currNodePtr == NULL){
       return true;
       }  
      }
       
  //Will return the higest degree of the polynomial
 unsigned LinkedPolynomial::getDegree() const{
       Node<term> *currNodePtr = Poly;
       unsigned exponent;
       if(Poly == nullptr){
          return 0;
       }
       else
       tie(ignore, exponent) = currNodePtr->getItem();
       return exponent;
       }
 
 //Will clear the polynomial       
void LinkedPolynomial:: clear(){
       Poly = nullptr;
    }

//Will evaluate the polynomial for f(x) values provided
double LinkedPolynomial:: evaluate(double x){
    Node<term> *currNodePtr = Poly;
    double total=0;
    unsigned exponent;
    double coeff;
    while(currNodePtr != nullptr){
      tie(coeff, exponent) = currNodePtr->getItem();
      total += (coeff*pow(x,exponent));
      currNodePtr = currNodePtr->getNext();
      }
      Node<double> *newNodePtr = new Node<double>(total);
      newNodePtr->setNext(EvalPoly);
      EvalPoly = newNodePtr;  
      return total;
 }
  
  //Will print the polynomial in a traditional sense with highest exponent term first to the constant  
  void LinkedPolynomial::print(){
      unsigned exponent;
      double coeff;
      Node<term> *currNodePtr = Poly;
    while(currNodePtr != nullptr){
          tie(coeff, exponent) = currNodePtr->getItem();
          if(exponent != 0){
            cout<< "("<< coeff << "x^" << exponent << ") + ";
            }
          else{
            cout<<"(" << coeff <<")";
           }
           currNodePtr = currNodePtr->getNext();
    }
    } 
    
    
      
    
    
    

#endif