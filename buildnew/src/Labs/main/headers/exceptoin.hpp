#pragma once

#ifndef PICTUREPLACE_EXCEPTION_HPP

#define PICTUREPLACE_EXCEPTION_HPP

#include <exception>

class PainterException :public  std::exception
{
	public:
		char const* what()const noexcept{ return "PainterException@";}
};

class BadPainterInit : public  PainterException
{
	public:
		char const* what()const noexcept{ return "PainterException@BadPainterIntitParams";}
};

class dynArrException : public std::exception
{
	public:
		char const* what()const noexcept{ return "dynArrException@";}
};

class CustomVectorException : public dynArrException
{
	public:
		char const* what()const noexcept{ return "CustomVectorException@";}
};

class CustomVectorOutOfRange : public CustomVectorException
{
	public:
		char const* what()const noexcept{ return "CustomVectorException@VectorIsOutOfRange";}
};

class DateException : public std::exception
{
	public:
		char const* what()const noexcept{ return "DateException@";}
};

class InvalidDate : public DateException
{
	public:
		char const* what()const noexcept{ return "DateException@InvalidDate";}
};

class BasicSheetException : public std::exception
{
	public:
		char const* what()const noexcept{ return "BasicSheetException@";}
};

class BasicSheetOutOfRange : public BasicSheetException
{
	public:
		char const* what()const noexcept { return "BasicSheetException@OutOfRange";}
};

class BasicSheetBadDiskSave : public BasicSheetException
{
	public:
		char const* what()const noexcept { return "BasicSheetException@AccessToFileDenied";}
};

class BasicSheetOverflow : public BasicSheetException
{
	public:
		char const* what()const noexcept { return "BasicSheetException@BasicSheetOverflow";}
};


class TemplateSheetException : public std::exception
{
	public:
		char const* what()const noexcept { return "TemplateSheetException@"; }
};

class TemplateSheetOutOfRange : public TemplateSheetException
{
	public:
		char const* what()const noexcept { return "TemplateSheetException@OutOfRange"; }
};

class TemplateSheetOverflow : public TemplateSheetException
{
	public:
		char const* what()const noexcept { return "TemplateSheetException@Overflow:MaxSizeExceeded"; }
};

class TemplateSheetIncorrectMaxSize : public TemplateSheetException
{
	public:
		char const* what()const noexcept{ return "TemplateSheetException@DefMaxSizeInTemplateBelowZero";}
};

#endif

