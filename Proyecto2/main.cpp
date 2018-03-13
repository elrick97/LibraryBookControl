/*
  main.cpp
  Proyecto2

 This project simulates a library where you can borrow books as a student and
 look for specific books by a lot of categories.
 
  Created by Ricardo Ramirez and Juan Pablo Ramos on 2/28/18
 
*/

#include <iostream>
#include <string>
#include <fstream>
#include "Books.h"

using namespace std;

/*  showBookList
 
    Display all books
 
 Parameters:
    Number of books and array of type Book
 Returns:
    NONE
 */
void showBookList(int bookNum, Books books[10])
{
	for (int i = 0; i < bookNum ; i++)
	{
		cout << "Book #" << i+1 << endl;
		cout << "Title: " << books[i].getTitle() << endl;
		cout << "Library: " << books[i].getLibKey() << endl;
		cout << "ISBN: " << books[i].getISBN() << endl;
		cout << "Quantity Borrowed: " << books[i].getCuantityBorrowed() << endl;
		cout << "--------------------" << endl;
	}
}
/*  BorrowBook
 
  borrow books
 
 Parameters:
    Number of books, array of type Book and array of type students
 Returns:
    NONE
 */
void BorrowBook(Books book[10],int bookNum, Student stu[15])
{
	string isbn;
	int stdtID, bookPosition = 0, studentPosition;
	int dd, mm, yyyy;
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
		// Getting date of borrowing
		cout << "Enter date of borrowing\n";
		cout << "Day: ";
		cin >> dd;
		cout << "Month: ";
		cin >> mm;
		cout << "Year: ";
		cin >> yyyy;
        if (book[bookPosition].borrow(isbn, stdtID, dd, mm, yyyy)){
		cout << "Book borrowed succesfully." << endl;
        }
	}
	else
	{
		cout << "Cound't borrow book." << endl;
	}
}
/*  SearchBookByDate
 
 searches book by specific date

 Parameters:
    Number of books, array of type Book.
 Returns:
    NONE
 */
void SearchBookByDate(Books book[10], int bookNum)
{
	// Asking user for return date
	int d, m, y;
	cout << "Enter day of return\n";
	cin >> d;
	cout << "Enter month of return\n";
	cin >> m;
	cout << "Enter year of return\n";
	cin >> y;
	
	// Searching for books with compatible return date
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

/*  SearchBookByISBN
 
 searches book by specific ISBN

 Parameters:
    Number of books, array of type Book.
 Returns:
    NONE
 */
void SearchBookByISBN(Books book[10], int bookNum)
{
	// Asking user for ISBN
	string isbn;
	bool isbnFound = false;
	cout << "Enter ISBN\n";
	cin >> isbn;
	
	// Searching for books with same ISBN
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

/*  SearchBookByLibraryKey
 
    searches book by specific library key
 
 Parameters:
    Number of books, array of type Book.
 Returns:
    NONE
 */
void SearchBookByLibraryKey(Books book[10], int bookNum)
{
	// Asking user for library key
	string libKey;
	bool libKeyFound = false;
	cout << "Enter Library Key\n";
	cin >> libKey;
	
	// Searching for books with same library key
	for (int i=0; i < bookNum; i++)
	{
		if (book[i].getLibKey() == libKey)
		{
			cout << "Title: " << book[i].getTitle() << endl;
			cout << "ISBN: " << book[i].getISBN() << endl;
			cout << "Quantity Borrowed: " << book[i].getCuantityBorrowed() << endl;
			libKeyFound = true;
		}
	}
	if (!libKeyFound)
	{
		cout << "Library Key wasn't found!\n";
	}
}

/*  SearchBookByStudent
 
    Searches books borrowed by specific student
 
 Parameters:
    Number of books, array of type Book and array of type students
 Returns:
    NONE
 */
void SearchBookByStudent(Books book[], int bookNum, Student stu[])
{
    int id;
	// Asking user for student
    cout << "Enter the student ID" << endl;
    cin >> id;
    bool studentExist = false, studentBorrowABook = false;
    
    for(int i = 0; i < 15; i++)
    {
        if (id == stu[i].getStudentId())
        {
            studentExist = true;
            cout << "Student Name: " << stu[i].getName() << endl;
            for (int j = 0; j < bookNum; j++)
            {
                for (int k = 0; i < bookNum; i++)
                {
                    if (stu[i].getStudentId() == book[j].getStudentList(k))
                    {
                        studentBorrowABook = true;
                        cout << "Title: " << book[j].getTitle() << endl;
                        cout << "ISBN: " << book[j].getISBN() << endl;
                        cout << "Quantity Borrowed: " << book[j].getCuantityBorrowed() << endl;                    }
                }
            }
        }
    }
}

/*  fillArrays
 
    This function is to pass everything from the text file to the arrays
 
 Parameters:
    array of type Book and array of type students
 Returns:
    NONE
 */
void fillArrays(Library lib[], Student stu[])
{
    string line, major, name, line2;
    string key, libKey;
    int floor, shelf;
    int id, count = 0;
	ifstream students;
	ifstream library;
    students.open("Alumnos.txt"); //opening files
    library.open("Biblioteca.txt");
    
    while((students >> id >> major) && (getline(students, name))) //filling the array with txt file
    {
		stu[count].setStudentId(id);
        stu[count].setMajor(major);
        stu[count].setName(name);
        count++;
    }
    count = 0;
    
    while(library >> libKey >> floor >> shelf >> key) //filling the array with txt file
    {
        lib[count].setLibKey(libKey);
        lib[count].setFloor(floor);
        lib[count].setShelf(shelf);
        lib[count].setKey(key);
        count++;
    }
	students.close(); //closing files
	library.close();
}

/*
 */
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
	
	fillArrays(lib, stu);

    if (bookNum < 10) //validating num of book do is not bigger than 10
    {
        for (int i = 0; i < bookNum; i++) //registering bookNum numbers
        {
            cout << "Enter book "<<i+1<<" title\n";
			cin.ignore();
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
            do { //Displaying menu
                cout << "1) Book List\n";
                cout << "2) Borrow a book\n";
                cout << "3) Books to be returned on X date\n";
                cout << "4) ISBN book search\n";
                cout << "5) Library book search\n";
                cout << "6) Student borrowed books\n";
                cout << "7) Exit\n";
                cin >> op;
                
                switch (op) { //all menu options
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
						SearchBookByISBN(book, bookNum);
                        break;
                    case '5':
						SearchBookByLibraryKey(book, bookNum);
                        break;
                    case '6':
                        SearchBookByStudent(book, bookNum, stu);
                        break;
                }
            }while(op != '7'); //if 7 breaks switch
    }
    else
    {
        cout << "Book limit exceeded\n";
    }
    return 0;
}
