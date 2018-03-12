//
//  Date.h
//  Proyecto2
//
//  Created by Juan Pablo Ramos on 3/7/18.
//  Copyright © 2018 Ricardo Ramirez. All rights reserved.
//

#ifndef Date_h
#define Date_h

using namespace std;

class Date
{
	public:
		// Constructors
		Date();
		Date(int,int,int);
		// Getters
		int getDD();
		int getMM();
		int getYYYY();
		// Setters
		void setDD(int);
		void setMM(int);
		void setYYYY(int);
		// Operation
		void Show();
	private:
		int dd, mm, yyyy;
};

//-------------------------------------Function Definition---------------------------------------------------
// Constructor Method
Date::Date()
{
	dd = 00;
	mm = 00;
	yyyy = 0000;
}

Date::Date(int d, int m, int y)
{
	dd = d;
	mm = m;
	yyyy = y;
}

// Access Method
int Date::getDD()
{
	return dd;
}

int Date::getMM()
{
	return mm;
}

int Date::getYYYY()
{
	return yyyy;
}

// Modification Method
void Date::setDD(int d)
{
	dd = d;
}

void Date::setMM(int m)
{
	mm = m;
}
void Date::setYYYY(int y)
{
	yyyy = y;
}

// Operation
void Date::Show()
{
	cout << dd << "/" << mm << "/" << yyyy << endl;
}

#endif /* Date_h */
