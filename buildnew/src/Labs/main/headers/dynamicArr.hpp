#ifndef STACKTEMPLATE_DYNAMICARR_HPP

#define STACKTEMPLATE_DYNAMICARR_HPP

#include <iostream>
#include <functional>

template<class T , const int step = 5>
class dynArr
{
	private:
		//указатель на массив объектов
		T* info;

		//размер выделенной памяти
		size_t size;

		//создание куч
		void heapyfaer(int range ,int i , std::function<int(T& , T& )>& cmp );

		//стандартное сравнение членов для сортировки
		static std::function<int(T&,T&)> defcmp;
	public:

		//конструктор
		dynArr(const size_t size = 1);
		
		//запрезаем неявное копированние
		dynArr(dynArr&) = delete;

		//запрещаем оператор присваивания
		dynArr& operator=(dynArr&) = delete;

		//деструктор
		virtual ~dynArr();

		//перегрузка оператора индексации
		T& operator[](const int pos);

		//вывод размера массива
		void printSize()const;

		//геттер размера массива
		size_t getSize()const;

		//сортировка кучей
		virtual dynArr<T>&  heapSort(std::function<int(T& , T& )>& cmp = defcmp);	

};


template<class T , const int step>
dynArr<T , step>:: dynArr(const size_t size):size(size)
{
	//выделяме памятьё под массив заданного размера
	info = new T[size];
}

template<class T , const int step>
dynArr<T , step>:: ~dynArr()
{
	//если массив есть
	if(info != nullptr)
	{
		//освобождаем память от масссива
		delete[] info;
	}
}

template<class T , const int step>
T& dynArr<T , step>:: operator[](const int pos)
{
	//если пытаемся адресоваться к элементу за пределами массива
	if(pos >=0 && pos >= size)
	{
		//выделяем память под новый массива большего размера
		T *newInf = new T[pos+step];
		for(int i = 0 ; i < size; i ++)
		{
			//коппируем объекты в новый массив
			newInf[i] = info[i];
		}
		//освобождаем память от старого массива
		delete[] info;
		//двигаем указатель
		info = newInf;
		//увеличиваем размер массива
		size = pos + step;
	}
	return info[pos];
}

template<class T , const int step>
void dynArr<T , step>::printSize()const
{
	std::cout<<size<<std::endl;
}

template<class T , const int step>
size_t dynArr<T , step>::getSize()const
{
	return size;
}


template<class T , const int step>
void dynArr<T ,step>::heapyfaer(int i , int range , std::function<int(T& , T&)>& cmp)
{
	int largest = i;

	//левое поддерево
	int left = 2*i + 1;

	//правое поддерево
	int right = 2*i + 2;

	//if( left < range && info[left] > info[largest] )largest = left;
	if( left < range && cmp(info[left] , info[largest] ) > 0 ) largest = left;

	//if(right < range && info[right] > info[largest])largest = right;
	if( right < range && cmp(info[right] , info[largest] ) > 0 ) largest = right;

	if(largest != i)
	{
		T tmp = info[i];
		info[i] = info[largest];
		info[largest] = tmp;

		heapyfaer( i , largest , cmp);
	}
}

//сортировка кучей
template<class T , const int step>
dynArr<T>& dynArr<T , step>::heapSort(std::function<int(T& , T& )>& cmp )
{
	//делаем кучи
	for( int i = size/2 - 1; i >= 0; i--)heapyfaer(size , i , cmp);

	//Достаем элементы из кучи
	for( int i = size - 1; i >= 0 ; i--)
	{	 
		T tmp = info[0];
		info[0] = info[i];
		info[i] = tmp;

		heapyfaer(i , 0 , cmp);
	}
	return *this;

}

template<class T>
int _defcmp(T& left , T& right)
{
	if(left == right) return 0;
	if(left > right)return 1;
        else return -1;	
}
template<class T,int step>
std::function<int(T&,T&)> dynArr<T,step>::defcmp = std::function<int(T&,T&)>(&_defcmp<T>);

#endif
