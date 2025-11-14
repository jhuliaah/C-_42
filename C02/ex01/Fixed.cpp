
#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

FIxed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << _fractionalBits;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value*(1<<_fractionalBits));
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy Constructor called" << std::endl;
	this->_value = src.value;
}

Fixed::~Fixed(void)
{
	std::cout << "Default destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = src.value;
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
	return;
}

float Fixed::toFloat(void) const
{
	return((float)this->_value / (1 <<_fractionalBits));
}

int Fixed::toInt(void) const
{
	return(this->_value >> _fractionalBits);
}

std::ostream& operato<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}

/*
** OPERATOR OVERLOADING & STREAM INSERTION OPERATOR (<<)
**
** 1. What is Operator Overloading?
** It's a C++ feature that allows re-defining the behavior of existing
** operators (like +, -, *, or <<) when applied to custom class objects.
** It makes the code more intuitive (e.g., using 'a + b' instead of 'a.add(b)').
**
** 2. Purpose of operator<<:
** This function overrides the stream insertion operator (<<) for the Fixed class.
** It is implemented as a non-member (global) function because the 'std::ostream'
** (e.g., std::cout) is on the left side.
**
** 3. Conversion Mechanism:
** - The function receives the output stream (os) and the Fixed object (obj).
** - It ensures that the Fixed number is printed in a human-readable, floating-point
** format by explicitly calling the 'obj.toFloat()' method before inserting the
** value into the stream.
** - Returning the stream reference (os) is crucial for chaining operations (e.g., cout << a << b).

To multiply a number by 2 in bits, you only need to shift the bytes to the left one time ( 1 << 1),
meaning, you are bringing the number 1 to the position 1; == 2 to the power of 1;
( 1 << 2) this brings the 1 to the position 2; == 2 to the power of 2;

((float)this->_value / (1 << _fractionalBits)) ==>> isso aqui é uma fração
Pensa comigo, ele vai pegar um valor e dividir ele por 2 elevado a uma potência, por exemplo
_value = 5;
_fractionalBits = 3
A conta final vai ser => 5 / 2³ => 5 / 8 => 0,25
*/