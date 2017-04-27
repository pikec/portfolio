/***************************************************
 * * filename: Code.hpp
 * * author: Candis Pike
 * * date: June 6, 2015
 * * description: class decleartion file Code class
 * * input: none
 * * output: none
 * ************************************************/

#ifndef CODE_HPP
#define CODE_HPP

#include "Room.hpp"
#include <string>

class Code:public Room
{
	private:
		int codeNum;
	
	protected:

	public:
		Code();
		Code(std::string);
		~Code();
		void determineCode();
		void moveN(Player*);
		void moveS(Player*);
		void moveE(Player*);
		void moveW(Player*);
};
#endif
