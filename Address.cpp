#include "Address.h"
#include <iostream>
#include <string.h>


Address::Address(const Address& source)
{
	m_City = strdup(source.m_City);
	m_Street = source.m_Street;
}


Address& Address:: operator=(const Address& source) {
	if (this == &source) return *this;
	delete[] m_City;
	m_City = strdup(source.m_City);
	m_Street = source.m_Street;

	return *this;
}
Address::Address(const char* city, int street) {
	m_Street = street;
	m_City = strdup(city);
}

Address::Address() {
	m_City = NULL;
	m_Street = -1;
}

Address::~Address()
{
}
