#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;
class BigInt{
private:
    string num;
public:
// Constructors
    BigInt(string n){
        num = n;
    }
    BigInt(){
        num = "";
    }
    BigInt(long long n){
        num = to_string(n);
    }
// Getting the size of string
    int size(){
        return num.length();
    }
// Operator +
    BigInt operator+(BigInt & obj){
        string result = "";
        if((num[0] == '-' || obj.num[0] == '-' ) && (num[0] != '-' && obj.num[0] != '-' )){

            if(num[0]=='-'){
                num.erase(0,1);
                long long n  = 0;
                int count = 1;
                for(int i=num.length()-1;i>=0;i--){
                    n += (num[i]-48)*count;
                    count *=10;
                }
                n = ( (pow(10,num.length()) -1) - n );
                num = to_string(n);

            }

            if(obj.num[0]=='-'){
                obj.num.erase(0,1);
                long long n  = 0;
                int count = 1;
                for(int i=obj.num.length()-1;i>=0;i--){
                    n += (obj.num[i]-48)*count;
                    count *=10;
                }
                n = ( (pow(10,obj.num.length()) -1) -  n );
                obj.num = to_string(n);
            }


            int diff;
            int length;
            string mo_str;
            if(num.length()>obj.num.length()){
                length = obj.num.length();
                diff=num.length() -obj.num.length();
                mo_str = num;
            }else{
                length = num.length();
                diff=obj.num.length()-num.length();
                mo_str = obj.num;
            }

            int sum;
            int mo = 0;
            for(int i=1;i<=length;i++){
                int digit1 = num[num.length()-i]-48;

                int digit2 = obj.num[obj.num.length()-i]-48;
                if((digit1+digit2+mo)>=10){
                        mo = (digit2+digit1+mo) % 10;

                        result =  to_string(mo) + result;
                        mo = 1;
                }else{
                        result  = to_string(digit1+digit2+mo) + result;
                        mo = 0;
                }
            }


            for (int i=diff-1; i>=0; i--) {

                int digit = mo_str[i]-48;
                if((digit+mo)>=10){

                        mo = (digit+mo) % 10;
                        result =  to_string(mo) + result;
                        mo = 1;

                }else{

                        result = to_string(digit+mo) + result;
                        mo = 0;
                }

            }

            if(result.length() > length){
                result.erase(0,1);
                long long n  = 0;
                int count = 1;
                for(int i=result.length()-1;i>=0;i--){
                    n +=  (result[i]-48)*count;
                    count *=10;
                }
                n =  n + 1;
                result = to_string(n);
            }else{
                if(result[0] == '0'){
                    result.erase(0,1);
                }
                long long n  = 0;
                int count = 1;
                for(int i=result.length()-1;i>=0;i--){
                    n += (result[i]-48)*count;
                    count *=10;
                }

                n =   ( (pow(10,result.length())-1) -  n );
                result      = to_string(n);
                if(result!="0"){
                    result = "-" + result;
                }

            }




        }else if(num[0] == '-' && obj.num[0] == '-'){
            num.erase(0,1);
            obj.num.erase(0,1);
            int diff;
            int length;
            string mo_str;
            if(num.length()>obj.num.length()){
                length = obj.num.length();
                diff=num.length() -obj.num.length();
                mo_str = num;
            }else{
                length = num.length();
                diff=obj.num.length()-num.length();
                mo_str = obj.num;
            }

            int sum;
            int mo = 0;
            for(int i=1;i<=length;i++){
                int digit1 = num[num.length()-i]-48;

                int digit2 = obj.num[obj.num.length()-i]-48;
                if((digit1+digit2+mo)>=10){
                        mo = (digit2+digit1+mo) % 10;

                        result =  to_string(mo) + result;
                        mo = 1;
                }else{
                        result = to_string(digit1+digit2+mo) + result;
                        mo = 0;
                }
            }


            for (int i=diff-1; i>=0; i--) {

                 int digit = mo_str[i]-48;
                if((digit+mo)>=10){

                        mo = (digit+mo) % 10;
                        result = to_string(mo) + result;
                        mo = 1;

                }else{

                        result = to_string(digit+mo) + result;
                        mo = 0;
                }

            }

            result = "-" + result;

        }else{
            int diff;
            int length;
            string mo_str;
            if(num.length()>obj.num.length()){
                length = obj.num.length();
                diff=num.length() -obj.num.length();
                mo_str = num;
            }else{
                length = num.length();
                diff=obj.num.length()-num.length();
                mo_str = obj.num;
            }

            int sum;
            int mo = 0;
            for(int i=1;i<=length;i++){
                int digit1 = num[num.length()-i]-48;

                int digit2 = obj.num[obj.num.length()-i]-48;
                if((digit1+digit2+mo)>=10){
                        mo = (digit2+digit1+mo) % 10;

                        result =  to_string(mo) + result;
                        mo = 1;
                }else{
                        result = to_string(digit1+digit2+mo) + result;
                        mo = 0;
                }
            }


            for (int i=diff-1; i>=0; i--) {

                 int digit = mo_str[i]-48;
                if((digit+mo)>=10){

                        mo = (digit+mo) % 10;
                        result =  to_string(mo) + result;
                        mo = 1;

                }else{

                        result = to_string(digit+mo) + result;
                        mo = 0;
                }

             }
        }



        BigInt temp(result);
        return temp;
    }

    BigInt operator=(BigInt & obj){
        BigInt temp(obj.num);
        return temp;
    }

    friend ostream & operator<<(ostream & out,BigInt obj){
        out<<obj.num;
        return out;
    }

};
// Test cases
    void test1(){
        BigInt num1("100");
        BigInt num2("200");
        BigInt num3 = num1 + num2;
        cout << "num1 = " << num1 << endl;
        cout << "num2 = " << num2 << endl;
        cout << "num2 + num1 = " << num3 << endl;
};

    void test2(){
        BigInt num1("-10");
        BigInt num2("-15");
        BigInt num3 = num1 + num2;
        cout << "num1 = -" << num1 << endl;
        cout << "num2 = -" << num2 << endl;
        cout << "num2 + num1 = " << num3 << endl;
};

    void test3(){
        BigInt num1("43148242");
        BigInt num2("92435456241");
        BigInt num3 = num1 + num2;
        cout << "num1 = " << num1 << endl;
        cout << "num2 = " << num2 << endl;
        cout << "num2 + num1 = " << num3 << endl;
};


    void test4(){
        BigInt num1("-353242353");
        BigInt num2("-2");
        BigInt num3 = num1 + num2;
        cout << "num1 = -" << num1 << endl;
        cout << "num2 = -" << num2 << endl;
        cout << "num2 + num1 = " << num3 << endl;
};


    void test5(){
        BigInt num1("423489248397539423");
        BigInt num2("5324353553256");
        BigInt num3 = num1 + num2;
        cout << "num1 = " << num1 << endl;
        cout << "num2 = " << num2 << endl;
        cout << "num2 + num1 = " << num3 << endl;
};

int main()
{

    test1();
    cout<<endl;
    test2();
    cout<<endl;
    test3();
    cout<<endl;
    test4();
    cout<<endl;
    test5();





    return 0;
}




