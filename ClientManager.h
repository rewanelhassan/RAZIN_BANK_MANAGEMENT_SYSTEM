#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Client.h"
#include"FilesHelper.h"
#include<ctime>

#define new_page system("cls")
#define time_op  {time_t timestamp; time(&timestamp); cout<<"\n------------\n"<<ctime(&timestamp)<<"\n";}

class ClientManager
{
	static void printClientMenu() {
		new_page;
		cout << "------------------------------------\n";
		cout << "          Client Main Menu          \n";
		cout << "------------------------------------\n";
		cout << "\n [1] WithDraw\n";
		cout << "\n [2] Deposit\n";
		cout << "\n [3] Check Balance\n";
		cout << "\n [4] Display My Info\n";
		cout << "\n [5] Update Passward\n";
		cout << "\n [6] Logout\n";
		cout << "\n [?] Pleace enter a choice (1-6) : ";
	}
	static void updatePassword(Person* person) {
		cout << "---------------------------------\n";
		cout << "          UPDATE PASSWARD        \n";
		cout << "---------------------------------\n";
		string newpass;
		new_page;
		cout << " Enter New Password: ";
		cin >> newpass;
		Validation::checkPWD(newpass);
		person->setPassword(newpass);
		FilesHelper::updateClientsFile();
		cout << "\n [^-^] Password Updated Successfully\n";
		cout << "\n\n\n\n";
		system("pause");

	}
public:
	

	static Client* login(int id, string password) {
		for (int i = 0; i < AllClients.size(); i++) {
			if (AllClients[i].getId() == id && AllClients[i].getPassword() == password) {
				cout << "[*] Login successful! Welcome, " << AllClients[i].getName();
				return &AllClients[i];
			}
		}
		return nullptr;
	}


	static void withdrawOperation(Client* client) {
		new_page;
		double amount;
		cout << "-------------------------------------\n";
		cout << "         WITHDRAW OPERATION          \n";
		cout << "-------------------------------------\n";
		cout << "\n [~] Please enter amount to withdraw: ";
		cin >> amount;
		client->withdraw(amount);
		time_op;
		cout << "\n\n\n\n";
		system("pause");

	}
	static void depositOperation(Client* client) {
		new_page;
		double amount;
		cout << "-------------------------------------\n";
		cout << "         DEPOSIT OPERATION          \n";
		cout << "-------------------------------------\n";
		cout << "\n [~] Please enter amount to deposit: ";
		cin >> amount;
		client->deposit(amount);
		time_op;
		cout << "\n\n\n\n";
		system("pause");
	}
	static void checkBalance(Client* client) {
		new_page;
		cout << "---------------------------------\n";
		cout << "         CHECK BALANCE           \n";
		cout << "---------------------------------\n";
		cout << "\n [~] Your Current Balance:$ " << client->getBalance();
		cout << "\n\n\n\n";
		system("pause");
	}
	static void clientInfo(Client* client) {
		new_page;
		cout << "-----------------------------\n";
		cout << "         CLIENT INFO         \n";
		cout << "-----------------------------\n";
		client->display();
		cout << "\n\n\n\n";
		system("pause");
	}


	static bool clientOptions(Client* client) {
		printClientMenu();

		int choice;
		double amount;

		cin >> choice;
		switch(choice){
		case 1:
			withdrawOperation(client);
			break;
		case 2:
			depositOperation(client);
			break;
			
		case 3:
			checkBalance( client);
			break;
		case 4:
			clientInfo(client);
			break;
		case 5:
			updatePassword(client);
			FilesHelper::updateClientsFile();
			break;
		case 6:
			new_page;
			cout << "\n [*] Thanks " << client->getName() << " for your time ,Goodbye (*^_^*)\n\n\n";
			system("pause");
			return false;
			break;
		default:
			cout << "\n [!] Invalid Choice !!";
		}
		return true;
	}
};

