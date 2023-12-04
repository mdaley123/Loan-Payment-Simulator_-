 //Program: The purpose of this program is to calculate omnthly loan payments
// Process: Obtain input from user: loan type, length of loan, aount of loan
// and compute monthly payent.
// Results: Display details of the loan along with the calculated payent,
// total paid over the life of the loan, and total interest paid.
//
// Class: CS2010
// Section: 1001
// Ter: Fall 2023
// Author: Maya Daley
//
// Reflection: This project went better than my last one yet I still think I did bad. 
//At least this time around I was confident enough to turn something in but I am optimistic for the
// third project. Hopefully I continue to do better and become better at coding, but right now all I see 
// is that there is big room for improvement. 
#include <iostream>
using namespace std;
#include <cmath>
#include <iomanip>

// Constants for interest rates
const double HOME_30_RATE = 7.21;
const double HOME_15_RATE = 5.51;
const double AUTO_RATE = 3.50;
const double PERSONAL_RATE = 8.75;

int main() {
    // Input variables
    string loanType;
    double loanAmount;
    int numPayments;

    // Prompts for user input
    cout << "Enter the loan amount: $";
    cin >> loanAmount;
    cout << "Enter the type of loan (Home, Auto, Personal): ";
    cin >> loanType;
    cout << "Enter the number of payments: ";
    cin >> numPayments;

    // Calculate interest rate based on loan type
    double interestRate;
    if (loanType == "Home") {
        if (numPayments == 30) {
            interestRate = HOME_30_RATE;
        } else if (numPayments == 15) {
            interestRate = HOME_15_RATE;
        } else {
            cout << "Invalid number of payments for Home loan." << endl;
        }
    } else if (loanType == "Auto") {
        interestRate = AUTO_RATE;
    } else if (loanType == "Personal") {
        interestRate = PERSONAL_RATE;
    } else {
        cout << "Invalid loan type." << endl;
    }

    // Calculate monthly payment
    double monthlyInterestRate = interestRate / 1200.0;
    double monthlyPayment = (loanAmount * monthlyInterestRate) /
             (1.0 -pow(1.0 + monthlyInterestRate, -numPayments));

    // Calculate total payent and interest paid
    double totalPayment = monthlyPayment * numPayments;
    double interestPaid = totalPayment - loanAmount;

    // Display the loan report
    cout << fixed << setprecision(2);
    cout << "---- Loan Report for " << loanType << " Loan ----" << endl; //set fill and set width
    cout << "Loan Amount: $ " << loanAmount << endl;
    cout << "Annual Interest Rate: % " << interestRate << endl;
    cout << "Number of Payments: " << numPayments << endl;
    cout << "Monthly Payment: $ " << monthlyPayment << endl;
    cout << "Total Payment: $ " << totalPayment << endl;
    cout << "Interest Paid: $ " << interestPaid << endl;

    return 0;
}


