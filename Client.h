#pragma once
#include "Address.h"

class Client
{
public:
	Client() ;
	Client(char* name, char* phonenumber, Address& homeaddres);
	Client(const Client& source);
	~Client();
public:
	Client& operator=(const Client& source);
	char* getname() { return m_Name; };
	char* getphone() { return m_PhoneNumber; };
	int getcredits() { return m_Credits; };
    int get_street(){return m_HomeAddres.getstreet();};
    char* get_city(){return m_HomeAddres.getcity();};

    void set_credits(int num){m_Credits += num;};
private:
	char* m_Name;
	char* m_PhoneNumber;
	int m_Credits;
	Address m_HomeAddres;
};


