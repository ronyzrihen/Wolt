#pragma once
#include "Client.h"
#include "Restaurant.h"
#include "Order.h"





class Application
{
public:
	Application(Restaurant* rest_list, Client* client);
	~Application();

private:
	Client* m_client;
	Restaurant* m_restaurant;
	Order* m_order;
};

void print();