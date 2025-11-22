#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


// This function displays the current timestamp in the format [YYYYMMDD_HHMMSS].
void	Account::_displayTimestamp(void) 
{
	time_t		now;
	struct tm	*ts;
	char		buf[80];

	now = time(NULL);
	ts = localtime(&now);
	strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", ts);
	std::cout << buf;
}

// Constructor: Initializes an account with an initial deposit, assigns an account index, and updates the total accounts and amount.
Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), 
	_nbDeposits(0), _nbWithdrawals(0) 
{

	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
	this->_nbAccounts++;
	this->_totalAmount += this->_amount;
}

// Destructor: Displays account closure information and updates the total accounts.
Account::~Account() 
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;
}

// Displays information about all accounts, including total accounts, total amount, deposits, and withdrawals.
void	Account::displayAccountsInfos() 
{
	Account::_displayTimestamp();//using account class scope is redundant but explicit
	std::cout << "accounts:" << Account::_nbAccounts;
	std::cout << ";total:" << Account::_totalAmount;
	std::cout << ";deposits:" << Account::_totalNbDeposits;
	std::cout << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

// Displays the status of the current account, including its index, amount, deposits, and withdrawals.
void	Account::displayStatus() const 
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

// Adds a deposit to the account, updates the deposit count, and displays the updated account information.
void	Account::makeDeposit(int deposit) 
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	this->_nbDeposits++;
	this->_amount += deposit;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout <<  ";nb_deposits:" << this->_nbDeposits << std::endl;
	_totalNbDeposits++;
}

// Attempts to withdraw an amount from the account. If the withdrawal amount exceeds the current balance, the withdrawal is refused.
// Updates the withdrawal count and displays the updated account information if successful.
bool	Account::makeWithdrawal(int withdrawal) 
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (withdrawal > this->_amount) {
		std::cout << ";withdrawal:refused" << std::endl; 
		return (0);
	}
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << this->_amount;
	std::cout <<  ";nb_withdrawal:" << this->_nbWithdrawals << std::endl;
	_totalNbWithdrawals++;
	return (1);
}


/////added values getters (statitic memenbers)/////
// Returns the total number of accounts.
int	Account::getNbAccounts(void) {
	return Account::_nbAccounts;
}

// Returns the total amount across all accounts.
int	Account::getTotalAmount(void) {
	return Account::_totalAmount;
}

// Returns the total number of deposits across all accounts.
int	Account::getNbDeposits(void) {
	return Account::_totalNbDeposits;
}

// Returns the total number of withdrawals across all accounts.
int	Account::getNbWithdrawals(void) {
	return Account::_totalNbWithdrawals;
}

// Returns the current amount in the account.
int	Account::checkAmount(void) const {
	return this->_amount;
}