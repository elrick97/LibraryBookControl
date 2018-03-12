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
    cout << "How many books do you want to register?\n";
    cin >> bookNum;
    
    if (bookNum < 10)
    {
        for (int i = 0; i < bookNum; i++)
        {
            cout << "";
        }
    }
    return 0;
}











