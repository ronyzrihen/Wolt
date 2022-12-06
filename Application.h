#pragma once
#include "Client.h"
#include "Restaurant.h"
#include "Order.h"





class Application
{
public:
	Application( Client& client, Restaurant* rest_list, int rest_size );
	~Application();
public:
    bool is_same_city(int rest);
	void print_rest(Restaurant* rest_list);
	void print_rest_menu(int rest);
    void Print_menu_by_type(){ return m_order->Print_menu();};
	void add_dish(int choice) ;
	void show_order() { m_order->showOrder(); };
	void delete_dish() { m_order->deleteDish(); };
    void delete_order() {m_order->delete_order();};
	bool check_out() {return m_order->checkOut();};
    int get_menu_size() { return m_order->get_menu_size(); };

    void set_rest(int choice);
private:
	Client* m_client;
	Restaurant* m_restaurant;
	Order* m_order;
};

void print(Order& order);
