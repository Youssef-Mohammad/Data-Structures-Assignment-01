#include <iostream>
#include <vector>
using namespace std;

vector<string> UniqueVector;
void RecPermute(string soFar, string rest)
{
    if (rest == "")
    {
        // No more characters
        UniqueVector.push_back(soFar);
    }
    else
    {
        // Still more chars
        // For each remaining char
        for (int i = 0; i < rest.length(); i++)
        {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i) + rest.substr(i + 1);
            RecPermute(next, remaining);
        }
    }
}

// "wrapper" function
void ListPermutations(string s)
{
    RecPermute("", s);
    for (int i = 0; i < UniqueVector.size(); i++)
    {
        for(vector<string>::iterator it=UniqueVector.begin()+i+1;it!=UniqueVector.end();it++){
            if(*it==UniqueVector[i]){
                UniqueVector.erase(it);
                --it;
            }

        }
    }
    for (int i = 0; i < UniqueVector.size(); i++)
    {
        cout << UniqueVector[i] << endl;
    }

}

int main()
{
    string s;
    cout << "Enter a string:";
    cin >> s;
    ListPermutations(s);
    return 0;
}