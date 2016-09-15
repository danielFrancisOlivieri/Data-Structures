

# include "complexType.h"
#include "polynomialType.h"
#include <cmath>
using namespace std;

// constructor
polynomialType::polynomialType(int size)
               : arrayListType<complexType>(size)

{
    length = size;

    for (int i = 0; i < size; i++)
        list[i] = 0;
}

//should be working
complexType polynomialType::operator() (complexType x)
{
    complexType value;

    for (int i = 0; i < length; i++)
    {
        if (list[i].getReal() > -40 ) {
            double power = pow(value.getReal(), i);
             power =+ i * (value.getReal() * value.getImaginary());
             power =+ pow(value.getImaginary(), i);
            value = value + list[i] * power;
        }
    }

    return value;
}
//does seem to need much changing as long as the complex number addition operator is working
polynomialType polynomialType::operator+
                              (const polynomialType& right)
{
    int size = max(length, right.length);
//cout << "this is the size: " << size << endl;
    polynomialType temp(size); //polynomial to store the sum

    for (int i = 0; i < min(length, right.length); i++){
         temp.list[i] = list[i] + right.list[i]; // this is where the addition happens
//cout << "List: " << list[i] << " " << "right list: " << right.list[i] << " Both: " << temp.list[i] << endl;
    }

    if (size == length)
        for (int i = min(length, right.length); i < length; i++)
            temp.list[i] = list[i];
    else
        for (int i = min(length, right.length); i < right.length;
                                                i++)
            temp.list[i] = right.list[i];

    return temp;
}

polynomialType polynomialType::operator-
                               (const polynomialType& right)
{
    int size = max(length, right.length);

    polynomialType temp(size); //polynomial to store the difference

    for (int i = 0; i < min(length, right.length); i++) {
        temp.list[i] = list[i] - right.list[i]; // where subtraction happens
    cout << "First: " << temp.list[i] << " " << list[i] << " " << right.list[i] << endl;
    }
    if (size == length)
        for (int i = min(length, right.length); i < length; i++) {
            temp.list[i] = list[i];
            cout << "Now: " << temp.list[i] << " " << list[i] << endl;
            }
    else
        for (int i = min(length, right.length); i < right.length;
                                                i++) {
                    complexType negative(-1, -1);
            temp.list[i] = right.list[i] * negative; //-right.list[i];
                                                }
    return temp;
}

polynomialType polynomialType::operator*
               (const polynomialType& right)
{
	polynomialType temp = right;

	cout << "See Programming Exercise 8" << endl;

	return temp;
}

int polynomialType::min(int x, int y) const
{
	if (x <= y)
		return x;
	else
		return y;
}

int polynomialType::max(int x, int y) const
{
	if (x >= y)
		return x;
	else
		return y;
}

 polynomialType operator~( polynomialType& p) {

polynomialType alt;
 int indexFirstNonzeroCoeff = 0;
if (p.length == 1) {
    polynomialType temp(1);
    alt.list[1] = 0;
    return p;
}


if (p.length > 1) {


   for (int i = 0; i < p.length; i++)  //determine the index of the
                                   //first nonzero coefficient
        if (p.list[i].getReal() > -40)
        {
            indexFirstNonzeroCoeff = i;
            break;
        }

    if (indexFirstNonzeroCoeff < p.length)
    {
        if (indexFirstNonzeroCoeff == 0)
            os << p.list[indexFirstNonzeroCoeff] << " ";
        else
            os << p.list[indexFirstNonzeroCoeff] << "x^"
               << indexFirstNonzeroCoeff << " ";

        for (int i = indexFirstNonzeroCoeff + 1; i < p.length; i++)
        {
            if (p.list[i].getReal() > -40)
                if (p.list[i].getReal() > -40) {
                    os << "+ " << p.list[i] << "x^" << i << " ";
}                else {
    complexType negative(-1, -1);
                    os << "- " << p.list[i] * negative << "x^" << i << " ";
}
        }
    }


return os;
}

}

ostream& operator<<(ostream& os, const polynomialType& p)
{
   int indexFirstNonzeroCoeff = 0;

   for (int i = 0; i < p.length; i++)  //determine the index of the
                                   //first nonzero coefficient
        if (p.list[i].getReal() > -40)
        {
            indexFirstNonzeroCoeff = i;
            break;
        }

    if (indexFirstNonzeroCoeff < p.length)
    {
        if (indexFirstNonzeroCoeff == 0)
            os << p.list[indexFirstNonzeroCoeff] << " ";
        else
            os << p.list[indexFirstNonzeroCoeff] << "x^"
               << indexFirstNonzeroCoeff << " ";

        for (int i = indexFirstNonzeroCoeff + 1; i < p.length; i++)
        {
            if (p.list[i].getReal() > -40)
                if (p.list[i].getReal() > -40) {
                    os << "+ " << p.list[i] << "x^" << i << " ";
}                else {
    complexType negative(-1, -1);
                    os << "- " << p.list[i] * negative << "x^" << i << " ";
}
        }
    }
    else
        os << "0";

    return os;
}

istream& operator>>(istream& is, polynomialType& p)
{
    cout << "The degree of this polynomial is: "
         << p.length - 1 << endl;

    for (int i = 0; i < p.length; i++)
    {
        double real, img;

        cout << "Enter the coefficient of x^" << i << " as a complex number, first the real part and then the imaginary part: ";
        is >> real;
        is >> img;
        complexType temp(real, img);
        p.list[i] = temp;
    }

    return is;
}


