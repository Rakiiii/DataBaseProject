#ifndef PICTUREPLACE_DATE_HPP

#define PICTUREPLACE_DATE_HPP

#include <iostream>
#include <sstream>

#include "baseInterface.hpp"
#include "exceptoin.hpp"

class Date : public base
{
	private:
		static int mDays[12];

		int day , month , year;

		static bool isValid(int , int , int);

		void validation();

		bool isOk();

	public:
		std::string toString()const;

		bool isEmpty()const;

		Date();
		Date(Date&);
		Date(int ,int , int);
		Date(std::string);
		Date(char const*);
		virtual ~Date();

		Date& setDate(int,int,int);
		Date& setDate(std::string);
		Date& setDate(char const*);

		Date& operator=(const Date&);
		bool operator==(const Date&)const;

		bool operator<=(const Date&)const;
		bool operator>=(const Date&)const;

		Date& operator++(int);
		Date& operator--(int);

		friend Date operator+(Date& ,const  int);
		friend Date operator-(Date& ,const  int);
};

#endif
