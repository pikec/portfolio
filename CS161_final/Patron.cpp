/***********************************************
 * * Candis Pike
 * * March 13, 1015
 * * class implemenation file for Patron class
 * ********************************************/

#include "Patron.hpp"
#include "Book.hpp"
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;  

Patron::Patron ()
   {
     idNum = " ";
     name = " " ;
     fineAmount = 0;
     checkedOutBooks.reserve(100);
   }

Patron::Patron (string idn, string n)
  {
    idNum = idn;
    name = n;
  }

//get methods
string Patron::getIdNum ()
  {  
     return idNum;
  }

string Patron::getName ()  
  {
    return name;
  }

double Patron::getFineAmount ()
  {
     return fineAmount;
  }
  
vector <Book*> Patron::getCheckedOutBooks ()
  {
    return  checkedOutBooks;
  }

/**********************************************************
 * * void PAtron:addBook (Book b*)                       ** 
 * * Takes in a pointer to a book object and returns     **
 * * no value. adds the book object pointer to a vector  **
 * * Parameters: Book *b                                 **
 * *******************************************************/
void Patron::addBook (Book *b)
  {
    checkedOutBooks.push_back(b);
  }

/*************************************************************
 * * void Patron::removeBook (Book *b)                      **
 * * Function takes in a book object pointer as an argument ** 
 * * and returns no value. Removes a book pointer from the  **
 * * vector of checked out books.                           **
 * * Parameters: Book *b                                    **
 * **********************************************************/
 void Patron::removeBook (Book *b)
  {
    for (int i = 0; i < checkedOutBooks.size(); i++ )
       {
         if (checkedOutBooks[i] == b)
           { 
             checkedOutBooks.erase(checkedOutBooks.begin() + i); 
             return;
           }
        }
  }

void Patron::amendFine (double amount)
  {
         fineAmount += amount;

   }
