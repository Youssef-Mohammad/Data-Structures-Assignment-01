#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

bool isUntitled(string name)
{
	string untitled = "Untitled";
	for (int i = 0; i < 8; i++)
	{
		if (name[i] != untitled[i])
		{
			return false;
		}
		return true;
	}
}

template<class T>
void BiasedSort(vector<T>& arr, int n)
{
	int i, j;
	T tmp;
	for (i = 1; i < n; i++)
	{
		tmp = arr[i];
		j = i;
		for (j; j > 0 && (arr[j - 1] > tmp || isUntitled(tmp)); j--)
		{
			if (isUntitled(tmp) && arr[j - 1] > tmp)
			{
				break;
			}
			arr.at(j) = arr.at(j - 1);
		}
		arr[j] = tmp;
	}
}

int main()
{
	vector<string> Songs = { "Basem", "Kareem", "Ahmed", "Mohammed", "Untitled", "Saad", "Untitled-1", "Untitled-3", "Untitled-2" };
	int len = Songs.size();
	BiasedSort<string>(Songs, len);
	for (int i = 0; i < len; i++)
	{
		cout << Songs[i] << (i != len - 1 ? ", " : "");
	}

	system("pause>0");
	return 0;
}