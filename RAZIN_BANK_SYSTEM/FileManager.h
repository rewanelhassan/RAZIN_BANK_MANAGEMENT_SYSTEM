#pragma once
#include<sstream>
#include"DataSourceInterface.h"
#include"FilesHelper.h"

class FileManager : public DataSourceInterface
{
public:
	void addClient(Client c) {
		FilesHelper::saveClient(c);
	}
	void addEmployee(Employee e) {
		FilesHelper::saveEmployee("Employee.txt", "lastIdEmployee.txt", e);
	}
	void addAdmin(Admin a) {
		FilesHelper::saveAdmin(a);
	}

	void getAllClients() {
		FilesHelper::getClients();
	}
	void getAllEmployees() {
		FilesHelper::getEmployees();
	}
	void getAllAdmins() {
		FilesHelper::getAdmins();
	}

	void removeAllClients() {
		FilesHelper::clearFile("Clients.txt", "lastIdClient.txt");
	}
	void removeAllEmployees() {
		FilesHelper::clearFile("Employee.txt", "lastIdEmployee.txt");
	}
	void removeAllAdmins() {
		FilesHelper::clearFile("Admin.txt", "lastIdAdmin.txt");
	}

};
