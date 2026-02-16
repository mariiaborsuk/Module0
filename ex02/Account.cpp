#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account ::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account ::getTotalAmount(void)
{
	return _totalAmount;
}
int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}
int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}
void Account::_displayTimestamp(void)
{
	time_t now = time(0);
	tm *ltm = localtime(&now);

	std::cout << "["
			  << 1900 + ltm->tm_year
			  << std::setfill('0') << std::setw(2) << ltm->tm_mon + 1
			  << std::setfill('0') << std::setw(2) << ltm->tm_mday
			  << "_"
			  << std::setfill('0') << std::setw(2) << ltm->tm_hour
			  << std::setfill('0') << std::setw(2) << ltm->tm_min
			  << std::setfill('0') << std::setw(2) << ltm->tm_sec
			  << "] ";
}
int Account::checkAmount(void) const
{
	return _amount;
}
void Account ::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}
void Account::makeDeposit(int deposit)
{
	int p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << p_amount
			  << ";deposit:" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits
			  << std::endl;
}
Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount=initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created" << std::endl;
}
void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;
}
bool Account::makeWithdrawal(int withdrawal)
{_displayTimestamp();
	int amount = checkAmount();
	if (withdrawal > amount)
	{

		std::cout << "index:" << _accountIndex << ";amount:" << amount << ";withdrawal:refused" << std::endl;
		return false;
	}
	else
	{
		_nbWithdrawals++;
		int p_amount = _amount;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << "index:" << _accountIndex
				  << ";p_amount:" << p_amount
				  << ";withdrawal:" << withdrawal
				  << ";amount:" << _amount
				  << ";nb_withdrawals:" << _nbWithdrawals
				  << std::endl;

		return true;
	}
}
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
	_nbAccounts--;
}
