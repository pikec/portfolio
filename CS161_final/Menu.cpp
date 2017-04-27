/*************************************************************
 * * Candis Pike
 * * March 13, 2015
 * * Program  runs a menu that simulates a library checkout 
 * ************************************************************/

#include "Library.hpp"
#include "Patron.hpp"
#include "Book.hpp"
#include <string>
#include <iostream>

using namespace std;

int main ()
{ 
   int menuChoice;     //menu choice
  
   string patronNum, bookNum;  //user provided patron id and book id
   
   Library bookShelf;   //create library object;

   do 
     {
       cout << endl;
       cout << "****************************************************" << endl;
       cout << "*           Library Management Simulator           *"  << endl;
       cout << "****************************************************" << endl;
       cout << "* Option 1: Add Book                               *" << endl;
       cout << "* Option 2: Add Patron                             *" << endl;
       cout << "* Option 3: Check Out Book                         *" << endl;
       cout << "* Option 4: Return Book                            *" << endl;
       cout << "* Option 5: Request Book                           *" << endl;
       cout << "* Option 6: Change Current Date                    *" << endl;
       cout << "* Option 7: Pay Fine                               *" << endl;
       cout << "* Option 8: View Patron Info                       *" << endl;
       cout << "* Option 9: View Book Info                         *" << endl;
       cout << "* Option 10: Exit the Program                      *" << endl;
       cout << "****************************************************" << endl;
       cout << "Please choose an option from 1-10:    " ;
       cin >> menuChoice;
       cout << endl;

       if (menuChoice ==1)
          bookShelf.addBook();

       else if (menuChoice ==2) 
          bookShelf.addMember();

       else if (menuChoice == 3)
          {
            cout << "Check Out Book" << endl;
            cout << "Enter Patron ID Number: " ;
            cin >> patronNum;
            
            cout << "Enter Book ID Code: " ;
            cin >> bookNum;
      
            bookShelf.checkOutBook(patronNum, bookNum);
         }

        else if (menuChoice ==4)
          {
             cout << "Return Book" << endl;
             cout << "Enter Book ID Code: " ;                         
             cin >> bookNum;
   
             bookShelf.returnBook(bookNum);
           }

         else if (menuChoice ==5)
           {
             cout << "Request Book" << endl;
             cout << "Enter Patron ID Number: " ;
             cin >> patronNum;
            
             cout << "Enter Book ID Code: " ;
             cin >> bookNum;
       
             bookShelf.requestBook(patronNum, bookNum);
            }

          else if (menuChoice == 6)
             bookShelf.incrementCurrentDate();   

          else if (menuChoice == 7)
             {
               double pay;
       
               cout << "Pay Fine" << endl;
               cout << "Enter Patron ID Number." ;
               cin >> patronNum;

               cout << "Enter payment amount: " ;
               cin >> pay;
               pay = -pay;
  
               bookShelf.payFine(patronNum, pay);
             }

          else if (menuChoice ==8)
             {
               cout << "View Patron Info" << endl;
               cout << "Enter Patron ID Number." ;
               cin >> patronNum;

               bookShelf.viewPatronInfo(patronNum);
             }

          else if (menuChoice == 9) 
             {
               cout << "View Book Info" << endl;
               cout << "Enter Book ID Code: " ;                         
               cin >> bookNum;
  
               bookShelf.viewBookInfo(bookNum);
             }
   } while (menuChoice != 10);

   return 0;

}
 


