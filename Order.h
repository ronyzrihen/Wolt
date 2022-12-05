#pragma once
#include "Client.h"
#include "Restaurant.h"
#include "Dish.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>




class Order
{
public:
	Order();
    Order(Client& client);
	Order(const Order& source);
	~Order();

public:
	bool checkOut();
	bool deleteDish();
    char* get_rest_city(){return restaurant.getcity();};
    char* get_client_city(){return client.get_city();};
	void showOrder();
	void adddish( Dish& new_dish);//finish application first
	void set_rest(Restaurant& rest) {restaurant = rest;};
	int get_menu_size() { return restaurant.get_menu_size(); };
    int get_ETA(){return abs(client.get_street()-restaurant.getstreet()) ;};
	Order& operator=(const Order& source);
private:
	Dish** dishes;
	int totalSum;
	Client client;
	Restaurant restaurant;
	int numofdish;
};


