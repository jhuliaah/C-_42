
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>


Class Animal
{
	protected:
		std::string type;

	public:

	Animal();
	Animal(const Animal &other);
	virtual	~Animal();

	virtual void	makeSound(const);
	const std::string	getType() const;
};

#endif