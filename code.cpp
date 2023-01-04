#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

void showBalance(double balance, char currency);
double deposit();
double withdraw(double balance, char currency);
char currency = '$';

int main() {
	
	double balance = 0;
	int choice = 0;


	do {
		cout << "********************" << endl;
		cout << "*Enter your choice!*" << endl;
	 cout << "********************" << endl;

		cout << "" << endl; // Breaks up the choises from Enter Your Choice box.

		cout << "1. Show Balance" << endl;
		cout << "2. Deposit Money" << endl;
		cout << "3. Withdraw Money" << endl;
		cout << "4. Exit" << endl;

		//Inputs
		cin >> choice;

		cin.clear();
		fflush(stdin);

		switch (choice) {
			case 1: showBalance(balance, currency);
				break;
			case 2: balance = balance += deposit();
				showBalance(balance, currency);
				break;
			case 3: balance -= withdraw(balance, currency);
				showBalance(balance, currency);
				break;
			case 4: std::cout << "Thanks for visiting!" << std::endl;
				break;
			default: std::cout << "Invalid Choice!" << std::endl;
		}
	}while(choice != 4);

	return 0;
}

void showBalance(double balance, char currency) {
	cout << "Your Balance is: " << ::currency << setprecision(2) << fixed << balance << endl;
}

double deposit() {


	double amount = 0;

	cout << "Enter amount to be deposited: " << endl;

	cin >> amount;

	if (amount > 0) {
		return amount;
	}
	else {
		cout << "That's not a valid amount" << endl;
	}


	return 0;
}

double withdraw(double balance, char currency) {
	
	double amount = 0;
	
	cout << "Enter amount to be withdrawn from your account: " << endl;
	cin >> amount;
	

	if (amount > balance) {
		cout << "Insufficient Funds!" << endl;
		return 0;
	}
	else if (amount < 0) {
		cout << "That's not a valid amount" << endl;
		return 0;
	}
	else {
		return amount;
	}
}
