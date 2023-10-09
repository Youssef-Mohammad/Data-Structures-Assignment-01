/*
    Ahmed Sobhy Abd El Hady Abd El Rahman

    20200020


*/



#ifndef FRACTION_H
#define FRACTION_H
#include<iostream>
using namespace std;
class fraction
{
public:
    int num,den;
public:

    fraction();
    fraction(int x, int y);
    fraction(const fraction &f);
    fraction operator+(fraction &f);
    fraction operator-(fraction &f);
    fraction operator*(fraction &f);
    fraction operator/(fraction &f);


    friend ostream &operator<<(ostream& out, fraction &f);
    friend istream &operator>>(istream& in, fraction &f);


    bool operator <(fraction &f);
    bool operator >(fraction &f);
    bool operator ==(fraction &f);
    bool operator <=(fraction &f);
    bool operator >=(fraction &f);

    int gcd(int a, int b);
    void reduction();

};

#endif // FRACTION_H
