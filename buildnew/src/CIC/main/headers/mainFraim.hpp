#ifndef CICLIB_MAINFRAME_HPP

#define CICLIB_MAINFRAME_HPP

#include "layout.hpp"

class MainFrame : public  Layout
{
	public:
		MainFrame(int,int,std::string,std::string);
		MainFrame(MainFrame&) = delete;
		virtual ~MainFrame();

		virtual void event(char32_t ev);
		virtual void update() = 0;
		virtual void addElem(View*);
		virtual void setXML(std::string);
		virtual void show()const;
};

#endif
