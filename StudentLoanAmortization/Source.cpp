#include <iostream>
#include <cstdlib>
#include <math.h>
#include <iomanip>
using std::cin; using std::cout; using std::string;

int main() {
	double principal;
	double interestRate;
	double monRate;
	int term, monthsTotal;
	double rateinput;
	double discountFactor;
	double monthlyPayment;

	cout << "What is the loan amount?" << "\n";
	cin >> principal; cout << "\n";

	cout << "What is the interest rate?(Type -1 to just use average rate.)" << "\n";
	cin >> rateinput; cout << "\n";

	if (rateinput <= 0) interestRate = 0.058;
	else if (rateinput > 1) interestRate = rateinput / 100;
		else interestRate = rateinput;

	monRate = interestRate / 12;

	cout << "How Many Years to pay it off?" << "\n";
	cin >> term; cout << "\n";
	monthsTotal = term * 12;

	discountFactor = (	(pow((1.0 + monRate)	, double(monthsTotal)	) - 1.0) /
		(monRate * pow((1.0 + monRate),monthsTotal))	);
		//double pow(double base, double exponent);
	cout << "discountFactor = " << std::setprecision(2) << std::fixed << discountFactor << "\n";
	cout << "monthlyPayment" << " = " << principal << " / " << discountFactor << "\n";
	monthlyPayment = principal / discountFactor;

	cout << "Your monthly payment amount will be " << std::setprecision(2) << std::fixed << monthlyPayment << "\n\n";
	cout << "Your total amount paid over  " << term << " years would be " << std::setprecision(2) << std::fixed << monthlyPayment*monthsTotal << "\n";

	system("Pause");
	return 0;
}


/*
1. Calculate your daily interest rate (sometimes called interest rate factor). 
Divide your annual student loan interest rate by the number of days in the year.

.07/365 = 0.00019, or 0.019%

2. Calculate the amount of interest your loan accrues per day. 
Multiply your outstanding loan balance by your daily interest rate.

$10,000 x 0.00019 = $1.90

3. Find your monthly interest payment. Multiply your daily interest 
amount by the number of days since your last payment.

$1.90 x 30 = $57








*/
