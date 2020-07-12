#include "Employee.h"
#include <iostream>

using std::cout;
using std::endl;

Employee::Employee() { 
	cout << "Creating Employee Object" << endl; 
	cout << "Employee Object Creation Complete" << endl;
}

Employee::Employee(string fn, string ln, unsigned int id) {
	cout << "Creating Employee Object" << fn << ln << endl;
	nameFirst = fn;
	nameLast = ln;
	employeeID = id;
	cout << "Employee Object" << fn << ln << "Creation Complete" << endl;
}

string Employee::getFirstName() { return nameFirst; }

string Employee::getLastName() { return nameLast; }

unsigned int Employee::getEmpID() { return employeeID; }

void Employee::setFirstName(string newFirstName) { nameFirst = newFirstName; }

void Employee::setLastName(string newLastName) { nameLast = newLastName; }

void Employee::setEmpID(unsigned int newEmpID) { employeeID = newEmpID; }

void Employee::printFirstName() { cout << nameFirst; }

void Employee::printLastName() { cout << nameLast; }

void Employee::printEmpID() { cout << employeeID; }


Employee::~Employee()
{
}


