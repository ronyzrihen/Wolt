#pragma once
#include "Address.h"

class Client
{
public:
	//Client() {};
	Client(char* name, char* phonenumber, Address& homeaddres);
	Client(const Client& source);
	~Client();
public:
	Client& operator=(const Client& source);
private:
	char* m_Name;
	char* m_PhoneNumber;
	int m_Credits;
	Address m_HomeAddres;
};


