#include "../headers/textView.hpp"


TextView::TextView(int width,int heigh,std::string id) : View(width + 2,heigh + 2,id)
{}

TextView::~TextView()
{}

void TextView::event(char32_t ev)
{}

void TextView::update()
{
	auto pos = text.begin();    
    	auto end = text.end();	
        bool flag = true;

        elem[0][0] = U'┌';
        for(int x = 1 ; x < width - 1; x++)elem[0][x] = U'\u2500';
        elem[0][width-1] = U'┐';
        for(int y = 1; y < heigh - 1 ; y++)
        {
                flag = true;
                elem[y][0] = U'\u2502';
                for(int x = 1 ; x < width - 1 && pos != end; x++)
                {
                        if(*pos != '\n' && flag)
                        {
                                elem[y][x] = *pos;
                                pos++;
                        }
                        else
                        {
                                if(flag)
                                {
                                        flag = false;
                                        elem[y][x] = ' ';
                                        pos++;
                                }
                                else
                                {
                                        elem[y][x] = ' ';
                                }
                        }
                }
                elem[y][width-1] = U'\u2502';
        }
        elem[heigh-1][0] = U'└';
        for(int x = 1; x < width - 1;x++)elem[heigh-1][x] = U'\u2500';
        elem[heigh-1][width-1] = U'┘';
        View::update();

}

TextView& TextView::setText(std::string newText)
{
	text = newText;
	update();
	return *this;
}

std::string TextView::getText()const
{
	return text;
}
