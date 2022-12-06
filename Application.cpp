#include <iostream>
#include "Application.h"
#include "Dish.h"
#define NUM_OF_REST 6
using namespace std;

Application::Application(Client& client, Restaurant* rest_list, int rest_size )
	:
m_order(new Order(client))

{
    m_restaurant = new Restaurant[rest_size];
    if(m_restaurant == NULL){
        cout << "ERROR!\n";
        m_restaurant = NULL;
    }
    for (int i = 0 ; i < rest_size ; i++){
        m_restaurant[i] = rest_list[i];
    }
	m_client = new Client;
	*m_client = client;

}

Application::~Application()
{
}

bool Application::is_same_city(int rest){

    if(!strcmp(m_order->get_client_city(),m_restaurant[rest].getcity()))
        return false;

    return true;
}

void Application::add_dish(int choice) {

	Dish* menu = m_order->get_menu();
	m_order->adddish(menu[choice]);
}

void Application::set_rest(int choice) {

	if (m_order == NULL) {
		m_order = new Order;
	}

	m_order->set_rest(m_restaurant[choice]);

}
void Application::print_rest(Restaurant* rest_list){
cout << "Choose restaurant:\n";
	for (int i = 0; i < NUM_OF_REST; i++)
	{
		cout << i+1 << " - " << rest_list[i].getrest() << " - " << rest_list[i].getcity() << endl;
	}

}
void Application::print_rest_menu(int rest){
	cout << "menu:\n";
    Print_menu_by_type();
}

void print(Order&order, Restaurant*& rest_list) {
	int num=0;
	cout << "Choose restaurant:\n";
	for (int i = 0; i < 3; i++)
	{
		cout << i << " - " << rest_list[i].getrest() << endl;
	}
	cin >> num;
	switch (num)
	{
	case 0: {
		cout << "menu:\n";
			for (int j = 0; j < rest_list[0].get_menu_size(); j++)
			{
				cout << " " << j + 1 << ".  " << rest_list[0].get_dish_name(j) << "-" << rest_list[0].get_dish_price(j) << " NIS" << endl;
			}
			cout << "====================================\n";
			break;
		}
	case 1:
	{
		int choose = -1;
		cout << "menu:\n";
		for (int j = 0; j < rest_list[1].get_menu_size(); j++)
		{
			cout << " " << j + 1 << ".  " << rest_list[1].get_dish_name(j) << "-" << rest_list[1].get_dish_price(j) << " NIS" << endl;
		}
		cout << "====================================\n";
		cout << "choose dish:";
		cin >> choose;
		//order.adddish(rest_list[1]);
		/*order.showOrder();*/
		break;
	}
	case 2:
		cout << "menu:\n";
	{
		for (int j = 0; j < rest_list[2].get_menu_size(); j++)
		{
			cout << " " << j + 1 << ".  " << rest_list[2].get_dish_name(j) << "-" << rest_list[2].get_dish_price(j) << " NIS" << endl;
		}
		cout << "====================================\n";
		break;
	}


	default:
		break;
	}
}

	
