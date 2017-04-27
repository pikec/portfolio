/*********************************************************
 * * filename:Manipulate.cpp
 * * author: Candis Pike
 * * date:June 6, 2015
 * * descrption: class immplemenation file Manipulate class
 * * input: none
 * * output: specified by function
 * *******************************************************/

#include "Player.hpp"
#include "Manipulate.hpp"
#include <string>
#include <iostream>
#include <cctype>

/******************************************************************
 * * function: Manipulate::Manipulate()                          **
 * * description: default constructor                            **
 * * parameters: none                                            **
 * * pre-conditions: object is created                           **
 * * post-conditions: object is created with default conditions  **
 * ***************************************************************/
Manipulate::Manipulate()
{
	this -> location = " ";
}

/******************************************************************
 * * function: Manipulate::Manipulate(std::string loc):Room(loc) **
 * * description: default constructor                            **
 * * parameters: none                                            **
 * * pre-conditions: object is created                           **
 * * post-conditions: object is created with initial conditions  **
 * ***************************************************************/
Manipulate::Manipulate(std::string loc):Room(loc)
{
	/*intentionally left blank*/
}

/******************************************************************
 * * function: Manipulate::~Manipulate()                         **
 * * description: default constructor                            **
 * * parameters: none                                            **
 * * pre-conditions: object is created                           **
 * * post-conditions: object is destroyed                        **
 * ***************************************************************/
Manipulate::~Manipulate ()
{
	/*intentionally left blank*/
}

/******************************************************************
 * * function: Manipulate::moveN(Player *p)                      **
 * * description: player moves east                              **
 * * parameters: player *p                                       **
 * * pre-conditions: object is created                           **
 * * post-conditions: player moves north bool moveOn is set true **
 * * when conditions are met
 * ***************************************************************/
void Manipulate::moveN(Player *p)
{
	char choice;

	/*check if north is previous room*/
	if (current.north != NULL)
	    {
		std::cout << p->getVisited() -> getLocation() << " room is that way." << std::endl;
		std::cout << "Going that way would be treachrous." << std::endl;
		std::cout << "The sentry automatons are fast on your heels!" << std::endl;
	     }

	else if (location == "cell")
	     {
		std::cout << "In the dim light of the cell you see an odd shaped piece" << std::endl;
		std::cout << "of metal on the floor." << std::endl;
 		std::cout << "Do you pick it up and add it to your pack? y/n   " ;
	        std::cin >> choice;
  
                if (toupper(choice) == 'Y')
		    {
    			if (p->searchInventory ("odd_metal"))
                            std::cout << "Oh look you added that to your pack and forgot." << std::endl;

			else  
                          {
			       p->addItem("odd_metal");
			       std::cout << "You now have a odd shaped piece of metal in your pack" << std::endl;
                          }
	            }
		else
	            std::cout << "You leave the odd shaped metal behind and hope it isn't needed" << std::endl;
	      }
 
	else if (location =="kitchen")
	     std::cout << "You see a series of well crafted cabinets. Nothing of use is found in them." << std::endl;
    		
}	

/******************************************************************
 * * function: Manipulate::moveS(Player *p)                      **
 * * description: player moves south                             **
 * * parameters: Player *p                                       **
 * * pre-conditions: object is created                           **
 * * post-conditions: player move south moveOn set to true if    **
 * * certain conditions are met
 * ***************************************************************/
void Manipulate::moveS(Player *p)
{
        char choice;

	/*check if south is previous room*/
	if (current.south != NULL)
	    {
		std::cout << p->getVisited() -> getLocation() << " room is that way." << std::endl;
		std::cout << "Going that way would be treachrous." << std::endl;
		std::cout << "The sentry automatons are fast on your heels!" << std::endl;
	     }

	else if (location == "kitchen")
	     {
		std::cout << "There is a plain looking door in the middle of the wall." << std::endl;
	        std::cout << "You try the handle and it is locked." << std::endl;
	 	std::cout << "Maybe there is something in your pack to help jimmie the door open." << std::endl;
		std::cout << std::endl;
                std::cout << "You look in your pack and see: " << std::endl;
	
		p->listInventory();

               std::cout << std::endl; 
    
		if (p->searchInventory("knife"))
		    {
		    	std::cout << "You see the knife in your pack and take it out to use." << std::endl;
	    		std::cout << "You succesfully jimmie the door open!" << std::endl;
			std::cout << "You put the knife back into your pack." << std::endl;
			moveOn = true;
		    }

		else 
		    {
		        std::cout << "There is nothing in your pack that can help you!" << std::endl;
	    		std::cout << "You realized you forgot to pick up an item in another room" << std::endl; 
                        std::cout << "During your panic you fail to notice the sentry" 
	                          << " automatons have entered the room." << std::endl;
                        std::cout << "You hear a familiar buzzz and the world goes dark." << std::endl;
                        std::cout << "Looks like you will become the nefarious mad scientists"  
	                          << " crowning achievemnet" << std::endl;
                        std::cout << "GAME OVER" << std::endl;
                        exit(1);
	             }
               }

	else if (location == "cell")
	      {
	         std::cout << "In the dim light of the candle you see a pencil and pad of paper" << std::endl;
   		 std::cout << "sitting on the table with the candle." << std::endl;
		 std::cout << "The pencil and paper could come in handy." << std::endl;
	         std::cout << "Do you pick it up and add it to your pack? y/n   ";
	         std::cin >> choice;
  
                if (toupper(choice) == 'Y')
		    {
    			if (p->searchInventory ("pen_paper"))
                            std::cout << "Oh look you added that to your pack and forgot." << std::endl;

			else
                           {  
	                     p->addItem("pen_paper");
			     std::cout << "You now have a pencil and paper in your pack" << std::endl;
	                   } 
                     }
		else
	            std::cout << "You leave the pencil and paper behind and hope it isn't needed" << std::endl;
	      }

	else if (location == "dining")
	      std::cout << "You see an itricately carved buffet. Only a flower vase graces the top." << std::endl;
}

/******************************************************************
 * * function: Manipulate::moveE(Player *p)                      **
 * * description: player moves east                              **
 * * parameters: Player *p                                       **
 * * pre-conditions: object is created                           **
 * * post-conditions: player moves east moveOn set to true if    **
 * * cetain condtions are met                                    **
 * ***************************************************************/
void Manipulate::moveE(Player *p)
{
	/*check if east is previous room*/
	if (current.east != NULL)
	    {
		std::cout << p->getVisited() -> getLocation() << " room is that way." << std::endl;
		std::cout << "Going that way would be treachrous." << std::endl;
		std::cout << "The sentry automatons are fast on your heels!" << std::endl;
	    }

	else if (location == "cell")
	    {
	        std::cout << "Cell bars cross from one wall to another." << std::endl;
		std::cout << "You see a laboratory on the other side." << std::endl;
		std::cout << "In the center is lock mechanism of gears" << std::endl;
		std::cout << "at the center is an odd shaped hole." << std::endl;
		std::cout << "You look in your pack and see: " << std::endl;
		std::cout << std::endl;

		p->listInventory();
 
                std::cout << std::endl; 

		if (p->searchInventory("odd_metal"))
		   {
			std::cout << "You see the odd shaped piece of metal and notice it is a perfect fit" << std::endl;
			std::cout << "You take the metal out and place it in the lock." << std::endl;
			std::cout << "The door opens!" << std::endl;
                        std::cout << "You removed the metal and put it back in your pack." << std::endl;
			moveOn = true;
	            }
                
                else 
	                std::cout << "Continue scouring the cell for some sort of key." << std::endl;
             }

         else if (location == "dining")
	     {
	         std::cout << "The door is bolted shut. You look in your pack: " << std::endl;
    		 std::cout << std::endl;

                  p->listInventory();
       
                  std::cout << std::endl; 
          
		 if  (p->searchInventory("spanner"))
		    {
		    	std::cout << "You see the spanner in your pack and take it out to use." << std::endl;
	    		std::cout << "You give the bolt a good tug with the spanner and the door opens" << std::endl;
			std::cout << "You put the spanner back in your pack." << std::endl;
			moveOn = true;
		    }

		else 
		    {
		        std::cout << "There is nothing in your pack that can help you!" << std::endl;
	    		std::cout << "You realized you forgot to pick up an item in another room" << std::endl; 
                        std::cout << "During your panic you fail to notice the sentry" 
	                          << " automatons have entered the room." << std::endl;
                        std::cout << "You hear a familiar buzzz and the world goes dark." << std::endl;
                        std::cout << "Looks like you will become the nefarious mad scientists"  
	                          << " crowning achievemnet" << std::endl;
                        std::cout << "GAME OVER" << std::endl;
                        exit(1);
	             }
               }
} 
                  		 
/******************************************************************
 * * function: Manipulate::moveW(Player *p)                      **
 * * description: player moves west                              **
 * * parameters: Player *p                                       **
 * * pre-conditions: object is created                           **
 * * post-conditions: player moves west in the room moveOn set   **
 * * true if certain conditions are met                          **
 * ***************************************************************/
void Manipulate::moveW(Player *p)
{
	char choice;

	/*check if west previous room*/
	if (current.west != NULL)
	    {
		std::cout << p->getVisited() -> getLocation() << " room is that way." << std::endl;
		std::cout << "Going that way would be treachrous." << std::endl;
		std::cout << "The sentry automatons are fast on your heels!" << std::endl;
	    }

	else if (location == "cell")
		std::cout << "There is nothing but a damp brick wall." << std::endl;

	else if (location == "kitchen")
                std::cout << "The main feature is a stove. Nothing useful is here." << std::endl;

	else if (location == "dining")
	    {
	        std::cout << "You see a single solitary gear on the floor. It is out" << std::endl;
     		std::cout << "of place in this pristine room. " << std::endl;
                std::cout << "Do you pick it up and add it to your pack? y/n   " ;
	         std::cin >> choice;
  
                if (toupper(choice) == 'Y')
		    {
    			if (p->searchInventory ("gear"))
                           std::cout << "Oh look you added that to your pack and forgot." << std::endl;

			else
                          { 
			       p->addItem("gear");
			       std::cout << "You now have a gear in your pack" << std::endl;
                          }
	            }
		else
	            std::cout << "You leave the gear behind and hope it isn't needed" << std::endl;
	      }
}	

