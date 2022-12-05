#pragma once
#include "Address.h"
#include "Menu.h"
#include <string>

class Restaurant
{
public:
	Restaurant();
	Restaurant(const char* name, Address &street, Dish* dish_list, int size);
	~Restaurant();

public:
	Restaurant& operator=( const Restaurant& rest);
    char* getrest() { return m_name; };
	int get_menu_size() { return m_menu.getsize(); };
	char* get_dish_name(int dish) { return m_menu.getdish(dish); };
	int get_dish_price(int dish) { return m_menu.getprice(dish); };
	int getstreet() { return m_street->getstreet(); };
	char* getcity() { return m_street->getcity(); };

	Dish* get_menu() { return m_menu.get_menu(); };
private:
	char* m_name;
	Address* m_street;
	Menu m_menu;
};


