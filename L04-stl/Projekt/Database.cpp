#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Database.hpp"

using namespace std;

Database::Database (){}
Database::~Database (){}

void Database::addStudent(Student stu)
	{
		students.emplace_back(stu);
	}
	
void Database::removeStudent(string name)
{
	auto result = find_if(begin(students), end(students), [name](auto it){return it.name_==name;});
	if(result != end(students))
	{
		students.erase(result);
	}
	
}