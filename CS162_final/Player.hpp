/****************************************************
 * * filename: Player.hpp
 * * author: Candis Pike 
 * * date: June 6, 2015
 * * description: class file decleration Plyaer class
 * * input: none
 * * output: none
 * **************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Room.hpp"
#include <string>
#include <vector>

class Player
{
	private: 
		std::vector <std::string> inventory;
		std::vector <Room*> visited;
		std::vector <int> fullCode;

	protected:

	public:
		Player();
		~Player();
		void addItem(std::string);
		void removeItem();
		void listInventory();
		bool searchInventory(std::string);
		void addVisited(Room*);
		Room* getVisited();
		void storeCode(int, int);
		bool searchCode (int, int);
};

#endif
