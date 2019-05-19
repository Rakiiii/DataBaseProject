#ifndef CICLIB_EDITTEXT_HPP

#define CICLIB_EDITTEXT_HPP

#include "textView.hpp"

class EditText : public TextView
{

	public:
	
		EditText(int,int,std::string);
		EditText(EditText&) = delete;
		virtual ~EditText();

		virtual void update();
		virtual void event(char32_t ev);
		
};

#endif
