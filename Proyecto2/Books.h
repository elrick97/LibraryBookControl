/*
  Books.h
  Proyecto2

  Created by Ricardo Ramirez on 2/28/18.
*/

#ifndef Books_h
#define Books_h
#include "Date.h"
#include "Student.h"

using namespace std;

class Books {
	public:
		//constructors
		Books();
    
        //Getters
        Date getDateBorrowed();
        int getDaysBorrwed();
    
        //Setters
    
	private:
		Date dateBorrowed;
		int daysBorrowed, cuantityBorrowed;
		string title, libKey, ISBN;
		int studentList[10];
};

//-------haz el constructor default JP----------
Books::Books()
{
    

}





#endif /* Books_h */
