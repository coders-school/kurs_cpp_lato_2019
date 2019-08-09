#pragma once
#include "Student.hpp"
#include <vector>
#include <string>

class Trainer 
{
private:
std::vector<Student>trainer; 
public:
    Trainer();
    ~Trainer();
    void addUser(std::string name, std::string surname, std::string discordName);
    void viewUsers() const;
    void deleteUser(int userNumber);
    void editUser(int userNumber,std::string name, std::string surname, std::string discordName);

    

};

