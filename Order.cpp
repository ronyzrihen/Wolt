#include "Order.h"
using namespace std;

Order::Order()
{
	dishes = NULL;
	totalSum = 0;
	numofdish = 0;
}

Order::Order(const Order& source) {

	totalSum = source.totalSum;
	clientAddress = source.clientAddress;
	restaurantAddress = source.restaurantAddress;
	numofdish = source.numofdish;
	dishes = new Dish[numofdish];
	if (dishes==NULL) {
		cout << "error";
	}
	for (int i = 0; i <numofdish ; i++)
	{
		dishes[i] = source.dishes[i];
	}

}

Order& Order:: operator=(const Order& source){

	if (this == &source) return *this;
	if (numofdish != source.numofdish) {
		delete[]dishes;
		numofdish = source.numofdish;
	}
		for (int i = 0; i < numofdish; i++)
		{
			dishes[i] = source.dishes[i];
		}

		totalSum = source.totalSum;
		clientAddress = source.clientAddress;
		restaurantAddress = source.restaurantAddress;

		return *this;
}

void Order::showOrder() {

	for (int i = 0; i < numofdish; i++)
	{
		cout <<i+1<<" - " << dishes[i].getname()<<"	-"<<dishes[i].getvalue() << endl;
	}
}



Order::~Order()
{
	delete[]dishes;
}
