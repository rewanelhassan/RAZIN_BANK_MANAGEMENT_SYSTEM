#pragma once
#include"Person.h"
#include"Client.h"
class Employee :public Person
{
protected:
	double salary;
public:

	Employee() {
		this->salary = 0.0;
	}

	Employee(int id, string name, string password, double salary) :Person(id, name, password) {
		setSalary(salary);
	}

	Employee(int id, string password) :Person(id, password) {
		this->salary = 0.0;
	}

	void setSalary(double salary) {

		while (!Validation::isValidSalary(salary)) {
			cout << "Error: Min Salary $5000!\n";
			cout << "Re-enter Salary: ";
			cin >> salary;
		}
		this->salary = salary;
		//cout << "\nSalary set successfully: $" << this->salary << endl;

		/*if (Validation::isValidSalary(salary)) {
			this->salary = salary;
			cout << "Salary set successfully: $" << this->salary << endl;
		}
		else
		{
			cout << "Error: Min Salary $5000!\n";
			cout << "Re-enter Salary: ";
			cin >> salary;
			cout << "Salary set successfully: $" << this->salary << endl;
		}*/
	}

	double getSalary() {
		return this->salary;
	}

	void editStatus(Client& c, bool newstate) {
		c.setStatus(newstate);
		cout << "\n [^-^] Client status updated successfully to " << (newstate ? "Active" : "Frozen") << endl;
	}

	void display() {
		Person::display();
		cout << "\n\tSalary: $" << this->salary << endl;
	}

 
};

static vector<Employee> AllEmployees;

