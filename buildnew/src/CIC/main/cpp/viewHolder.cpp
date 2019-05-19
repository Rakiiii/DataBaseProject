#include "../headers/viewHolder.hpp"

ViewHolder::~ViewHolder()
{
	if(elem)
	{
		for(int i =0 ; i< heigh ; i++)
		{
			delete[] elem[i];
		}
		delete[] elem;
	}
}

ViewHolder::ViewHolder(int width,int heigh):width(width),heigh(heigh)
{
	elem = new wchar_t*[heigh];
	for(int i = 0 ; i < heigh ; i++)
	{
		elem[i] = new wchar_t[width];
	}
}

ViewHolder::ViewHolder(ViewHolder& obj):ViewHolder(obj.width,obj.heigh)
{
	for(int i =0 ; i < heigh ; i ++)
	{
		for ( int j = 0 ; j < width ; j++)
		{
			elem[i][j] = obj.elem[i][j];
		}
	}
}

ViewHolder& ViewHolder::operator=(ViewHolder& obj)
{
	if(this == &obj)return *this;
        if(elem)
        {
                for(int i =0 ; i< heigh ; i++)
                { 
                        delete[] elem[i];
                } 
                delete[] elem;
        } 	
	width = obj.width;
	heigh = obj.heigh;
        elem = new wchar_t*[heigh];
        for(int i = 0 ; i < heigh ; i++)
        {
                elem[i] = new wchar_t[width];
        }
  	for(int i =0 ; i < heigh ; i ++)
        {
                for ( int j = 0 ; j < width ; j++)
                {
                        elem[i][j] = obj.elem[i][j];
                }
        }
	return *this;
}

