#ifndef CICLIB_CORDINATEMAINFRAME_HPP

#define CICLIB_CORDINATEMAINFRAME_HPP

#include "mainFraim.hpp"

class CordinateMainFrame : public MainFrame
{
        protected:
                //Добавление элемента на layout по координата X и Y, и id элемента
                 virtual CordinateMainFrame& addElemAt(std::string , int , int);

                  /*
                  *шаблона должен иметь вид:
                  *"количество_элементов<int> |id:id_элемента [Кординат_по_x<int>,Кординаты_по_y<int>] |..."
                  */

	public:
		CordinateMainFrame(int,int,std::string,std::string);
		CordinateMainFrame(CordinateMainFrame&) = delete;
		virtual ~CordinateMainFrame();


                //обновление состояния элемента
                virtual void update();

                //реализация callback
                virtual void event(char32_t ev);

                //добавление нового элемента в mainframe
                virtual void addElem(View*);

                //смена шаблона mainframe
                virtual void setXML(std::string);



};

#endif
