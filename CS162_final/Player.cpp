/********************************************************
 * * filename: Playercpp
 * * author: Candis Pike 
 * * date: June 6, 2015
 * * description: class implementation file Player class
 * * input: none
 * * output: specified by function
 * ******************************************************/

#include "Player.hpp"
#include <string>
#include <vector>
#include <cctype>
#include <iostream>

/*******************************************************
 * * function: Player::Player ()                      **
 * * description: constructor for player object       **
 * * parameters: none                                 **
 * * pre-conditions: player object is created         **
 * * post-conditions: player object created with      **
 * * default conditions                               **
 * ****************************************************/
Player::Player()
{
	inventory.reserve(5);
	visited.reserve(10);
        fullCode.push_back(0);
        fullCode.push_back(0);
        fullCode.push_back(0); 
}

/*******************************************************
 * * function: Player::~Player ()                      **
 * * description: destructor for player object        **
 * * parameters: none                                 **
 * * pre-conditions: player object is created         **
 * * post-conditions: player object destroyed         **
 * ****************************************************/
Player::~Player()
{
	/*intentionally blank*/
}

/*******************************************************
 * * function: void Player::addItem (std::string item)**
 * * description: adds player picked up item to       **
 * * inventory                                        **
 * * parameters: string                               **
 * * pre-conditions: player object is created and     **
 * * valid string passed                              **
 * * post-conditions: item is in player pack          **
 * ****************************************************/
void Player::addItem(std::string item)
{
	char answer;
	
	if (inventory.size() <= 4)
	     inventory.push_back (item);
  
        else
	     {
	        std::cout << "The pack is full!" << std::endl;
		std::cout << "Do you wish to remove an item? y/n " ;
		std::cin >> answer;

		if (toupper(answer) == 'Y')
	            {
	                 listInventory();
                         removeItem();
                         inventory.push_back (item);
                    }
 
		else
                    std::cout << "No items were removed to make room." << std::endl;
              }
}

/*******************************************************
 * * function: void Player::removeItem ()             **
 * * description: remove item from player pack        **
 * * parameters: none                                 **
 * * pre-conditions: player object is created         **
 * * post-conditions: item is removed from player     **
 * * pack                                             **
 * ****************************************************/
void Player::removeItem()
{
	std::string item;

	std::cout << "What item would you like to remove?" ;
        std::cin.ignore(10, '\n');
	std::getline(std::cin, item);
        

	for (unsigned i=0; i < inventory.size(); i++)
		{
			if (inventory [i] == item)
			    inventory.erase (inventory.begin() + i);
		}

	std::cout << item << " was removed from your pack." << std::endl;
}

/*******************************************************
 * * function: void Player::listInventory ()          **
 * * description: list all the items in the players   **
 * * pack                                             ** 
 * * parameters: none                                 **
 * * pre-conditions: player object is created         **
 * * post-conditions: all items in player's pack      **
 * * printed to screen                                **
 * ****************************************************/
void Player::listInventory()
{
	if (inventory.size() == 0)
		std::cout << "Pack is empty." << std::endl;

	else
		{
		     for (unsigned i = 0; i < inventory.size(); i++)
			     std::cout << "Pack Item: " << inventory[i] << std::endl;
                 }
}

/*****************************************************************
 * * function: bool Player::searchInventory (std::string item)  **
 * * description: search for an item in the players pack        **
 * * parameters: std::string                                    **
 * * pre-conditions: player object is created and valid string  **
 * * passed                                                     ** 
 * * post-conditions: true returned if item is in pack else     **
 * * false returned                                             **
 * **************************************************************/
bool Player::searchInventory(std::string item)
{
	for (unsigned i = 0; i < inventory.size(); i++)
		{
			if (inventory [i] == item)
		  		return true;
		}	
			
	return false;
}

/*******************************************************
 * * function: void Player::addVisited (Room*)        **
 * * description: add last room visited to vector     **
 * * parameters: Room* r                              **
 * * pre-conditions: player object is created and     **
 * * Room object created                              **
 * * post-conditions: room added to vector            **
 * ****************************************************/
void Player::addVisited(Room* r)
{
	visited.push_back(r);
}

/*******************************************************
 * * function: Room* Player::getVisited()             **
 * * description: get previos room visited            **
 * * parameters: none                                 **
 * * pre-conditions: player object is created and     **
 * * Room object created                              **
 * * post-conditions: room object returned            **
 * ****************************************************/
Room* Player::getVisited()
{
	return (visited.back());
}

/*******************************************************
 * * function: void Player::storeCode (int c)         **
 * * description: values for the final code store     **
 * * parameters: int c                                **
 * * pre-conditions: valid int is pasesd              **
 * * post-conditions: value is stored in vector       **
 * ****************************************************/
void Player::storeCode(int i, int c)
{
	fullCode[i] = c;
}

/*********************************************************
 * * function: bool Player::getCode (int num, int pos)  **
 * * description: searches the vector to see if the     **
 * * correct numbers are present                        **
 * * parameters: int num, int pos                       **
 * * pre-conditions: valid num and pos passed           **
 * * post-conditions: true returned if value is present **
 * * false if not                                       **
 * ****************************************************/
bool Player::searchCode (int num, int pos)
{
	if (fullCode[pos] == num)
		return true;

	else 
		return false;
}

