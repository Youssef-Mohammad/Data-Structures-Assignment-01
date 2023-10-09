/*
    Ahmed Sobhy Abd El Hady Abd El Rahman

    20200020


*/



#include "fraction.h"
#include<iostream>
using namespace std;
// Constructors
    fraction:: fraction(){
        num = 0;
        den =0;
        }
    fraction::fraction (int x, int y){
            num = x;
            den = y;
        };
    fraction :: fraction(const fraction &f){
        num = f.num;
        den = f.den;
        }
// Operators for mathematical calculations
    fraction fraction:: operator+(fraction &f){
           fraction tmp;
           tmp.den = den * f.den;
           tmp.num =(tmp.den/den*num)+(tmp.den/f.den*f.num);
           return tmp;

        };
    fraction fraction:: operator-(fraction &f){
           fraction tmp;
           tmp.den = den * f.den;
           tmp.num =(tmp.den/den*num)-(tmp.den/f.den*f.num);
           return tmp;

        };
    fraction fraction:: operator*(fraction &f){
           fraction tmp;
           tmp.den = den * f.den;
           tmp.num =num*f.num;
           return tmp;

        };
    fraction fraction:: operator/(fraction &f){
           fraction tmp;
           tmp.den = den*f.num;
           tmp.num = num*f.den;
           return tmp;

        };
// Input and Output operators
    ostream &operator<<(ostream& out, fraction &f){
            if(f.num == 0){
                out << f.num;
            } else if(f.den == 1){
            out << f.num;
            }
             else if (f.den == 0){
            cout <<"You can't divide by zero" << endl;

             } else

             {
            out << f.num << "/" <<f.den;
            }
            return out;
        };
    istream &operator>>(istream& in, fraction &f){
        cout << "Enter Nominator: " << endl;
            in >> f.num;
        cout << "Enter  Dominator: "<< endl;
            in >> f.den;
                while(f.den == 0){
                    cout <<"You can't enter a number with zero denominator" << endl;
                    cout << "Please enter correct number..." << endl;
                    cout << endl;
                    cout << "Enter Nominator: " << endl;
                        in >> f.num;
                    cout << "Enter  Dominator: "<< endl;
                        in >> f.den;
                }
                return in;

            }
// Comparison operators
        bool fraction:: operator <(fraction &f){
            bool tmp = true;
            float x = num;
            float y = den;
            float z = x/y;
            float a = f.num;
            float b = f.den;
            float c = a/b;
            if(z<c){
                tmp = true;
            }
            else{
                tmp = false;
            }
            return tmp;
        }
        bool fraction:: operator >(fraction &f){
            bool tmp = true;
            float x = num;
            float y = den;
            float z = x/y;
            float a = f.num;
            float b = f.den;
            float c = a/b;
            if(z>c){
                tmp = true;
            }
            else{
                tmp = false;
            }
            return tmp;
        }
        bool fraction:: operator ==(fraction &f){
            bool tmp = true;
            float x = num;
            float y = den;
            float z = x/y;
            float a = f.num;
            float b = f.den;
            float c = a/b;
            if(z==c){
                tmp = true;
            }
            else{
                tmp = false;
            }
            return tmp;
        }
        bool fraction:: operator <=(fraction &f){
            bool tmp = true;
            float x = num;
            float y = den;
            float z = x/y;
            float a = f.num;
            float b = f.den;
            float c = a/b;
            if(z<=c){
                tmp = true;
            }
            else{
                tmp = false;
            }
            return tmp;
        }
        bool fraction:: operator >=(fraction &f){
            bool tmp = true;
            float x = num;
            float y = den;
            float z = x/y;
            float a = f.num;
            float b = f.den;
            float c = a/b;
            if(z>=c){
                tmp = true;
            }
            else{
                tmp = false;
            }
            return tmp;
        }
// Function to find the greatest common divisor
    int fraction:: gcd(int n, int d)
    {
    if (d == 0){
        return n;
    }
    return gcd(d,n%d);
    }
// Reduction function by using the gcd
    void fraction:: reduction()
    {
    int x;
    x = gcd(num,den);
    num = num/x;
    den = den/x;

    }
