#pragma once
#include "Client.h"
#include "Restaurant.h"
#include "Order.h"





class Application
{
public:
	Application( Client& client);
	~Application();
public:
	char* get_client_name() { return m_client->getname(); };
	void print_rest();
	void print_rest_menu(int rest);
	void add_dish(int choice) ; // need 2 finish
	void set_rest(int choice){m_order->set_rest(m_restaurant[choice]);}; // maybe just assin..op
private:
	Client* m_client;
	Restaurant* m_restaurant;
	Order* m_order;
};

void print(Order& order);
