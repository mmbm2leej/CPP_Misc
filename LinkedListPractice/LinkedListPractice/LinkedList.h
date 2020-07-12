#pragma once
class LinkedList
{
private:
	typedef struct node {
		int data;
		node* next;
	}* nodeptr;

	//^^this is the same as: typedef struct node* nodeptr;

	nodeptr head;
	nodeptr curr;
	nodeptr temp;

public:
	LinkedList();
	void addNode(int dataToAdd);
	void deleteNode(int dataToDel);
	void printList();
	nodeptr reverseList();
	bool checkPalindrome();
	nodeptr reverseReturnList(nodeptr head);
};

