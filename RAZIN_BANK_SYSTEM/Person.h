#pragma once
#include"Validation.h"

class Person
{
protected:
	string name, password;
	int id;
public:
	static int idCounter;

	Person() {
		idCounter++;
		id = idCounter;
	}

	Person(int id, string name, string password) {
		this->id = id;
		setName(name);
		setPassword(password);
	}

	Person(int id, string password) {
		this->id = id;
		this->password = password;
	}

	void setId(int id) {
		this->id = id;
	}

	void setName(string name) {
		while (!Validation::isValidName(name)) {
			cout << "\n [Error] invalid name!\n";
			cout << "\n [~] Re-enter: ";
			cin >> name;
			cin.ignore();
		}
		this->name = name;
	}

	void setPassword(string password) {
		string pass = password;
		while (!Validation::isValidPWD(pass) || !Validation::passwordState(pass)) {
			cout << "\n [Error] Invalid password!\n";
			cout << " [~] Re-enter: ";
			cin >> password;
			cin.ignore();
			cout << endl;
		}
		this->password = pass;
	}

	int getId() {
		return this->id;
	}

	string getName() {
		return this->name;
	}

	string getPassword() {
		return password;
	}

	virtual void display() {
		cout << "\tID: " << this->id;
		cout << "\n\tName: " << this->name;
		cout << "\n\tPassword: " << this->password;
	}

};



