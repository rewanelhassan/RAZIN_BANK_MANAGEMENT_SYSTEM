#pragma once
#include"Employee.h"
class Admin :public Employee
{
public:

	Admin() {
	}
	Admin(int id, string password) :Employee(id, password) {
	}
	Admin(int id, string name, string password, double salary) :Employee(id, name, password, salary) {
	}
	void display() {
		Employee::display();
	}


};

static vector<Admin> AllAdmins;

