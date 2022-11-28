#pragma once


class Address
{
public:
	Address();
	Address(const char* city, int street);
	Address(const Address& source);
	Address& operator=(const Address& source);
	int getstreet(){ return m_Street; };
	char* getcity() { return m_City; };
	void setstreet(int street) { m_Street = street; };
	void setcity(char* city);
	~Address();

private:
	int m_Street;
	char* m_City;
};


