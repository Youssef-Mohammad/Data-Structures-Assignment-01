#include<iostream>
#include<iomanip>
#include<string.h>
#include <cstdlib>
using namespace std;

class entry
{
public:
    string firstName = "";
    string lastName = "";
    string phoneNumber = "";
    entry* next = NULL;
    entry* prev = NULL;

    friend ostream& operator <<(ostream& Cout, const entry* n)
    {
        string name = n->firstName + ' ' + n->lastName;
        Cout << setw(15) << left << name;
        Cout << " : " << n->phoneNumber << endl;
        return Cout;
    }
};

class PhoneDirectory
{
public:

    int length;
    entry* head;
    entry* end;
    entry* tmp;

    PhoneDirectory()
    {
        length = 0;
        head = NULL;
        end = NULL;
        tmp = NULL;
    }

    ~PhoneDirectory()
    {
        if (head != NULL)
        {
            entry* n = head;
            entry* m = head->next;
            while (n != NULL)
            {
                m = n;
                n = n->next;
                delete m;
            }
        }
        else
        {
            cout << endl << "No Directory Found" << endl;
        }
    }

    void addAtEnd(string phone, string fn, string ln)
    {
        if (length == 0)
        {
            addAtFront(phone, fn, ln);
        }
        else
        {
            end->next = new entry;
            tmp = end->next;
            tmp->phoneNumber = phone;
            tmp->firstName = fn;
            tmp->lastName = ln;

            tmp->prev = end;
            end->next = tmp;
            end = tmp;

            end->next = NULL;
            length++;
        }
    }

    void addAtFront(string phone, string fn, string ln)
    {
        if (length == 0)
        {
            head = new entry;
            head->phoneNumber = phone;
            head->firstName = fn;
            head->lastName = ln;
            end = head;
            head->next = NULL;
            head->prev = NULL;
            length++;
        }
        else
        {
            tmp = new entry;
            tmp->phoneNumber = phone;
            tmp->firstName = fn;
            tmp->lastName = ln;

            tmp->next = head;
            tmp->prev = NULL;

            head->prev = tmp;

            head = tmp;

            length++;
        }
    }

    void insertAt(int i, string phone, string fn, string ln)
    {
        if (i == 0)
        {
            this->addAtFront(phone, fn, ln);
            return;
        }

        else if (i == length)
        {
            addAtEnd(phone, fn, ln);
        }

        else if (i > length || i < 0)
        {
            cout << "Invalid Index" << endl;
            return;
        }
        tmp = new entry;
        tmp->phoneNumber = phone;
        tmp->firstName = fn;
        tmp->lastName = ln;
        entry* tmp2;
        tmp2 = this->operator[](i - 1);
        tmp->prev = tmp2;
        tmp->next = tmp2->next;
        tmp2->next->prev = tmp;
        tmp2->next = tmp;
        length++;

    }

    void deleteFromFront() {
        if (length > 1)
        {
            tmp = head;
            head = head->next;
            head->prev = NULL;
        }
        else if (length == 0)
        {
            cout << "Empty Directory!" << endl;
            return;
        }
        
        delete tmp;
        length--;
    }

    void deleteFromEnd() {
        if (length < 2)
        {
            deleteFromFront();
        }
        else
        { 
            tmp = end;
            end = end->prev;
            end->next = NULL;
            delete tmp;
            length--;
        }  
    }

    void deleteByIndex(int i)
    {
        if (length == 0)
        {
            cout << "Empty Directory!" << endl;
            return;
        }
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
            cout << i << ' ' << length << endl;
            cout << "Invalid Index" << endl;
        }
        else
        {
            tmp = this->operator[](i);
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete tmp;
            length--;
        }
    }

    int searchByFirstName(string first)
    {
        for (int i = 0; i < length; i++) {
            if ((this->operator[](i)->firstName) == first)
            {
                return i;
            }
        }
        return -1;
    }

    void deleteByFirstName(string& first)
    {
        int i = searchByFirstName(first);
        deleteByIndex(i);
    }

    void ListAllEntries() {
        if (length == 0)
        {
            return;
        }

        srand(time(0));
        int sorting = rand() % 4;
        if (sorting == 1) {
           this->selectionSort();
        }
        if (sorting == 2) {
           this->insertionSort();
        }
        if (sorting == 3) {
           this->BubbleSort();
        }
        this->printList();
    }

    int lookUpByPhoneNumber(string phoneNum)
    {
        for (int i = 0; i < length; i++) {
            if (this->operator[](i)->phoneNumber == phoneNum)
            {
                cout << "Your Entire Phone Number Found at : " << i + 1 << endl;
                cout << setw(15) << left << "First Name is " << this->operator[](i)->firstName << endl;
                cout << setw(15) << left << "Last Name is " << this->operator[](i)->lastName << endl;
                cout << setw(15) << left << "Phone Number is " << this->operator[](i)->phoneNumber << endl;
                return i;
            }
        }

    }

    int lookUpByFirstName(string firstName)
    {
        int i = searchByFirstName(firstName);
        if (i != -1) {
            cout << "Your Entire First Name Found at : " << i + 1 << endl;
            cout << setw(15) << left << "First Name is " << this->operator[](i)->firstName << endl;
            cout << setw(15) << left << "Last Name is " << this->operator[](i)->lastName << endl;
            cout << setw(15) << left << "Phone Number is " << this->operator[](i)->phoneNumber << endl;
        }
        return i;
    }

    void swap(int& i, int& j)
    {
        string tmp_fn;
        string tmp_ln;
        string tmp_pn;

        tmp_fn = this->operator[](i)->firstName;
        tmp_ln = this->operator[](i)->lastName;
        tmp_pn = this->operator[](i)->phoneNumber;

        this->operator[](i)->firstName = this->operator[](j)->firstName;
        this->operator[](i)->lastName = this->operator[](j)->lastName;
        this->operator[](i)->phoneNumber = this->operator[](j)->phoneNumber;

        this->operator[](j)->firstName = tmp_fn;
        this->operator[](j)->lastName = tmp_ln;
        this->operator[](j)->phoneNumber = tmp_pn;
    }

    void printList()
    {
        entry* n = head;
        string name;
        while (n != NULL)
        {
            cout << n;
            n = n->next;
        }
    }

    entry* operator[] (int i)
    {
        entry* current = head;
        for (int j = 0; j < i; j++)
        {
            current = current->next;
        }
        return current;
    }

    //------------------------------------------

    void BubbleSort()
    {
        int i, j;
        for (i = 0; i < length - 1; i++)
        {
            for (j = length - 1; j > i; j--)
            {
                if (this->operator[](j)->firstName < this->operator[](j - 1)->firstName)
                {
                    int x = j - 1;
                    this->swap(j, x);
                }
            }
        }
    }

    void selectionSort() {
        entry* current = head;
        entry* min;
        entry* r;
        string x;
        string y;
        string z;
        while (current) {
            min = current;
            r = current->next;

            while (r) {
                if (min->firstName > r->firstName) {
                    min = r;
                }
                r = r->next;
            }
            x = current->firstName;
            current->firstName = min->firstName;
            min->firstName = x;

            y = current->lastName;
            current->lastName = min->lastName;
            min->lastName = y;

            z = current->phoneNumber;
            current->phoneNumber = min->phoneNumber;
            min->phoneNumber = z;
            current = current->next;

        }
    }

    void insertionSort()
    {
        int i, j;
        entry* tmp = new entry;

        for (i = 1; i < this->length; i++)
        {
            tmp->firstName = this->operator[](i)->firstName;
            tmp->lastName = this->operator[](i)->lastName;
            tmp->phoneNumber = this->operator[](i)->phoneNumber;

            j = i;
            for (j; j > 0 && this->operator[](j - 1)->firstName > tmp->firstName; j--)
            {
                this->operator[](j)->firstName = this->operator[](j - 1)->firstName;
                this->operator[](j)->lastName = this->operator[](j - 1)->lastName;
                this->operator[](j)->phoneNumber = this->operator[](j - 1)->phoneNumber;
            }
            this->operator[](j)->firstName = tmp->firstName;
            this->operator[](j)->lastName = tmp->lastName;
            this->operator[](j)->phoneNumber = tmp->phoneNumber;
        }
        delete tmp;
    }
};

int main()
{
    string firstname;
    string lastname;
    string phonenumber;
    bool exit = false;
    int directory;
    PhoneDirectory d1;
    int select;
    cout << " 1. Add an entry to the directory" << endl;
    cout << " 2. Look up a phone number" << endl;
    cout << " 3. Look up by first name" << endl;
    cout << " 4. Delete an entry from the directory" << endl;
    cout << " 5. List All entries in phone directory" << endl;
    cout << " 6. Exit form this program " << endl;
    while (exit == false) {
        cout << "Please Select What Do You Want To Do From Above:" << endl;
        cin >> select;
        if (select <= 6 && select > 0) {
            cout << endl;

            if (select == 1) {
                cout << "                           ---------------------------------------------" << endl;
                cout << "Please Enter Your Data AS  ||Phone Number  |First Name  | Last Name   ||" << endl;
                cout << "                           ---------------------------------------------" << endl;
                cin >> phonenumber;
                cin >> firstname;
                cin >> lastname;

                d1.addAtEnd(phonenumber, firstname, lastname);
            }
            else if (select == 2) {
                cout << "Enter Phone Number You Want To Look up:" << endl;
                cin >> phonenumber;
                d1.lookUpByPhoneNumber(phonenumber);
            }
            else if (select == 3) {
                srand(time(0));
                int sorting = rand() % 4;
                if (sorting == 1) {
                    d1.selectionSort();
                }
                if (sorting == 2) {
                    d1.insertionSort();
                }
                if (sorting == 3) {
                    d1.BubbleSort();
                }
                cout << "Enter First Name You Want To Look up:" << endl;
                cin >> firstname;
                d1.lookUpByFirstName(firstname);
            }
            else if (select == 4) { 
                srand(time(0));
                int sorting = rand() % 4;
                if (sorting == 1) {
                    d1.selectionSort();
                }
                if (sorting == 2) {
                    d1.insertionSort();
                }
                if (sorting == 3) {
                    d1.BubbleSort();
                }
                cout << "Enter The Name that you want to delete:" << endl;
                cin >> firstname;
                d1.deleteByFirstName(firstname);
            }
            else if (select == 5) {
                cout << (d1.length == 0?"Empty Directory":"List Of Phone Directories Are") << endl;
                d1.ListAllEntries();
            }
            else  if (select == 6) {
                cout << "Thanks for using our software ... Good Bye! ";
                exit = true;

            }
        }
    }
    return 0;
}