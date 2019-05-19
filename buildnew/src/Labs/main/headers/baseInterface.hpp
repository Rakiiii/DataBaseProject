#ifndef PICTUREPLACE_BASEINTERFACE_HPP

#define PICTUREPLACE_BASEINTERFACE_HPP

#include <string>

class base 
{
	public:
		virtual std::string toString()const = 0;
		virtual bool isEmpty()const = 0;
};

#endif
