#include "Client.h"
#include <iostream>
#include <string.h>



Client::Client(char* name, char* phonenumber, Address& homeaddres)
	:m_Name(_strdup(name)),
	m_PhoneNumber(_strdup(phonenumber)),
	m_Credits(100),
	m_HomeAddres(homeaddres)
{}

Client::Client(const Client& source) :
	m_Name(_strdup(source.m_Name)),
	m_PhoneNumber(_strdup(source.m_PhoneNumber)),
	m_Credits(source.m_Credits),
	m_HomeAddres(source.m_HomeAddres)
{

}

Client& Client:: operator=(const Client& source) {
	if (this == &source) { return *this; }
	
	delete[]m_Name;

	m_Name = _strdup(source.m_Name);

	delete[]m_PhoneNumber;
	m_PhoneNumber = _strdup(source.m_PhoneNumber);

	m_Credits = source.m_Credits;
	m_HomeAddres = source.m_HomeAddres;

	return *this;
}

Client::Client():
	m_Name(NULL),
	m_PhoneNumber(NULL),
    m_Credits(-1){}


Client::~Client()
{
	delete[] m_Name;
	delete[] m_PhoneNumber;
}
