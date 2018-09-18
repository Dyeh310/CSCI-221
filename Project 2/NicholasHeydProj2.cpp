/* Do Programming Project 2 on page 611. You may watch the video note for 
 * Programming Project 1 on page 611 to get some idea. Then try to finish
 * independently by complete this sample file.
 * 
 * Author: Nicholas Heyd
 * Version: 1.0 / Septemeber 3, 2018 - September 5, 2018
 */

#include <iostream>
using namespace std;

class CDAccount
{
public:
    CDAccount();
    CDAccount(double new_balance, double new_interest_rate, int new_term);
    double get_initial_balance() const;
    double get_balance_at_maturity() const;
    double get_interest_rate() const;
    int get_term() const;
    void input(istream& in);
    void output(ostream& out);
    
private:
    int dollar;
    int cent;
    double interest_rate;
    int term; // months until maturity
};

int main()
{
	//Created Object of the CDAccount class
	CDAccount account;
	//accept the user input
	account.input(cin);
	//print output
	account.output(cout);

}

//Empty constructor
CDAccount::CDAccount(){}

CDAccount::CDAccount(double new_balance, double new_interest_rate, int new_term)
{
	dollar = (int)new_balance;
	cent = (int)((new_balance - dollar)*100);
	interest_rate = new_interest_rate/100;
	term = new_term;
}

double CDAccount::get_initial_balance() const
{
	return (double)((double)dollar + (double)((double)cent/100.0));
}

double CDAccount::get_balance_at_maturity() const
{
	double total = dollar + (cent/100);
	return get_initial_balance() + total * interest_rate * term;
}

double CDAccount::get_interest_rate() const
{
	return interest_rate;
}

int CDAccount::get_term() const
{
	return term;
}

void CDAccount::output (ostream& out)
{
	//This acts as the user interface
	out << "Balance: " << get_initial_balance() << endl;
	out << "Interest Rate: " << get_interest_rate() << endl;
	out << "Term: " << get_term() << endl;
	out << "Balance once reached maturity: " << get_balance_at_maturity() << endl;
}

void CDAccount::input(istream& in)
{
    double balance;
	cout << "Please enter the balance: " << endl;
    in >> balance; // get initial balance from user
    
    // convert balance to dollars and cents since this is how balance stored
    dollar = (int) balance; // dollar is the interger part of balace
    cent = (int) ((balance - dollar)*100); // cent is the fraction part * 100
    
	cout << "Please enter the interest rate: " << endl;
    in >> interest_rate; // get interest rate from user
	interest_rate = interest_rate / 100;
	cout << "Please enter a term: " << endl;
    in >> term; // get term from user
}
