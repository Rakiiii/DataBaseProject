#include "../headers/cordinateLayout.hpp"


CordinateLayout::CordinateLayout(int width,int heigh,std::string id,std::string xml) : Layout(width,heigh,id,xml)
{}

CordinateLayout::~CordinateLayout()
{}

CordinateLayout& CordinateLayout::addElemAt(std::string id,int posX, int posY)
{
	for(auto i =  parts.begin();i != parts.end(); i++)
	{
		if( (*i)->checkId(id) )
		{
			char32_t** inElem = (*i)->getElem();
			for(int y = 0; y < (*i)->getHeigh() ; y++)
			{
				for(int x = 0 ; x < (*i)->getWidth() ; x++)
				{
					elem[posY + y][posX + x] = inElem[y][x]; 
				}
			}
			return *this;

		}
	}
	throw InvalideId();
}

void CordinateLayout::update()
{
	Layout::clear();

	//запихиваем шаблон в поток
	std::stringstream ss(xml);

	//извлекаем количества элементов из потока-шаблона
	int amountOfElems;
	ss >> amountOfElems;
	
	//если в начале не число кидаем ошибку
	if(amountOfElems <= 0)throw InvalideXml();

	//выкидываем все до разделительного символа
	ss.ignore(std::numeric_limits<std::streamsize>::max(),'|');

	for(int i = 0 ; i < amountOfElems ; i ++)
	{
		//иниициализируем строки для id действующего элемента и поиска id
		std::string tmpid,checkId;

		//иниициализация переменных для позиции элемента
		int posX = 0, posY = 0;

		//проверка коректности шаблона
		checkId += ss.get();checkId += ss.get();checkId += ss.get();
		if( checkId != std::string("id:" ) )throw InvalideId();

		//чтение id элемента 
		while(ss.peek() != ' ' && ss.peek() != '|')
		{
			tmpid += ss.get();
		}

		//переход к чтению координат
		ss.ignore(std::numeric_limits<std::streamsize>::max(),'[');

		//чтение координаты по x
		ss>>posX;
		
		//переход к чтению y
		ss.ignore(std::numeric_limits<std::streamsize>::max(),',');

		//чтение координаты по y	
		ss>>posY;
		
		//добовляем элемента на layout
		addElemAt(tmpid,posX,posY);

		//переход к чтению следующего элемента
		ss.ignore(std::numeric_limits<std::streamsize>::max(),'|');
	}
	View::update();	
}

void CordinateLayout::event(char32_t ev)
{
	Layout::event(ev);
}

void CordinateLayout::addElem(View* el)
{
	Layout::addElem(el);
}

void CordinateLayout::setXML(std::string xml)
{
	Layout::setXML(xml);
}
