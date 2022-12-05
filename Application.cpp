#include <iostream>
#include "Application.h"
#include "Dish.h"
using namespace std;





Dish Berger("Hamburger",MainCourse,70), Steak("Steak",MainCourse,5), Pasta("Pasta",MainCourse,5),Pizza("Pizza",MainCourse,5),Salad("Salad",Appetizer,5),Sushi("Sushi",MainCourse,5),Sufle("Sufle",Dessert,5),Banana_loti("Banana loti",Dessert,5),Crack_Pie("Crack Pie",Dessert,5);

Dish menu1[] = {Salad,Steak,Crack_Pie,Banana_loti,Sufle};//todo change prices
Dish menu2[] = {Salad,Pasta,Pizza,Banana_loti,Sufle};
Dish menu3[] = {Salad,Sushi,Sufle,Banana_loti,Sufle};
Address c1("Afula", 100),c2("Tel-Aviv",77),c3("Ramat-Gan",80);
Restaurant rest_list[] = { Restaurant("BBB", c2, menu1, 5),Restaurant("Jupanika", c1, menu3, 5), Restaurant("Vivino", c3, menu2, 5)};



Application::Application(Client& client)
	:
m_order(new Order(client)),
m_restaurant(rest_list)
{
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

	Dish* menu = m_restaurant->get_menu();
	m_order->adddish(menu[choice]);
}

void Application::set_rest(int choice) {

	if (m_order == NULL) {
		m_order = new Order;
	}

	m_order->set_rest(m_restaurant[choice]);

}
void Application::print_rest(){
cout << "Choose restaurant:\n";
	for (int i = 0; i < 3; i++)
	{
		cout << i+1 << " - " << rest_list[i].getrest() << endl;
	}

}
void Application::print_rest_menu(int rest){
	cout << "menu:\n";
	cout << " " << 0 << ".  " << "return to restaurants\n";
			for (int j = 0; j < rest_list[rest].get_menu_size(); j++)
			{
				cout << " " << j + 1 << ".  " << rest_list[rest].get_dish_name(j) << "-" << rest_list[rest].get_dish_price(j) << " NIS" << endl;
			}
			cout << "====================================\n";

}

void print(Order&order) {
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

	
