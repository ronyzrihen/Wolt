#include "Restaurant.h"
#include <iostream>
using namespace std;



Restaurant::Restaurant()
    :
    m_name(NULL),
    m_street(NULL),
    m_menu()
{
}

Restaurant::Restaurant(const char* name, Address &street, Dish* dish_list, int size)
: m_menu(dish_list,size)
{
    m_name = strdup(name);
    m_street = new Address;
    if (m_street == NULL) {
        cout << "error";/////����� ���
    }
    *m_street = street; // need to check this one...
    
}
Restaurant& Restaurant::operator=( const Restaurant& rest){
    if(this == &rest){return *this;};
    if (m_name != NULL) {
    delete[] m_name;
    }
    
    m_name = strdup(rest.m_name);

    delete m_street;
    m_street = new Address;
    if (m_street == NULL) {
        cout << "error";/////����� ���
    }
    *m_street= *rest.m_street; 
    
    m_menu = rest.m_menu; 


return *this;
}

Restaurant::~Restaurant()
{
}
