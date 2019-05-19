#pragma once
#ifndef STRINGPROJECT_STRING_H

#define STRINGPROJECT_STRING_H
#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <string.h>
#include <cmath>
#include <sstream>

#include "baseInterface.hpp"

class String : public base
{
  private:

	  char *_string;

	  int length;

	  //сравнение символов
	  bool comprationChar(const String &secondString)const;

	  //меняет местами значения двух строк
	  void swap(String &b);

	   //перевод в число с плаваяюзей запятой
            double convertToDouble()const;

            //перевод в целое число
            int convertToInt()const;

            //перевод в числос плавающей запятой
            float convertToFloat()const;


  public:
	  
	  //конструктор
	  String();
        
	  //конструктор копированния
	  String(const String &secondString);

	  //конструктор новой строки
	  String(const char *newString);
	  
	  //перегрузка опретора конкатенации строк
	  String operator+(const String &rightString);
	  
	  //перегрузка операции присваивания
	  String& operator= (const String &rightString);

	  String& operator+=(const String& );

	  //метод вывода строки 
	  void printString()const;

	  //перегрузка оператора >=
	  bool operator>=(const String &rightString)const;

	  //перегрузка оператора <=
	  bool operator<=(const String &rightString)const;

	  //перегрузка оператора ==
	  bool operator==(const String &rightString)const;

	  //перегрузка оператора >
	  bool operator>(const String &rightString)const;

	  //перегрузка оператора <
	  bool operator<(const String &rightString)const;

	  //перегрузка оператора !=
	  bool operator!=(const String &rightString)const;

	  //деструктор 
	  ~String();

	  //перегрузка ввода из потока
	  friend std::ostream& operator<< (std::ostream &os, String &obj);

	  //оператор приведения типов к целому
	  operator int()const;

	  //оператор приведения типа к дабл
	  operator double()const;

	  //оператор приведения типов к флот
	  operator float()const;

	  //оператор примедения к типу константный указатель на символ
	  operator const char*()const;
	  
	  std::string toString()const;

	  bool isEmpty()const;
};


#endif 

