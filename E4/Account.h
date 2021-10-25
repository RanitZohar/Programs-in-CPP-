//Ranit Zohar ID  208569327
// שאלה 4
// סדנא ב C
//the program help to mennegment ATMS


#pragma once
#include <iostream>
using namespace std;
class Account
{

private:
	static int sumWithdraw;
	static int sumDeposit;
	int accountNumber;
	int code;
	int balance;


public:
	Account(int myAccountNumber = 0, int myCode = 0, int myBalance = 0);
	static int getSumWithdraw();
	static int getSumDeposit();
	void withdraw(int nis);
	void deposit(int);
	int getAccountNumber()const;
	int getCode()const;
	int getBalance()const;
	friend istream& operator >> (istream& is, Account& num);
};
