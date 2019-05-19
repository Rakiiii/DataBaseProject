

#ifndef PICTUREPLACE_BASICSHEET_HPP
#define PICTUREPLACE_BASICSHEET_HPP

#include <fstream>
#include <functional> 

#include "dynamicArr.hpp"
#include "painter.hpp"
#include "date.hpp"



class BasicSheet : public dynArr<Painter>
{
	private :
		Date _date;

		size_t maxSize;

		size_t amountOfStrings;

		void move(const int , bool right = true);

	public:

		static std::function<int(Painter&,Painter&)> cmp;

		BasicSheet(Date date ,const size_t size = 1);
		BasicSheet(std::string);
		BasicSheet(BasicSheet&) = delete;

		virtual ~BasicSheet();

		Painter& operator[](const int);

		void insert(const int,Painter&);
		void insert(const int,std::string , int , std::string ,std::string , std::string* , int );

		void deleteAt(const int);

		void replace(const int , Painter&);
		
		int search(std::string)const;

		Date getDate();
		void setDate(Date&);

		std::string saveOnDisk(std::string);
		std::string saveOnDisk(char const*);
		
		dynArr<Painter>& heapSort(std::function<int(Painter&,Painter&)>& = BasicSheet::cmp );
};



#endif
