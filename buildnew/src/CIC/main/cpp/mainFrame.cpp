#include "../headers/mainFraim.hpp"

MainFrame::MainFrame(int width , int heigh , std::string id , std::string xml) : Layout(width , heigh , id , xml)
{}

MainFrame::~MainFrame()
{}

void MainFrame::event(char32_t ev)
{
        for(auto i = parts.begin(); i != parts.end() ; i ++)
        {
                (*i)->event(ev);
        }
}

void MainFrame::show()const
{
	wclear(stdscr);
	for(int posY = 0 ; posY  < heigh ; posY ++) 
	{
		mvaddnwstr(posY,0,(wchar_t*)elem[posY],width);
	
	}
}
void MainFrame::addElem(View* newElem) 
{
	Layout::addElem(newElem);
}

void MainFrame::setXML(std::string newXML)
{
	Layout::setXML(newXML);
}
