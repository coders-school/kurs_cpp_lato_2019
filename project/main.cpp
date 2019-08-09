#include <iostream>
#include <Coach.hpp>
#include <Student.hpp>


int main()
{
    Trainer trainer1;
    Trainer1.addUser("Wiktor","Lasota","Arakis14");
    Trainer1.addUser("Jan","Kowalski","kowal1234");
    Trainer1.addUser("Test","something ","anything");
    std::cout<<"=============================="<<std::endl;
    Trainer1.viewUsers();
    Trainer1.deleteUser(0);
    Trainer1.deleteUser(1);

    return 0;
}
