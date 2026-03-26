#define _CRT_SECURE_NO_WARNINGS
#define NOMINMAX

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<ctime>
#include<Windows.h>

#include"ClientManager.h"
#include"AdminManager.h"
#include"BankManagerManager.h"


#include "Validation.h"
#include "Parser.h"  

#include "Person.h"
#include "Client.h"
#include"Employee.h"
#include "Admin.h"


#include "FilesHelper.h"
#include "DataSourceInterface.h"
#include "FileManager.h"

#include"Screens.h"

using namespace std;



int main() {
	
   
    
    /*if (AllAdmins.empty()) {
        Admin defaultAdmin(1001, "RewanElhassan", "Rewan123#", 9000);
        AllAdmins.push_back(defaultAdmin);
        FileManager::addAdmin(defaultAdmin);
    }
    if (AllEmployees.empty()) {
        Employee defaultEmployee(1002, "ZeinabAyman", "Zeinab123#", 9000);
        AllEmployees.push_back(defaultEmployee);
        FileManager::addEmployee(defaultEmployee);
    }
    if (AllClients.empty()) {
        Client defaultClient(1003, "WafaaAli", "Wafaa123#", 9000);
        AllClients.push_back(defaultClient);
        FileManager::addClient(defaultClient);
    }*/
    Screens::runApp(); 

    return 0;
    
}
