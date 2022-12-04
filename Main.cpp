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
	switch (choice) {
	case 1:{
		wolt.set_rest(choice -1);
		wolt.print_rest_menu(choice-1);
		
		break;
	}
	case 2:{

		break;
	}
	case 3:{

		break;
	}
	}





	
	
	



	return 0;
	}
}
