#include <math.h>
#include <iostream>
#include <iomanip>
#include <vector>

#include <stdlib.h>
#include <time.h>
#include <algorithm>

using std::cout; using std::cin; 
using std::vector; using std::max;
using std::setprecision; using std::fixed;

// Find the mean
double VecMean(vector<double> x) {
	int n = x.size();
	double sum = 0.0;
	for (int i = 0; i <= n - 1; i++)
		sum += x[i];
	double xbar = sum / n;
	return xbar;
}

// N(0,1) density
double f(double x) {	
	double pi = 4.0 * atan(1.0);
	return exp(-x * x * 0.5) / sqrt(2 * pi);
}

// Boole's Rule
double Boole(double StartPoint, double EndPoint, int n) {
	vector < double >X(n + 1, 0.0);
	vector < double >Y(n + 1, 0.0);
	double delta_x = (EndPoint - StartPoint) / double(n);
	for (int i = 0; i <= n; i++)
	{
		X[i] = StartPoint + i * delta_x;
		Y[i] = f(X[i]);
	}
	double sum = 0;
	for (int t = 0; t <= (n - 1) / 4; t++)
	{
		int ind = 4 * t;
		sum +=
			(1 / 45.0) * (14 * Y[ind] + 64 * Y[ind + 1] + 24 * Y[ind + 2] +
				64 * Y[ind + 3] + 14 * Y[ind + 4]) * delta_x;
	}
	return sum;
}

// N(0,1) cdf by Boole's Rule
double N(double x) {
	return Boole(-10.0, x, 240);
}

// Black Scholes closed form price
double BS(double S, double K, double v, double T, double r, double q, char PutCall) {
	double d1 = (log(S / K) + (r - q + 0.5 * v * v) * T) / v / sqrt(T);
	double d2 = d1 - v * sqrt(T);
	double Call = S * exp(-q * T) * N(d1) - K * exp(-r * T) * N(d2);
	if (PutCall == 'C')
		return Call;
	else
		return Call - S * exp(-q * T) + K * exp(-r * T);
}

int main() {

#pragma region Establish variables
	srand(time(0));		//randomize
	double spot, strike, years, intRate, divYield, volatility;		// Spot Price
	long int Nsims = 1e7;		// Number of simulations
	double Z;			// Random standard normal Z(0,1)

	cout << "Enter spot price: "; cin >> spot;
	cout << "Enter strike price: "; cin >> strike;
	cout << "Enter years to expiration: "; cin >> years;
	cout << "Enter interest rate: "; cin >> intRate;
	cout << "Enter dividend yield: "; cin >> divYield;
	cout << "Enter volatility: "; cin >> volatility;
	cout << "Enter number of simulations: "; cin >> Nsims;

	vector < double >ST(Nsims, 0.0);	// Initialize terminal prices S(T)
	vector < double >ST_K(Nsims, 0.0);	// Initialize call payoff
	vector < double >K_ST(Nsims, 0.0);	// Initialize put payoff
	double u1, u2;
	const double pi = 3.141592653589793;
#pragma endregion

	for (int i = 0; i <= Nsims - 1; i++)
	{
		// Independent uniform random variables
		u1 = ((double)rand() / ((double)(RAND_MAX)+(double)(1)));
		u2 = ((double)rand() / ((double)(RAND_MAX)+(double)(1)));
		// Floor u1 to avoid errors with log function
		u1 = max(u1, 1.0e-10);
		// Z ~ N(0,1) Box-Muller transformation
		Z = sqrt(-2.0 * log(u1)) * sin(2 * pi * u2);
		ST[i] = spot * exp((intRate - divYield - 0.5 * volatility * volatility) * years + volatility * sqrt(years) * Z);	// Simulated terminal price S(T)
		ST_K[i] = max(ST[i] - strike, 0.0);	// Call payoff
		K_ST[i] = max(strike - ST[i], 0.0);	// Put payoff
	}

#pragma region Monte and BS

	double BSCallSim = exp(-intRate * years) * VecMean(ST_K);
	double BSPutSim = exp(-intRate * years) * VecMean(K_ST);

	// Closed form prices
	double BSCall = BS(spot, strike, volatility, years, intRate, divYield, 'C');
	double BSPut = BS(spot, strike, volatility, years, intRate, divYield, 'P');
#pragma endregion

#pragma region Error
	// Calculate Errors between BS and Sim
	double CallError = BSCall - BSCallSim;
	double PutError = BSPut - BSPutSim;
#pragma endregion

#pragma region Output

	cout << setprecision(4) << fixed;
	cout << "Using " << Nsims << " simulations..." << "\n";
	cout << " " << "\n";
	cout << "Method					CallPrice	PutPrice " << "\n";
	cout << "----------------------------------" << "\n";
	cout << "Simulation(Monte)			" << BSCallSim << "		" << BSPutSim << "\n";
	cout << "Closed(Black Scholes)			" << BSCall << "		" << BSPut << "\n";
	cout << "Error					" << CallError << "		" << PutError << "\n";
	cout << "----------------------------------" << "\n";
	cout << " " << "\n";
	system("PAUSE");
	return 0;

#pragma endregion
}

