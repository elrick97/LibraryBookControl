//
//  Library.h
//  Proyecto2
//
//  Created by Juan Pablo Ramos on 3/7/18.
//  Copyright © 2018 Ricardo Ramirez. All rights reserved.
//

#ifndef Library_h
#define Library_h

using namespace std;

class Library
{
	public:
	// Constructors
	Library();
	Library(string, string, int, int);
	// Getters
	string getKey();
	string getLibKey();
	int getFloor();
	int getShelf();
	// Setters
	void setKey(string);
	void setLibKey(string);
	void setFloor(int);
	void setShelf(int);
	// Operation
	void Show();
	private:
		string key, libKey;
		int floor, shelf;
};

//-------------------------------------Function Definition---------------------------------------------------
// Constructors
Library::Library()
{
	key = "";
	libKey = "";
	floor = 0;
	shelf = 0;
}

Library::Library(string k, string lK, int f, int s)
{
	key = k;
	libKey = lK;
	floor = f;
	shelf = s;
}

// Getters
string Library::getKey()
{
	return key;
}

string Library::getLibKey()
{
	return libKey;
}

int Library::getFloor()
{
	return floor;
}

int Library::getShelf()
{
	return shelf;
}

// Setters
void Library::setKey(string k)
{
	key = k;
}

void Library::setLibKey(string lK)
{
	libKey = lK;
}

void Library::setFloor(int f)
{
	floor = f;
}

void Library::setShelf(int s)
{
	shelf = s;
}

// Operation
void Library::Show()
{
	cout << "Key: " << key << endl;
	cout << "Library Key: " << libKey << endl;
	cout << "Floor: " << floor << endl;
	cout << "Shelf: " << shelf << endl;
}
#endif /* Library_h */
