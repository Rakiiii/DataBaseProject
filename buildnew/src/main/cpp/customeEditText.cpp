#include "../headers/customeEditText.hpp"
#include "../headers/trim.hpp"
#include "/usr/include/ConsoleComponentsLib/editText.hpp"

CustomeEditText::CustomeEditText(int width,int heigh,std::string id):EditText(width,heigh,id),addSt(false),err(false),help(false),
	_addTV(false),fpos(true),helpTextView(160,6,std::string("hTV"))
{
	helpTextView.setText(std::string("-add                               -quit -q!\n")+
			     std::string("-remove <number or template>       -exit    \n")+
			     std::string("-help                              -wq!     \n")+
			     std::string("-search <template>                          \n")+
			     std::string("-load <filepath/filename.txt>               \n")+
			     std::string("-save <filepath/filename.txt>"		 )			
			    );
	pos = hist.begin();
}

CustomeEditText::~CustomeEditText()
{}

void CustomeEditText::update()
{
	EditText::update();
	elem[1][width-1]=U'\u2502';
}

void CustomeEditText::setErr()
{
	err = true;
}

CustomeEditText& CustomeEditText::operator++(int)
{
	if(fpos)
	{
		text = *pos;
		fpos = false;
	}
	else
	{
		if(pos != --(hist.end()))
		{
			pos++;
			text = *pos;
		}
		else
		{
			text = "";
			pos = hist.begin();
			fpos = true;
		}
	}
	return *this;
}

CustomeEditText& CustomeEditText::operator--(int)
{
	if(!fpos)
	{
		if(pos == hist.begin())
		{
			text = "";
			fpos = true;
		}
		else
		{
			pos--;
			text = *pos;
		}
	}
	else
	{
		fpos = false;
		pos = (--hist.end());
		text = *pos;
	}
	return *this;
}

CustomeEditText& CustomeEditText::addToHist(std::string _hist)
{
	hist.push_front(_hist);
	pos = hist.begin();
	fpos = true;
	return *this;
}

CustomeEditText& CustomeEditText::addStart()
{
	tmpXML = ((LinearMainFrame*)parent)->getXML();
	addSt = true;
	((LinearMainFrame*)parent)->setXML(std::string("2|id:informTextView|id:mCustomeEditText|"));
	return *this;
}

CustomeEditText& CustomeEditText::addEnd()
{
        if(text == "quit" || text == "abort" || text == "q!")
        {
                 ((LinearMainFrame*)parent)->setXML(tmpXML);
                 tmpXML = "";
                 addSt = false;
		 text = "";
                 return *this;
        }
	std::stringstream ss(text);
	std::string email,adress,name;
	int amount = 0 ;
	long phone;
	ss>>name;
	ss>>phone;
	ss>>email;
	ss>>adress;
	ss>>amount;
	std::string* pic = new std::string[amount]();
	text = "";
	for(int i = 0 ; i < amount; i ++)ss>>pic[i];
	try
	{
	((RecyclerView<Sheet,PainterViewHolder,Painter>*)((LinearMainFrame*)parent)->getPartWithId(std::string("mRecycleView")))->addNewElem(Painter(name,phone,email,adress,pic,amount));
	}
	catch(BadPainterInit e)
	{
		text = "Wrong patern format for adding";
		err = true;
		return *this;
	}
	catch(TemplateSheetOutOfRange e)
	{
		text = "Error: too many elems in sheet";
		err = true;
		((LinearMainFrame*)parent)->setXML(tmpXML);
		tmpXML = "";
		addSt = false;
		return *this;
	}
	((LinearMainFrame*)parent)->setXML(tmpXML);
	tmpXML = "";
	addSt = false;
	return *this;
}

CustomeEditText& CustomeEditText::printHelp()
{
	if(help)
	{
		help = false;
		std::string xml = ((LinearMainFrame*)parent)->getXML();
		size_t pos = 0;
		int _am = stoi(xml,&pos);
		_am --;

		((LinearMainFrame*)parent)->setXML(std::to_string(_am) + xml.substr(pos,xml.rfind("hTV")-4));
	}
	else
	{
		std::string xml = ((LinearMainFrame*)parent)->getXML();
		size_t pos = 0;
		int _am = stoi(xml,&pos);
		_am++;
		if(!_addTV)
		{
			_addTV = true;
			((LinearMainFrame*)parent)->addElem(&helpTextView);
		}
		((LinearMainFrame*)parent)->setXML( std::to_string(_am) + xml.substr(pos) + "id:hTV|");
		help = true;
	}
	return *this;
}

CustomeEditText& CustomeEditText::load(std::string _file)
{
	if(_file[0] == '~')
	{
		_file = "/home/smurf" + _file.substr(1);
	}
	if(_file == "")
	{
		_file = "/home/smurf/painter.txt";
	}
	((RecyclerView<Sheet,PainterViewHolder,Painter>*)((LinearMainFrame*)parent)->getPartWithId(std::string("mRecycleView")))->readFromFile(_file);
	return *this;
}	

CustomeEditText& CustomeEditText::save(std::string _file)
{
	if(_file[0] == '~')
	{
		_file = "/home/smurf" + _file.substr(1);
	}
	if(_file == "")
	{
		_file = "/home/smurf/painter.txt";
	}
	((RecyclerView<Sheet,PainterViewHolder,Painter>*)((LinearMainFrame*)parent)->getPartWithId(std::string("mRecycleView")))->saveToFile(_file);
	return *this;
}

CustomeEditText& CustomeEditText::remove(std::string obj)
{
	std::stringstream ss(obj);
	int number ;
	ss>>number;
	if( !(ss.good()) && ss.eof() )
	{
		try
		{
		((RecyclerView<Sheet,PainterViewHolder,Painter>*)((LinearMainFrame*)parent)->getPartWithId(std::string("mRecycleView")))->deleteAt(number-1);
		text = "";
		((RecyclerView<Sheet,PainterViewHolder,Painter>*)((LinearMainFrame*)parent)->getPartWithId(std::string("mRecycleView")))->update();
		}
		catch(TemplateSheetException e)
		{
			text = "Error: there is no elements with such number";
			err = true;
		}
		return *this;
	}	
	else
	{

	RecyclerView<Sheet,PainterViewHolder,Painter> *res = ((RecyclerView<Sheet,PainterViewHolder,Painter>*)((LinearMainFrame*)parent)->getPartWithId(std::string("mRecycleView")));
          for(int i = 0 ; i < res->getSize() ; i ++)
          {
                  if((*res)[i].toString().rfind(obj) != std::string::npos)
                  {
                          res->deleteAt(i);
			  text = "";
			  res->update();
                          return *this;
                  }
          }
	  text = "Nothing was found by this patern";
	  err = true;
	  return *this;
	}
}

CustomeEditText& CustomeEditText::search(std::string obj)
{
	RecyclerView<Sheet,PainterViewHolder,Painter> *res = ((RecyclerView<Sheet,PainterViewHolder,Painter>*)((LinearMainFrame*)parent)->getPartWithId(std::string("mRecycleView")));
	for(int i = 0 ; i < res->getSize() ; i ++)
	{
		if((*res)[i].toString().rfind(obj) != std::string::npos)
		{
			if(i-res->getAmountOfShowenElems() >= 0)res->setShowenElem(i - res->getAmountOfShowenElems() + 1);
			else res->setShowenElem(i);
			text = "";
			res->update();
			return *this;
		}
	}
	err = true;
	text = "Nothing was found by this template";
	return *this;
}

void CustomeEditText::event(char32_t ev)
{
	if(err)
	{
		err = false;
		text = "";
	}
	if(ev == '\n')
	{
		if(addSt)
		{
			addEnd();
				
		}
		else
		{
			if(text.rfind(std::string("add")) != std::string::npos)
			{
				addToHist(text);
				addStart();
				text = "";
			}
			else
			{
				if(text.rfind(std::string("help")) != std::string::npos)
				{
					addToHist(text);
					printHelp();
					text = "";
				}
				else
				{
					if(text.rfind(std::string("load")) != std::string::npos)
					{
						addToHist(text);
						load(trim_copy(text.substr(text.rfind(std::string("load")) + 4 )));
						text = "";
					}
					else
					{
						if(text.rfind(std::string("save")) != std::string::npos)
						{
							addToHist(text);
							save(trim_copy(text.substr(text.rfind(std::string("save")) + 4)));
							text = "";
						}
						else
						{
							if(text.rfind(std::string("remove")) != std::string::npos)
							{
								addToHist(text);
								remove(trim_copy(text.substr(text.rfind(std::string("remove"))+6)));
							}	
							else
							{
								if((text.rfind(std::string("search"))) != std::string::npos)
								{	
									addToHist(text);
									search(trim_copy(text.substr(text.rfind(std::string("search"))+6)));
								}
								else
								{
									if(text.rfind(std::string("wq")) != std::string::npos)
									{
										try
										{
											save(std::string("DB.txt"));
										}
										catch(std::exception e)
										{
											addToHist(text);
											err = true;
											text = std::string(e.what());
											EditText::update();
											return;
										}	
										throw Exit();
									}
									else
									{
										if(text == "exit" || text == "quit" || text == "Exit" || text == "Quit" || text == "q!")throw Exit();
								}	}
							}
						}
					}
				}
			}
		}
	}else
	{
		if((ev >= 'a' && ev <= 'z') || (ev >= '0' && ev <= '9') || ( ev >= 'A' && ev <= 'Z' ) ||
			ev == ' ' || ev == '@' || ev == '.' || ev == '/' || ev == '!' || ev == ':' || ev == '-')EditText::event(ev);
		else
		{
			if(ev == U'\177' && text != "")text.pop_back();
			else
			{
				switch(ev)
				{
					case U'\034':
						(*this)++;	
						break;
					case U'\035':
						(*this)--;
						break;
					default:
						break;
				}	
			}
		}
	}
	EditText::update();

}

