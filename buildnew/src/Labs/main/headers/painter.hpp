#pragma once 

#ifndef PICTUREPLACE_PAINTER_HPP

#define PICTUREPLACE_PAINTER_HPP

#include <iostream>
#include <sstream>

#include "exceptoin.hpp"
#include "painterStruct.hpp"


class Painter
{
	private:
		//множественный указатель на структуру художник
		std::shared_ptr<PainterStruct> value;

	public:

	Painter();

	//деструктор
	~Painter();
	
	//конструктор
	Painter(std::string _name , long _phoneNumber , std::string _email ,std::string _addres , std::string* _pictures , int _amountOfPictures);

	//конструктор
        Painter(char const* _name , long _phoneNumber , char const* _email ,char const* _addres , char const** _pictures , int _amountOfPictures);

	//явное копированние
	Painter(const Painter& obj);
	
	//явное присваивание
	Painter& operator=(const Painter&);

	//оператор равенства
	bool operator==(const Painter&)const;

	//приведение к указателю на void
	operator void*()const;

	//оператор отрицания
	bool operator!()const;

	//приведение к строке
	std::string toString()const;

	//оператор вывода в поток
	friend std::ostream& operator<<(std::ostream& os , Painter& obj);


};



#endif 

