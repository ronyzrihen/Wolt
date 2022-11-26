#pragma once
#include "Address.h"
#include "Menu.h"
#include <string>

class Restaurant
{
public:
	Restaurant& operator=(const Restaurant& rest);
	Restaurant(char* name, Address *street, Menu menu);
	~Restaurant();

private:
	char* m_name;
	Address* m_street;
	Menu m_menu;
};


