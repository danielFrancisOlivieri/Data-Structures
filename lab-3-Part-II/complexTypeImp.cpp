

//Implementation file complexType.cpp

#include <iostream>
#include "complexType.h"
#include <math.h>

using namespace std;

ostream& operator<<(ostream& osObject,
                    const complexType& complex)

{
    // the offender

    osObject << "(";                    //Step a
    osObject << complex.realPart;       //Step b
    osObject << ", ";                   //Step c
    osObject << complex.imaginaryPart;  //Step d
    osObject << ")";                    //Step e

    return osObject;    //return the ostream object
}

istream& operator>>(istream& isObject, complexType& complex)
{
    char ch;

    isObject >> ch;                     //Step a
    isObject >> complex.realPart;       //Step b
    isObject >> ch;                     //Step c
    isObject >> complex.imaginaryPart;  //Step d
    isObject >> ch;                     //Step e

    return isObject;    //return the istream object
}

bool complexType::operator==
                    (const complexType& otherComplex) const
{
    return (realPart == otherComplex.realPart &&
            imaginaryPart == otherComplex.imaginaryPart);
}


    //Constructor
complexType::complexType(double real, double imag)
{
    realPart = real;
    imaginaryPart = imag;
}

    //Function to set the complex number after the object
    //has been declared.
void complexType::setComplex(const double& real,
                             const double& imag)
{
    realPart = real;
    imaginaryPart = imag;
}

void complexType::getComplex(double& real, double& imag) const
{
    real = realPart;
    imag = imaginaryPart;
}

	//overload the operator +
complexType complexType::operator+
 			   (const complexType& otherComplex) const
{
    complexType temp;

    temp.realPart = realPart + otherComplex.realPart;
    temp.imaginaryPart = imaginaryPart
                         + otherComplex.imaginaryPart;

	return temp;
};

    //overload the operator *
complexType complexType::operator*
 				(const complexType& otherComplex) const
{
    complexType temp;

    temp.realPart = (realPart * otherComplex.realPart) -
                 (imaginaryPart * otherComplex.imaginaryPart);
    temp.imaginaryPart = (realPart * otherComplex.imaginaryPart)
                   + (imaginaryPart * otherComplex.realPart);
    return temp;
};

// what exactly does the lab want us to find here?
 complexType complexType::operator~ ()
{
  imaginaryPart = imaginaryPart * -1;
  return this->imaginaryPart;
 // return complexType;
}

 complexType complexType::operator! ()
{
    double aSquared, bSquared, sum;

    aSquared = ((this->realPart) * (this->realPart));
bSquared = ((this->imaginaryPart) * (this->imaginaryPart));
sum = aSquared + bSquared;
absoluteValue = sqrt(sum);
return absoluteValue;
}

complexType operator- (complexType firstComplex, const complexType& otherComplex)
 {

     complexType temp;

    temp.realPart = firstComplex.realPart - otherComplex.realPart;
    temp.imaginaryPart = firstComplex.imaginaryPart - otherComplex.imaginaryPart;
    cout << "This is the f(): " << temp << endl;
    return temp;

 }

complexType operator/ (complexType firstComplex, const complexType& otherComplex)
 {

     complexType temp;

    temp.realPart = firstComplex.realPart / otherComplex.realPart;
    temp.imaginaryPart = firstComplex.imaginaryPart / otherComplex.imaginaryPart;

    return temp;

 }
