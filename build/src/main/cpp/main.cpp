#include "/usr/include/ConsoleComponentsLib/linearMainFrame.hpp" 
#include "/usr/include/ConsoleComponentsLib/textView.hpp"
#include "/usr/include/LabsLib/templateSheet.hpp"
#include "../headers/customeEditText.hpp"
#include <locale.h>
#include "/usr/include/ConsoleComponentsLib/cicException.hpp"

int main()
{
	setlocale(LC_ALL,"");
	initscr();
	LinearMainFrame m(170,50,std::string("mFrame"),std::string("3|id:dateTextView|id:mCustomeEditText|id:mRecycleView|"));
	TextView informTextView(160,4,std::string("informTextView"));
	TextView dateTextView(160,1,std::string("dateTextView"));
	CustomeEditText cet(160,1,std::string("mCustomeEditText"));
	RecyclerView<Sheet,PainterViewHolder,Painter> mRecycleView(160,36,std::string("mRecycleView"),12);
	m.addElem(&informTextView);
	m.addElem(&mRecycleView);
	m.addElem(&cet);
	m.addElem(&dateTextView);
	dateTextView.setText(std::string("12/12/2012"));
	informTextView.setText(std::string("hold this patern for add:\nname phonenumber email adress amount_of_pictures pictures_names_with_spaces\n-quit or -q! or -abort to go back"));
	char choose;
	bool flag = true;
	while(flag)
	{
		
		choose = getch();
		if(choose == U'\033')
		{
			getch();
			choose = getch();
			switch(choose)
			{
				case U'A':
					choose = U'\032';
					break;
				case U'B':
					choose = U'\033';
					break;
				case U'C':
					choose = U'\034';
					break;
				case U'D':
					choose = U'\035';
					break;
				default: 
					break;
			}
		}
		try
		{
			m.event(choose);
		}
		catch(OutOfRange e)
		{
			cet.setErr();
			cet.setText(std::string("Error:the limit of the elements is catched"));
		}
		catch(Exit e)
		{
			flag = false;	
		}
	}
	endwin();
	return 0;
}
