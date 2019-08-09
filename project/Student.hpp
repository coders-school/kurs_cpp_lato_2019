#pragma once
#include <string>
class Student
{
protected:
    std::string name {};
    std::string surname {};
    std::string discordName {};

public:
    Student();
    Student (std::string nameVal, std::string surnameVal, std::string discordNameVal);
    Student (const Student &source);
    void viewUser() const;
    

    ~Student();

};

