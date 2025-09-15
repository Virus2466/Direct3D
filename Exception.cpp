#include "Exception.h"
#include<sstream>


ExpectionClass::ExpectionClass(int line , const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* ExpectionClass::what() const noexcept  
{  
    std::ostringstream oss;  
    oss << GetType() << std::endl  
        << GetOriginString();  
    whatBuffer = oss.str();  
    return whatBuffer.c_str();  
}

const char* ExpectionClass::GetType() const noexcept
{
	return "Exception Clas";
}

int ExpectionClass::GetLine() const noexcept
{
	return line;
}

const std::string& ExpectionClass::GetFile() const noexcept
{
	return file;
}

std::string ExpectionClass::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}
