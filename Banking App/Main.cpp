/**CS-210-T6594 Programming Languages 20EW6
 * Project Two: Airgead Banking Savings Account
 *
 * Bank.cpp
 *
 *  Created on: Jul 28, 2020
 *  Author: Ryan
 *
 *  v1.1: Added error handling for negative input.
 *  v1.2: Was able to remove 9 lines of code from the main by consolidating
 *  setters into the Account constructor. Changed the wording to quit the
 *  while loop to eliminate the need for any error handling.
 *  v1.3: Added a try catch for the then end of the program to ensure
 *  the user enters y or n. Added some validation to ensure the user doesn't
 *  input a letter instead of an integer.
 *
 */
#include <iostream>
#include <stdexcept>
#include <limits>
#include "Account.h"
using namespace std;

int main() {
	//Variables for temporarily storing user input to pass to account.
	char quit = 'y';
	int years;
	double startAmount, monthlyDeposit, interestRate;

	//While loop allows user to continue to try new values.
	while (quit != 'n' && quit != 'N') {
		cout << "**********************************" << endl;
		cout << "********** Data Input ************" << endl;
		cout << "Initial Investment Amount:" ;

		/*Try catch block will prevent the program from running into an error
		 * if the user enters the wrong input at the wrong time.
		 * It will ask the user if they want to try again or quit.*/
		try {
			cin >> startAmount;
			cout << "Monthly Deposit:";
			cin >> monthlyDeposit;
			cout << "Annual Interest:";
			cin >> interestRate;
			cout << "Number of Years:";
			cin >> years;

			//Creates account with no monthly deposit and prints table.
			Account noDepositAccount(startAmount, monthlyDeposit, interestRate, years);
			noDepositAccount.print();
			system("pause");//Press a key to continue...
			noDepositAccount.printTableNoPayments();

			//Creates an account with Monthly deposits and prints table.
			Account depositAccount(startAmount, monthlyDeposit, interestRate, years);
			depositAccount.printTablePayments();
		}
	    // Prints the error message passed by throw statement inside Account.
		catch (runtime_error &excpt){
			cout << excpt.what() << endl;
			cout << "Cannot compute account info.";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		//Allows the user to try to enter new values if they like, validates input.
		do {
			try {
				cout << endl << "Enter new values? Enter (y/n).";
				cin >> quit;
				if (quit != 'y' && quit != 'n' && quit != 'Y' && quit != 'N') {
					throw runtime_error("Invalid input. ");
				}
			}
			catch (runtime_error &excpt2) {
				cout << excpt2.what();
				cout << "Please enter y or n.";
			}
		} while (quit != 'y' && quit != 'Y' && quit != 'n' && quit != 'N');
	}
	return 0;
}
