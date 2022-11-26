#include "Client.h"
#include <iostream>
#include <string.h>


Client::Client(char* name, char* phonenumber, Address homeaddres)
{
	strcpy(Name, name);
	strcpy(PhoneNumber, phonenumber);
	HomeAddres.setstreet(homeaddres.getstreet());
	HomeAddres.setcity(homeaddres.getcity());
	Credits = 100;

}

Client::~Client()
{
}