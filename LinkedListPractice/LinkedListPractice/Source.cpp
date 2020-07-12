#include <iostream>
#include "LinkedList.h"
#include <vector>

int main() {
	std::vector<int> myNumbers = { 5,2,12,3,6,178,52,88 };
	std::vector<int> palNumbers = { 5,4,3,2,1,2,3,4,5 };

	LinkedList myList;

	for (auto x : palNumbers) {
		myList.addNode(x);
	}

	myList.printList();
	/*
	myList.deleteNode(5);

	myList.deleteNode(6);
	*/
	myList.printList();

	myList.reverseList();

	if (myList.checkPalindrome()) std::cout << "List is a palindrome.\n";
	else std::cout << "Not a palindrome.\n";

	return 0;
}