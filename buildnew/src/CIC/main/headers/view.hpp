#ifndef CICLIB_VIEW_HPP

#define CICLIB_VIEW_HPP

#include <string>

#include "cicException.hpp"

#include </usr/include/ncursesw/ncurses.h>


class View
{
	protected:
		//размеры элемента
		int width;
		int heigh;

		//указатель на родительский элемент
		View* parent;

		//представление элемента
		char32_t** elem;
		
		//id элемента
		std::string id;

	public:
		//запрет яного копированния
		View(View&) = delete;

		//конструктор 
		View(int ,int,std::string);

		//метод реализации сallback
		virtual void event(char32_t ev) = 0;

		//метод эксплицитного обновления состояния элемента
		virtual void update();

		//диструктор
		virtual ~View();

		//геттеры для размеров элемента
		int getWidth()const;
		int getHeigh()const;

		//метод проверки id элемента
		bool checkId(std::string)const;

		//метод получения карты элемента
		char32_t** getElem();

		void setParent(View*);
};



#endif
