#pragma once
#include <iostream>
#include <cstring>


typedef enum {Appetizer,MainCourse,Dessert}DishType;
class Dish
{
public:
	Dish();
	Dish(const char* name, DishType type, int value);
	Dish(const Dish& source);
	~Dish();

public:

	Dish& operator=(const Dish& source);
	char* getname() { return m_name; };
	int getvalue() { return m_value; };
private:
	char* m_name;
	DishType m_type;
	int m_value;
};

