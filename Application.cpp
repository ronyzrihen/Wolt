#include <iostream>
#include "Application.h"
#include "Dish.h"
using namespace std;





Dish Steak("Steak",MainCourse,5), Pasta("Pasta",MainCourse,5),Pizza("Pizza",MainCourse,5),Salad("Salad",Appetizer,5),Sushi("Sushi",MainCourse,5),Sufle("Sufle",Dessert,5),Banana_loti("Banana loti",Dessert,5),Crack_Pie("Crack Pie",Dessert,5);

Dish menu1[] = {Salad,Steak,Crack_Pie,Banana_loti,Sufle};
Dish menu2[] = {Salad,Pasta,Pizza,Banana_loti,Sufle};
Dish menu3[] = {Sushi,Salad,Sufle,Banana_loti,Sufle};
Address c1("Afula", 100),c2("Tel-Aviv",77),c3("Ramat-Gan",80);
Restaurant rest_list[] = { Restaurant("BBB", c2, menu1, 5),Restaurant("Jupanika", c1, menu3, 5), Restaurant("Vivino", c3, menu2, 5)};



Application::Application(Restaurant* rest_list, Client* client)
:
m_client(client),
m_restaurant(rest_list),
m_order()
{

}

Application::~Application()
{
}



void print() {

	for (int i = 0; i < 3; i++)
	{
		cout << rest_list[i].getrest()<<endl<<"Menu:\n";

		for (int j = 0; j < rest_list[i].get_menu_size(); j++)
		{
			cout << " " << j + 1 << ".  " << rest_list[i].get_dish_name(j)<<endl;
		}
		cout << "====================================\n";
	}
}