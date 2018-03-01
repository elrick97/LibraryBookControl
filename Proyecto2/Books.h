/*
  Books.h
  Proyecto2

  Created by Ricardo Ramirez on 2/28/18.
*/

#ifndef Books_h
#define Books_h

using namespace std;

class Books {
public:
    //constructors
    Books();
private:
//    Date Date_borrow;
    int daysBorrowed;
    string title;
    string bibKey;
    string ISBN;
    int borrowed;
    int studentList[10];
};

Books::Books(){
    
}

#endif /* Books_h */
