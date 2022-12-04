#include <iostream>
#include "Application.h"
using namespace std;




int main() {


	char*name = new char;
	char*city = new char;
	char*phonenumber = new char;

	int street=-1;
	cout << "Create client\nclient name: ";
	cin >> name;
	cout << "client phone number: ";
	cin >> phonenumber;
	cout << "Home Address: \n"
		<<"  City: ";
	cin >> city;
	cout << "  Street: ";
	cin >> street;
	Address useraddress(city, street);
	Client user(name, phonenumber, useraddress);
	Application wolt(user);

	for(;;){
	int choice = -1;
	wolt.print_rest();
	cin >> choice;
	while (choice < 1 || choice > 3) {
		cout << " Choice invalid!\n Try again: ";
		cin  >> choice;
	}

		wolt.set_rest(choice -1);

		wolt.print_rest_menu(choice-1);

		for (;;) {
		int dish_choice = -1;
		cout << "1 - Add to order		2 - delete from order\n"
			<<  "3 - show order			4 - check out\n"
			<<  "0 - change Restaurant\n";

		cout << "choose option: ";
		cin >> dish_choice;
		while (dish_choice < 0 || dish_choice > 4) {
			cout << " Choice invalid!\n Try again: ";
			cin >> dish_choice;
		}


		switch (dish_choice) {
		case 1: {
		wolt.print_rest_menu(choice - 1); //fix

		cout << "Choose a dish to add: ";
		cin >> dish_choice;
		while (dish_choice < 1 || dish_choice > wolt.get_menu_size()) {
			cout << " Choice invalid!\n Try again: ";
			cin >> dish_choice;
		}
		wolt.add_dish(dish_choice - 1);

			break;
		}
		case 2: {

		wolt.delete_dish();

		return 0;
		}//case 2
		}

		}//end of dish







	
	
	



	return 0;
	} //end of rest for
}
