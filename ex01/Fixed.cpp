/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:04:06 by tjorge-l          #+#    #+#             */
/*   Updated: 2025/06/09 15:53:54 by tjorge-l         ###   ########.fr       */
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
	if (i > OVERFLOW_MAX || i < OVERFLOW_MIN)
	{
		this->_fixed = 0;
		std::cerr << "Overflow detected. Setting it to 0." << std::endl;
		return ;
	}
	this->_fixed = roundf(i * SCALE);
	return ;
}

Fixed::Fixed(const float i)
{
	std::cout << "Float constructor called" << std::endl;
	if (i > OVERFLOW_MAX || i < OVERFLOW_MIN)
	{
		this->_fixed = 0;
		std::cerr << "Overflow detected. Setting it to 0." << std::endl;
		return ;
	}
	this->_fixed = roundf(i * SCALE);
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

float	Fixed::toFloat(void) const
{
	return (this->_fixed / SCALE_F);
}

int		Fixed::toInt(void) const
{
	return (roundf(this->_fixed / SCALE));
}
// Alternative _fixed >> _fract_bits

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

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}
