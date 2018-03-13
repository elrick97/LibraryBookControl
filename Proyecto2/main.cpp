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
		cout << "Quantity Borrowed: " << books[i].getCuantityBorrowed() << endl;
		cout << "------------------------------------";
	}
}

void BorrowBook(Books book[10],int bookNum, Student stu[15])
{
	string isbn;
	int stdtID, bookPosition = 0, studentPosition;
	bool isbnFound = false;
	bool IDFound = false;
	cout << "Enter book ISBN\n";
	cin >> isbn;
	cout << "Enter student ID\n";
	cin >> stdtID;
	
	// Searching for ISBN
	for (int i=0; i < bookNum; i++)
	{
		if (book[i].getISBN() == isbn)
		{
			isbnFound = true;
			bookPosition = i;
		}
	}
	if (!isbnFound)
	{
		cout << "Book wasn't found!\n";
	}
	
	// Searching for student ID
	for (int i=0; i < 16; i++)
	{
		if (stu[i].getStudentId() == stdtID)
		{
			IDFound = true;
			studentPosition = i;
		}
	}
	if (!IDFound)
	{
		cout << "Student wasn't found!\n";
	}
	
	if (isbnFound && IDFound)
	{
		book[bookPosition].borrow(isbn, stdtID);
		cout << "Book borrowed succesfully." << endl;
	}
	else
	{
		cout << "Cound't borrow book." << endl;
	}
}

void SearchBookByDate(Books book[10], int bookNum)
{
	int d, m, y;
	cout << "Enter day of return\n";
	cin >> d;
	cout << "Enter month of return\n";
	cin >> m;
	cout << "Enter year of return\n";
	cin >> y;
	
	for (int i=0; i < bookNum; i++)
	{
		if (book[i].calculateReturnDate().getDD() == d && book[i].calculateReturnDate().getMM() == m && book[i].calculateReturnDate().getYYYY() == y)
		{
			cout << "Title: " << book[i].getTitle() << endl;
			cout << "Library: " << book[i].getLibKey() << endl;
			cout << "ISBN: " << book[i].getISBN() << endl;
			cout << "Date Borrowed: ";
			book[i].getDateBorrowed().Show();
		}
	}
}

void SearchBookByISBN(Books book[10], int bookNum)
{
	string isbn;
	bool isbnFound = false;
	cout << "Enter ISBN\n";
	cin >> isbn;
	
	for (int i=0; i < bookNum; i++)
	{
		if (book[i].getISBN() == isbn)
		{
			cout << "Title: " << book[i].getTitle() << endl;
			cout << "Library: " << book[i].getLibKey() << endl;
			cout << "Quantity Borrowed: " << book[i].getCuantityBorrowed() << endl;
			isbnFound = true;
		}
	}
	if(!isbnFound)
	{
		cout << "ISBN wasn't found!\n";
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
    int bookNum;
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
						BorrowBook(book, bookNum, stu);
                        break;
                    case '3':
						SearchBookByDate(book, bookNum);
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











