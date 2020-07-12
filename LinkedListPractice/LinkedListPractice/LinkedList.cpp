#include "LinkedList.h"
#include <iostream>


LinkedList::LinkedList() {
	head = nullptr;
	curr = nullptr;
	temp = nullptr;
}
	
void LinkedList::addNode(int dataToAdd) {
	nodeptr n = new node;
	n->data = dataToAdd;
	n->next = nullptr;

	//create first node if there is none
	if (head == nullptr) head = n;
	
	//if there is already a list, traverse to the end of it first
	else {
		curr = head;
		while (curr->next != nullptr) {
			curr = curr->next;
		}
		curr->next = n;
	}
}

void LinkedList::deleteNode(int dataToDel) {
	nodeptr delPtr = nullptr;
	temp = head;
	curr = head;

	//traverse the list and look for the value
	while ((curr != nullptr) && (curr->data != dataToDel) ) {
		temp = curr;
		curr = curr->next;
	}

	//reached the end
	if (curr == nullptr) {
		std::cout << dataToDel << " does not exist in the list.\n";
	}
	//found the value
	else {
		//mark the node to delete
		delPtr = curr;

		//connect prev with the next around the node to delete
		curr = curr->next;
		temp->next = curr;
		
		if (delPtr == head) {
			head = head->next;
			temp = nullptr;
		}

		delete delPtr;
		std::cout << dataToDel << " deleted.\n";
	}
}

void LinkedList::printList() {
	std::cout << "Printing List...\n";

	curr = head;
	while (curr != nullptr) {
		std::cout << curr->data << " ";


		curr = curr->next;
	}
	std::cout << "\n";
}

LinkedList::nodeptr LinkedList::reverseList()
{
	curr = head;
	nodeptr next = nullptr;
	nodeptr prev = nullptr;

	while (curr != nullptr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
	return head;
}

//Does it in O(n) time and O(1) space
bool LinkedList::checkPalindrome()
{
	if ((head == nullptr) || (head->next == nullptr)) {
		return false;
	}
	nodeptr fastPtr = head;
	nodeptr slowPtr = head;

	while ((fastPtr->next != nullptr) && (fastPtr->next->next != nullptr)) {
		fastPtr = fastPtr->next->next;
		slowPtr = slowPtr->next;
	}

	nodeptr secondHalfHead = reverseReturnList(slowPtr->next);	//need to make a reverse fn that returns the list
	nodeptr firstHalfHead = head;

	while ((secondHalfHead != nullptr) && (firstHalfHead != nullptr)) {
		if (firstHalfHead->data != secondHalfHead->data) return false;
		secondHalfHead = secondHalfHead->next;
		firstHalfHead = firstHalfHead->next;
	}

	return true;
}

LinkedList::nodeptr LinkedList::reverseReturnList(nodeptr head) {
	nodeptr newHead = nullptr;

	while (head != nullptr) {
		nodeptr next = head->next;
		head->next = newHead;
		newHead = head;
		head = next;
	}
	return newHead;
}


