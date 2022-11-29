#include "Order.h"
using namespace std;

Order::Order() {
  dishes = NULL;
  totalSum = 0;
  numofdish = 0;
}

Order::Order(const Order &source) {

  totalSum = source.totalSum;
  clientAddress = source.clientAddress;
  restaurantAddress = source.restaurantAddress;
  numofdish = source.numofdish;
  dishes = new Dish[numofdish];
  if (dishes == NULL) {
    cout << "error";
  }
  for (int i = 0; i < numofdish; i++) {
    dishes[i] = source.dishes[i];
  }
}

Order &Order::operator=(const Order &source) {

  if (this == &source)
    return *this;
  if (numofdish != source.numofdish) {
    delete[] dishes;
    numofdish = source.numofdish;
  }
  for (int i = 0; i < numofdish; i++) {
    dishes[i] = source.dishes[i];
  }

  totalSum = source.totalSum;
  clientAddress = source.clientAddress;
  restaurantAddress = source.restaurantAddress;

  return *this;
}

void Order::showOrder() {

  for (int i = 0; i < numofdish; i++) {
    cout << i + 1 << " - " << dishes[i].getname() << "	-"
         << dishes[i].getvalue() <<"NIS		 " << dishes[i].getType() << endl;
  }
}

bool Order::deleteDish() {

  int choice = 0;
  Dish *new_list = NULL;

  if (numofdish == 0) {
    cout << "No items in order yet";
    return false;
  }

  cout << "|DELETE A DISH|\n===============\n\n";
  showOrder();

  cout << " Choose dish: ";
  cin >> choice;
  if (choice > numofdish || choice < 1) {
    cout << "Invalid Number\n";
    return false;
  }

  new_list = new Dish[numofdish - 1];
  if (new_list){
	  cout << "ERROR!\n";
	  return false;
  }

    for (int i = 0, j = 0; i < numofdish; i++, j++) {

      if (i == choice)
        i++;

      dishes[i] = new_list[j];
    }

  numofdish--;
  totalSum -= dishes[choice].getvalue();

cout << dishes[choice].getname() << "Was deleted from your order.\n";
if (numofdish == 0)
	cout << "Order is now empty\n";

delete[] dishes;
dishes = new_list;

return true;

}

bool Order::checkOut(){




}


Order::~Order() { delete[] dishes; }
