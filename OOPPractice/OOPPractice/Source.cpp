#include <iostream>
#include <string>
#include <vector>
#include "MoveClass.h"

using std::cout; using std::cin; using std::endl; using std::vector;



int main() {

	cout << "Running main." << "\n";

#pragma region Using Move Constructors
	/*
	vector<MoveClass> myVector;

	cout << "Beginning object insertion" << endl;
	myVector.emplace_back(MoveClass{ 10 });
	myVector.emplace_back(MoveClass{ 20 });
	myVector.emplace_back(MoveClass{ 30 });
	myVector.emplace_back(MoveClass{ 40 });
	myVector.emplace_back(MoveClass{ 50 });
	cout << "All objects inserted into myVector" << endl;
	*/

	/*
	Move constructors take priority over copy constructors where possible
	because it uses R-value argument
	*/

#pragma endregion 
	int x = 16;
	int y = 7;

	cout << "X = " << x << " and Y = " << y << "\n";

	//xor swap test
	x ^= y;
	y ^= x;
	x ^= y;

	cout << "X = " << x << " and Y = " << y << "\n";


	cout << "Completing Main function" << endl;
	
	return 0;
}