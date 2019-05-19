#include "../headers/basicSheet.hpp"

int defCmp(Painter& left,Painter& right)
{
	if(left.toString() == right.toString()) return 0;
	if(left.toString() > right.toString() ) return 1;
	else return -1;
}

std::function<int(Painter&,Painter&)> BasicSheet::cmp = std::function<int(Painter&,Painter&)>(&defCmp); 


BasicSheet::BasicSheet(Date date , const size_t size):dynArr<Painter>(1)
{
	maxSize = size;
	_date = date;
	amountOfStrings = 0;
}

BasicSheet::BasicSheet(std::string fileAdress):dynArr<Painter>(1)
{
	std::fstream file(fileAdress);
	if(file.is_open())
	{
		std::string info;
		getline(file,info);
		maxSize = stoi(info);
		getline(file,info);
		amountOfStrings = stoi(info);
		getline(file,info);
		_date = Date(info);
		for(int i =0 ; i < amountOfStrings;i ++)
		{
			getline(file,info);
			std::stringstream ss(info);
			std::string name,email,adress;
			int amounOfPictures;
			long phoneNumber;
			ss>>name>>phoneNumber>>email>>adress>>amounOfPictures;
			std::string pictures[amounOfPictures];
			for(int j = 0; j < amounOfPictures; j ++)
			{
				ss>>pictures[j];
			}
			this->dynArr<Painter>::operator[](i) = 
				Painter(name,phoneNumber,email,adress,pictures,amounOfPictures);
		}
		file.close();
	}else
	{
		_date = Date();
		maxSize = 0;
		amountOfStrings = 0;
	}
}

BasicSheet::~BasicSheet()
{}

Painter& BasicSheet::operator[](int pos)
{
	if(pos < 0)throw BasicSheetOutOfRange();
	if((size_t)pos < amountOfStrings)
	{
		return this->dynArr<Painter>::operator[](pos);
	}
	else throw BasicSheetOutOfRange();
}

void BasicSheet::move(int pos , bool right)
{
	if(pos < 0)throw BasicSheetOutOfRange();
	if(right && amountOfStrings >= maxSize)throw BasicSheetOverflow();
        if(right)
	{
		Painter *tmp = new Painter[amountOfStrings - pos];
		for(int i = pos ; i < amountOfStrings ; i++)
		{
			tmp[i-pos] = this->dynArr<Painter>::operator[](i);
		}
		amountOfStrings ++;
		for(int i = pos + 1 ;(size_t) i < amountOfStrings ; i++)
		{
			this->dynArr<Painter>::operator[](i) = tmp[i - pos - 1];
		}        
		delete[] tmp;
	}
	else
	{
		for(int i = pos; (size_t)i < amountOfStrings ; i++)
		{
			this->dynArr<Painter>::operator[](i) = this->dynArr<Painter>::operator[](i+1);
		}
		amountOfStrings--;
	}
}

void BasicSheet::insert(const int pos , Painter& obj)
{
	if(pos < 0)throw BasicSheetOutOfRange();
	if((size_t)(pos) >= maxSize)throw BasicSheetOverflow();
	if(!(this->dynArr<Painter>::operator[](pos)))
	{
		this->dynArr<Painter>::operator[](pos) = obj;	
	}
	else 
	{
		if(amountOfStrings >= maxSize)throw BasicSheetOverflow();
		else
		{
			move(pos);
			this->dynArr<Painter>::operator[](pos) = obj;  
		}
	}
}

void BasicSheet::insert(const int pos,std::string _name,int _phoneNumber,std::string _email,std::string _addres,std::string* _pictures,int _amountOfPictures)
{
	Painter obj(_name , _phoneNumber , _email,_addres,_pictures,_amountOfPictures);
	insert(pos , obj);
}


void BasicSheet::deleteAt(const int pos)
{
	move(pos,false);
}

void BasicSheet::replace(const int pos , Painter& obj)
{
	(*this)[pos] = obj;
}


int BasicSheet::search( std::string request)const
{
	for(int i = 0;(size_t) i < amountOfStrings ; i ++)
	{
		int pos = (*const_cast<BasicSheet*>(this))[i].toString().find(request);
		if(pos != std::string::npos)return i;
	}
	return -1; 
}

int cmp(Painter& obj1,Painter& obj2)
{
	std::string str1 = obj1.toString() , str2 = obj2.toString();
	if(str1[0] == str2[0])return 0;
	if(str1[0] > str2[0])return 1;
	else return -1;
}

Date BasicSheet::getDate()
{
	return _date;
}

void BasicSheet::setDate(Date& obj)
{
	_date = obj;
}

std::string BasicSheet::saveOnDisk(std::string fileAdress)
{
	std::fstream file(fileAdress);
	if(file.is_open())
	{
		file<<maxSize<<std::endl<<amountOfStrings<<std::endl<<_date.toString()<<std::endl;
		for(int i = 0 ;(size_t)i < amountOfStrings; i ++)
		{
			file<<(*this)[i];
		}
	}
	else throw BasicSheetBadDiskSave();
	file.close();
	return fileAdress;
}

std::string BasicSheet::saveOnDisk(char const* fileAdress)
{
	return saveOnDisk(std::string(fileAdress) );
}


dynArr<Painter>& BasicSheet::heapSort(std::function<int(Painter&,Painter&)>& comp )
{
	return dynArr<Painter>::heapSort(comp);
}
