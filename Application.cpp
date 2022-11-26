#include <iostream>
#include "Application.h"
#include "Dish.h"
using namespace std;


char d1[] = "Steak", d2[] = "Pasta", d3[] = "Pizza", d4[] = "Salad", d5[] = "Sushi",d6[] = "Sufle",d7[] = "Banana loti",d8[] = "Crack Pie",
R1[] = "Jupanika", R2[] = "BBB", R3[] = "Vivino";





Application::Application(Restaurant* rest_list, Client* client)
:
m_client(client),
m_restaurant(rest_list),
m_order(NULL)
{

}

Application::~Application()
{
}
