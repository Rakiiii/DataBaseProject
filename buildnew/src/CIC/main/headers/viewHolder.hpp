#ifndef CICLIB_VIEWHILDERINTERFACE_HPP

#define CICLIB_VIEWHILDERINTERFACE_HPP

#include "view.hpp"

struct ViewHolder 
{
		wchar_t** elem;
		
		int width;
		int heigh;

		
		ViewHolder(int,int);
		ViewHolder(ViewHolder&);
		ViewHolder& operator=(ViewHolder&);
		virtual ~ViewHolder();
};

#endif
