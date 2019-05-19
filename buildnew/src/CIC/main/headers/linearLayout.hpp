#ifndef CICLIB_LINEARLAYOUT_HPP

#define CICLIB_LINEARLAYOUT_HPP

#include "cordinateLayout.hpp"

class LinearLayout : public CordinateLayout
{

	/*
	 *шаблон должен иметь вид:
	 *"количество_элементов<int> |id:id_элеменат |..."
	 */


	public:
		LinearLayout(int, int ,std::string , std::string);
		LinearLayout(LinearLayout&) = delete;
		virtual ~LinearLayout();

		virtual void update();
};

#endif
