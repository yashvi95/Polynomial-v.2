///////////////////////////////////////////////////////////////
// ADT Polynomial /////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/** Developed by Ben Juliano for CSCI 211 @ Chico State
    @file PolynomialInterface.h */

#ifndef POLYNOMIAL_INTERFACE_
#define POLYNOMIAL_INTERFACE_

class PolynomialInterface
{
    public:
    
    /** Determines if this is the zero polynomial.
        @return true if polynomial is the constrant zero,
            or false if not. */
        bool isZero() const;
        
    /** Determines the degree of the polynomial.
        @return Degree of the polynomial. */
        unsigned getDegree() const;
        
    /** Adds a new term to the polynomial.
        @post  If successful, a new term is added to the polynomial
            and the degree of the polynomial is updated, if needed.
        @param coefficient The coefficient of the new term.
        @param exponent The exponent of the new term.
        @return  True if addition was successful, or false if not. */
        bool addTerm( double coefficient , unsigned exponent );

    /** Resets the polynomial to degree 0.
        @post  Polynomial is set to the zero polynomial. */
        void clear();

    /** Evaluates the polynomial based on a given value for x.
        @param x The value to evaluate the polynomial with.
        @return The value f(x) of the polynomial. */
        double evaluate( double x );

    /** Display the polynomial in the "traditional" sense.
        @post Display to standard output the non-zero terms of the
            polynomial from highest exponent to the lowest exponent.
            Displays constant polynomials correctly. */
        void print();

}; // end PolynomialInterface

#endif