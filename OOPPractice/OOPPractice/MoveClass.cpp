#include "MoveClass.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

void MoveClass::setDataValue(int d) {
	*data = d;
}

int MoveClass::getDataValue() {
	return *data;
}

MoveClass::MoveClass(int d) {
	data = new int;
	*data = d;
	cout << "Constructor for: " << d << endl;
}

MoveClass::MoveClass(const MoveClass& source) : MoveClass{ *source.data } {
	cout << "Copy Constructor - deep copy for: " << *data << endl;
}

MoveClass::MoveClass(MoveClass &&source) noexcept : data{ source.data } {
	source.data = nullptr;
	cout << "Move constructor - moving resource: " << *data << endl;
}

MoveClass::~MoveClass() {
	if (data != nullptr) {
		cout << "Destructor freeing data for: " << *data << endl;
	}
	else {
		cout << "Destructor freeing data for nullptr" << endl;
	}
	delete data;
}
