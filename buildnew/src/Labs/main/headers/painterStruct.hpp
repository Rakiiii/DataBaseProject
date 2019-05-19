#pragma once

#ifndef PICTUREPLACE_PAINTERSTRUCT_HPP

#define PICTUREPLACE_PAINTERSTRUCT_HPP

#include <string>
#include <memory>
#include <vector>

struct PainterStruct
{	
	//имя
        std::string name;

        //номер телефона
        long  phoneNumber;

        //электронный адрес
        std::string email;

        //адрес
        std::string addres;

        //количество картин
        int amountOfPictures;

        //список картин
        std::vector<std::string> pictures;
};


#endif
