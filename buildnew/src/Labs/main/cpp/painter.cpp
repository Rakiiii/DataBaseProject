#include "../headers/painter.hpp"

Painter::Painter()
{
	value = std::make_shared<PainterStruct>();
}

Painter::~Painter()
{}


Painter::Painter(std::string _name , long _phoneNumber , std::string _email ,std::string _addres , std::string* _pictures , int _amountOfPictures)
            {
		    //выделяем место под структуру в указателе
		    value = std::make_shared<PainterStruct>();

		    //инициализируем поля структуы в указателе
		    value->name = _name;
		    value->phoneNumber = _phoneNumber;
		    value->email = _email;
		    value->addres = _addres;
		    value->amountOfPictures = _amountOfPictures;

		    //инициализируем уникальный указатель на массив списка картин
		    //value->pictures = std::make_shared<std::string[]>(value->amountOfPictures);

		    //если нет картин или указатель на null то кидаем ошибку инициализации
		    if(!value->amountOfPictures)throw BadPainterInit();
		    //иначе заполням массив
		    else
		    {
		    	for(int i = 0 ; i < value->amountOfPictures ; i++) value->pictures.push_back( _pictures[i]);
		    }

	    }

Painter::Painter(char const* _name , long _phoneNumber , char const* _email ,char const* _addres , char const** _pictures , int _amountOfPictures)
{
	//выделяем место под структуру в указателе
                    value = std::make_shared<PainterStruct>();

                    //инициализируем поля структуы в указателе
                    value->name = std::string(_name);
                    value->phoneNumber = _phoneNumber;
                    value->email = std::string(_email);
                    value->addres = std::string(_addres);
                    value->amountOfPictures = _amountOfPictures;

                    //инициализируем уникальный указатель на массив списка картин
                    //value->pictures = std::make_shared<std::string[]>(value->amountOfPictures);

                    //если нет картин или указатель на null то кидаем ошибку инициализации
                    if(!value->amountOfPictures)throw BadPainterInit();
                    //иначе заполням массив
                    else
                    {
                        for(int i = 0 ; i < value->amountOfPictures ; i++) value->pictures.push_back( std::string(_pictures[i]));
                    }

}


Painter::Painter(const Painter& obj) : value(obj.value)
{
}

Painter& Painter::operator=(const Painter& obj)
{
	this->value = obj.value;
	return *this;
}
//оператор равенства
bool Painter::operator==(const Painter& obj)const
{
	return (value == obj.value) || ( toString() == obj.toString() );
}

Painter::operator void*()const
{
	return (void*)value.get();
}

bool Painter::operator!()const
{
	return !value.get();
}

//приведение к строке
std::string Painter::toString()const
{
	std::stringstream ss;
	
	ss<<value->name<<" "<<value->phoneNumber<<" "<<value->email<<" "<<value->addres<<" "<<value->amountOfPictures<<" ";

	for(int i = 0 ; i < value->amountOfPictures ; i++ ) ss<<value->pictures[i]<<" ";

	return ss.str();
}

//оператор вывода в поток
std::ostream&  operator<<(std::ostream& os , Painter& obj)
{
	os<<obj.toString();
	return os;	
}

