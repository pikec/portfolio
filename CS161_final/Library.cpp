/****************************************************
 * * Candis Pike
 * * March 13, 2015
 * * class implemetnation file for the Library Class
 * *************************************************/

#include "Book.hpp"
#include "Patron.hpp"
#include "Library.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

/**************************************************
 * * Library::Library ()                         ** 
 * * Defualt constructor takes in no argumenets  **
 * * and returns no values. Reserves the vector  **
 * * size to 100 and sets current date to 0      **
 ** parameters: none                             **
**************************************************/ 
 Library::Library()
  {
    holdings.reserve(100);
    members.reserve(100);
    currentDate = 0;
  }

/***********************************************************
 * * void Library::addBook()                              **
 * * Function takes in no arguments and returns no values **
 * * Creates a new book object for the library holdings   **
 * * vector.                                              **
 * * parameters: none                                     **
 * *********************************************************/
void Library::addBook ()
   {
     string id, title, author;  //variables to obtain id num, book title, and author

     //prompt user for book title
     cout << "Adding a new book."  << endl;
     cout << "Enter New Book ID Code: " ;
     cin >> id;

     //check to see if id is already in use
     for (int i = 0; i < holdings.size(); i++)
       {
          if (holdings[i].getIdCode() == id)
             {
               cout << "That book ID is already in use." << endl;
               cout << "Returning to main menu." << endl;
               return;
             }
      }
   
    //prompt user for book title
    cout << "Enter New Book Title: " ;  
    cin.ignore();
    getline(cin, title);

    //prompt user for book author
    cout << "Enter New Book Author: " ;
    getline(cin, author);

    Book newBook (id, title, author);  //create newBook object 
  
    holdings.push_back(newBook);   //add new book to holdings vector
   }
/*********************************************************************
 * * void Library::addMember ()                                     **
 * * Function takes in no arguments and returns no value            **
 * * Creates a new patron object to be added to the members vector  **
 * * parameters: none                                               **
 * ******************************************************************/
void Library::addMember ()
   {
      string id, name; //varibales for user input id and name of patron

      //prompt user for patron id number
      cout << "Adding a New Patron."  << endl;
      cout << "Enter New Patron ID Number: ";
      cin >> id;
 
     //validate that the patron id is not in use
     for (int  i = 0; i < members.size(); i++) 
          {
            if (members[i].getIdNum() == id)
               {
                cout << "That Patron ID is already in use." << endl;
                cout << "Returning to main menu. " << endl;   
                return;
               }
          }

     //prompt user for member name
     cout << "Enter New Patron Name: " ;
     cin.ignore();
     getline(cin, name);

     Patron newPatron (id, name);  //creete newPatron object

     members.push_back(newPatron);  //add new patron to members vector   
    }

/***************************************************************************
 * * void Library::checkOutBook (string, string)                          **
 * * Function takes in a string for a patron id and book id and retruns   **
 * * no vlaue. If a book is available it is checked out the patron        **
 * * parameters: string patronID, string bookID                           **
 * ************************************************************************/
 void Library::checkOutBook (string patronID, string bookID)
    {

     Patron *p = NULL;
     Book *b = NULL; 
      //validate member id
      for (int i = 0; i < members.size(); i++)
          {
             if (members[i].getIdNum()== patronID)
                 p = &members[i]; 
          }  
           
      if ( p == NULL)    
          {
            cout << "That Patron ID does not exist." << endl;
            cout << "Returning to main menu." << endl;
            return;
           }

       //validate book id
        for (int i = 0; i < holdings.size(); i++)
          {
             if (holdings[i].getIdCode() == bookID)
                b = &holdings[i];
          }
      
         if (b == NULL)
                {
                  cout << "That Book ID code does not exist." << endl;
                  cout << "Returning to main menu." << endl;
                  return;
                }
                   

       //check to see if book is checked out or on reserve
       if ( b -> getLocation() == CHECKED_OUT)
           {
             cout << "That book has already been checked out." << endl;
             cout << "Returning to main menu." << endl;
             return;
            }
      
       else if (b -> getLocation() == ON_HOLD_SHELF && b -> getRequestedBy()!= p) 
           {
             cout << "That book is on reserve." << endl;
             cout << "Returning to main menu." << endl;
             return;
           }
  
       //update location of book
       Locale lo;
       lo = CHECKED_OUT;
       b -> Book::setLocation(lo);
      
      //update date checked out
      b -> Book::setDateCheckedOut(currentDate);
      
      //update patron has checked out book
      b -> Book::setCheckedOutBy(p); 
      
      //update if reserved
      if (b -> getRequestedBy() == p)
         b -> Book::setRequestedBy(NULL);

      //print tilte of the book and patron who has checked it out
      cout << b -> getTitle() << " is now checked out to  " 
           <<p -> getName() << ". " << endl;  
     
      //prevent dangling pointers
      p = NULL;
      b = NULL;  

     }

/****************************************************************************
 * * void Library returnBook (string)                                      **
 * * Function takes in a book id string argument and returns no value.     **
 * * Function returns the book to the library. Places book on hold shelf   **
 * * if requested.                                                         **
 * * parameters: string bookID                                             **
 * *************************************************************************/
void Library::returnBook (string bookID)
   {
       Book *b = NULL;
       
       //validate book id
        for (int i = 0; i < holdings.size(); i++)
          {
             if (holdings[i].getIdCode() == bookID)
                b = &holdings[i];
          }
      
         if (b == NULL)
                {
                  cout << "That Book ID code does not exist." << endl;
                  cout << "Returning to main menu." << endl;
                  return;
                }
 
    
       //validate that book was not on shelf
       if (b -> getLocation() != CHECKED_OUT)
          {
             cout << "Book has not been checked out."  << endl;
             cout << "Returning to main menu." << endl;
             return;
          }

       //remove book from patron record
       b -> getCheckedOutBy() ->  removeBook(b);

      //reset checked out by
      b -> setCheckedOutBy(NULL); 
       
      //update location
       Locale lo;

       if (b -> Book::getRequestedBy() == NULL)
           {
              lo = ON_SHELF;
              b -> Book::setLocation(lo);
            }
       
       else 
           {
              lo = ON_HOLD_SHELF;
              b -> Book::setLocation(lo);
           }

       //print book has been returned message
       cout << b -> getTitle() << " has been returned." << endl;

      //prevent dangling pointer 
      b = NULL;             
    }

/*************************************************************************
 * * void Library::requestBook (sting, string)                          **
 * * Function takes in as arguments a string for a book id and a string **
 * * for a patron id and returns no value. Function reserves a book.    **
 * * parameters: string patornID, strong bookID                         **
 * **********************************************************************/
void Library::requestBook (string patronID, string bookID)
   {
     Patron *p = NULL;
     Book *b = NULL; 
      //validate member id
      for (int i = 0; i < members.size(); i++)
          {
             if (members[i].getIdNum()== patronID)
                 p = &members[i]; 
          }  
           
      if ( p == NULL)    
          {
            cout << "That Patron ID does not exist." << endl;
            cout << "Returning to main menu." << endl;
            return;
           }

       //validate book id
        for (int i = 0; i < holdings.size(); i++)
          {
             if (holdings[i].getIdCode() == bookID)
                b = &holdings[i];
          }
      
         if (b == NULL)
                {
                  cout << "That Book ID code does not exist." << endl;
                  cout << "Returning to main menu." << endl;
                  return;
                }
       //check to see if on request
       if ((b -> getRequestedBy() != NULL)  &&  (b -> getRequestedBy() != p ))
          {
            cout << "That book has been requested by another patron." << endl;
            cout << "Returning to main menu." << endl;
            return;
          }

      //check if curret patron has the book
       if (b -> getCheckedOutBy() == p)
          {
            cout << "The current patron currently has the book checked out." << endl;
            cout << "Patron cannot request the book." << endl;
            cout << "Returning to main menu." << endl;   
            return; 
          }

      //update request list
      b -> setRequestedBy(p);
     
      //update location
      if (b -> getLocation() == ON_SHELF)
         {
           Locale lo;
           lo = ON_HOLD_SHELF;
           b -> setLocation(lo);
          }

      //print request message confirmation
      cout << b -> getTitle() << " is now on request for " 
          << p -> getName() << "." << endl;
  
       b = NULL;
       p = NULL;
   }
/********************************************************************************
 * * void Library::incrememntCurrentDate()                                     **
 * * Function takes in no arguments and returns no values.  Function changes   **
 * * the current date.                                                         **
 * * parameters: none.                                                         **
 * *****************************************************************************/
void Library::incrementCurrentDate()
   {
      cout << "Increment Current Date." << endl;
      ++currentDate;
      cout << "The Current Date has been incremented by 1." << endl;
      cout << "The New Date is: " << currentDate << endl;

     vector <Book*> fine;


     for (int i = 0; i < fine.size(); i++)
       { fine = members[i].getCheckedOutBooks();
               
          for (int i=0; i <fine.size(); i++)
            {
               if (currentDate - fine[i]-> getDateCheckedOut() > Book::CHECK_OUT_LENGTH)
                    members[i].amendFine(0.10);
            }
       }
    }

/************************************************************************************
 * * void Patron::payFine (string, double)                                         **
 * * Function takes in a double and a stringas a parameter and returns no value    **
 * * Function uses the amend fine of the library function to pay fines             **
 * * parameters: string patronID, double payment                                   **
 * **********************************************************************************/
void Library::payFine (string patronID, double payment)     
   {
     Patron *p = NULL;

      //validate member id
      for (int i = 0; i < members.size(); i++)
          {
             if (members[i].getIdNum()== patronID)
                 p = &members[i]; 
          }  
           
      if ( p == NULL)    
          {
            cout << "That Patron ID does not exist." << endl;
            cout << "Returning to main menu." << endl;
            return;
           }

     //pay fines
     p -> amendFine(payment);

     //print paid messge with current balance
     cout << p -> getName() << " fines are now " 
          << fixed << showpoint << setprecision(2) <<  p -> getFineAmount() << "." << endl;

     p = NULL; //prevent dangling pointer
   }

 /********************************************************************
 * * void Libary::viewPatronInfo (string)                           **
 * * Function takes in a string parameters and returns no values.   **
 * * Functin prints the inforimation for a givem patron             **
 * * Parameters: string patronID                                    **
 * ******************************************************************/
void Library::viewPatronInfo (string patronID)
    {
      Patron *p = NULL;

      //validate member id
      for (int i = 0; i < members.size(); i++)
          {
             if (members[i].getIdNum()== patronID)
               {
                  p = &members[i]; 
               }
          }
           
      if ( p == NULL)    
          {
            cout << "That Patron ID does not exist." << endl;
            cout << "Returning to main menu." << endl;
            return;
           }

     //print id num, name, checked out books,and fine
     cout << "Patron Information." << endl; 
     cout << "Patron ID Num: "<< p -> getIdNum() << endl;
     cout << "Patron Name: " << p -> getName() << endl;
     cout << "Patron  Books: " ;

     vector <Book*> memBook(p -> getCheckedOutBooks());
     //memBook = p -> getCheckedOutBooks();

     for (int i=0; i < memBook.size(); i++)
        {
         cout << (memBook.at(i) -> getTitle() ) << " "  << endl;   
        }
     cout << "Patron Fines: " << fixed << showpoint <<  setprecision(2) << p -> getFineAmount() << endl;
   
     p = NULL; //prevent dangling pointer
   }

/***************************************************************************
 * * void Library::viewBookInfo(string)                                   **
 * * Function takes in a string as an argument and returns no value.      **
 * * Function prints the information about a given book.                  **
 * ************************************************************************/
void Library::viewBookInfo (string bookID)
   {
        Book *b = NULL;
       
       //validate book id
        for (int i = 0; i < holdings.size(); i++)
          {
             if (holdings[i].getIdCode() == bookID)
                b = &holdings[i];
          }
      
         if (b == NULL)
                {
                  cout << "That Book ID code does not exist." << endl;
                  cout << "Returning to main menu." << endl;
                  return;
                }
      
       
     //print book code, title, author, shelf location, if on request
     //if checked out and return date
     cout << "Book Information." << endl;
     cout << "Book ID Code: " << b ->  getIdCode() << endl;
     cout << "Book Title: " << b -> getTitle() << endl;
     cout << "Book Author: "  << b ->getAuthor() << endl;
     
     cout << "Book Location: " ;
         if ( b -> getLocation()== 0 )
           cout << "On Shelf" << endl;
       
         else if (b -> getLocation() == 1)
           cout << "On Request" << endl;      

         else if (b -> getLocation() == 2)
           cout << "Checked Out" << endl;   
    
     cout << "Book Requested By: ";  
          if ( !b -> getRequestedBy())
              cout << "Not On Request" << endl;
          
          else 
               cout << b -> getRequestedBy() -> getName()  << endl;
      
     cout << "Book Checeked Out By: ";
          if ( !b -> getCheckedOutBy())
              cout << "Not Checked Out" << endl;

          else
              cout << b -> getCheckedOutBy()-> getName() << endl;
     
     cout << "Book Due Date: "  ;
         if (!b -> getCheckedOutBy())
              cout << " " << endl;
 
         else if ((currentDate  - (b -> getDateCheckedOut())) <  b -> CHECK_OUT_LENGTH) 
             cout << (b -> CHECK_OUT_LENGTH - (currentDate -  ( b -> getDateCheckedOut()))) << endl;

         else
             cout << "OVERDUE" << endl;
      
     b = NULL; //prevent dangling pointer  
   } 
