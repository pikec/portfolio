/*********************************************
 * * Candis Pike
 * * march 13. 2015
 * * class implementation file for Book class
 * ********************************************/

#include "Patron.hpp"
#include "Book.hpp"
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

/************************************************
 * * Book::Book()                              **
 * * Default constructor that sets the member  ** 
 * * variables to default values               **
 * * Parameters: none                          **
 * *********************************************/ 
Book::Book()
   {
     idCode = " " ;  
     title = " " ;
     author = " " ;
     checkedOutBy = NULL;
     requestedBy = NULL;
     dateCheckedOut = 0;
   }

/****************************************************
 * * Book::Book(string, string, string             **
 * * overloaded constructor that sets member       **
 * * varaibles to user input initial values        **
 * * parpameters: string idc, strong, t, string a. **
 * *************************************************/ 
Book::Book (string idc, string t, string a)
   {
     idCode = idc;
     title = t;
     author = a;
     setLocation (ON_SHELF);
     setCheckedOutBy(NULL);
     setRequestedBy(NULL);
     dateCheckedOut = 0;
   }

//set methods
void Book::setLocation(Locale lo)
   {
      location = lo;
   }


void Book::setDateCheckedOut(int d)
   {
     dateCheckedOut = d;
   }

void Book::setCheckedOutBy(Patron *p)
   {
     checkedOutBy = p;
   }

void Book::setRequestedBy(Patron *p)
   {
     requestedBy = p;
   }

//get methods
string Book::getIdCode()
   {
     return idCode;
   }

string Book::getTitle()
   {
     return title;
   }

string Book::getAuthor()
   {
     return author;
   }

Locale Book::getLocation()
   {
     return location;
   }

int Book::getDateCheckedOut()
   {
     return dateCheckedOut;
   }
 
Patron* Book::getCheckedOutBy()
   {
     return checkedOutBy;
   }

Patron* Book::getRequestedBy()
   {
     return requestedBy;
   }            
