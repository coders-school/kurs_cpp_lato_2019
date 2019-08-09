#include "Student.hpp"
#include <iostream>
#include <vector>
#include <string>

Student::Student(string name, string nick, string lGit, string lFire, Group group)
	   : name_(name),
  		 nick_(nick),
  		 linkGit_(lGit),
		 linkFire_(lFire),
		 group_(group)
	{}		
	
Student::~Student(){}	

