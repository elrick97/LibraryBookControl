/*
  main.cpp
  Proyecto2

  Created by Ricardo Ramirez and Juan Pablo Ramos on 2/28/18
 
*/

#include <iostream>
#include <string>
#include "Books.h"

using namespace std;

void showBookList(int bookNum, Books books[10])
{
	for (int i = 0; i < bookNum ; i++)
	{
		cout << "------------------------------------";
		cout << "Book #" << i+1;
		cout << "Title: " << books[i].getTitle() << endl;
		cout << "Library: " << books[i].getLibKey() << endl;
		cout << "ISBN: " << books[i].getISBN() << endl;
		cout << "------------------------------------";
	}
}

void BorrowBook(Books book[10],int bookNum, int countStudents, Student stu[15])
{
	string isbn;
	int stdtID, bookPosition, studentPosition;
	bool isbnFound = false;
	bool IDFound = false;
	cout << "Enter book ISBN\n";
	cin >> isbn;
	cout << "Enter student ID\n";
	cin >> stdtID;
	
	for (int i=0; i < bookNum; i++)
	{
		if (book[i].getISBN() == isbn)
		{
			isbnFound = true;
			bookPosition = i;
		}
		else
		{
			cout << "Book wasn't found!\n";
		}
	}
	for (int i=0; i < countStudents; i++)
	{
		if (stu[i].getStudentId() == stdtID)
		{
			IDFound = true;
			studentPosition = i;
		}
		else
		{
			cout << "Student wasn't found!\n";
		}
	}
	
	if (isbnFound && IDFound)
	{
		book[bookPosition].
	}
}
void fillArrays(Library lib[5], Student stu[15])
{
    string line, major, name, line2;
    string key, libKey;
    int floor, shelf;
    int id, count = 0;;
    ifstream students, library;
    students.open("Alumnos.txt");
    library.open("Biblioteca.txt");
    while(getline(students, line))
    {
        cin >> id >> major;
        cin.ignore();
        getline(cin, name);
        stu[count].setStudentId(id);
        stu[count].setMajor(major);
        stu[count].setName(name);
        count++;
    }
    count = 0;
    while(getline(library, line2))
    {
        cin >> libKey >> floor >> shelf >> key;
        lib[count].setLibKey(libKey);
        lib[count].setFloor(floor);
        lib[count].setShelf(shelf);
        lib[count].setKey(key);
        count++;
    }
}

int main()
{
    Library lib[5];
    Student stu[15];
    Books book[10];
    int bookNum, countStudents;
    char op, daysBorrow;
    string title, ISBN, LibKey;
    cout << "How many books do you want to register?\n";
    cin >> bookNum;
    
    if (bookNum < 10)
    {
        for (int i = 0; i < bookNum; i++)
        {
            cout << "Enter book "<<i+1<<" title\n";
            getline(cin, title);
            
            cout << "Enter Library key\n";
            cin >> LibKey;
            
            cout << "Enter ISBN\n";
            cin >> ISBN;
			
			cout << "Enter days to borrow\n";
			cin >> daysBorrow;
            
            book[i].setTitle(title);
            book[i].setLibKey(LibKey);
            book[i].setISBN(ISBN);
			book[i].setDaysBorrowed(daysBorrow);
        }
            do {
                cout << "1) Book List\n";
                cout << "2) Borrow a book\n";
                cout << "3) Books to be turned on X date\n";
                cout << "4) ISBN book search\n";
                cout << "5) Library book search\n";
                cout << "6) Student borrowed books\n";
                cout << "7) Exit";
                cin >> op;
                
                switch (op) {
                    case '1':
                        showBookList(bookNum, book);
                        break;
                    case '2':
                        //Borrow a book
                        break;
                    case '3':
                        //Books to be turned on X date
                        break;
                    case '4':
                        //ISBN book search
                        break;
                    case '5':
                        //Library book search
                        break;
                    case '6':
                        //Student borrowed books
                        break;
                }
            }while(op != '7');
    }
    else
    {
        cout << "Book limit exceeded\n";
    }
    return 0;
}











