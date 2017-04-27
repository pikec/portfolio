/***************************************************
 * * filename: Room.cpp
 * * author: Candis Pike
 * * description: class implemneation file Room class
 * * input: none
 * * output: specified by funtion
 * *************************************************/

#include "Room.hpp"
#include <string>
#include <cstdlib>
#include <cctype>
#include <iostream>

/********************************************************************
 * * function: Room::Room ()                                       **
 * * description: default constructor                              **
 * * parameters: none                                              **
 * * pre-conditions: class object is created                       **
 * * post-conditions: class object created with default conditions **
 * *****************************************************************/
Room::Room ()
{
	this -> location = " " ;
	this -> moveOn = false;
}

/********************************************************************
 * * function: Room::Room (std::string loc)                        **
 * * description: initializer constructor                          **
 * * parameters: none                                              **
 * * pre-conditions: class object is created                       **
 * * post-conditions: class object created with initial conditions **
 * *****************************************************************/
Room::Room(std::string loc)
{
	this -> location = loc;
}

/********************************************************************
 * * function: Room::~Room ()                                      **
 * * description: default constructor                              **
 * * parameters: none                                              **
 * * pre-conditions: class object is created                       **
 * * post-conditions: class object destroyed                       **
 * *****************************************************************/
Room::~Room()
{
	/*intentionally blank*/
}

/********************************************************************
 * * function: std::string Room::getLocation ()                    **
 * * description: return room name                                 **
 * * parameters: none                                              **
 * * pre-conditions: class object is created                       **
 * * post-conditions: name of room reutrned                        **
 * *****************************************************************/
std::string Room::getLocation()
{
	return location;
}

/********************************************************************
 * * function: void Room::setCompass ()                            **
 * * description: set the values of the compass struct             **
 * * parameters: Room *n, Room *s, Room *e, Room *w                **
 * * pre-conditions: class object is created valid pointers passed **
 * * to struct                                                     **
 * * post-conditions: struct has inital pointers for room direction**
 * *****************************************************************/
void Room::setCompass (Room *n, Room *s, Room *e , Room *w)
{
	current.north = n;
	current.south = s;
	current.east = e;
	current.west = w;
}

/********************************************************************
 * * function: Compass Room:getCompass ()                          **
 * * description: return a rooms compass                           **
 * * parameters: none                                              **
 * * pre-conditions: class object is created                       **
 * * post-conditions: sruct of room compass returned               **
 * *****************************************************************/
/*Compass Room:: getCompass ()
{
	return current;
}*/
/********************************************************************
 * * function: void Room::navigate (Player *p)                     **
 * * description: player navigation in a room                      **
 * * parameters: player *p                                         **
 * * pre-conditions: class object is created                       **
 * * post-conditions: player navigates through room                **
 * *****************************************************************/
void Room::navigate(Player *p)
{
	char direction;

	do 
            {
		std::cout << std::endl;
                std::cout << "Which direction do you want to move? N/S/E/W " ;
		std::cin >> direction;
		std::cout << std::endl;

		if (toupper(direction) == 'N')
			moveN(p);

		else if (toupper(direction) == 'S')
			moveS(p);

		else if (toupper(direction) == 'E')
			moveE(p);

		else if (toupper(direction) == 'W')
			moveW(p);
	        else
		       std::cout << "Invalid direction. Try again." << std::endl;	
	    } while (!moveOn);

}
