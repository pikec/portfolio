/***************************************************
 * * filename: Room.hpp
 * * author: Candis Pike
 * * description: class decleration file Room class
 * * input: none
 * * output: none
 * *************************************************/

#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <cstdlib>

class Player;

class Room
{
	private:

	protected:
		std::string location;
		bool moveOn;
	public:
		struct Compass
			{
				Room *north;
				Room *south;
				Room *east;
				Room *west;
			Compass (Room *n = NULL, Room *s = NULL, Room *e = NULL, Room *w = NULL)
				{
					north = n;
					south = s;
					east = e;
					west = w;
				}
			};
		Compass current;

		Room ();
		Room(std::string);
		virtual ~Room();
		std::string getLocation();
		void setCompass (Room*, Room*, Room*, Room*);
		//Compass getCompass ();
		void navigate(Player*);
		virtual void moveN (Player*) = 0;
		virtual void moveS (Player*) = 0;
		virtual void moveE (Player*) = 0;
		virtual void moveW (Player*) = 0;
};

#endif
