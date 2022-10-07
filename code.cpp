#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>


void showBalance(double balance, char currency);
double deposit();
double withdraw(double balance, char currency);
char currency = '$';

int main() {
	
	double balance = 0;
	int choice = 0;
	char currency = '!';


	do {
		std::cout << "********************" << std::endl;
		std::cout << "*Enter your choice!*" << std::endl;
		std::cout << "********************" << std::endl;

		std::cout << "" << std::endl; // Breaks up the choises from Enter Your Choice box.

		std::cout << "1. Show Balance" << std::endl;
		std::cout << "2. Deposit Money" << std::endl;
		std::cout << "3. Withdraw Money" << std::endl;
		std::cout << "4. Exit" << std::endl;

		//Inputs
		std::cin >> choice;

		std::cin.clear();
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
	std::cout << "Your Balance is: " << ::currency << std::setprecision(2) << std::fixed << balance << std::endl;
}

double deposit() {


	double amount = 0;

	std::cout << "Enter amount to be deposited: " << std::endl;

	std::cin >> amount;

	if (amount > 0) {
		return amount;
	}
	else {
		std::cout << "That's not a valid amount" << std::endl;
	}


	return 0;
}

double withdraw(double balance, char currency) {
	
	double amount = 0;
	
	std::cout << "Enter amount to be withdrawn from your account: " << std::endl;
	std::cin >> amount;
	

	if (amount > balance) {
		std::cout << "Insufficient Funds!" << std::endl;
		return 0;
	}
	else if (amount < 0) {
		std::cout << "That's not a valid amount" << std::endl;
		return 0;
	}
	else {
		return amount;
	}
}
