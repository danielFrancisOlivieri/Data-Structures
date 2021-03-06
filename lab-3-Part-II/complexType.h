//Specification file complexType.h

#ifndef H_complexNumber
#define H_complexNumber

//*****************************************************************
// Author: D.S. Malik
// class complexType.h
// This class specifies the members to implement a complex number.
//*****************************************************************
#include <math.h>
#include <iostream>

using namespace std;

class complexType
{
      //Overload the stream insertion and extraction operators
    friend ostream& operator<<(ostream&, const complexType&);
    friend istream& operator>>(istream&, complexType&);

public:
    double absoluteValue;
    void setComplex(const double& real, const double& imag);
      //Function to set the complex numbers according to
      //the parameters.
      //Postcondition: realPart = real; imaginaryPart = imag;

    void getComplex(double& real, double& imag) const;
	  //Function to retrieve the complex number.
      //Postcondition: real = realPart; imag = imaginaryPart;

    complexType(double real = 0, double imag = 0);
      //Constructor
      //Initializes the complex number according to
      //the parameters.
      //Postcondition: realPart = real; imaginaryPart = imag;

      double getReal() {
      return realPart;
      }
      double getImaginary(){
      return imaginaryPart;
      }


    complexType operator+
                     (const complexType& otherComplex) const;
      //Overload the operator +

    complexType operator*
                     (const complexType& otherComplex) const;
      //Overload the operator *

    bool operator == (const complexType& otherComplex) const;
      //Overload the operator ==

    complexType operator~ ();
//Overload the operator ~

complexType operator! ();
//Overload the operator !

      friend complexType operator-
                     ( complexType firstComplex, const complexType& otherComplex);
      //Overload the operator - in a nonmember function
     friend complexType operator/
                     (complexType firstComplex, const complexType& otherComplex) ;
      //Overload the operator / in a nonmember function

private:
    double realPart;       //variable to store the real part
    double imaginaryPart;  //variable to store the
                           //imaginary part
};


//Implementation file complexType.cpp




#endif

