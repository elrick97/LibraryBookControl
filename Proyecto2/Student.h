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
		string getMajor();
		string getName();
		// Setters
		void setStudentId(int);
		void setMajor(string);
		void setName(string);
		// Operation
		void Show();
	private:
		int studentId;
		string major, name;
};

//-------------------------------------Function Definition-----------------------------------------
// Constructors
Student::Student()
{
	studentId = 0;
	major = "";
	name = "";
}

Student::Student(int ID, string m, string n)
{
	studentId = ID;
	major = m;
	name = n;
}

// Getters
int Student::getStudentId()
{
	return studentId;
}

string Student::getMajor()
{
	return major;
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

void Student::setMajor(string m)
{
	major = m;
}
void Student::setName(string n)
{
	name = n;
}

// Operation
void Student::Show()
{
	cout << "Student ID: " << studentId << endl;
	cout << "Major: " << major << endl;
	cout << "Name: " << name << endl;
}

#endif /* Student_h */
