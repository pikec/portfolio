/*********************************************************
 * * filename:Manipulate.cpp
 * * author: Candis Pike
 * * date:June 6, 2015
 * * descrption: class immplemenation file Manipulate class
 * * input: none
 * * output: specified by function
 * *******************************************************/

#ifndef MANIPULATE_HPP
#define MANIPULATE

#include "Room.hpp"
#include <string>

class Manipulate:public Room
{
	private:

	protected:
	
	public:
		Manipulate();
		Manipulate(std::string);
		~Manipulate ();
		void moveN(Player*);
		void moveS(Player*);
		void moveE(Player*);		
		void moveW(Player*);
};

#endif
