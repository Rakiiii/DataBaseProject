#ifndef CICLIB_CORDINATELAYOUT_HPP

#define CICLIB_CORDINATELAYOUT_HPP

#include "layout.hpp"


//layout с координатным позиционированнием
class CordinateLayout : public Layout 
{
	protected:
		//Добавление элемента на layout по координата X и Y, и id элемента
		 virtual CordinateLayout& addElemAt(std::string , int , int);

		 /*
		  *шаблона должен иметь вид:
		  *"количество_элементов<int> |id:id_элемента [Кординат_по_x<int>,Кординаты_по_y<int>] |..."
		  */

	public:
		CordinateLayout(int,int,std::string,std::string);
		CordinateLayout(CordinateLayout&) = delete;
		virtual ~CordinateLayout();
		
		//обновление состояния элемента		
		virtual void update();

		//реализация callback
		virtual void event(char32_t ev);

		//добавление нового элемента в layout
		virtual void addElem(View*);

		//смена шаблона layout
		virtual void setXML(std::string);



};

#endif
