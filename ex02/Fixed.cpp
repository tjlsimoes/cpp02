/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:04:06 by tjorge-l          #+#    #+#             */
/*   Updated: 2025/06/09 17:38:57 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed(void) : _fixed(0)	// Default Constructor
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & src)	// Copy Constructor
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	if (i > Fixed::overflowMax() || i < Fixed::overflowMin() )
	{
		this->_fixed = 0;
		std::cerr << "Overflow detected. Setting it to 0." << std::endl;
		return ;
	}
	this->_fixed = roundf(i * Fixed::scale());
	return ;
}

Fixed::Fixed(const float i)
{
	std::cout << "Float constructor called" << std::endl;
	if (i > Fixed::overflowMax() || i < Fixed::overflowMin() )
	{
		this->_fixed = 0;
		std::cerr << "Overflow detected. Setting it to 0." << std::endl;
		return ;
	}
	this->_fixed = roundf(i * Fixed::scale());
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixed = rhs.getRawBits();
	return (*this);
}

int	Fixed::scale()
{
	return (1 << Fixed::_fract_bits);
}

float	Fixed::scaleFloat()
{
	return (static_cast<float>(1 << Fixed::_fract_bits));
}

float	Fixed::overflowMax()
{
	return (static_cast<float>((1 << (32 - Fixed::_fract_bits - 1)) - 1));
}

float	Fixed::overflowMin()
{
	return (static_cast<float>(-(1 << (32 - Fixed::_fract_bits - 1))));
}
float	Fixed::toFloat(void) const
{
	return (this->_fixed / Fixed::scaleFloat());
}

int		Fixed::toInt(void) const
{
	return (roundf(this->_fixed / Fixed::scale()));
}
// Alternative _fixed >> _fract_bits

bool	Fixed::operator>(Fixed const & rhs)
{
	if (this->_fixed > rhs._fixed)
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const & rhs)
{
	if (this->_fixed < rhs._fixed)
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const & rhs)
{
	if (this->_fixed >= rhs._fixed)
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const & rhs)
{
	if (this->_fixed <= rhs._fixed)
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const & rhs)
{
	if (this->_fixed == rhs._fixed)
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const & rhs)
{
	if (this->_fixed != rhs._fixed)
		return (true);
	return (false);
}

Fixed	Fixed::operator+(Fixed const & rhs)
{
	Fixed	result;

	result = *this;
	result._fixed = this->_fixed + rhs._fixed;
	return (result);
}

Fixed	Fixed::operator-(Fixed const & rhs)
{
	Fixed	result;

	result = *this;
	result._fixed = this->_fixed - rhs._fixed;
	return (result);
}

Fixed	Fixed::operator*(Fixed const & rhs)
{
	Fixed	result;

	result._fixed = (this->_fixed * rhs._fixed) / Fixed::scale();
	return (result);
}

Fixed	Fixed::operator/(Fixed const & rhs)
{
	Fixed	result;

	result = *this;
	result._fixed = (this->_fixed / rhs._fixed) * Fixed::scale();
	return (result);
}

// Sufix ++
Fixed	Fixed::operator++(int)
{
	Fixed	temp;

	temp = *this;
	this->_fixed += 1;
	return (temp);
}

// Prefix ++
Fixed &	Fixed::operator++()
{
	this->_fixed += 1;
	return (*this);
}

// Sufix --
Fixed 	Fixed::operator--(int)
{
	Fixed	temp;

	temp = *this;
	this->_fixed -= 1;
	return (temp);
}

// Prefix --
Fixed &	Fixed::operator--()
{
	this->_fixed -= 1;
	return (*this);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed = raw;
	return ;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed);
}

const int Fixed::_fract_bits = 8;

Fixed &			Fixed::min(Fixed & a, Fixed & b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed const &	Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed &			Fixed::max(Fixed & a, Fixed & b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

Fixed const &	Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}
