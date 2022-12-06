#include "Order.h"
#include "Dish.h"
using namespace std;

Order::Order() {
  dishes = NULL;
  totalSum = 0;
  numofdish = 0;
}
Order::Order(Client& client)
:
dishes(NULL),
totalSum(0),
client(client),
restaurant(),
numofdish(0)
{
}
Order::Order(const Order &source) {

  totalSum = source.totalSum;
  client = source.client;
  restaurant = source.restaurant;
  numofdish = source.numofdish;
  dishes = new Dish*[numofdish];
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
      *(dishes+i) = *(source.dishes+i);
  }

  totalSum = source.totalSum;
  client= source.client;
  restaurant = source.restaurant;

  return *this;
}

void Order::showOrder() {
 cout << "your order:\n===========\n";
  for (int i = 0; i < numofdish; i++) {
    cout << "  " <<i + 1 << " - " << dishes[i]->getname() << "	-"
         << dishes[i]->getvalue() <<"NIS		 " << dishes[i]->getType() << endl;
  }
  cout << "===========================\n";
}
void Order::delete_order(){

    for (int i = 0 ; i < numofdish ; i++){
        delete *(dishes + i);
    }
    if(dishes != NULL)
        delete[] dishes;

    dishes = NULL;
    numofdish = 0;
    totalSum = 0;
}

bool Order::deleteDish() {

  int choice = 0;
  Dish **new_list = NULL;

  if (numofdish == 0) {
    cout << "No items in order yet\n";
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

  choice--;
  new_list = new Dish*[numofdish - 1];
  if (new_list == NULL){
	  cout << "ERROR!\n";
	  return false;
  }

    for (int i = 0, j = 0; i < numofdish; i++, j++) {

        if (i == choice) {
        i++;
        if (i == numofdish) {
            break;
        }
      }
       *(new_list+j) = *(dishes+i);
    }

  numofdish--;
  totalSum -= dishes[choice]->getvalue();

cout << dishes[choice]->getname() << " Was deleted from your order.\n";
if (numofdish == 0)
	cout << "Order is now empty\n";


delete[] dishes;
dishes = new_list;

return true;

}





bool Order::checkOut(){
    int out = -1;
    cout << "               CHECK - OUT\n            ```````````````````\n"
            << " Name: " << client.getname() << endl
            << " Phone Number:" << client.getphone()<< endl
            << " Address: " << client.get_city() << " " << client.get_street() << endl
            << " Credit: " << client.getcredits() << endl << endl

            << " Restaurant:" << restaurant.getrest() << endl
            << " Address: " << restaurant.getcity() << "  " << restaurant.getstreet() << endl;

    showOrder();
    cout << "-------------------------\n Total cost: " <<  totalSum << endl << endl;

    if (totalSum > client.getcredits())
    {
        cout << "You don't have enough credits\nReturning to menu\n";
        return false;
    }

    cout << ">>Do you wish to proceed? " << endl <<"1 - Yes        2 - No\n";
    cin >> out;
    if (out == 2){
        cout << "Returning to order\n";
        return false;
    }
        client.set_credits(-totalSum);
        cout << "Your balance is now:" << client.getcredits() << endl
        << "Your delivery will arrive in:" << get_ETA() << " MINUTS\n";
        delete[] dishes;

    return true;
}


void Order::adddish( Dish& new_dish) {
    Dish **new_dishes = NULL;
    Dish *dish = new Dish(new_dish);
if (dishes == NULL){

  dishes = new Dish*;
  *dishes = new Dish(new_dish);

}else{

    new_dishes = new Dish*[numofdish+1];
    memcpy(new_dishes,dishes,numofdish*sizeof(Dish*));
    *(new_dishes+numofdish) = dish;

    delete dishes;
    dishes = new_dishes;
}

    totalSum += new_dish.getvalue();
    numofdish++;

    cout << new_dish.getname() << " was added!\n";
}



Order::~Order() {


for (int i = 0 ; i < numofdish ; i++){
    delete *(dishes + i);
}
    delete[] dishes;
}
