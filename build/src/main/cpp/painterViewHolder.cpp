#include "../headers/painterViewHolder.hpp"

PainterViewHolder::~PainterViewHolder()
{}

PainterViewHolder::PainterViewHolder(Painter obj):ViewHolder(obj.toString().length()+2,3)
{
	std::string tmp = obj.toString();
	elem[0][0] = U'┌';
	elem[2][0] = U'└';
	elem[0][width-1] = U'┐';
	elem[2][width-1] = U'┘';
	for(int i = 1 ; i < width-1; i++)
	{
		elem[0][i] = U'\u2500';
		elem[2][i] = U'\u2500';
		elem[1][i] = tmp[i-1];
	}
}

PainterViewHolder::PainterViewHolder(PainterViewHolder& obj) : ViewHolder(obj)
{
	for(int y = 0 ; y < heigh ; y ++)
	{
		for(int x = 0 ; x < width ; x ++)
		{
			elem[y][x] = obj.elem[y][x];
		}
	}
}

PainterViewHolder& PainterViewHolder::operator=(PainterViewHolder& obj)
{
	this->ViewHolder::operator=(obj);
	return *this;
}
