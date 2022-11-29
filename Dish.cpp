#include "Dish.h"
using namespace std;

 char type0[] = "Appetizer", type1[] = "Main Course", type2[] = "Dessert";
char* types[] = {type0,type1,type2};

Dish::Dish():
    m_name(NULL),m_type(Appetizer),m_value(-1)
{

}
Dish::Dish(const char *name, DishType type, int value)
{
    m_name = _strdup(name);
    m_type = type;
    m_value = value;
}

Dish::Dish(const Dish &source)
{

    if (source.m_name == NULL)
    {
        m_name = NULL;
    }
    else
    {
        m_name = _strdup(source.m_name);
    }
        m_type = source.m_type;
        m_value = source.m_value;
}

Dish::~Dish()
{
    delete[] m_name;
}

Dish &Dish::operator=(const Dish &source)
{

    if (this == &source){return *this;};
    m_name = _strdup(source.m_name);
    m_type = source.m_type;
    m_value = source.m_value;
    return *this;

}

char* Dish::getType(){
return types[m_type];
}


