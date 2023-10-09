/*
    Ahmed Sobhy Abd El Hady Abd El Rahman

    20200020


*/



#include "FractionCalculator.h"

FractionCalculator::FractionCalculator()
{

}

void FractionCalculator::Calculator(){
    fraction f1,f2;
    cout <<"Enter the first fraction number" << endl;
    cin >> f1;
    cout <<"Enter the second fraction number"<<endl;
    cin >> f2;
    int counter;
    string reduction;
    while (true){
        cout << endl;
        cout << "Choose a mathematical calculation" << endl;
        cout <<"1 Adding" << endl;
        cout <<"2 Subtracting" << endl;
        cout <<"3 Multiplication" << endl;
        cout <<"4 Dividing" << endl;
        cout <<"5 Exit" << endl;
    cin >> counter;
    if(counter==1){

                fraction f3(f1+f2);

                cout<<"f1+f2= "<<f3 <<endl;
                if (f3.num == 0 ){
                    continue;
                } else {
                cout << "Would you like to reduce fraction?"<< "        Type Yes or No" << endl;
                cin >> reduction;
                if (reduction == "YES" || reduction == "yes" || reduction == "Yes" ){
                   f3.reduction();
                   cout << endl;
                   cout << "Fraction after reduction: " << f3 << endl;
                } else if (reduction == "NO" || reduction == "no" || reduction == "No"){
                    continue;
                }
                else {
                    continue;
                }
                }

        }
        else if(counter==2){

                fraction f3(f1-f2);

                cout<<"f1-f2= "<<f3<<endl;
                if (f3.num == 0){
                        continue;
                } else {

                cout << "Would you like to reduce fraction?"<< "       Type Yes or No" << endl;
                cin >> reduction;
                if (reduction == "YES" || reduction == "yes" || reduction == "Yes" ){
                   f3.reduction();
                   cout << endl;
                   cout << "Fraction after reduction: " << f3 << endl;
                } else if (reduction == "NO" || reduction == "no" || reduction == "No"){
                    continue;
                }
                else {
                    continue;
                }
        }}
        else if(counter==3){

                fraction f3(f1*f2);

                cout<<"f1*f2= "<<f3<<endl;
                if (f3.num == 0){
                        continue;
                        }
                        else {
                cout << "Would you like to reduce fraction?"<< "        Type Yes or No" << endl;
                cin >> reduction;
                if (reduction == "YES" || reduction == "yes" || reduction == "Yes" ){
                   f3.reduction();
                   cout << endl;
                   cout << "Fraction after reduction: " << f3 << endl;
                } else if (reduction == "NO" || reduction == "no" || reduction == "No"){
                    continue;
                }
                else{
                    continue;
                }
                                }
        }
         else if(counter==4){
                fraction f3(f1/f2);

                cout<<"f1/f2= "<<f3<<endl;
                if (f3.num == 0){
                        continue;
                } else {

                cout << "Would you like to reduce fraction?"<< "        Type Yes or No" << endl;
                cin >> reduction;
                if (reduction == "YES" || reduction == "yes" || reduction == "Yes" ){
                   f3.reduction();
                   cout << endl;
                   cout << "Fraction after reduction: " << f3 << endl;
                } else if (reduction == "NO" || reduction == "no" || reduction == "No"){
                    continue;
                }
                else{
                    continue;
                }
                }
        }
        else if(counter==5){
                cout << endl;
                cout << "Thank you for using my program!"<< endl;
                cout<<"Have a wonderful day!"<<endl;
                break;

        }
    }
}
