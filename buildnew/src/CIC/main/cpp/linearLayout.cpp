#include "../headers/linearLayout.hpp"


LinearLayout::LinearLayout(int width, int heigh , std::string id , std::string xml) : CordinateLayout(width,heigh,id,xml)
{}

LinearLayout::~LinearLayout()
{}

void LinearLayout::update()
{
	Layout::clear();
	//позиция вставки элемента
	int posY = 0;

	//инициализация потока для шаблона
	std::stringstream ss(xml);

        //извлекаем количества элементов из потока-шаблона
        int amountOfElems;
        ss >> amountOfElems;

        //если в начале не число кидаем ошибку
        if(amountOfElems <= 0)throw InvalideXml();

        //выкидываем все до разделительного символа
        ss.ignore(std::numeric_limits<std::streamsize>::max(),'|');
	
	for(int i = 0 ; i < amountOfElems ; i++)
	{
                //иниициализируем строки для id действующего элемента и поиска id
                std::string tmpid,checkId;

                //проверка коректности шаблона
                checkId += ss.get();checkId += ss.get();checkId += ss.get();
                if( checkId != std::string("id:" ) )throw InvalideId();

                //чтение id элемента
                while(ss.peek() != ' ' && ss.peek() != '|')
                {
                        tmpid += ss.get();
                }
		
		//вставляем все в наш layout
		CordinateLayout::addElemAt(tmpid,0,posY);

		//обновляем полжения указателя высоты
		bool flag = true;
		auto j = parts.begin();
		while(flag)
		{
			if((*j)->checkId(tmpid)) 
			{
				posY += (*j)->getHeigh();
				flag = false;
			}
			else
			{
				j++;
			}
		}
		
		//переходим к чтению следующего элемента
		ss.ignore(std::numeric_limits<std::streamsize>::max(),'|');
	}

	        View::update();

}
