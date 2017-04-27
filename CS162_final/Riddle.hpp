/****************************************************
 * * filename: Riddle.hpp
 * * author: Candis Pike
 * * date: June 6, 2015
 * * description: class decleration file Riddle class
 * * input: none
 * * output: none
 * ***************************************************/

#ifndef RIDDLE_HPP
#define RIDDLE_HPP

#include "Room.hpp"
#include <string>

class Riddle:public Room
{
	private:

	protected:

	public:	
                Riddle();
		Riddle(std::string);
		~Riddle();
		void riddle1();
		void riddle2();
		void riddle3();
		void moveN (Player*);
		void moveS (Player*);
		void moveE (Player*);
		void moveW (Player*);
};

#endif
