#pragma once
#include "Address.h"
#include "Dish.h"
#include <iostream>


enum checkOut{};
enum deleteDish{};

class Order
{
public:
	Order();
	void showOrder();
	~Order();

private:
	Dish dishes;
	int totalSum;
	Address clientAddress;
	Address restaurantAddress;
};


