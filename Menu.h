#pragma once
#include "Dish.h"
#include <iostream>


class Menu
{
public:
	Menu();
	~Menu();

private:
	Dish* dishes;
};

