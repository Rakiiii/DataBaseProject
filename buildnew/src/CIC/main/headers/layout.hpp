#ifndef CICLIB_LAYOUT_HPP

#define CICLIB_LAYOUT_HPP

#include <list>
#include <sstream>
#include <limits>

#include "view.hpp"


//view содержащий другие view
class Layout : public View
{
	protected:

		//список указательей на дочерние элементы layout
		std::list<View*> parts;
		
		//шаблон расположения дочерних элементов в layout
		std::string xml;

	public:
		Layout(int,int,std::string,std::string);
		Layout(Layout&) = delete;
		virtual ~Layout();
		
		//обновление состояния элемента		
		virtual void update() = 0;

		//реализация callback
		virtual void event(char32_t ev);

		//добавление нового элемента в layout
		virtual void addElem(View*);

		//смена шаблона layout
		virtual void setXML(std::string);

		virtual std::string getXML()const;

		virtual View* getPartWithId(std::string);

		void clear();

};

#endif
