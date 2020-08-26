/*
 * Account.h
 *
 *  Created on: Jul 28, 2020
 *      Author: Ryan
 *
 *  The header file containing private variables and functions for Account.cpp
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

using namespace std;

class Account {
public:
	Account(double t_startAmount, double t_monthlyDeposit,double t_interestRate,int t_years);
    void print();
    void printTableNoPayments();
    void printTablePayments();

private:
	int m_years = 0;
	double m_startAmount = 0;
	double m_monthlyDeposit = 0; //needed for printTablePayments only
	double m_interestRate = 0;
	double m_closingBalance = 0;
	double m_yearlyInterest = 0;
	double m_monthlyInterest = 0; //needed for printTablePayments only
};

#endif /* ACCOUNT_H */
