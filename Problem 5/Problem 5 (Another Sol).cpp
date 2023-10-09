#include <iostream>
#include <string>
#include <vector>
using namespace std;

class student_name {
private:
    string name;
public:
    student_name(string Name) {
        name = Name;
        int counter = 0;
        int pos = 0;
        string temp = "";
        for (int i = 0; i < name.length() - 1; i++) {
            if (name[i] == ' ') {
                counter++;
                pos = i;
            }
        }
        for (int i = pos; i < name.length(); i++) {
            temp += name[i];
        }
        if (counter == 0) {
            temp = ' ' + temp;
        }
        while (counter < 2) {
            name = name + temp;
            counter++;
        }
    }

    void print() {

        int j = 1;
        cout << "detailed parts of name are  : " << endl;
        cout << "1" << ")";
        for (int i = 0; i < name.length(); i++) {
            if (name[i] == ' ') {
                cout << endl;
                cout << ++j<< ")";
            } else {
                cout << name[i];
            }
        }
    }/*
        string mn="";
        vector<string>N;
        for(int i=0;i<name.length();i++){
            if(name[i]==' '){
                N.push_back(mn);
                mn="";
            }
           else if(i==name.length()-1){
                mn+=name[i];
                N.push_back(mn);
            }
            else{
                mn+=name[i];
            }

        }
        int j=1;
        for(int i=0; i<N.size(); ++i)
        {
            cout<<j<<") "<<N[i]<<endl;
            ++j;
        }*/

    bool replace(int x, int y) {
        vector<string> nam;
        string nm = "";
        for (int i = 0; i < name.length(); i++) {
           /// nm += name[i]; not okay
            if (name[i] == ' ') { //to add space value as element into vector
                nam.push_back(nm);
                nm = "";
            } else if (i == name.length()-1) { //to insert the end of the string name at the end of  vector and contenue from right to left
                nm += name[i];
                nam.push_back(nm);
            } else {
                nm += name[i];//to add name char to string that we use it to set string names as vector values
            }

        }
        if (x > nam.size()|| y > nam.size()||x<0||y<0) {
            return false;
        }
        else {
            string final;
            string s = nam[x - 1];
            nam[x - 1] = nam[y - 1];
            nam[y - 1] = s;
            ///changed from here
            int i = 0;
            for (; i < nam.size()-1; i++) {
                final += nam[i] +" ";
            }
            final += nam[i];
            name = final;
            cout << name << endl;
            return true;

        }
    }
    string get_name(){

        return name;
    }
};

int main() {
    student_name test1("Ahmed Sayed bnb");
    test1.replace(1,3);
    test1.print();
    return 0;
}