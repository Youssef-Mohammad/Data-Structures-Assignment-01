#include<iostream>
using namespace std;


//class node
template<class T>
class node
{
public:
	T info;
	node* next;
	node* last;
};


//LinkedList class
template<class T>
class List
{
public:

	//Iterator
	class Iterator
	{
	private:
		node<T>* Node;
	public:

		Iterator(node<T>* head) //Take only one node
		{ 
			Node = head;
		}

		Iterator() // default
		{
			Node = NULL;
		}
		
		void setNode(node<T>* nd) // setter
		{
			Node = nd;
		}

		node<T>* getNode() //getter
		{
			return Node;
		}

		//------------------------------------------
		//operator overloading

		Iterator& operator++(int)
		{
			if (Node != NULL )
			{
				Node = Node->next;
				return *this;
			}
			throw "Position Points After The Last Element";
		}

		Iterator& operator--(int)
		{
			if (Node->last != NULL)
			{
				Node = Node->last;
				return *this;
			}
			throw "Position Points At The First Element";
		}

		bool operator==(const Iterator& itr)
		{
			return (this->Node->info == itr->Node->info);
		}

		T& operator*() const 
		{
			return Node->info;
		}
	};

	//-----------------------------------------------------
	int length;
	node<T>* head;
	node<T>* endNode;
	node<T>* dummyNode;
	node<T>* tmp;

	List() //default
	{
		length = 0;
		dummyNode = new node<T>;
		head = dummyNode;
		endNode = dummyNode;
		tmp = NULL;
	}

	List(T value, int initial_size) //parameterized
	{
		dummyNode = new node<T>;
		head = new node<T>;
		head->info = value;
		head->next = NULL;
		head->last = NULL;
		endNode = dummyNode;
		for (int i = 0; i < initial_size; i++)
		{
			push_back(value);
		}
	}

	List(List& li) //copy constructor
	{
		dummyNode = new node<T>;
		head = new node<T>;
		head->next = NULL;
		head->last = NULL;
		endNode = dummyNode;
		for (int i = 0; i < li.length; i++)
		{
			push_back(li.operator[](i)->info);
		}
	}

	~List() //destructor frees memory automatically
	{
		delete dummyNode;
		node<T>* n = head;
		node<T>* m = head->next;
		for (int i = 0; i < length; i++)
		{
			m = n;
			n = n->next;
			delete m;
		}
	}

	int size()
	{
		return length;
	}

	int getPosition(Iterator& it) // returns the index if known the iterator 
	{
		int i = -1;
			for (int j = 0; j < length; j++)
			{
				if (it.getNode() == this->operator[](j))
				{
					i = j;
					break;
				}
			}
			return i;

	}

	void push_back(T data)
	{
		if (length == 0)
		{
			head = new node<T>;
			head->info = data;
			endNode = head;
			head->next = dummyNode;
			dummyNode->last = head;
			head->last = NULL;
			length++;
		}
		else
		{
			endNode->next = new node<T>;
			tmp = endNode;
			endNode = endNode->next;
			endNode->last = tmp;
			length++;
			endNode->info = data;
			endNode->next = dummyNode;
			dummyNode->last = endNode;
		}
	}

	void addAtFront(T data)
	{
		if (length == 0)
		{
			tmp = new node<T>;
			tmp->info = data;
			head->last = tmp;
			tmp->next = head;
			head->next = dummyNode;
			dummyNode->last = head;
			head = tmp;
			head->last = NULL;
			length++;
		}
		else
		{
			tmp = new node<T>;
			tmp->next = head;
			head->last = tmp;
			head = tmp;
			tmp->info = data;
			length++;
		}
	}

	void insert(T data, int i)
	{
		if (i == 0)
		{
			this->addAtFront(data);
			return;
		}

		else if (i == length)
		{
			push_back(data);
			return;
		}

		else if (i > length || i < 0)
		{
			cout << "Invalid Index" << endl;
			return;
		}

		tmp = new node<T>;
		tmp->info = data;

		node<T>* cur = this->operator[](i);

		tmp->next = cur;
		tmp->last = cur->last;
		cur->last->next = tmp;
		cur->last = tmp;
		length++;
	}

	void deleteFromFront()
	{
		if (length == 0)
		{
			cout << "Already Empty List!" << endl;
		}
		else
		{
			tmp = head->next;
			delete head;
			head = tmp;
			head->last = NULL;
			length--;			
		}
	}

	void deleteFromEnd()
	{
		tmp = endNode;
		endNode = endNode->last;
		endNode->next = dummyNode;
		dummyNode->last = endNode;
		delete tmp;
		length--;
	}

	void deleteByIndex(int i)
	{
		if (i == 0)
		{
			deleteFromFront();
		}
		else if (i == length - 1)
		{
			deleteFromEnd();
		}
		else if (i >= length || i < 0)
		{
			cout << "Invalid Index" << endl;
		}
		else
		{
			tmp = this->operator[](i);
			tmp->last->next = tmp->next;
			tmp->next->last = tmp->last;
			delete tmp;
			length--;
		}
	}

	Iterator erase(Iterator& position)
	{
		int pos = getPosition(position);
		if (pos == -1)
		{
			throw "Position Points After The Last Element";
		}
		else
		{
			position++;
			this->deleteByIndex(pos);
		}
		return position;

	}


	Iterator begin()
	{
		Iterator itr;
		itr.setNode(head);
		return itr;
	}

	Iterator end() //points at the dummy node after the end node
	{
		Iterator itr;
		itr.Node = dummyNode;
		return itr;
	}

	void printList()
	{
		node<T>* n = head;
		for(int i = 0; i < length; i++)
		{
			cout << n->info << endl;
			n = n->next;
		}
	}

	//-------------------------------------------------------------
	//operator overloading

	node<T>* operator[] (int i)
	{
		node<T>* current = head;
		for (int j = 0; j < i; j++)
		{
			current = current->next;
		}
		return current;
	}

	List<T>& operator= (List<T>& another_list)
	{
		T data;
		for (int i = 0; i < another_list.length; i++)
		{
			data = another_list.operator[](i)->info;
			this->push_back(data);
		}
		
		return *this;
	}


};

int main()
{
	//Default Constructor
	List<int> l1;

	//Initialization Constructor
	List<int> l3(15, 10);

	//Basic Functions
	l1.push_back(2);
		
	l1.push_back(4);
		
	l1.push_back(5);

	l1.addAtFront(1);
		
	l1.addAtFront(0);
		
	l1.insert(3, 3);
		
	l1.deleteByIndex(3);
	
	l1.insert(3, 3);

	l1.deleteFromEnd();
	
	//Testing Iterator
	List<int>::Iterator it = l1.begin();
	cout << "Iterator Points to: " << * it << endl;

	cout << endl << "Printing List:" << endl;
	l1.printList();

	//Testing erase
	try
	{
		//iterator opeartor ++ ,opeartor --

		it++;
		l1.erase(it);
		it--;
	}
	catch(const char* e)
	{
		cout << e << endl;
	}
	
	cout << endl << "Printing List After Erase: " << endl;
	l1.printList();

	//Testing Operator = 
	List<int> l2;
	l2 = l1;

	cout << endl << "Testing operator =" << endl;
	cout << "--------------------------" << endl;
	l2.printList();
	cout << "--------------------------" << endl;
	
	//copy constructor
	List<int> l4 = l2;
	cout << endl << "Testing Copy Constructor: " << endl;
	l4.printList();
	return 0;
}