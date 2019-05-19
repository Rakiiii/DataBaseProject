#include "../headers/customStirng.hpp"

//конструктор пустой строки

	String::String()
	{
		this->length = 0;

		this->_string = nullptr;
	}

	//конструктор копированния

	String::String(const String &secondString)
	{
		//копируемм длинну строки

		this->length = secondString.length;

		//выделяем память в куче для нашей строки + закрывающий ноль
		if(this->length != 0)
		this->_string = new char[length + 1];

		//случай строка пустая
		if(secondString._string != nullptr)
			//копируем все символы
		strcpy(this->_string,secondString._string);
		else this->_string = nullptr;
	}

	//конструктор новой строки
	String::String(const char *newString)
	{
		//длина равная количеству символов
		this->length = strlen(newString);

		//выделяем память
		this->_string = new char[this->length + 1];

		//копируем все символы
		strcpy(this->_string, newString);
	}

	//перегрузка оператора конкатенации
	String String::operator+(const String &rightString)
	{
		//случай если одна их строк пустая
		if (rightString._string == nullptr)return *this;
		if (this->_string == nullptr)return rightString;

		//создаем результируюшую строку
		String newString;

		//получаем длину новой строки
		newString.length = this->length + rightString.length;

		//выделяем память строки
		newString._string = new char[newString.length + 1];

		//складываем непосредственно строки
		strcpy(newString._string,this->_string);
		strcpy(newString._string + this->length, rightString._string);

		//newString._string[newString.length + 1] = '\0';
		//возвращаем наш объект
		return newString;
	}

	//меняет местами значения двух строк
	void String::swap(String &b)
	{
		//меняем местами значения длинны
		std::swap(length, b.length);

		//меняем местами указатели на строку
		std::swap(_string, b._string);
	}

	//перегрузка оператора присваивания
	String& String::operator=(const String &rightString)
	{
		//если присваиваем к не нулевой строке то очищаем память и обнуляем указтель
		if (this->_string != nullptr)
		{
			delete[] this->_string;
			this->_string = nullptr;
		}
		//если справа 0 строка
		if (rightString._string == nullptr)
		{
			//то длинна тоже 0
			this->length = 0;
		}
		else
		{
			//если не нулевая строка, то копируем длинну
			this->length = rightString.length;

			//выделяем память и копируем строку
			this->_string = new char[this->length + 1];
			strcpy(this->_string , rightString._string);
		}
		return *this;
	}
	
	//перегрузка операции конкатенации к себе
	String& String::operator+=(const String& obj)
	{	
		*this = ( *this + obj );
		return *this;
		
	}

	//метод вывода строки

	void String::printString()const
	{
		if(this->_string != nullptr)std::cout << this->_string << std::endl;
		else std::cout << std::endl;
	}

	//перегрузка оператора >=
	bool String::operator>=(const String &rightString)const
	{
		if (this->length >= rightString.length)return true;
		else return false;
	}

	//перегрузка оператора <=
	bool String::operator<=(const String &rightString)const
	{
		if (this->length <= rightString.length)return true;
		else return false;
	}

	//перегрузка оператора >

 	bool String::operator>(const String &rightString)const
	{
		if (this->length > rightString.length)return true;
		else return false;
	}

	//перегрузка оператора <

	bool String::operator<(const String &rightString)const
	{
		if (this->length < rightString.length)return true;
		else return false;
	}

	//перегрузка оператора ==

	bool String::operator==(const String &rightString)const
	{
		//побитово сравниваем строки
		return this->comprationChar(rightString);
	}

	//перегрузка оператора !=

	bool String::operator!=(const String &rightString)const
	{
		//побитово сравниваем строки
		return !(this->comprationChar(rightString));
	}

	//сравнение символов
	bool String::comprationChar(const String &secondString)const
	{
		//проверяем длины строк
		if (this->length != secondString.length)
		{
			//строки разной длинны не могут быть равны
			return false;
		}
		else
		{
			//прозодим все символы
			for (int i = 0; i < this->length; i++)
			{
				//если символы не совпадают ,строки не равны
				if (this->_string[i] != secondString._string[i])return false;
			}
		}
		//в ином случае строки равны
		return true;
	}

	//деструктор

	 String::~String()
	{
		 //если указатель не нулевой
		if (this->_string != nullptr)
		{
			//освобождаем выделенную под строку память
			delete[] this->_string;

			//обнуляем указатель,память которого освободили
			this->_string = nullptr;
		}
	}

	//преобразование строки в число

	int String::convertToInt()const
	{
		//инициализируем возвращаемое значение
		int number = NULL;
		int signFlag = 1;

		//проходим все элементы строки
		for (int i = 0; i < this->length; i++)
		{
			//если наткнулись на минус
			if (this->_string[i] == '-')
			{
				//проверяем первый ли он
				if (signFlag == 1)
				{
					//если первый , то учитываем его в числе и смотрим слудеющее
					signFlag = -1;
					i++;
				}
				//если >1 минуса то возвращаем NULL
				else return NULL;
			}
			//если элемент строки число
			if ((this->_string[i] >= '0') && (this->_string[i] <= '9'))
			{
				//тогда прибаляем его в возвращаемое значение
				number = number * 10 + this->_string[i] - 0x30;
			}
            //иначе возвращаем NULL
			else return NULL;
		}
		//возвращаем число , если в строке были только числа
		return number*signFlag;
	}

	//перевод из строки в число с плавающей запятой

	double String::convertToDouble()const
	{
		//инициализируем возвращаемое значение
		double number = NULL;

		//инциализируем флаг для точки
		bool flag = false;
		double signFlag = 1.0;

		//инициализируем счетчик для степени
		int counter = 0;

		//проходим строку
		for (int i = 0; i < this->length; i++)
		{
			//если наткнулись на минус
			if (this->_string[i] == '-')
			{
				//проверяем первый ли он
				if (signFlag == 1.0)
				{
					//если первый , то учитываем его в числе и смотрим слудеющее
					signFlag = -1.0;
					i++;
				}
				//если >1 минуса то возвращаем NULL
				else return NULL;
			}
			//если точка или запятая или число
			if (
				(this->_string[i] == '.') ||
				(this->_string[i] == ',') ||
				((this->_string[i] >= '0') && (this->_string[i] <= '9'))
				)
			{
				//если точка или запяиая
				if ((this->_string[i] == '.') || (this->_string[i] == ','))
				{
					//проверяем была ли точка или запятая до этого
					if (!flag)
					{
						//если небыло,то перескакиваем на соедующий элемент
						i++;
						//и обновляем флаг
						flag = true;
					}
					//если вторая точка или запятая ,то возвращаем null
					else return NULL;
				}
				//если число
				if ((this->_string[i] >= '0') && (this->_string[i] <= '9'))
				{
					//если после точки то увеличиваем сетчик степени
					if (flag) counter++;
					//добовляем к возвращаемому значению
					number = number * 10 + this->_string[i] - 0x30;
				}
			}
			//если не допустимый сисмвол возвращаем NULL
			else return NULL;
		}
		if (counter > 0)number = (double)(number) / (double)pow(10, counter);
		return number*signFlag;
	}

	float String::convertToFloat()const
	{
		float number = NULL;
		bool flag = false;
		int counter = 0;
		for (int i = 0; i < this->length; i++)
		{
			if (
				(this->_string[i] == '.') ||
				(this->_string[i] == ',') ||
				((this->_string[i] >= '0') && (this->_string[i] <= '9'))
				)
			{
				if ((this->_string[i] == '.') || (this->_string[i] == ','))
				{
					if (!flag)
					{
						i++;
						flag = true;
					}
					else return NULL;
				}
				if ((this->_string[i] >= '0') && (this->_string[i] <= '9'))
				{
					if (flag) counter++;
					number = number * 10 + this->_string[i] - 0x30;
				}
			}
			else return NULL;
		}
		if (counter > 0)number =(float) (number / pow(10, counter));
		return number;
	}

	//перегрузка вывода в поток

std::ostream& operator<< (std::ostream &os, String &obj)
	{
		//посимвольном отправлем строку в поток
		for (int i = 0; i < obj.length; i++)
		{
			os << obj._string[i];
		}
		//возвращаем изменненый поток
		return os;
	}

	//перегрузка приведения к константному указателю на строку

	String::operator const char *()const
	{
		return this->_string;
	}

	//перегрузка приведения к целому числу

	String::operator int()const
	{
		//возвращаем хранящееся в строке число если оно там есть
		return this->convertToDouble();
	}

	//перегрузка оператора приведенеия к числу с плавающей запятой

	String::operator double()const
	{
		//возвращаем хранящееся в строке число если оно там есть
		return this->convertToDouble();
	}

	//перегрузка оператора приведенеия к числу с плавающей запятой

	String::operator float()const
	{
		//возвращаем хранящееся в строке число если оно там есть
		return this->convertToFloat();
	}

std::string String::toString()const
{
	std::stringstream ss;
	//посимвольном отправлем строку в поток
                  for (int i = 0; i < length; i++)
                  {
                          ss << _string[i];
                  }
	return ss.str();
	//return std::string(this->length,*this->_string);
}

bool String::isEmpty()const
{
	return (this->_string == nullptr);
}
