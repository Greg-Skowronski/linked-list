// Lesson1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class record
{
public:
	//by default class is private
	string name;
	string tel;

	record *ptr;
};

class list
{
private:
	record *header;
public:
	list()
	{
		header = new record;
		header->ptr = NULL;
	};
	void addrecord(const string, const string);
	void insert(const string, const string);
	void showrecord();
	void deleterecord(const string);
	void deleteall();
	int correctness(const string, const char);
};

void list::addrecord(const string na, const string te)
{
	record *xx = new record; //temporary
	//record yy;

	xx->name = na;
	xx->tel = te;
	xx->ptr = NULL;

	if (header == NULL)
	{
		header = xx;
		return;
	}

	record *last;
	last = header;
	while (last->ptr != NULL)
	{
		last = last->ptr;
	}
	last->ptr = xx;
};

void list::insert(const string na, const string te)
{
	record *xx = new record; //temporary
	
	xx->name = na;
	xx->tel = te;
	/*
	xx->ptr = header;

	header = xx;*/
	//header->ptr = xx;
	
	xx->ptr = header->ptr;
	header->ptr = xx;
}

void list::showrecord()
{
	record *x;
	x = header->ptr;


	while (x != NULL)
	{
		cout << setw(20) << x->name;
		cout << " ";
		cout << setw(12) << x->tel;
		cout << endl;
		
		x = x->ptr;
	}
};

void list::deleterecord(const string todel)
{
	record *prev = header;
	record *curr = header->ptr;

	cout << "You chose: " << todel << endl;


	while (curr != NULL) {
		//if (strcmp(curr->name,todel)==0) 
		if (curr->name == todel)
		{
			break;
		}
		else 
		{
			prev = curr;
			curr = curr->ptr; // go to next value
		}
	}

	if (curr == NULL) { // if we reached end of list or the list is empty
		cout << "Can't remove value: no match found.\n";
	}
	else {
		prev->ptr = curr->ptr;
		delete curr; 
	}

};

void list::deleteall()
{
	record *temp;
	temp = header->ptr;
	while (temp != NULL) 
	{
		header->ptr = temp->ptr;
		temp->ptr = NULL;
		delete temp;
		temp = header->ptr;
	}
};

int list::correctness(const string data, const char type)
{
	int len=0;
	len = data.length();
	
	if(len==0)
	{
		cout << "Too short text. Try again. \n";
		return 0; // 0 = bad input
	} 
	
	if(isalpha(data[0])!=0 && type=='T') //in case of text
	{
		for (int i = 1; i < len; i++) 
		{
			if(isalpha(data[i])==0 && data[i] != ' ')
			{
				cout << "Data must be text. \n";
				return 0;	
			} 
		}	
		return 1; // 1 = text
	}
	if(isdigit(data[0])!=0 && type=='N') //in case of number
	{
		for (int i = 1; i < len; i++) 
		{
			if(isdigit(data[i])==0 && data[i] != ' ')
			{
				cout << "Data must be number. \n";
				return 0;	
			} 
		}	
		return 2; // 2 = number
	}
	if(type=='N') cout << "Data must be number. \n";
	if(type=='T') cout << "Data must be text. \n";
	return 0;
};

int main()
{
	string del;
	string na, tel;
	int exit = 0;
	char choice;

	cout << "Hello!" << endl;

	list mylist; //calling the constructor
	/*
	mylist.addrecord("Kowalski", "321123456");
	mylist.addrecord("Pawlewicz", "456789123");
	mylist.addrecord("Nowak", "345876123");
	mylist.addrecord("Kozak", "987654567");
	*/

	mylist.showrecord();

	while (exit != 1)
	{
		cout << endl << "1. Append. (at the end)" << endl << "2. Insert. (at the beginning)" << endl << "3. Show records." << endl << "4. Delete record." << endl << "5. Delete all." << endl << "6. Quit." << endl << "Your choice: ";
		cin >> choice;
		cout << endl;
		while ((getchar()) != '\n');

		switch (choice)
		{
			case '1':
			{
				do{
				cout << "Enter name: ";
				getline(cin, na);
				}while(mylist.correctness(na,'T')!=1);
				
				do{
				cout << "Enter phone number: ";
				getline(cin, tel);
				}while(mylist.correctness(tel,'N')!=2);
				
				mylist.addrecord(na, tel);
				break;
			}
			case '2':
			{
				do{
				cout << "Enter name: ";
				getline(cin, na);
				}while(mylist.correctness(na,'T')!=1);
				
				do{
				cout << "Enter phone number: ";
				getline(cin, tel);
				}while(mylist.correctness(tel,'N')!=2);
				
				mylist.insert(na, tel);
				break;
			}
			case '3':
			{
				mylist.showrecord();
				break;
			}
			case '4':
			{
				cout << "Enter name to delete: ";
				getline(cin, del);
				mylist.deleterecord(del);
				break;
			}
			case '5':
			{
				mylist.deleteall();
				break;
			}
			case '6':
			{
				exit = 1;
				break;
			}
			default:
			{
				cout << endl << "TRY AGAIN" << endl;
				break;
			}
		}
	}

	return 0;
}

