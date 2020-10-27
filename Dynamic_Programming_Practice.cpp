#include <iostream>
#include <array>
#include <vector>
#include <utility>
#include <cmath>
#include <numeric>
#include <algorithm>

#define vofi std::vector<int>
#define vofd std::vector<double>

//Finding Fib at near O(1) on compile time
#pragma region Fib compile time
template<int I>
struct Fib {
	static const int val = Fib<I - 1>::val + Fib<I - 2>::val;
};

template<>
struct Fib<0> {
	static const int val = 0;
};

template<>
struct Fib<1> {
	static const int val = 1;
};

template<size_t ... I>
int fib_impl(std::index_sequence<I...>, const int i) {
	constexpr std::array<int, sizeof...(I)> a = { 
		Fib<I>::val... };
	return a[i];
}

int fib(const int i) {
	return fib_impl(std::make_index_sequence<47>(), i);
}
#pragma endregion

//Normal Fib runs O(2^n)
#pragma region Naive Fib
/*
int fib(int n) {
	return (
		(n <= 0) ? 0 : (n == 1) ? 1 : (fib(n - 1) + fib(n - 2))
		);
}*/
#pragma endregion

#pragma region Knapsack

void calcGrid(std::vector<vofi> &grid, vofi values, vofi weights) {
	//THIS IS ASSUMING NONE OF THE ITEMS ARE 0 weight, and capacity is > 0

	for (int i = 0; i < grid.size(); ++i) {	//for each row(item type)
		for (int j = 1; j < grid[0].size(); ++j) {	//for each column(weight capacity)
			if (weights[i] > j) grid[i][j] = 0;	//skip if cant fit
			else if (i == 0) {	//first item
				if (j >= weights[i]) grid[i][j] = values[i];
			}
			else {
				int checkedTopLeft = grid[i - 1][j - weights[i]];
				int checkedAbove = grid[i - 1][j];
				grid[i][j] = std::max(values[i] + checkedTopLeft, checkedAbove);
			}

		}

	}



}


#pragma endregion

//Fib Binet Method
/*
long long fibBinet(int n) {
	if (n <= 1) return n;
	else {
		const double rt5 = sqrt(5);
		long long result = (pow(1 + rt5, (double)n) - pow(1 - rt5, (double)n)) / (pow(2.0, (double)n) * rt5);
		return result;
	}
}
*/

double calcAvg(vofd list) {
	return (std::accumulate(list.begin(), list.end(), 0.0) / list.size());
}

int findLowestChangeableIndex(std::vector<vofi> list) {
	int idx = 0, lowestDenom = INT_MAX;
	for (size_t i = 0; i < list.size(); ++i) {
		if ((list[i][0] < list[i][1]) && (list[i][1] < lowestDenom)) {
			idx = i;
			lowestDenom = list[i][1];
		}
	}

	return idx;
}

vofd findAvg(std::vector<vofi> list) {
	vofd avgs{};
	double currAvg = 0;
	for (size_t i = 0; i < list.size(); ++i) {
		currAvg = (list[i][0] * 1.0) / (list[i][1] * 1.0);
		avgs.emplace_back(currAvg);
		std::cout << currAvg << " ";
	}
	std::cout << "\n";

	return avgs;
}

void print2dArray(std::vector<vofi> x) {
	std::cout << "\n\n";
	for (int i = 0; i < x.size(); ++i) {
		for (int j = 0; j < x[0].size(); ++j) {
			std::cout << x[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n\n";
}

int main() {
	//int fibNumber = 6;
	//std::cout << Fib<45>::val;

	//std::cout << fibBinet(11);
	/*
	std::vector<int> weights = { 1,2,3,4,5 };
	std::vector<int> values = { 30,10,50,40,60 };
	int limit = 8;

	std::cout << highestValue(weights, values, limit);
	*/

#pragma region Product Ratings Needed Problem
	/*
	std::vector<vofi> productRatings{ {4,4}, {3,4}, {3,6}, {2,3}, {2,7}, {5,6}, {1,3}, {2,6}, {1,4}, {4,7} };
	int threshold = 90;

	std::vector<double> avgList = findAvg(productRatings);
	
	double threshRatio = (threshold * 1.0) / 100;
	double currAvg = calcAvg(avgList);
	int targetIndex, addedFives = 0;

	std::cout << "currAvg = " << currAvg << "\n";
	std::cout << "threshRatio = " << threshRatio << "\n";

	while (currAvg < threshRatio) {
		targetIndex = findLowestChangeableIndex(productRatings);

		//increase ratings
		productRatings[targetIndex][0]++;
		productRatings[targetIndex][1]++;
		
		//update avgList
		avgList[targetIndex] = (productRatings[targetIndex][0]*1.0) / (productRatings[targetIndex][1]*1.0);

		//update currAvg
		currAvg = calcAvg(avgList);
		addedFives++;

		std::cout << "Added a five-star rating...\n";
		std::cout << "currAvg = " << currAvg << "\n";
		//std::cout << "threshRatio = " << threshRatio << "\n";

	}

	std::cout << "\n\n Number of five-star ratings needed is " << addedFives << "\n";
	*/
#pragma endregion

#pragma region Knapsack

	//Inputs
	vofi givenWeights = {4,2,3,3,1};
	vofi givenValues = {5,3,4,2,2};
	int capacity = 7, greatestValueTotal = 0;

	//Implementation
	//rows are items, columns are capacity 0 to full
	//rows are givenValues.size(), columns are capacity+1 just to include zero;
	vofi perRow(capacity + 1, 0);
	std::vector<vofi> myBag(givenValues.size(),perRow);

	print2dArray(myBag);
	calcGrid(myBag, givenValues, givenWeights);
	print2dArray(myBag);

	//find the greatest Value Total Possible
	for (int i = 0; i < myBag[0].size(); ++i) {
		if (myBag[myBag.size() - 1][i] > greatestValueTotal)
			greatestValueTotal = myBag[myBag.size() - 1][i];
	}

	std::cout << "Greatest Possible Value Total is " << greatestValueTotal << "\n\n";


#pragma endregion


	return 0;
}
