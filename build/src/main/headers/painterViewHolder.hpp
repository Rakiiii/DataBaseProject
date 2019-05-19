#ifndef DATABASEPROJECT_PAINTERVIEWHOLDER_HPP

#define DATABASEPROJECT_PAINTERVIEWHOLDER_HPP

#include "../../../usr/include/ConsoleComponentsLib/viewHolder.hpp"
#include "../../../usr/include/LabsLib/painter.hpp"

struct PainterViewHolder : public ViewHolder  
{
	Painter value;

	PainterViewHolder(Painter);
	PainterViewHolder(PainterViewHolder&);
	PainterViewHolder& operator=(PainterViewHolder&);
	virtual ~PainterViewHolder();
	
};

#endif
