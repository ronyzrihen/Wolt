#include "Menu.h"
using namespace std;




Menu::Menu(Dish* dish_list, int size )
{
int i = 0;
m_dishes = new Dish[size];
if(m_dishes == NULL){
    cout << "ERROR"; ///////////////need 2 decide what to do here
}
for(int i = 0 ; i < size ; i++){
    m_dishes[i] = dish_list[i];
}
m_size = size;
}

Menu::~Menu()
{
delete[] m_dishes;
}

Menu& Menu::operator=(const Menu& source){

    if(this == &source)
        return *this;

    if (m_size == source.m_size){
        for(int i = 0 ; i < m_size; i++){
            m_dishes[i] = source.m_dishes[i];
        }
        return *this;
    }

    delete[] m_dishes;
    m_size = source.m_size;
    
    m_dishes = new Dish[m_size];
    if(m_dishes == NULL){
        cout << "ERROR"; ///////need 2 decide what to do here
    }

    for(int i = 0 ; i < m_size ; i++){
        m_dishes[i] = source.m_dishes[i];
    } 

    return *this;
}
