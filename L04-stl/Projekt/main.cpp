#include <iostream>
#include <vector>
#include "Student.hpp"
#include "Database.hpp"

using namespace std;


void show(const vector<Student> & s)
{
	for(auto a : s)
	{
		cout<<a.name_<<endl;
		cout<<a.nick_<<endl;
		cout<<a.linkGit_<<endl;
		cout<<a.linkFire_<<endl;
		//cout<<a.group_<<endl;
	}
}

int main()
{
	Database db;
	Student s("Michal", "Mike", "michu@gmail.com", "michu.firecode.io", Group::weekend);
	db.addStudent(s);
	Student z("Andrzej", "Endrju", "and@gmail.com", "and.firecode.io", Group::weekend);
	db.addStudent(z);
	
	show(db.students);	
	cout<<"Rozmiar vectora: "<<db.students.size()<<endl;
	db.removeStudent("Michal");
	show(db.students);	
	cout<<"Rozmiar vectora: "<<db.students.size()<<endl;
return 0;
}
