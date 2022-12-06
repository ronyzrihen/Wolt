#include <iostream>
#include "Application.h"
#define NUM_OF_REST 6
#define NUM_OF_ADD 3
using namespace std;




int main() {

    Dish Berger("Hamburger",MainCourse,69), Steak("Steak",MainCourse,80), Pasta("Pasta",MainCourse,50),Pizza("Pizza",MainCourse,50),Salad("Salad",Appetizer,25),Sushi("Sushi",MainCourse,70),Sufle("Sufle",Dessert,10),Banana_loti("Banana loti",Dessert,10),Crack_Pie("Crack Pie",Dessert,5);

    Dish menu1[] = {Salad,Berger,Steak,Crack_Pie,Banana_loti,Sufle};
    Dish menu2[] = {Salad,Pasta,Pizza,Banana_loti,Sufle};
    Dish menu3[] = {Salad,Sushi,Sufle,Banana_loti,Sufle};
    Address c1("Afula", 100),c2("Tel-Aviv",77),c3("Ramat-Gan",80);
    Address cities[] = {c1,c2,c3};
    Restaurant rest_list[] = { Restaurant("BBB", c2, menu1, 5),Restaurant("Jupanika", c1, menu3, 5),Restaurant("Jupanika", c2, menu3, 5),Restaurant("Jupanika", c3, menu3, 5), Restaurant("Vivino", c3, menu2, 5),Restaurant("Vivino", c1, menu2, 5)};

    char*name = new char;
    char*phonenumber = new char;
    int city = -1;
    int street=-1;

	cout << "Create client\nclient name: ";
	cin >> name;
	cout << "client phone number: ";
	cin >> phonenumber;
	cout << "Home Address: \n"
		<<"  Choose city: \n";
    for (int i = 0 ; i < NUM_OF_ADD ; i++){
        cout << "  " << i+1 << ".  " << cities[i].getcity() << endl;
    }
    cout << ">>>> ";
    cin >> city;
    while (city < 1 || city > NUM_OF_ADD){
        cout << "Invalid option!\nPlease try again: ";
        cin >> city;
    }
	cout << "  Street: ";
	cin >> street;
	Address useraddress(cities[city-1].getcity(), street);
	Client user(name, phonenumber, useraddress);
	Application wolt(user, rest_list, NUM_OF_REST);
    int flag = 0;

	for(;;){
	int choice = -1;
    flag = 0;
	wolt.print_rest(rest_list);
	cin >> choice;
	while (choice < 1 || choice > NUM_OF_REST) {
		cout << " Choice invalid!\n Try again: ";
		cin  >> choice;
	}
        if (wolt.is_same_city(choice-1)){
            cout << "Restaurant is in a different city!\n";
            continue;
        }



        wolt.set_rest(choice -1);
		//wolt.print_rest_menu(choice-1); todo delete

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

		break;
		}//case 2

        case 3:{
            wolt.show_order();
            break;
        }// case 3
        case 4: {

            if(wolt.check_out() == false)
                break;

            cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~\n|Thanks fo choosing wolt!|\n ~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            return 0;
        }//case 4
        case 0 :{
            wolt.delete_order();
            flag++;
            break;
        }
		} // end of switch
        if(flag == 1)
            break;
		}//end of dish








	} //end of rest for

    return 0;
}
