#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Validation
{
public:
	static bool isValidName(string name) {
		if (name.length() >= 5 && name.length() <= 20)
		{
			for (auto i : name) {
				if (!((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))) {
					cout << "Error: name must be only alphabetic characters without spaces!!\n";
					return false;
				}
			}
			return true;
		}
		cout << " [Error] min size 5 and max size 20!!\n";
		return false;
	}

	static bool isValidPWD(string password) {
		if (password.length() >= 8 && password.length() <= 20)
		{
			for (auto i : password) {
				if (!((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9') || i == '_' || i == '#'))
					return false;
			}
			return true;
		}
		cout << " [Error] Min size 8 and Max size 20!!";
		return false;
	}

	static bool passwordState(string password) {
		int score = 0;
		int upper = 0, lower = 0, digit = 0, special = 0;

		for (auto i : password) {
			if (i >= 'A' && i <= 'Z') upper++;
			else if (i >= 'a' && i <= 'z') lower++;
			else if (i >= '0' && i <= '9') digit++;
			else if (i == '_' || i == '#') special++;
		}

		if (upper >= 1) score++;
		else cout << " [!] not enough upper char.\n";
		if (lower >= 2) score++;
		else cout << " [!] not enough lower char.\n";
		if (digit >= 2) score++;
		else cout << " [!] not enough digit.\n";
		if (special >= 1) score++;
		else cout << " [!] at least one special char (#,_).\n";

		if (score <= 2) {
			cout << " [*] Password State: Weak\n";
			return false;
		}
		else {
			cout << " [*]Password State: Strong\n";
			return true;
		}
	}

	static void checkPWD(string password){
		string pass = password;
		while (!Validation::isValidPWD(pass) || !Validation::passwordState(pass)) {
			//if (!Validation::isValidPWD(pass)) {
				cout << "\n [Error] Invalid password!\n";
				cout << " [~] Re-enter: ";
				cin >> password;
				cin.ignore();
				cout << endl;

			/*}
			else {
				if (!Validation::passwordState(pass)) {
					cout << "\n [Error] Invalid password!\n";
					cout << " [~] Re-enter: ";
					cin >> password;
					cin.ignore();
					cout << endl;

				}
			}*/
			
		}
	}

	static void checkSalary(double salary) {
		while (!Validation::isValidSalary(salary)) {
			cout << " [!] Error: Min Salary $5000!\n";
			cout << " [~] Re-enter Salary: ";
			cin >> salary;
		}
	}
	static void checkBalance(double balance) {
		while (!Validation::isValidBalance(balance)) {
			cout << " [!] Error: Min Balance $1500!\n";
			cout << " [~] Re-enter Balance: ";
			cin >> balance;
		}
	}

	static bool isValidBalance(double balance) {
		return(balance >= 1500);
	}

	static bool isValidSalary(double salary) {
		return(salary >= 5000);
	}

	static string encrypt(string password) {
		for (int i = 0; i < password.length(); i++)
			password[i]++;
		return password;
	}

	static string decrypt(string encryptedpwd) {
		for (int i = 0; i < encryptedpwd.length(); i++)
			encryptedpwd[i]--;
		return encryptedpwd;
	}
};

