#include "Student.hpp"
#include <iostream>

Student::Student()
        :Student {"name","",""}{
        }
Student::Student(std::string nameVal, std::string surnameVal, std::string discordNameVal)
        :name{nameVal},    surname{surnameVal},    discordName{discordNameVal} 
        {
        }        
Student::Student(const Student &source)
      :name{source.name},    surname{source.surname},    discordName{source.discordName}
    {
    }
Student::~Student()
{
}
void Student::viewUser() const 
{
    std::cout<<name << ", " << surname << ", " <<discordName <<std::endl;
}


