#pragma once

class MoveClass
{
private:
	int* data;
public:
	void setDataValue(int d);
	int getDataValue();
	MoveClass(int d);	//simple constructor
	MoveClass(const MoveClass& source);	//deep copy constructor
	MoveClass(MoveClass &&source) noexcept;	//move constructor
	~MoveClass();	//destructor;
};

