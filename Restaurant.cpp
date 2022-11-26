#include "Restaurant.h"
#include <iostream>
using namespace std;





Restaurant::Restaurant(char* name, Address *street, Menu menu)
{
    m_name = new char[strlen(name)+1];
    if(m_name ==NULL ){
        cout << "ERROR!"; ///////////////////////change later
    }
    strcpy(m_name, name);

    m_street = street; // need to check this one...

    //m_nemu = menu()

}
Restaurant& Restaurant::operator=(const Restaurant& rest){
    if(this == &rest){return *this;};
    delete[] m_name;
    m_name = new char[strlen(rest.m_name)+1];
    if(m_name == NULL){
        cout << "ERROR!"; ///////////////////////change later
    }

    strcpy(m_name, rest.m_name);

    delete m_street;

    m_street = rest.m_street; /////////////need to implement = operator

    m_menu = rest.m_menu; /////////////////need to implement = operator


return *this;
}

Restaurant::~Restaurant()
{
}
