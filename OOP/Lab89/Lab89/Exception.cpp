#include "Exception.h"



Exception::Exception(const std::string &message) :
	message{ message }
{
}

std::string Exception::get_message()
{
	return this->message;
}

Exception::~Exception()
{
}
