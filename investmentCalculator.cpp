// Project Two: Airgead Banking Project
// Ava Lindgren - 10/05/2025

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// function to calculate and display the year-end balances and earned interest 
void calculateInvestment(double initialInvestment, double monthlyDeposit, double annualInterest, int numberOfYears, bool withDeposits) {
	// initialize variables and their proper calculations
	double openingAmount = initialInvestment;
	double totalInterest = 0.0;
	double monthlyInterestRate = (annualInterest / 100) / 12;
	int numberOfMonths = numberOfYears * 12;

	// display the two different reports' headers 
	cout << (withDeposits ? "\nWith Monthly Deposits" : "\nWithout Monthly Deposits") << endl;
	cout << "============================================================================" << endl;
	cout << setw(5) << "Year" << setw(35) << "Year End Balance ($)" << setw(35) << "Year End Earned Interest ($)" << endl;
	cout << "----------------------------------------------------------------------------" << endl;

	// for loop
	for (int year = 1; year <= numberOfYears; ++year) {
		double yearEndInterest = 0.0;

		// for loop for calculating the proper amounts based on the user input
		for (int month = 1; month <= 12; ++month) {
			double depositedAmount = withDeposits ? monthlyDeposit : 0.0;
			double total = openingAmount + depositedAmount;
			double interest = total * monthlyInterestRate;
			double closingBalance = total + interest;
			yearEndInterest += interest;
			openingAmount = closingBalance;
		}

		totalInterest += yearEndInterest;

		// included set width and precision to display the output correctly and clearly
		cout << setw(5) << year << fixed << setprecision(2) << setw(35) << openingAmount << setw(35) << yearEndInterest << endl;
	}

	cout << "============================================================================" << endl;
	// display the total amount of interest earned
	cout << "Total Interest Earned: $" << totalInterest << endl;
	// display the total balance of the account
	cout << "Total Balance: $" << openingAmount << endl << endl;
}

int main() {
	double initialInvestment, monthlyDeposit, annualInterest;
	int numberOfYears;
	// get user input for the initial investment, monthly deposit, annual interest, and number of years
	cout << "************* Data Input *************" << endl;
	cout << "\nInitial Investment Amount: $";
	cin >> initialInvestment;
	cout << "Monthly Deposit: $";
	cin >> monthlyDeposit;
	cout << "Annual Interest: %";
	cin >> annualInterest;
	cout << "Number of Years: ";
	cin >> numberOfYears;
	cout << endl;
	cout << "**************************************" << endl << endl;

	// display both of the reports by calling the functions
	calculateInvestment(initialInvestment, monthlyDeposit, annualInterest, numberOfYears, false);
	calculateInvestment(initialInvestment, monthlyDeposit, annualInterest, numberOfYears, true);

	// end the program
	return 0;

}
