#include "Address.h"
#include <iostream>
#include <string.h>


void Address::setcity(char* city)
{
	if (city == NULL) {
		return;
	}
	strcpy(City, city);
}

Address::Address()
{
}

Address::~Address()
{
}