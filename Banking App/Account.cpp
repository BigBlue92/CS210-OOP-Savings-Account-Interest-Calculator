/*
 * Account.cpp
 *
 *  Created on: Jul 28, 2020
 *      Author: Ryan
 *
 *
 */
#include <iostream> //input and output
#include <string> //for Strings
#include <cmath> //Exponents
#include <stdexcept>//for error handling
#include "Account.h"
using namespace std;

//Constructor used in main, also include error handling with specific messages.
Account::Account(double t_startAmount, double t_monthlyDeposit,double t_interestRate,int t_years) {

	if (t_startAmount < 0 || !cin) {
        throw runtime_error("Invalid Initial Investment.");
	}
	m_startAmount = t_startAmount;

	if (t_interestRate < 0 || !cin) {
	    throw runtime_error("Invalid interest rate.");
	}
	m_interestRate = t_interestRate;

	if (t_monthlyDeposit < 0 || !cin) {
		throw runtime_error("Invalid Monthly deposit.");
	}
	m_monthlyDeposit = t_monthlyDeposit;

	if (t_years < 0 || !cin) {
	    throw runtime_error("Invalid Number of Years.");
	}
	m_years = t_years;
}

//Presents the user with a nicely formatted display that shows what they entered.
void Account::print() {
	cout << "**********************************" << endl
		 << "********** Data Input ************" << endl
	     << "Initial Investment Amount: $" << m_startAmount<< endl
	     << "Monthly Deposit: $";
	printf("%.2f", m_monthlyDeposit);
	cout << endl << "Annual Interest: %";
	printf("%.2f", m_interestRate);
	cout << endl << "Number of Years:" << m_years << endl;
}

//Prints the table that shows values without monthly payments.
void Account::printTableNoPayments() {
	cout << "     Balance and Interest Without Additional Monthly Deposits     "
	     << endl << "=========================================================="
	     << "=======" << endl << "   Year         Year End Balance     Year End"
		 << " Earned Interest    " << endl << "--------------------------------"
		 << "---------------------------------" << endl;
	//Below each line of the table is calculated.
	m_closingBalance = m_startAmount;
	for (int i = 1; i <= m_years; i++) {
		m_yearlyInterest = (m_closingBalance * pow(1 + (m_interestRate/100/12),
				12)) - m_closingBalance;

		m_closingBalance += m_yearlyInterest;
		//Formats and prints each line of the table so the columns align.
		printf("%2s %-12d %s %-18.2f %s %-6.2f \n", "", i, "$",
				m_closingBalance, "$", m_yearlyInterest);
	}
}

//Prints the table that shows values with monthly payments.
	void Account::printTablePayments() {
	cout << endl << "      Balance and Interest With Additional Monthly Deposits"
	<< endl << "========================================================"
	<< "=========" << endl << "   Year         Year End Balance     Year End"
	<< " Earned Interest    " << endl << "--------------------------------"
	<< "---------------------------------" << endl;

	//Below each month is calculated individually.
	m_closingBalance = m_startAmount;
	for (int i = 1; i <= m_years * 12; i++) {
		m_closingBalance  += m_monthlyDeposit;
		m_monthlyInterest = (m_closingBalance * (m_interestRate/100)/12);
		m_yearlyInterest += m_monthlyInterest;
		m_closingBalance += m_monthlyInterest;

		//Once 12 months are calculated, the result is formatted and printed.
		if (i % 12 == 0) {
			printf("%2s %-12d %s %-18.2f %s %-6.2f \n", "", i / 12, "$",
	    		m_closingBalance, "$", m_yearlyInterest);
			m_yearlyInterest = 0;
		}
	}
}

