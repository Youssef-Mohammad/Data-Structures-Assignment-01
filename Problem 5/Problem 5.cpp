#include <iostream>

using namespace std;

class Student_Name
{
private:
	string name;
public:
	Student_Name(string Name)
	{
		name = Name;
		int numOfSpaces = 0;
		int lastSpaceIndex = 0;
		string tmp = "";
		for (int i = 0; i < name.length()-1; i++)
		{
			if (name[i] == ' ')
			{
				numOfSpaces++;
				lastSpaceIndex = i;
			}
		}


		for (int i = lastSpaceIndex ; i < name.length(); i++)
		{
			if (i == 0)
			{
				tmp += ' ';
			}
			tmp += name[i];
		}

		while (numOfSpaces < 2)
		{
			name = name  + tmp;
			numOfSpaces++;
		}
	}

	void print()
	{
		int count = 1;
		cout << "Detailed Parts Of Name Are: " << endl;
		cout << count << ") ";
		for (int i = 0; i < name.length(); i++)
		{
			if (name[i] == ' ')
			{
				cout << endl;
				count++;
				cout << count << ") ";
			}
			else
			{
				cout << name[i];
			}
		}
	}

	void Replace(int n1, int n2)
	{
		if (n1 > n2)
		{
			Replace(n2, n1);
		}
		else
		{
			if (n1 < 1 || n1 > name.length() - 2 || n2 < 2 || n2 > name.length() - 1)
			{
				cout << "Invalid Indices" << endl;
			}
			else
			{
				int counter = 0;
				string first = " ";
				string second = "";
				for (int i = 0; i < name.length(); i++)
				{
					if (name[i] == ' ')
					{
						counter++;
					}
					if (counter == n1 - 1 && name[i] != ' ')
					{
						first += name[i];
						name.erase(i, 1);
						i--;
					}
					if (counter == n2 - 1 && name[i] != ' ')
					{
						second += name[i];
						name.erase(i, 1);
						i--;
					}
				}
				first.erase(0, 1);
				string temp = "";
				counter = 0;
				bool firstNotDone = true;
				bool secondNotDone = true;
				for (int i = 0; i < name.length(); i++)
				{
					if (name[i] == ' ')
					{
						counter++;
					}

					if (name[i] == ' ' && ((counter + 1 == n1 && secondNotDone) || n1 == 1 && secondNotDone))
					{
						if (n1 != 1)
						{
							temp += ' ';
						}
						temp = temp + second;
						if (name[i + 1] != ' ')
						{
							temp += ' ';
						}
						secondNotDone = false;
						continue;
					}
					else if (name[i] == ' ' && counter + 1 == n2 && firstNotDone)
					{
						temp = temp + ' ' + first;
						firstNotDone = false;
						continue;
					}
					else
					{
						temp += name[i];
					}
				}
				if (temp[0] == ' ')
				{
					temp.erase(0, 1);
				}
				cout << temp << endl;
			}
		}



	}
};

int main()
{
	Student_Name s1("Youssef Mohammed Abd_El_Hay Ali Hassan Abd_Elrahman Mostafa");
	s1.Replace(1, 7);

	system("pause>0");
}

