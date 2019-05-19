#include "../headers/date.hpp"



       int Date::mDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};


bool Date::isValid(int day , int month , int year)
{
	if(day < 1 || month < 1 || month > 12 || day > 31 || year < 1970)return 0;
	if(mDays[month - 1] < day)return 0;
	else return 1;
}

bool Date::isOk()
{
	return Date::isValid(day , month , year);
}

std::string Date::toString()const
{
	std::stringstream ss;
	ss<<day<<'/'<<month<<'/'<<year;
	return ss.str();
}

bool Date::isEmpty()const
{
	return !(day);
}

Date& Date::setDate(int _day , int _month , int _year)
{
	if(Date::isValid(_day , _month , _year))
        {
                day = _day;
                month = _month;
                year = _year;
	     	return *this;	
        }
        else throw InvalidDate();

}

Date& Date::setDate(std::string date)
{
	int _day , _month, _year;
          _day = stoi(date.substr( 0 , 2));
          _month = stoi(date.substr( 3 , 2));
          _year = stoi(date.substr( 6 , 4));
          setDate(_day , _month ,_year);
	return *this;
}

Date& Date::setDate(char const* date)
{
	std::string _date(date);
	setDate(_date);
	return *this;
}
Date::Date():day(1) , month(1) , year(1970){}

Date::Date(int _day , int _month , int _year)
{
	setDate(_day , _month , _year);
}

Date::Date(Date& obj)
{
	this->day = obj.day;
	this->month = obj.month;
	this->year = obj.year;
}

Date::Date(std::string date)
{
	setDate(date);
}

Date::Date(char const* date)
{
	setDate(date);
}

Date::~Date()
{}

void Date::validation()
{
	while(!isOk())
	{
		if(day > 0)
		{
			day = day - mDays[month - 1];
			month++;
			if(month == 13)
			{
				month = 1;
				year ++;
			}
		}
		else
		{
			month --;
                        if(month == 0)
                        {
                                month = 12;
                                year --;
                        }

			day = day + mDays[month - 1];
		}
	}
}

bool Date::operator==(const Date& obj)const
{
	return (day == obj.day && month == obj.month && year == obj.year);
}

bool Date::operator<=(const Date& obj)const
{
	if((*this) == (obj))return 1;
	if(year <= obj.year)
	{
		if(month <= obj.month || year < obj.year)
		{
			if(day <= obj.day || month < obj.month || year < obj.year)return 1;
			else return 0;
		}else return 0;
	}else return 0;
}

bool Date::operator>=(const Date& obj)const
{
	 if((*this) == (obj))return 1;
        if(year >= obj.year)
        { 
                if(month >= obj.month || year > obj.year)
                {
                        if(day >= obj.day || month > obj.month || year > obj.year)return 1;
                        else return 0;
                }else return 0;
        }else return 0;

}



Date& Date::operator++(int)
{
	day ++;
	validation();
	return *this;
}

Date& Date::operator--(int)
{
	day --;
	validation();
	return *this;
}

Date& Date::operator=(const Date& obj)
{
	this->day = obj.day;
        this->month = obj.month;
        this->year = obj.year;
	return *this;
}

Date operator+(Date& date, const int number)
{
	Date res(date);
	res.day += number;
	res.validation();
	return res;	
}

Date operator-(Date& date , const int number)
{
	Date res(date);
	res.day -= number;
	res.validation();
	return res;
}






















