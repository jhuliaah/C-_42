
#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called." << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called." << std::endl;
	type = other.type;
	brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this != &other)
	{
		type = other.type;
		if (brain)
			*brain = *other.brain;
		else
			brain = new Brain(*other.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
	delete brain;
}

void	Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}

Brain*	Cat::getBrain() const
{
	return (brain);
}