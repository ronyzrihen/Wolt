#pragma once
#include "Address.h"
#include "Dish.h"
#include <iostream>




class Order
{
public:
	Order();
	Order(const Order& source);
	~Order();

public:
	bool checkOut();
	bool deleteDish();
	void showOrder();
	Order& operator=(const Order& source);
private:
	Dish* dishes;
	int totalSum;
	Address clientAddress;
	Address restaurantAddress;
	int numofdish;
};


