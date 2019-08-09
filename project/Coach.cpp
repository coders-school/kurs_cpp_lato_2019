#include "Coach.hpp"
#include <iostream>
#include <string>


Trainer::Trainer()
{
}
Trainer::~Trainer()
{
}
void Trainer::addUser(std::string name, std::string surname, std::string discordName)
{
    Student temp {name,surname,discordName};
    trainer.emplace_back(temp);
}

void Trainer::viewUsers() const 
{
    for (const auto &student: trainer)
        student.viewUser();
}
void Trainer::deleteUser(int userNumber)
{
    trainer.erase(trainer.begin()+userNumber);
}
//void Trainer::editUser(int userNumber,std::string name, std::string surname, std::string discordName)
//{
//    std::string temp {name,surname,discordName};
//    trainer.swap(temp.begin()+userNumber);
//}




