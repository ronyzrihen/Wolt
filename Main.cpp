#include <iostream>
#include "Application.h"
using namespace std;




int main() {

	char* name,*city,*phonenumber;
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

	
	print();


	return 0;
}
