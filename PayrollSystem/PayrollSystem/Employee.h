#pragma once
#include <string>

using std::string;

class Employee
{
private:
	string nameFirst;
	string nameLast;
	unsigned int employeeID;

public:
	Employee();
	Employee(string fn, string ln, unsigned int id);
	~Employee();
	string getFirstName();
	string getLastName();
	unsigned int getEmpID();
	void setFirstName(string newFirstName);
	void setLastName(string newLastName);
	void setEmpID(unsigned int newEmpID);
	void printFirstName();
	void printLastName();
	void printEmpID();
};
