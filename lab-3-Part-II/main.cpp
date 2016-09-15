//****************************************************************
// Author: D.S. Malik
//
// This program illustrates how to use the class polynomialType.
//****************************************************************

#include <iostream>                                    //Line 1

#include "polynomialType.h"

# include "complexType.h"                       //Line 2

using namespace std;                                   //Line 3

int main()                                             //Line 4
{
     complexType one(43.2, 44.1);
    complexType two (33.2, 3);
   // cout << "----- " << one() << endl;
                                     //Line 5
    polynomialType p(8);                               //Line 6
    polynomialType q(4);                               //Line 7
    polynomialType t;                                  //Line 8

    cin >> p;                                          //Line 9
    cout << endl << "Line 10: p(x): " << p << endl;    //Line 10
    cout << endl << "Derivitive: " << ~p << endl;
    cout << "Line 11: p(5): " << p(5) << endl << endl; //Line 11

    cin >> q;                                          //Line 12
    cout << endl << "Line 13: q(x): " << q << endl
         << endl;                                      //Line 13

    t = p + q;                                         //Line 14

    cout << "Line 15: p(x) + q(x): " << t << endl;     //Line 15

    cout << "Line 16: p(x) - q(x): " << p - q << endl; //Line 16
    //system("pause");
    return 0;                                          //Line 17
}                                                      //Line 18
