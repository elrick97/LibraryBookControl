//
//  Student.h
//  Proyecto2
//
//  Created by Juan Pablo Ramos on 3/7/18.
//  Copyright © 2018 Ricardo Ramirez. All rights reserved.
//

#ifndef Student_h
#define Student_h

using namespace std;

class Student
{
	public:
		// Constructors
		Student();
		Student(int, string, string);
		// Getters
		int getStudentId();
		string getMayor();
		string getName();
		// Setters
		void setStudentId(int);
		void setMayor(string);
		void setName(string);
		// Operation
		void Show();
	private:
		int studentId;
		string mayor, name;
};

//-------------------------------------Function Definition---------------------------------------------------
// Constructors
Student::Student()
{
	studentId = 0;
	mayor = "";
	name = "";
}

Student::Student(int ID, string m, string n)
{
	studentId = ID;
	mayor = m;
	name = n;
}

// Getters
int Student::getStudentId()
{
	return studentId;
}

string Student::getMayor()
{
	return mayor;
}
string Student::getName()
{
	return name;
}

// Setters
void Student::setStudentId(int ID)
{
	studentId = ID;
}

void Student::setMayor(string m)
{
	mayor = m;
}
void Student::setName(string n)
{
	name = n;
}

// Operation
void Student::Show()
{
	cout << "Student ID: " << studentId << endl;
	cout << "Mayor: " << mayor << endl;
	cout << "Name: " << name << endl;
}

#endif /* Student_h */
