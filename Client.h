#pragma once
#include "Address.h"

class Client
{
public:
	Client() {};
	Client(char* name, char* phonenumber, Address homeaddres);
	~Client();

private:
	char* Name;
	char* PhoneNumber;
	int Credits;
	Address HomeAddres;
};


