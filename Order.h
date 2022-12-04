#pragma once
#include "Client.h"
#include "Restaurant.h"
#include "Dish.h"
#include <iostream>
#include <string.h>




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
	void adddish( Dish& new_dish);//finish application first
	void set_rest(Restaurant& rest) {restaurant = rest;};
	Order& operator=(const Order& source);
private:
	Dish* dishes;
	int totalSum;
	Client client;
	Restaurant restaurant;
	int numofdish;
};


