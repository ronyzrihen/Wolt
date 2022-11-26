#pragma once

typedef enum {Appetizer,MainCourse,Dessert}DishType;

class Dish
{
public:
	Dish();
	~Dish();

private:
	DishType type;
	int value;
};

Dish::Dish()
{
}

Dish::~Dish()
{
}
