#pragma once  
#include<exception>  
#include<string>  

class ExpectionClass : public std::exception {  
public:  
    ExpectionClass(int line, const char* file) noexcept;  
    const char* what() const noexcept override; // Changed return type to match std::exception::what  
    virtual const char* GetType() const noexcept;  
    int GetLine() const noexcept;  
    const std::string& GetFile() const noexcept;  
    std::string GetOriginString() const noexcept;  
private:  
    int line;  
    std::string file;  
protected:  
    mutable std::string whatBuffer; // Changed to std::string to align with char* return type  
};