#ifndef DATABASE_CUSTOMEEDITTEXT_HPP

#define SHEET
#define DATABASE_CUSTOMEEDITTEXT_HPP

#include <sstream>
#include <list>

#include "../headers/painterViewHolder.hpp"

#include "/usr/include/ConsoleComponentsLib/editText.hpp" 
#include "/usr/include/ConsoleComponentsLib/linearMainFrame.hpp"
#include "/usr/include/ConsoleComponentsLib/recycleViewForTemplateSheet.hpp"
#include "/usr/include/LabsLib/templateSheet.hpp"
#include "/usr/include/LabsLib/painter.hpp"

class CustomeEditText : public EditText
{
        private:
                bool addSt;

		bool err;

		bool help;

		bool _addTV;

		bool fpos;

                std::string tmpXML;

		TextView helpTextView;

		std::list<std::string> hist;

		std::list<std::string>::iterator pos;

                CustomeEditText& addStart();
                CustomeEditText& addEnd();
                CustomeEditText& remove(std::string);
                CustomeEditText& search(std::string);
		CustomeEditText& printHelp();
		CustomeEditText& save(std::string);
		CustomeEditText& load(std::string);
		CustomeEditText& addToHist(std::string);
		CustomeEditText& operator++(int);
		CustomeEditText& operator--(int);
        public:
                CustomeEditText(int,int,std::string);
                CustomeEditText(CustomeEditText&) = delete;
                virtual ~CustomeEditText();


                virtual void event(char32_t ev);
		virtual void update();

		void setErr();
};

class Exit : public std::exception
{
	public:
		char const* what() const noexcept {  return "Exit@" ; }
};

#endif

