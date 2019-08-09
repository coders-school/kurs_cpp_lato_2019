#ifndef DATABASE
#define DATABASE
#include <iostream>
#include <vector>
#include "Student.hpp"

using namespace std;

class Database
{
public:
	Database ();
	~Database ();
	//Student student_;
	vector<Student> students;
	
	void addStudent(Student);
	void removeStudent(string);
};
#endif