#include "../headers/cordinateMainFrame.hpp"

CordinateMainFrame::CordinateMainFrame(int width , int heigh , std::string id , std::string xml) : MainFrame(width , heigh , id , xml)
{}

CordinateMainFrame::~CordinateMainFrame()
{}

CordinateMainFrame& CordinateMainFrame::addElemAt(std::string id , int posX , int posY)
{
        for(auto i =  parts.begin();i != parts.end(); i++)
        {
                if( (*i)->checkId(id) )
                {
                        char32_t** inElem = (*i)->getElem();
			int wd = (*i)->getWidth(),hg = (*i)->getHeigh();
                        for(int y = 0; y < hg ; y++)
                        {
                                for(int x = 0 ; x < wd ; x++)
                                {
                                        elem[posY + y][posX + x] = inElem[y][x];
                                }
				//elem[posY+y][posX + wd] = inElem[y][wd];
                        }
                        return *this;

                }
        }
	auto i = parts.begin();
	if(parts.begin() == parts.end()  && (*i)->checkId(id))
	{
			auto i = parts.begin();
                        char32_t** inElem = (*i)->getElem();
                        int wd = (*i)->getWidth(),hg = (*i)->getHeigh();
                        for(int y = 0; y < hg ; y++)
                        {
                                for(int x = 0 ; x < wd ; x++)
                                {
                                        elem[posY + y][posX + x] = inElem[y][x];
                                }
                        }
                        return *this;

	}
	else throw InvalideId();
}

void CordinateMainFrame::update()
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

void CordinateMainFrame::event(char32_t ev)
{
	MainFrame::event(ev);
}

void CordinateMainFrame::addElem(View* newElem)
{
	Layout::addElem(newElem);
}

void CordinateMainFrame::setXML(std::string newXML)
{
	Layout::setXML(newXML);
}
