#ifndef STUDENT
#define STUDENT
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Group {weekend=0, evening=1}; 

class Student
{
public:
	Student(string name, string nick, string lGit, string lFire, Group group);
	~Student();
	
	string name_;
	string nick_;
	string linkGit_;
	string linkFire_;
	Group group_;
	

};
#endif