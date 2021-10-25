//Ranit Zohar ID  208569327
// שאלה 4
// סדנא ב C
//the program help to mennegment ATMS




#include "Account.h"
int Account::sumWithdraw = 0;
int Account::sumDeposit = 0;



Account::Account(int myAccountNumber, int myCode, int myBalance)
{
	accountNumber = myAccountNumber;
	code = myCode;
	balance = myBalance;
}

int Account::getSumWithdraw()
{
	return sumWithdraw;
}
int Account::getSumDeposit()
{
	return sumDeposit;
}
void Account::withdraw(int nis)
{
	if ((balance - nis) < -6000)
		throw "ERROR: cannot have less than - 6000 NIS!\n";
	if (nis > 2500)
		throw "ERROR: cannot withdraw more than 2500 NIS!\n";
	balance -= nis;
	sumWithdraw += nis;
}
void Account::deposit(int check)
{
	if (check > 10000)
		throw "ERROR: cannot deposit more than 10000 NIS!\n";
	balance += check;
	sumDeposit += check;
}
int Account::getAccountNumber()const
{
	return accountNumber;
}
int Account::getCode()const
{
	return code;
}
int Account::getBalance()const
{
	return balance;
}
istream& operator >> (istream& is, Account& num)
{
	is >> num.accountNumber;
	is >> num.code;
	return is;
}
