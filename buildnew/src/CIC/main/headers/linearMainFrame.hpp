#ifndef CICLIB_LINEARMAINFRAME_HPP

#define CICLIB_LINEARMAINFRAME_HPP

#include "cordinateMainFrame.hpp"

class LinearMainFrame : public CordinateMainFrame
{
	public:
		LinearMainFrame(int,int,std::string,std::string);
		LinearMainFrame(LinearMainFrame&) = delete;
		virtual ~LinearMainFrame();
		
		virtual void event(char32_t ev);
                virtual void update();
                virtual void addElem(View*);
                virtual void setXML(std::string);
		virtual View* getPartWithId(std::string);

};

#endif
