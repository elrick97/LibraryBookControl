/*
  Books.h
  Proyecto2

  Created by Ricardo Ramirez on 2/28/18.
*/

#ifndef Books_h
#define Books_h
#include "Date.h"
#include "Student.h"
#include "Library.h"

using namespace std;

class Books {
	public:
		//constructors
		Books();
        //Getters
        Date getDateBorrowed();
        int getDaysBorrwed();
        string getLibKey();
        string getTitle();
        string getISBN();
		int getStudentList(int pos);
		int getCuantityBorrowed();
        //Setters
		void setDateBorrowed(int, int, int);
        void setDaysBorrowed(int);
        void setLibKey(string);
        void setTitle(string);
        void setISBN(string);
		//Operation
		Date calculateReturnDate();
		bool borrow(string, int);
	
	private:
		Date dateBorrowed;
		int daysBorrowed, cuantityBorrowed;
		string title, libKey, ISBN;
		int studentList[10];
};

//-------------------------------------Function Definition---------------------------------------------------
//Constructor
Books::Books()
{
	daysBorrowed = 0;
	cuantityBorrowed = 0;
	title = "N/A";
	libKey = "N/A";
	ISBN = "N/A";
	dateBorrowed.~Date();
}
//Getters
Date Books::getDateBorrowed()
{
	return dateBorrowed;
}
int Books::getDaysBorrwed()
{
	return daysBorrowed;
}
string Books::getLibKey()
{
	return libKey;
}
string Books::getTitle()
{
	return title;
}
string Books::getISBN()
{
	return ISBN;
}
int Books::getStudentList(int pos)
{
	return studentList[pos];
}
int Books::getCuantityBorrowed()
{
	return cuantityBorrowed;
}
//Setters
void Books::setDateBorrowed(int d, int m, int y)
{
	dateBorrowed.setDD(d);
	dateBorrowed.setMM(m);
	dateBorrowed.setYYYY(y);
}
void Books::setDaysBorrowed(int days)
{
	daysBorrowed = days;
}
void Books::setLibKey(string libKey)
{
	this -> libKey = libKey;
}
void Books::setTitle(string t)
{
	title = t;
}
void Books::setISBN(string isbn)
{
	ISBN = isbn;
}
//Operation
Date Books::calculateReturnDate()
{
	int d, m, y;
	d = dateBorrowed.getDD();
	m = dateBorrowed.getMM();
	y = dateBorrowed.getYYYY();
	d += daysBorrowed;
	
	// Making sure day doesn't goes over 31
	if (d > 31)
	{
		// Calculating day in new month
		d -= 31;
		m++;
	}
	// Making sure month doesn't goes over 12
	if (m > 12)
	{
		m -= 12;
		y++;
	}
	
	Date returnDate(d,m,y);
	return returnDate;
}
bool Books::borrow(string isbn, int stdtID)
{
	bool repeated = false;
	for (int i=0; i <= cuantityBorrowed; i++)
	{
		if (studentList[i] == stdtID)
		{
			repeated = true;
		}
		else
		{
			repeated = false;
		}
	}
	if (!repeated)
	{
		studentList[cuantityBorrowed+1] = stdtID;
		cuantityBorrowed++;
	}
	return !repeated;
}



#endif /* Books_h */
