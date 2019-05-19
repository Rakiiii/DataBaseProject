#ifndef CICLIB_TEXTVIEW_HPP

#define CICLIB_TEXTVIEW_HPP

#include "view.hpp"

class TextView : public View
{
	protected:
		std::string text;
	
	public:
		TextView(int,int,std::string);
		TextView(TextView&) = delete;
		virtual ~TextView();

		virtual void update();
		virtual void event(char32_t ev);
		virtual TextView& setText(std::string);
		virtual std::string getText()const;
};

#endif
