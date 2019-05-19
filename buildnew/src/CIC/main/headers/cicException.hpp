#ifndef CICLIB_CICEXCEPTION_HPP

#define CICLIB_CICEXCEPTION_HPP

#include <exception>

class ViewException : public std::exception
{
	public:
		char const* what() const noexcept { return "ViewException@" ; }

};

class LayoutException : public ViewException
{
	public: 
		char const* what()const noexcept { return "ViewException@LayoutException@" ; }
};

class InvalideXml : public LayoutException
{
	public:
		char const* what()const noexcept { return "ViewException@LayoutException@InvalidXml@" ;}
};

class InvalideSize : public InvalideXml 
{
	public:
		char const* what()const noexcept { return "ViewException@LayoutException@InvalidXml@InvalidSize" ; }
};

class SizeNotFound : public InvalideXml 
{
	
	public:
		char const* what() const noexcept { return "ViewException@LayoutException@InvalidXml@SizeForElemNotFoundInXml" ;}
};

class InvalideId : InvalideXml
{
	public:
		char const* what() const noexcept { return "ViewException@LayoutException@InvalidXml@NoElemWithSuchId" ;}
};

class RecycleViewException : public ViewException 
{
	public:
		char const* what() const noexcept { return "ViewException@RecycleViewException@" ; }
};

class OutOfRange : public RecycleViewException
{
	public:
		char const* what() const noexcept { return "ViewException@RecycleViewException@OutOfRangeForShowenElems" ; }
};

class FileIsNotOpen : public RecycleViewException
{
	public:
		char const* what() const noexcept { return "ViewException@RecycleViewException@FileIsNotOpen" ; }

};

#endif
