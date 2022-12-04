#pragma once
#include "Dish.h"
#include <iostream>


class Menu
{
public:
	Menu() ;
	Menu(Dish* dish_list, int size );
	~Menu();

public:
Menu& operator=(const Menu& source);
int getsize() { return m_size; };
char* getdish(int dish) { return m_dishes[dish].getname(); };
int getprice(int dish) { return m_dishes[dish].getvalue(); };

private:
	Dish* m_dishes;
	int m_size;
};

