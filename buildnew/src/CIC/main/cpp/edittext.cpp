#include "../headers/editText.hpp"

EditText::EditText(int width,int heigh, std::string id) : TextView(width,heigh,id)
{
	TextView::setText(std::string(""));
}

EditText::~EditText()
{}

void EditText::update()
{
	int pos = 0;
        bool flag = true;
	
	elem[0][0] = U'┌';
	for(int x = 1 ; x < width - 1; x++)elem[0][x] = U'\u2500';
	elem[0][width-1] = U'┐';
	for(int y = 1; y < heigh - 1 ; y++)
	{
		flag = true;
		elem[y][0] = U'\u2502';
		for(int x = 1 ; x < width - 1; x++)
		{
			if(text[pos] != '\n' && flag)
			{
				elem[y][x] = text[pos];
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


void EditText::event(char32_t ev)
{
	text += ev;
	update();
}
