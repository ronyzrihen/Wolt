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
Dish*& get_menu() { return m_dishes; };
DishType get_dish_type(int num) {return m_dishes[num].get_int_Type();};
void Print_menu_by_type();
private:
	Dish* m_dishes;
	int m_size;
};

