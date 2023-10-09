#include<iostream>
#include<chrono>
#include<vector>
#include<iomanip>

using namespace std;
using namespace chrono;

//----------------------------------------------------
//QuickSort
int partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int i = left;

	for (int j = left + 1; j <= right; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i], arr[left]);
	return i;
}

void QuickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int middle = partition(arr, left, right);
		QuickSort(arr, left, middle - 1);
		QuickSort(arr, middle + 1, right);
	}
}

//------------------------------------------------------

class list
{
public:
	int* listAddress;
	int size;

public:
	list()
	{
		listAddress = NULL;
		size = 0;
	}

	list(int* add, int s)
	{
		listAddress = add;
		size = s;
	}
};

//---------------------------------------------------

class Sorter
{
public:
	char type = ' ';

	void setType(char Type)
	{
		type = Type;
	}

	char getType()
	{
		return type;
	}

	virtual void sort(list) {}
	virtual void sort(int*, int ) {}
};

class QuickSorter : public Sorter
{
public:

	QuickSorter()
	{
		setType('Q');
	}

	void sort(list l)
	{
		sort(l.listAddress, l.size);
	}

	void sort(int* arr, int size)
	{
		QuickSort(arr, 0, size - 1);
	}
};

class SelectionSorter : public Sorter
{
public:

	SelectionSorter()
	{
		setType('S');
	}

	void sort(list l)
	{
		sort(l.listAddress, l.size);
	}

	void sort(int* arr, int size)
	{
		for (int i = 0, j, least; i < size - 1; i++) {

			for (j = i + 1, least = i; j < size; j++)

				if (arr[j] < arr[least])
					least = j;
			swap(arr[least], arr[i]);
		}

	}
};

//---------------------------------------------------

class Testbed
{

	vector<list> lists;

public:
	int* currentSelection;
	int currentSelectionSize;

	Testbed()
	{
		currentSelection = NULL;
		currentSelectionSize = 0;
	}

	~Testbed()
	{
		for (int i = 0; i < lists.size(); i++)
		{
			delete this->lists[i].listAddress;
		}
	}

	int* GenerateRandomList(int min, int max, int size)
	{
		srand(time(0));
		list l(new int[size], size);
		for (int i = 0; i < size; i++)
		{
			l.listAddress[i] = min + rand() % (max - min);
		}
		currentSelection = l.listAddress;
		currentSelectionSize = size;
		lists.push_back(l);
		return l.listAddress;
	}

	int* GenerateReverseOrderedList(int min, int max, int size)
	{
		int* arr = GenerateRandomList(min, max, size);
		QuickSort(arr, 0, size - 1);
		reverse(arr, arr + size);
		return arr;
	}

	microseconds RunOnce(Sorter* sorter, int* arr, int size)
	{
		auto start = high_resolution_clock::now();
		sorter->sort(arr, size);
		auto end = high_resolution_clock::now();

		auto duration = duration_cast<microseconds>(end - start);
		cout << "Duration in Microseconds: " << duration.count() << endl;
		return duration;
	}

	microseconds RunAndAverage(Sorter* sorter,string type,int min,int max,int size,int sets_num)
	{
		microseconds time = 0ms;

		if (type == "random" || type == "Random" || type == "r" || type == "R")
		{
			for (int i = 0; i < sets_num; i++)
			{
				GenerateRandomList(min, max, size);

				auto start = high_resolution_clock::now();
				sorter->sort(this->currentSelection, this->currentSelectionSize);
				auto end = high_resolution_clock::now();

				auto duration = duration_cast<microseconds> (end - start);
				time += duration;
			}

		}
		else
		{
			for (int i = 0; i < sets_num; i++)
			{
				GenerateReverseOrderedList(min, max, size);

				auto start = high_resolution_clock::now();
				sorter->sort(this->currentSelection, this->currentSelectionSize);
				auto end = high_resolution_clock::now();

				auto duration = duration_cast<microseconds> (end - start);
				time += duration;
			}
		}

		microseconds avg = time / sets_num;
		return avg;
		
	}

	void RunExperiment(Sorter* sorter, string type, int min, int max, int min_val, int max_val, int sets_num, int step)
	{
		cout << setw(10) << left << "Set Size" <<setw(3) << left << ':' << "Average Time" << endl << endl;
		for (int i = min_val; i <= max_val; i += step)
		{
			cout << setw(9) << left << i << setw(4) << left << " : " << RunAndAverage(sorter, type, min, max, i, sets_num).count() << endl;;
		}
	}

	void print()
	{
		for (int i = 0; i < currentSelectionSize; i++)
		{
			cout << currentSelection[i] << endl;
		}
	}
};



int main()
{	
	Testbed t1;
	t1.GenerateRandomList(0, 50, 20);
	cout << "Random List" << endl;
	t1.print();
	cout << endl << "------------------------------------" << endl;

	cout << "Reversed Ordered List" << endl;
	t1.GenerateReverseOrderedList(0, 60, 25);
	t1.print();
	cout << endl << "------------------------------------" << endl;

	Sorter* s = new QuickSorter;

	cout << "Run Once" << endl;
	t1.RunOnce(s, t1.currentSelection, t1.currentSelectionSize);
	cout << endl << "------------------------------------" << endl;

	cout << "Run And Average" << endl;
	cout << "Average Time in Microseconds: " << t1.RunAndAverage(s, "random", 0, 100, 50, 10).count();
	cout << endl << "------------------------------------" << endl;

	t1.RunExperiment(s, "reversed", 0, 100, 0, 10000, 20, 5);

	

	return 0;
}