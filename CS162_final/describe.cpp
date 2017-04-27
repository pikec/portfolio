/********************************************
 * * filename: describe.cpp
 * * author: Candis Pike
 * * date: June 6, 2105
 * * description: function implementation file
 * * input: none
 * * output: descriptiopn of various rooms
 * ******************************************/

#include "describe.hpp"
#include <iostream>

/**************************************************
 * * function: void hints()                      **
 * * description: function has no parameters and **
 * * returns no vlaues. Prints solution to  game **
 * * parameters: none                            **
 * * pre-condtions: function is called at proper **
 * * time.                                       **
 * * post-condions: contents of function are     **
 * * printed.                                    **
 * ***********************************************/
void hints()
{
	std::cout << "In order to win the game: " << std::endl;
	std::cout << "Check for objects. Wrirte down the code. Solve riddles." << std::endl;
        std::cout << "For cell: pick up pen/paper (s) and metal(n) before escaping (e). "  << std::endl;
	std::cout << "For lab: pick up spanner(n) and solve riddle (s). answer:stars." << std::endl;
	std::cout << "For store room: get random code number(e), pick up knife (s), and solve riddle(w) answer: 3" << std::endl;
	std::cout << "For kitchen: use knife (s)" << std::endl;
	std::cout << "For dining room: get gear(w), use spanner(e)" << std::endl;
 	std::cout << "For game room: get random code (n), solve riddle(s) answer: 4" << std::endl;
	std::cout << "For library: solve riddle (e) answer: shoe" << std::endl;
	std::cout << "For secret room: pickup handle (n), get random code(e), solve riddle(s) answer: 2." << std::endl;
	std::cout << "For coat room: solve riddle (w) andswer: candle" << std::endl;
	std::cout << "For main entrance and to win: enter the 3 random vlaues. store number,"
		  << " game number, and secret number." << std::endl;
	std::cout << std::endl;
}

 /**************************************************
 * * function: void intro()                       **
 * * description: function has no parameters and  **
 * * returns no vlaues. Prints solution to  game  **
 * * parameters: none                             **
 * * pre-condtions: function is called at proper  **
 * * time.                                        **
 * * post-condions: contents of function are      **
 * * printed.                                     **
 * ************************************************/
void intro()
{
	std::cout << "The year is 1870. London, England. Queen Victoria sits on the throne." << std::endl;
	std::cout << "It is a time of steam inventions and adventure! Or so you belief. " << std::endl;
	std::cout << "You have been fascinated with tinkering and inventions every since"  << std::endl;
	std::cout << "reading Jules Vernes 'Twenty Thousands Leagues Under the Sea." << std::endl;
	std::cout << "Much to the horror of your prime and proper aristocratic parents," << std::endl;
        std::cout << "your room is scattered with a variety of cogs, gears, metal, and books." << std::endl;
	std::cout << "One evening after a particular heated debate with your parents you" << std::endl;
	std::cout << "go for a walk in your home neighborhod of Picaddilly. As soon as "  << std::endl;
	std::cout << "you turn around to head home and apologize, you hear an unfamiliar" << std::endl;
	std::cout << "buzz and the world goes dark..."  << std::endl;
	std::cout << std::endl;
}

/**************************************************
 * * function: void cell()                       **
 * * description: function has no parameters and **
 * * returns no vlaues. Prints solution to  game **
 * * parameters: none                            **
 * * pre-condtions: function is called at proper **
 * * time.                                       **
 * * post-condions: contents of function are     **
 * * printed.                                    **
 * ***********************************************/
void cellText()
{
	std::cout << "You wake up to find yourself in an unfamiliar setting. " << std::endl;
	std::cout << "It's appears to be a prison cell!" << std::endl;
	std::cout << "You know this isn't Bedlam but where are you. " << std::endl;
	std::cout << "You see a laboratory thorugh the prison bars and know the answer lies there. " <<std::endl;
	std::cout << "You see a small pack and pick it up. You need to bring home soivenirs." << std::endl;
	std::cout << std::endl;
}	

/**************************************************
 * * function: void lab()                        **
 * * description: function has no parameters and **
 * * returns no vlaues. Prints solution to  game **
 * * parameters: none                            **
 * * pre-condtions: function is called at proper **
 * * time.                                       **
 * * post-condions: contents of function are     **
 * * printed.                                    **
 * ***********************************************/
void labText()
{
	std::cout << "As you enter the laboratory from the cell. You see a table." << std::endl;
	std::cout << "full of schematics. You pick one up. It's a schematic for " << std::endl;
	std::cout << "a half man/half automaton. You sickening realize you have " << std::endl;
	std::cout << "been kidnapped by a nefarious mad scientist in order to become his " << std::endl;
	std::cout << "centerpiece invention. You must escape before he comes back! "  << std::endl;
	std::cout << "Before looking aroud futher you notice a hastily written note" << std::endl;
	std::cout << "It says find useful objects, look for the code numbers, and solve " << std::endl;
	std::cout << "the riddles to escape. " << std::endl;
	std::cout << std::endl;
}	

/**************************************************
 * * function: void store()                      **
 * * description: function has no parameters and **
 * * returns no vlaues. Prints solution to  game **
 * * parameters: none                            **
 * * pre-condtions: function is called at proper **
 * * time.                                       **
 * * post-condions: contents of function are     **
 * * printed.                                    **
 * ***********************************************/
void storeText()
{
	std::cout << "You enter the store room. It is full of various size boxes, " << std::endl;
	std::cout << "pieces of metal, and gears. There is a strong musty scent." << std::endl;
	std::cout << std::endl;
}

/**************************************************
 * * function: void kitchen()                    **
 * * description: function has no parameters and **
 * * returns no vlaues. Prints solution to  game **
 * * parameters: none                            **
 * * pre-condtions: function is called at proper **
 * * time.                                       **
 * * post-condions: contents of function are     **
 * * printed.                                    **
 * ***********************************************/
void kitchenText()
{
	std::cout << "You enter the kitchen. It is a typical kitchen. Nothing  appears" << std::endl;
	std::cout << "out of the ordinary.  There is a lingering scent of fresh baked bread." << std::endl;	
	std::cout << std::endl;
}

/**************************************************
 * * function: void dine()                       **
 * * description: function has no parameters and **
 * * returns no vlaues. Prints solution to  game **
 * * parameters: none                            **
 * * pre-condtions: function is called at proper **
 * * time.                                       **
 * * post-condions: contents of function are     **
 * * printed.                                    **
 * ***********************************************/
void dineText()
{
	std::cout << "You enter the dining. It is richly appointed large table ready to go" << std::endl;
        std::cout << "for the next party. You can see the moon rising in the large window"  << std::endl;
	std::cout << "on the west wall." << std::endl;
	std::cout << std::endl;
}

/**************************************************
 * * function: void game()                       **
 * * description: function has no parameters and **
 * * returns no vlaues. Prints solution to  game **
 * * parameters: none                            **
 * * pre-condtions: function is called at proper **
 * * time.                                       **
 * * post-condions: contents of function are     **
 * * printed.                                    **
 * ***********************************************/
void gameText()
{
	std::cout << "As you enter the game room you are struck by the normalcy of the room." << std::endl;
	std::cout << "This nefarious evil scientist does a wonderful job blending in with society" << std::endl;
	std::cout << "with the typical trappings of a game room. " << std::endl;
	std::cout << std::endl;
}

/**************************************************
 * * function: void library()                    **
 * * description: function has no parameters and **
 * * returns no vlaues. Prints solution to  game **
 * * parameters: none                            **
 * * pre-condtions: function is called at proper **
 * * time.                                       **
 * * post-condions: contents of function are     **
 * * printed.                                    **
 * ***********************************************/
void libraryText()
{
	std::cout << "Books, books, books, and books. This room is a dream come true." << std::endl;
	std::cout << "For a moment you forget that you have been kidnapped to become" << std::endl;
	std::cout << "the centerpiece invention of a mad scientist and marvel at the" << std::endl;
	std::cout << "splendid array of books. You wish you could stay here for days." << std::endl;
	std::cout << "An unusual sound breaks you of your day dream." << std::endl; 
	std::cout << std::endl;
}

/**************************************************
 * * function: void secret()                     **
 * * description: function has no parameters and **
 * * returns no vlaues. Prints solution to  game **
 * * parameters: none                            **
 * * pre-condtions: function is called at proper **
 * * time.                                       **
 * * post-condions: contents of function are     **
 * * printed.                                    **
 * ***********************************************/
void secretText()
{
	std::cout << "You enter a secret room. It looks like a store room" << std::endl;
	std::cout << "that has been hidden from the world. " << std::endl;
	std::cout << std::endl;
}	

/**************************************************
 * * function: void coat()                       **
 * * description: function has no parameters and **
 * * returns no vlaues. Prints solution to  game **
 * * parameters: none                            **
 * * pre-condtions: function is called at proper **
 * * time.                                       **
 * * post-condions: contents of function are     **
 * * printed.                                    **
 * ***********************************************/
void coatText()
{
	std::cout << "You enter what appears to be a coat closet." << std::endl;
	std::cout << "At this time it is empty." << std::endl;
	std::cout << std::endl;
}

/**************************************************
 * * function: void entrance()                   **
 * * description: function has no parameters and **
 * * returns no vlaues. Prints solution to  game **
 * * parameters: none                            **
 * * pre-condtions: function is called at proper **
 * * time.                                       **
 * * post-condions: contents of function are     **
 * * printed.                                    **
 * ***********************************************/
void entranceText()
{
	std::cout << "You have made it to the main palor!" << std::endl;
	std::cout << "Across from you is the main door and freedom." << std::endl;
	std::cout << "You are too fixated on the door to notice the" << std::endl;
	std::cout << "portrait above the fireplace of what can only be" << std::endl;
	std::cout << "the nefarious mad scientist." << std::endl;
	std::cout << std::endl;
}
