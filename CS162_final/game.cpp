/**********************************************
 * * filename: game.cpp
 * * author: Candis Pike
 * * date: June 6, 2015
 * * descripiton: game engine for text based 
 * * adventure game
 * * input: none
 * * output: room to room description
 * *********************************************/

#include "describe.hpp"
#include "Player.hpp"
#include "Room.hpp"
#include "Manipulate.hpp"
#include "Riddle.hpp"
#include "Code.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main ()
{
	/*create player objec to navigate game*/
	Player play;

	/*seed random number generator*/
	srand(time(NULL));

        /*cerate objects for all rooms*/
	Room *cell,
	     *lab,
	     *store,
	     *kitchen,
	     *dine,
	     *game,	
	     *library,
             *secret,
	     *coat,
	     *entrance;

	/*hints for the grader*/
	hints();
        std::cout << std::endl;

	/*set-up description of the game*/
	intro();

	/*Room 1: prison cell*/
	cellText ();
	cell = new Manipulate ("cell");
	cell -> setCompass (NULL, NULL, NULL, NULL);
	cell -> navigate(&play);
	play.addVisited(cell);

	std::cout << std::endl;
        std::cout << "You have moved from the prison cell to the laboratory." << std::endl;
        std::cout << std::endl;

	/*Room 2: laboratory*/
	labText();
	lab = new Riddle ("lab");
	lab -> setCompass (NULL, NULL, NULL, cell);
	lab -> navigate (&play);
	play.addVisited(lab);

	std::cout << std::endl;
	std::cout << "You have moved from the laboratory to the storage room." << std::endl;
	std::cout << std::endl;

	/*Room 3: store room*/
	storeText();
	store = new Code("store");
	store -> setCompass (lab, NULL, NULL, NULL);
	store -> navigate (&play);
	play.addVisited(store);

	std::cout << std::endl;
	std::cout << "You have moved from the store room up the stairs to the kitchen." << std::endl;
	std::cout << std::endl;

	/*Room 4: kitchen*/
	kitchenText();
	kitchen = new Manipulate("kitchen");
	kitchen -> setCompass(NULL, NULL, store, NULL);
        kitchen -> navigate(&play);
        play.addVisited(kitchen);

        std::cout << std::endl;
        std::cout << "You have moved from the kitchen to the dining room." << std::endl;
        std::cout << std::endl;

        /*Room 5: dining*/
        dineText();
        dine = new Manipulate("dining");
        dine -> setCompass (kitchen, NULL, NULL, NULL);
        dine -> navigate(&play);
        play.addVisited(dine);

        std::cout << std::endl;
        std::cout << "You have moved from the dining room to the game room." << std::endl;
        std::cout << std::endl;

        /*Room 6: game*/
        gameText();
        game = new Code("game");
        game -> setCompass (NULL, NULL, NULL, dine);
        game -> navigate(&play);
        play.addVisited(game);

        std::cout << std::endl;
        std::cout << "You have moved from the game room to the library." << std::endl;
        std::cout << std::endl;
 
        /*Room 7: libary room*/
        libraryText();
        library = new Riddle("library");
        library ->setCompass(game, NULL, NULL, NULL);
        library -> navigate(&play);
        play.addVisited(library);

        std::cout << std::endl;
        std::cout << "You have moved from the library to a secret room" << std::endl;
        std::cout << std::endl;

         /*Room 8: secret room*/
         secretText();
	 secret= new Code("secret");
	 secret -> setCompass (NULL, NULL, NULL, library);
	 secret -> navigate(&play);
	 play.addVisited(secret);

	 std::cout << std::endl;
	 std::cout << "You have moved from the secert room to the coat room" << std::endl;
	 std::cout << std::endl;

	 /*Room 9: coat room*/
	 coatText();
	 coat = new Riddle ("coat");
         coat -> setCompass (secret, NULL, NULL, NULL);
         coat -> navigate(&play);
         play.addVisited(coat);

	 std::cout << std::endl;
         std::cout << "You have moved from the coat room to the main entrance." << std::endl;
         std::cout << std::endl;

	/*Room 10: main entrance*/
	entranceText();
        entrance = new Code ("entrance");
        entrance -> setCompass (NULL, NULL, coat, NULL);
        entrance -> navigate(&play);
        play.addVisited(entrance);

        std::cout << std::endl;
        std::cout << "Congratulations! You have escaped from the mad scientists mansion!" << std::endl;

	/*release memory*/
	delete cell;
	delete lab;
	delete store;
	delete kitchen;
	delete dine;
	delete game;
	delete library;
	delete secret;
	delete coat;
	delete entrance;

	return 0;
}
