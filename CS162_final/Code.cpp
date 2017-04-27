/***************************************************
 * * filename: Code.cpp
 * * author: Candis Pike
 * * date: June 6, 2015
 * * description: class implementation file Code class
 * * input: none
 * * output: specified by function
 * ************************************************/

#include "Player.hpp"
#include "Code.hpp"
#include <string>
#include <cstdlib>
#include <cctype>
#include <iostream>

/****************************************************************
 * * function: Code::Code():Room()                             **
 * * description: defualt constructor                          **
 * * parameters: none                                          **
 * * pre-conditions: object is created                         **
 * * post-conditions: object is created with default condiions **
 * *************************************************************/ 
Code::Code():Room()
{
	this -> location = " ";
	this -> moveOn = false;
}
/****************************************************************
 * * function: Code::Code(std:;string loc):Room(loc)           **
 * * description: defualt constructor                          **
 * * parameters: std::string loc                               **
 * * pre-conditions: object is created                         **
 * * post-conditions: object is created with initial condiions **
 * *************************************************************/ 
Code::Code(std::string loc):Room (loc)
{
	/*intentionally blank*/
}
/****************************************************************
 * * function: Code::~Code()                                   **
 * * description: deconstructor                                **
 * * parameters: none                                          **
 * * pre-conditions: object is created                         **
 * * post-conditions: object is destroyed                      **
 * *************************************************************/ 
Code::~Code()
{
	/*intentionally blank*/
}

/****************************************************************
 * * function: Code::determineCode()                           **
 * * description: create random number for code                **
 * * parameters: none                                          **
 * * pre-conditions: object is created                         **
 * * post-conditions: random number generated                  **
 * *************************************************************/ 
void Code::determineCode()
{
	this -> codeNum = (rand()%10);
}

/****************************************************************
 * * function: Code::moveN(Player *p)                          **
 * * description:player moves north                            **
 * * parameters: Player *p                                     **
 * * pre-conditions: object is created                         **
 * * post-conditions: player moves north moveOn set true with  **
 * * certain conditions                                        **
 * *************************************************************/ 
void Code::moveN(Player *p)
{
	char choice;

	/*check if north is previous room*/
	if (current.north != NULL)
	    {
		std::cout << p->getVisited() -> getLocation() << " room is that way." << std::endl;
		std::cout << "Going that way would be treachrous." << std::endl;
		std::cout << "The sentry automatons are fast on your heels!" << std::endl;
	     }

	else if (location == "game")
            {
		 determineCode();
                 int num = codeNum;

		 std::cout << "There is a dart board on the wall" << std::endl;
		 std::cout << "The number: " << num << " is prominately displayed" << std::endl;
		 std::cout << "You take out the pencil and paper and jot the number down." << std::endl;
		    
		 p->storeCode(1,num);
	     }

	else if (location ==  "secret")
	     {
		       std::cout << "You see a lever handle on the ground. It could be useful." << std::endl;
		     	std::cout << "Do you pick it up and add it to your pack? y/n  ";
	        	std::cin >> choice;
  
                if (toupper(choice) == 'Y')
		    {
    			if (p->searchInventory ("handle"))
                            std::cout << "Oh look you added that to your pack and forgot." << std::endl;

			else
                          {
			       p->addItem("handle");
			       std::cout << "You now have a handle in your pack" << std::endl;
	                  }
                     }  		    
       		else
	            std::cout << "You leave the handle behind and hope it isn't needed" << std::endl;
	      }
		     

        else if (location == "entrance")
	      std::cout << "You see a set of mahogany stairs leading to the upper floor." << std::endl;

}	

/****************************************************************
 * * function: Code::moveS(Player *p)                          **
 * * description: player moves south                           **
 * * parameters: Player *p                                     **
 * * pre-conditions: object is created                         **
 * * post-conditions: player moves south moveOn set true when  **
 * * certain conditions are met                                ** 
 * *************************************************************/ 
void Code::moveS(Player *p)
{
      char choice;

	/*check if south is previous room*/
	if (current.south != NULL)
	    {
		std::cout << p->getVisited() -> getLocation() << " room is that way." << std::endl;
		std::cout << "Going that way would be treachrous." << std::endl;
		std::cout << "The sentry automatons are fast on your heels!" << std::endl;
	     }

	else if (location == "store")
	     {
	     	       std::cout << "You see a variety of boxes with shipping lables from around the world." << std::endl;
		       std::cout << "You see a knife on one of the boxes." << std::endl;
	     	     	std::cout << "Do you pick it up and add it to your pack? y/n   " ;
	        	std::cin >> choice;
  
                if (toupper(choice) == 'Y')
		    {
    			if (p->searchInventory ("knife"))
                            std::cout << "Oh look you added that to your pack and forgot." << std::endl;

			else
                          {  
			     p->addItem("knife");
			     std::cout << "You now have a knife in your pack" << std::endl;
                          } 
	            }		    
       		else
	            std::cout << "You leave the knife behind and hope it isn't needed" << std::endl;
	      }

	else if (location == "game")
	     {
	      	int answer;

                std::cout << "You see a familiar door with plaque and keypad to the left." << std::endl;
		std::cout << "Math me this! You have 2 chances to answer and open the door." << std::endl;
		std::cout << "What is 2 * 2 ? " ;

		for (int i = 0; i < 3; i++)
	             {
	                std::cin >> answer;
                        std::cout <<std::endl;

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
                       
                        else if (answer == 4)
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
                           std::cout << "The door fails to open. " << std::endl;
 
                    }

                 }

		else if (location == "secret")
      		     {
		      	int answer;
	
        	        std::cout << "You see a familiar door with plaque and keypad to the left." << std::endl;
			std::cout << "Math me this! You have 2 chances to answer and open the door." << std::endl;
			std::cout << "What is 1 + 1 ? " ;

			for (int i = 0; i < 3; i++)
	             	   {
                               std::cin >> answer;
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
                       
                        else if (answer == 2)
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
                    }
                  } 
		
		else if	(location == "entrance")
		    std::cout << "You see a roaring comfotable fire in the fireplace and can't"
		              << " to get home." << std::endl;
}		

/****************************************************************
 * * function: Code::moveE(Player *p                           **
 * * description:player moves east                             **
 * * parameters: player *p                                     **
 * * pre-conditions: object is created                         **
 * * post-conditions: player moves east moveOn is set true if  **
 * * certain condisions are met                                **      
 * *************************************************************/ 
void Code::moveE(Player *p)
{
	/*check if east is previous room*/
	if (current.east != NULL  )
	    {
		std::cout << p->getVisited() -> getLocation() << " room is that way." << std::endl;
		std::cout << "Going that way would be treachrous." << std::endl;
		std::cout << "The sentry automatons are fast on your heels!" << std::endl;
	    }

	else if (location == "store")
	   {    
		 determineCode();  
                 int num = codeNum;
 
		std::cout << "All the boxes have the same number of them: " << num << std::endl;
		
		if (p->searchInventory("pen_paper"))
		   {		
			std::cout << "You take out the pencil and paper and jot down the number." << std::endl;
			p->storeCode(0, num);
		   }

		else
		   {
	   		   std::cout << "You have nothing to jot the number down! " 
	                             << "There is no way you can remember it. Panic sets in!" << std::endl;
                           std::cout << "During your panic you fail to notice the sentry" 
	                             << " automatons have entered the room." << std::endl;
                           std::cout << "You hear a familiar buzzz and the world goes dark." << std::endl;
                           std::cout << "Looks like you will become the nefarious mad scientists"  
	                             << " crowning achievemnet" << std::endl;
                           std::cout << "GAME OVER" << std::endl;
                           exit(1);
	            }		   
	   }

	else if (location == "game")
           {
   		std::cout << "You see a series of couches and game tables." << std::endl;
		std::cout << "There is nothing here to use." << std::endl;
           }

	else if (location == "secret")
           {
      		determineCode();
                int num = codeNum;
 	
		std::cout << "In red paint on the wall you see the number: " << num << std::endl;
		std::cout << "You take out the pencil and paper and jot down the number." << std::endl;
		p->storeCode(2,num);
	    }
}
     		
/****************************************************************
 * * function: void Code::moveW(player *p)                     **
 * * description: player moves west in room                    **
 * * parameters: Player *p                                     **
 * * pre-conditions: object is created                         **
 * * post-conditions: player moves west in the room moveOn set **
 * * true if certain conditions are met                        **
 * *************************************************************/ 
void Code::moveW(Player *p)
{
	/*check if west previous room*/
	if (current.west != NULL)
	    {
		std::cout << p->getVisited() -> getLocation() << " room is that way." << std::endl;
		std::cout << "Going that way would be treachrous." << std::endl;
		std::cout << "The sentry automatons are fast on your heels!" << std::endl;
	    }

	else if (location == "store")
	    {
	      	int answer;
	
                std::cout << "You see a familiar door with plaque and keypad to the left." << std::endl;
		std::cout << "Math me this! You have 2 chances to answer and open the door." << std::endl;
		std::cout << "What is 9/3? " ;

		for (int i = 0; i < 3; i++)
	            {
	               std::cin >> answer;
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
	          else if (answer == 3)
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
                    }

	    }

	else if (location == "entrance")
	    {
	    	std::cout << "You stand before the main door to the mansion." << std::endl;
    		std::cout << "To the left of the door is a familiar keypad." << std::endl;
 		std::cout << "The plaque above reads" << std::endl;
		std::cout << "Riddle me this! Did you pay attention on your journey." << std::endl;
		std::cout << "To leave this mansion type in the 3 number code."  << std::endl;
		std::cout << "You have 2 chances to open the door." << std::endl;
 		std::cout << "You pull out the pad of paper and type the numbers." << std::endl;
	
		for (int i = 0; i < 3; i++)
		{
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

			int num1, num2, num3;

        	        std::cout << "You type in the first number: " ;
			std::cin >> num1;
     			std::cout << "You type in the second number: ";
			std::cin >> num2;
			std::cout << "You type in the third number: ";
			std::cin >> num3;			

                        std::cout << std::endl;
	         
			bool final1 = p->searchCode(num1, 0);
			bool final2 = p->searchCode (num2,1);
			bool final3= p->searchCode (num3, 2);
		      	
			if (final1 && final2 && final3 )
                           {
                              std::cout << "The door clicks open" << std::endl;
                              std::cout << "You go through the door." << std::endl;
	                      std::cout << "You are free! " << std::endl; 
			      std::cout << "You step through the door into the cool night air." << std::endl;
			      std::cout << "You don't look back as you head home." << std::endl;
			      moveOn = true;
                              break;
                            }

                      else 
                           std::cout << "The door fails to open." << std::endl;
                    } 
           }
}
