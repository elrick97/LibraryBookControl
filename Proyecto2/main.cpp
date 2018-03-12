/*
  main.cpp
  Proyecto2

  Created by Ricardo Ramirez and Juan Pablo Ramos on 2/28/18
 
*/

#include <iostream>
#include <string>
#include "Books.h"

using namespace std;

int main()
{
    Library lib[5];
    Student stu[15];
    Books book[10];
    int bookNum;
    char op;
    string title, ISBN, LibKey;
    cout << "How many books do you want to register?\n";
    cin >> bookNum;
    
    if (bookNum < 10)
    {
        for (int i = 0; i < bookNum; i++)
        {
            cout << "Enter book title\n";
            getline(cin, title);
            
            cout << "Enter Library key\n";
            cin >> LibKey;
            
            cout << "Enter ISBN\n";
            cin >> ISBN;
            
            book[i].setTitle(title);
            book[i].setLibKey(LibKey);
            book[i].setISBN(ISBN);
            
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
                        //Book List
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
    }
    else
    {
        cout << "Book limit exceeded\n";
    }
    return 0;
}











