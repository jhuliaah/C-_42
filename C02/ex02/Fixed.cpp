
#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << _fractionalBits;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value*(1<<_fractionalBits));
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy Constructor called" << std::endl;
	this->_value = src._value;
}

Fixed::~Fixed(void)
{
	std::cout << "Default destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = src._value;
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

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->_value > rhs._value);
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (this->_value < rhs._value);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_value >= rhs._value);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_value <= rhs._value);
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return (this->_value == rhs._value);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_value != rhs._value);
}

Fixed &Fixed::operator++( void )
{
	++this->_value;
	return *this;
}

Fixed Fixed::operator++( int )
{
	Fixed temp = *this;
	this->_value++;
	return temp;
}

Fixed &Fixed::operator--( void )
{
	--this->_value;
	return *this;
}

Fixed Fixed::operator--( int )
{
	Fixed temp = *this;
	this->_value--;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}


Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits(this->_value + rhs._value);
	return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits(this->_value - rhs._value);
	return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits(this->_value * rhs._value);
	return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	Fixed result;
	if (rhs._value == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return result;
	}
	long numerator = (long)this->_value << _fractionalBits;
	long result_raw = numerator / rhs._value;
	result.setRawBits((int)result_raw);
	return result;
}