#pragma once


class Address
{
public:
	Address();
	int getstreet(){ return Street; };
	char* getcity() { return City; };
	void setstreet(int street) { Street = street; };
	void setcity(char* city);
	~Address();

private:
	int Street;
	char* City;
};


