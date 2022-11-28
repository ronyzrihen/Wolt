#pragma once
#include "Address.h"
#include "Menu.h"
#include <string>

class Restaurant
{
public:
	Restaurant(const char* name, Address &street, Dish* dish_list, int size);
	~Restaurant();

public:
	Restaurant& operator=(const Restaurant& rest);
	char* getrest() { return m_name; };
	int get_menu_size() { return m_menu.getsize(); };
	char* get_dish_name(int dish) { return m_menu.getdish(dish); };
private:
	char* m_name;
	Address* m_street;
	Menu m_menu;
};


