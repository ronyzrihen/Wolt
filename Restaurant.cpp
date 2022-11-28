#include "Restaurant.h"
#include <iostream>
using namespace std;





Restaurant::Restaurant(const char* name, Address &street, Dish* dish_list, int size)
: m_menu(dish_list,size)
{
    m_name = _strdup(name);
    m_street = new Address;
    if (m_street == NULL) {
        cout << "error";/////לחזור לזה
    }
    *m_street = street; // need to check this one...
    
}
Restaurant& Restaurant::operator=(const Restaurant& rest){
    if(this == &rest){return *this;};
    delete[] m_name;
    m_name = _strdup(rest.m_name);

    delete m_street;
    m_street = new Address;
    if (m_street == NULL) {
        cout << "error";/////לחזור לזה
    }
    *m_street= *rest.m_street; 
    
    m_menu = rest.m_menu; 


return *this;
}

Restaurant::~Restaurant()
{
}
