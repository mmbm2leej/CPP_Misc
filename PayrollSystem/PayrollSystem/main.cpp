#include <iostream>
#include "Employee.h"

using std::cout;
using std::endl;

int main() {
	Employee sue = Employee("Sue", "Higgenbottom", 10001);
	
	cout << "Employee sue:" << endl;
	cout << "First Name:";
	sue.printFirstName(); cout << endl;
	cout << "Last Name:";
	sue.printLastName();
	cout << sue.getLastName() << endl;
	cout << "ID:";
	sue.printEmpID(); cout << endl;

	system("Pause");
	return 0;
}