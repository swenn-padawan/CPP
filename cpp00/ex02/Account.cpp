#include "Account.hpp"
#include <iostream>


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::makeDeposit( int deposit )
{
	Account::_totalAmount += deposit;	
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > getTotalAmount())
		return (false);
	Account::_totalAmount -= withdrawal;
	return (true);
}

Account::Account(int initialDeposit)
{
	static int	index = 0;
	Account::_totalAmount = initialDeposit;
	Account::_nbAccounts = index++;
	std::cout << "index:" << this->getNbAccounts() << "Amount:" << this->getTotalAmount() << ";" << "created" << std::endl;
}

Account::~Account(void){
	std::cout << "index:" << this->getNbAccounts() << "Amount:" << this->getTotalAmount() << ";" << "closed" << std::endl;
}

int	Account::checkAmount(void) const
{
	return (this->getTotalAmount());
}

void	Account::displayStatus(void) const
{
	std::cout << "Created" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	std::cout << "Nb Account = " << getNbAccounts() << std::endl;
	std::cout << "Total Amount = " << getTotalAmount() << std::endl;
	std::cout << "Nb Deposit = " << getNbDeposits() << std::endl;
	std::cout << "Nb Withdrawals = " << getNbWithdrawals() << std::endl;
}
