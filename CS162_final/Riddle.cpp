/****************************************************
 * * filename: Riddle.cpp
 * * author: Candis Pike
 * * date: June 6, 2015
 * * description: class implementation file Riddle class
 * * input: none
 * * output: specified by function
 * ***************************************************/

#include "Player.hpp"
#include "Riddle.hpp"
#include <string>
#include <iostream>

/********************************************************************
 * * function: Riddle::Riddle():Room                               **
 * * description: default constructor                              **
 * * parameters: none                                              **
 * * pre-conditions: class object created                          **
 * * post-condtions: class object created with default conditions  **
 * *****************************************************************/
Riddle::Riddle():Room()
{
	this -> location = " " ;
	this -> moveOn = false;
}

/********************************************************************
 * * function: Riddle::Riddle(std::string loc):Room(loc)           **
 * * description: initializer constructor                          **
 * * parameters: std::string loc                                   **
 * * pre-conditions: class object created                          **
 * * post-condtions: class object created with initial conditions  **
 * *****************************************************************/
Riddle::Riddle(std::string loc):Room(loc)
{
	/*intentionally blank*/
}

/********************************************************************
 * * function: Riddle::~Riddle()                                   **
 * * description: destructor constructor                           **
 * * parameters: none                                              **
 * * pre-conditions: class object created                          **
 * * post-condtions: class object desroyed                         **
 * *****************************************************************/
Riddle::~Riddle()
{
	/*intentionally blank*/
}

/********************************************************************
 * * function: void Riddle::riddle1()                              **
 * * description: prints the first riddle                          **
 * * parameters: none                                              **
 * * pre-conditions: class object created                          **
 * * post-condtions: first riddle printed to screen                **
 * *****************************************************************/
void Riddle::riddle1()
{
	std::cout << "At night they come without being fetched" << std::endl;
	std::cout << "and by day they are lost without being stolen." << std::endl;
	std::cout << "What are they? " ;
	/*answer: stars*/
}

/********************************************************************
 * * function: void Riddle::riddle2()                              **
 * * description: prints the second riddle                         **
 * * parameters: none                                              **
 * * pre-conditions: class object created                          **
 * * post-condtions: second riddle printed to screen               **
 * *****************************************************************/
void Riddle::riddle2()
{
	std::cout << "I have a tongue but can not taste." << std::endl;
	std::cout << "I have a soul but can not feel." << std::endl;
	std::cout << "What am I? " ;
	/*answer: shoe*/
}

/********************************************************************
 * * function: void Riddle::riddle2()                              **
 * * description: prints the third riddle                          **
 * * parameters: none                                              **
 * * pre-conditions: class object created                          **
 * * post-condtions: third riddle printed to screen                **
 * *****************************************************************/
void Riddle::riddle3()
{
	std::cout << "I'm tall when I am young." << std::endl;
	std::cout << "and I'm short when I am old" << std::endl;
	std::cout << "What am I? " ;
	/*answer: candle*/
}

/********************************************************************
 * * function: void Riddle::moveN(Player *p)                       **
 * * description: moving north direction in room                   **
 * * parameters: Player *p                                         **
 * * pre-conditions: class object created                          **
 * * post-condtions: bool moveOn will be set to true if conditions **
 * * are met
 * *****************************************************************/
void Riddle::moveN (Player *p)
{
	char choice;

	/*check if north is previous room*/
	if (current.north !=NULL)
 
	    {
		std::cout << p->getVisited() -> getLocation() << " room is that way." << std::endl;
		std::cout << "Going that way would be treachrous." << std::endl;
		std::cout << "The sentry automatons are fast on your heels!" << std::endl;
	     }

	else if (location == "lab")
             {
	        std::cout << "Along the north wall is a variety of automotan sentries." << std::endl;
       		std::cout << "They appear to be deactivated. Much to your delight." << std::endl;
		std::cout << "You also see a spanner on the floor and think it may be userful." << std::endl;
		std::cout << "Do you pick it up and add it to your pack? y/n   " ;
		std::cin >> choice;
  
                if (toupper(choice) == 'Y')
		    {
    			if (p->searchInventory("spanner"))
                            std::cout << "Oh look you added that to your pack and forgot." << std::endl;

			else
                          {
                              p->addItem("spanner");
                              std::cout << "You now have a spanner in your pack" << std::endl;
                          }
		    }	   
       		else
	            std::cout << "You leave the spanner behind and hope it isn't needed" << std::endl;
	      }

 }
     	
/********************************************************************
 * * function: void Riddle::moveS(Player *p)                       **
 * * description: moving south direction in room                   **
 * * parameters: none                                              **
 * * pre-conditions: class object created                          **
 * * post-condtions: player moves set bool moveOn set to true if   **
 * * certain conditions are met                                    ** 
 * *****************************************************************/
void Riddle::moveS (Player *p)
{
        std::string answer;

	/*check if south is previous room*/
	if (current.south != NULL)
	    {
		std::cout << p->getVisited() -> getLocation() << " room is that way." << std::endl;
		std::cout << "Going that way would be treachrous." << std::endl;
		std::cout << "The sentry automatons are fast on your heels!" << std::endl;
	     }

	else if (location == "lab")
	     {
		 std::string answer;    
	         std::cout << "You encounter a door with no visible door handle." << std::endl;
    		 std::cout << "To the left of the door is a 'key pad' " << std::endl;
                 std::cout << "Above the key pad is a brass plaque that reads: " << std::endl;
		 std::cout << "Riddle me this! You have 2 chances to answer and open the door." << std::endl;
                 riddle1();
                 std::getline (std::cin, answer);
    
                 std::cin.clear();
 
                 for (int i = 0; i < 3; i++)
	             {
                         std::getline(std::cin, answer);
                         std::cout << std::endl;
 
			if (answer == "stars")
                           {
                              std::cout << "The door clicks open" << std::endl;
                              std::cout << "You go through the door and at the same time hear" << std::endl;
	                      std::cout << "'Sentries Initiated'" << std::endl;
       			      std::cout << "You realize the sentry automatons are now active" << std::endl;
                              std::cout << "Time is of the essence! You must stay one step" << std::endl;
                              std::cout << "ahead of them!" << std::endl;
                              moveOn = true;
                              break;
                            }

	                 else if (i == 2)
	                    {
	                       std::cout << "For the second time you have failed to input the " 
	                                 << "answer. Panic sets in!" << std::endl;
                               std::cout << "During your panic you fail to notice the sentry"
	                                 << " automatons have awaken." << std::endl;
                               std::cout << "You hear a familiar buzzz and the world goes dark." << std::endl;
                               std::cout << "Looks like you will become the nefarious mad scientists" 
	                                 << " crowning achievemnet" << std::endl;
                               std::cout << "GAME OVER" << std::endl;
                               exit(1);
 		           }

 
                      else 
                           std::cout << "The door fails to open." << std::endl;
                      
                      std::cout << std::endl;

                    }
               }
 	
	else if (location == "library")
	      std::cout << "All you see is books from for to ceiling!" << std::endl;

         else if (location == "coat")
	      std::cout << "Nothing useful here. Just places to hang coats." << std::endl;
}

/********************************************************************
 * * function:void Riddle::moveE(Player *p)                        **
 * * description: moving east in the room                          **
 * * parameters: Player *p                                         **
 * * pre-conditions: class object created                          **
 * * post-condtions: players move in the east direction moveOn     **
 * * true if certain conditions met                                **
 * *****************************************************************/
void Riddle::moveE (Player *p)
{
	/*check if south is previous room*/
	if (current.east != NULL )
	    {
		std::cout << p->getVisited() -> getLocation() << " room is that way." << std::endl;
		std::cout << "Going that way would be treachrous." << std::endl;
		std::cout << "The sentry automatons are fast on your heels!" << std::endl;
	    }

	else if (location == "lab")
	    { 
	        std::cout << "On the wall there are a variety of schematics " 
	                  << "but nothing you can use." << std::endl;
            }

        else if (location == "library")
	    {
		std::string answer;

		std::cout << "You move a book on the shelf entitled 'Warload of the Air" << std::endl;
                std::cout << "You see a familiar door with plaque and keypad to the left." << std::endl;
		std::cout << "Riddle me this! You have 2 chances to answer and open the door." << std::endl;
                riddle2();	
                std::getline(std::cin,answer); 	

                 for (int i = 0; i < 3; i++)
	             {
                         std::getline(std::cin, answer); 	        
                         std::cout << std::endl;
 
                          if (i == 2)
	                    {
	                       std::cout << "For the second time you have failed to input the " 
	                                 << "answer. Panic sets in!" << std::endl;
                               std::cout << "During your panic you fail to notice the sentry" 
	                                 << " automatons have entered the room." << std::endl;
                               std::cout << "You hear a familiar buzzz and the world goes dark." << std::endl;
                               std::cout << "Looks like you will become the nefarious mad scientists"  
	                                 << " crowning achievemnet" << std::endl;
                               std::cout << "GAME OVER" << std::endl;
                               exit(1);
 		           }
                       
                        else if (answer == "shoe")
                           {
                              std::cout << "The door clicks open" << std::endl;
                              std::cout << "You go through the door." << std::endl;
	                      std::cout << "You look back and see the sentry automatons enter " 
				        << "as you go through the door" << std::endl;
                              std::cout << "Time is of the essence! You must stay one step" << std::endl;
                              std::cout << "ahead of them!" << std::endl;
                              moveOn = true;
                              break;
                            }

                      else 
                           std::cout << "The door fails to open." << std::endl;

                      std::cout << std::endl;   
                    }
               }

	else if (location == "coat")
		std::cout << "There is a lot of room for coats but nothing you can use." << std::endl;
}

/********************************************************************
 * * function: void riddle::moveW(player *p)                       **
 * * description: player moves in the west direction               **
 * * parameters: Player *p                                         **
 * * pre-conditions: class object created                          **
 * * post-condtions: player moves west bool moveOn set true when   **
 * * certain conditions are met                                    ** 
 * *****************************************************************/
void Riddle::moveW (Player *p)
{
	/*check if west previous room*/
	if (current.west != NULL)
	    {
		std::cout << p->getVisited() -> getLocation() << " room is that way." << std::endl;
		std::cout << "Going that way would be treachrous." << std::endl;
		std::cout << "The sentry automatons are fast on your heels!" << std::endl;
	    }
 
	else if (location == "library")
	   std::cout << "You are still amazed by how many books there are." << std::endl;

	else if (location == "coat")
	    {
		std::string answer;

		std::cout << "You move a book on the shelf entitled 'Warload of the Air" << std::endl;
                std::cout << "You see a familiar door with plaque and keypad to the left." << std::endl;
		std::cout << "Riddle me this! You have 2 chances to answer and open the door." << std::endl;
                riddle3();		
                std::getline(std::cin, answer);

                 for (int i = 0; i < 3; i++)
	             {
	                 std::getline(std::cin,answer);
                         std::cout  << std::endl;
 
                         if (i == 2)
	                    {
	                       std::cout << "For the second time you have failed to input the " 
	                                 << "answer. Panic sets in!" << std::endl;
                               std::cout << "During your panic you fail to notice the sentry" 
	                                 << " automatons have entered the room." << std::endl;
                               std::cout << "You hear a familiar buzzz and the world goes dark." << std::endl;
                               std::cout << "Looks like you will become the nefarious mad scientists"  
	                                 << " crowning achievemnet" << std::endl;
                               std::cout << "GAME OVER" << std::endl;
                               exit(1);
 		           }
                       
                        else if (answer == "candle")
                           {
                              std::cout << "The door clicks open" << std::endl;
                              std::cout << "You go through the door." << std::endl;
	                      std::cout << "You look back and see the sentry automatons enter " 
				        << "as you go through the door" << std::endl;
                              std::cout << "Time is of the essence! You must stay one step" << std::endl;
                              std::cout << "ahead of them!" << std::endl;
                              moveOn = true;
                              break;
                            }
		       

                      else 
                          std::cout << "The door fails to open." << std::endl;
                     
                     std::cout << std::endl;
                     }
               }
}
