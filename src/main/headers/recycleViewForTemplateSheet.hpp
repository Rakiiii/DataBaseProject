#ifndef CICLIB_RECYCLERVIEW_HPP

#define CICLIB_RECYCLERVIEW_HPP

#include <list>
#include <vector>

#include "viewHolder.hpp"

//ViewHolder выводимый объект принимающий в конструктор тип type,и уонструирующий из него объект, содержащий публичное поле elem представляющее из себя матрицу символов,
//width определяющий ширину матрицы,
//heigh определяющий высоту матрицы
//поддерживающий неявное копированние
/*
 * specialization for sheet
 */


template <template<class, template<class ...> class, int> class container,class ViewHolder , class type>
class RecyclerView : public View
{
        private:

                //список всех viewholder содержащихся в recyclerview
                container<type,std::vector,1024> collectionOfElems;

                //итератора на первый отображаемый элемент
                int cap;

                //количество отображаемых элементов
                int amountOfShowenElems;

        public:

                RecyclerView(int,int,std::string,int);
                RecyclerView(RecyclerView&) = delete;
                virtual ~RecyclerView();

                virtual void event(char32_t ev);
                virtual void update();

                //добавление нового элемента
                virtual RecyclerView& addNewElem(type);

                //сдвиг на n элемент
                virtual RecyclerView& move(int);

                //удаление элемента
                virtual RecyclerView& deleteAt(int);

                //перегрузка оператора индексации для редактированния вкличаемых элементов
                type& operator[](int);

                //получение количества выводимых элементов
                int getAmountOfShowenElems()const;
                //установка количества выводимых элементов
                RecyclerView& setAmountOfShowenElems(int);

                //установка первого отображаемого элемента
                RecyclerView& setShowenElem(int);
                //первый отображаемый элемент
                int getShowenElem()const;
                                                                                                                                                       
                //общее количество элементов в колекции
                int getSize()const;

		int readFromFile(std::string);

		int saveToFile(std::string);
};

template <template<class, template<class ...> class, int> class container,class ViewHolder , class type>
int RecyclerView<container,ViewHolder,type>::getSize()const
{
        return collectionOfElems.getSize();
}

template <template<class, template<class ...> class, int> class container,class ViewHolder , class type>
int RecyclerView<container,ViewHolder,type>::getShowenElem()const
{
        return cap;
}

template <template<class, template<class ...> class, int> class container,class ViewHolder , class type>
RecyclerView<container,ViewHolder,type>&  RecyclerView<container,ViewHolder,type>::setShowenElem(int pos)
{
        if(pos < 0 || pos > collectionOfElems.getSize())throw OutOfRange();
        cap = pos;
        return *this;
}

template <template<class, template<class ...> class, int> class container,class ViewHolder , class type>
RecyclerView<container,ViewHolder,type>::RecyclerView(int width,int heigh,std::string id,int _amountOfShowenElems):View(width,heigh,id)
{
        if(_amountOfShowenElems < 0)throw OutOfRange();
	cap = 0;
        amountOfShowenElems = _amountOfShowenElems;
}

template <template<class, template<class ...> class, int> class container,class ViewHolder , class type>
RecyclerView<container,ViewHolder,type>::~RecyclerView()
{}

template <template<class, template<class ...> class, int> class container,class ViewHolder , class type>
RecyclerView<container,ViewHolder,type>&  RecyclerView<container,ViewHolder,type>::move(int mv)
{
        if(cap+mv < 0 || cap+mv>collectionOfElems.getSize())throw OutOfRange();
        cap += mv;
        update();
        return *this;
}

template <template<class, template<class ...> class, int> class container,class ViewHolder , class type>
int RecyclerView<container,ViewHolder,type>::readFromFile(std::string _file)
{
	int res =  collectionOfElems.readFromFile(_file);
	if(res > 0)update();
	return res;
}

template<template<class,template<class...>class,int> class container,class ViewHolder , class type>
int RecyclerView<container , ViewHolder, type>::saveToFile(std::string _file)
{
	int res =  collectionOfElems.saveToFile(_file);
	if(res > 0)update();
	return res;
}

template <template<class, template<class ...> class, int> class container,class ViewHolder , class type>
void  RecyclerView<container,ViewHolder,type>::event(char32_t ev)
{
        switch(ev)
        {
                case U'\033':
                        {
                                move(1);
                                break;
                        }
                case U'\032':
                        {
                                move(-1);
                                break;
                        }
                default :
                        break;
        }
}

template <template<class, template<class ...> class, int> class container,class ViewHolder , class type>
void  RecyclerView<container,ViewHolder,type>::update()
{
        int outEl = 0;
        //определяем что меньше,количество элементов в коллекции или количество выводимых элементов
        if( amountOfShowenElems < collectionOfElems.getSize()) outEl = amountOfShowenElems;
        else outEl = collectionOfElems.getSize();
        //позиция вывода элементов из контаинера в recycle view
        int Xpos = 0,Ypos = 0;
        for(int i = cap; i < outEl; i++)
        {
                ViewHolder mviewHolder(collectionOfElems[i]);
                int ViewHolderWidth = mviewHolder.width,ViewHolderHeigh = mviewHolder.heigh;
                for(int ypos = 0 ; ypos < ViewHolderHeigh; ypos++)
                {
                        for(int xpos = 0 ; xpos < ViewHolderWidth ; xpos++)
                        {
                                elem[Ypos+ypos][Xpos+xpos] = mviewHolder.elem[ypos][xpos];
                        }
                }
                //в случае выхода за границу recycle view заканчиваем вывод
                if( ( ( Xpos + ViewHolderWidth > width ) || ( Ypos + ViewHolderHeigh > heigh ) ) && (i+1 < outEl) )
                {
                        parent->update();
                        return;
                }
                //Xpos += ViewHolderWidth;
                Ypos += ViewHolderHeigh;
        }
        View::update();

}

template <template<class, template<class ...> class, int> class container,class ViewHolder , class type>
RecyclerView<container,ViewHolder,type>&  RecyclerView<container,ViewHolder,type>::setAmountOfShowenElems(int am)
{
        amountOfShowenElems = am;
        update();
        return *this;
}

template <template<class, template<class ...> class, int> class container,class ViewHolder , class type>
int  RecyclerView<container,ViewHolder,type>::getAmountOfShowenElems()const
{
        return amountOfShowenElems;
}

template <template<class, template<class ...> class, int> class container,class ViewHolder , class type>
RecyclerView<container,ViewHolder,type>&  RecyclerView<container,ViewHolder,type>::addNewElem(type newObj)
{
        collectionOfElems.push(newObj);
        if(amountOfShowenElems >= collectionOfElems.getSize()) update();
        return *this;
}

template <template<class, template<class ...> class, int> class container,class ViewHolder , class type>
RecyclerView<container,ViewHolder,type>&  RecyclerView<container,ViewHolder,type>::deleteAt(int pos)
{
        collectionOfElems.deleteAt(pos);
        if(pos > cap && pos < cap+amountOfShowenElems)update();
        return *this;
}

template <template<class, template<class ...> class, int> class container,class ViewHolder , class type>
type&  RecyclerView<container,ViewHolder,type>::operator[](int pos)
{
        return collectionOfElems[pos];
}

#endif
