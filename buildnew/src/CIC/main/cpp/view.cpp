#include "../headers/view.hpp"

View::View(int width,int heigh,std::string id)
{
	//инициализируем все значения присущие любому view
	this->width = width;
	this->heigh = heigh;
	this->parent = nullptr;
	this->id = id;

	//выделяем память под графическое представление элемента
	this->elem = new char32_t*[heigh];
	for(int i = 0 ; i < heigh; i++)
	{
		this->elem[i] = new char32_t[width];
	}
	for(int i = 0 ; i < heigh ; i++)
	{
		for(int j =0 ; j < width ; j++)
		{
			elem[i][j] = ' ';
		}
	}
}

View::~View()
{
	if(elem)
	{
		for(int i = 0; i < heigh; i++)
		{
			if(elem[i]) delete[] elem[i];
		}

		delete[] elem;
	}
}

char32_t** View::getElem()
{
	return elem;
}

bool View::checkId(std::string testId)const
{
	return (testId == id);
}

int View::getWidth()const
{
	return width;
}

int View::getHeigh()const
{
	return heigh;
}

void View::update()
{
	if(parent != nullptr)
	{
		parent->update();
	}
}

void View::setParent(View* newParent)
{
	parent = newParent;
}
