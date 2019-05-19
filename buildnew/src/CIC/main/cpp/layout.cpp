#include "../headers/layout.hpp"

Layout::Layout(int width,int heigh,std::string id,std::string xml) : View(width,heigh,id)
{
        this->xml = xml;
}

Layout::~Layout()
{}

void Layout::addElem(View* obj)
{
        parts.push_back(obj);
	obj->setParent(this);
}

void Layout::setXML(std::string newXml)
{
        this->xml = newXml;
        this->update();
}

void Layout::event(char32_t ev)
{
	for(auto i = parts.begin(); i != parts.end() ; i ++)
	{
		(*i)->event(ev);
	}
	View::update();
}

std::string Layout::getXML()const
{
	return xml;
}

View* Layout::getPartWithId(std::string objId)
{
	for(auto it = parts.begin(); it != parts.end(); it++)
		if((*it)->checkId(objId))return (*it);
	throw InvalideId();
}

void Layout::clear()
{
	for(int y = 0 ; y < heigh ; y++)
	{
		for( int x = 0 ; x < width ; x ++)
		{
			elem[y][x] = ' ';
		}	
	}
}
