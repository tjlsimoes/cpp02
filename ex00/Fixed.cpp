/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l < tjorge-l@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:04:06 by tjorge-l          #+#    #+#             */
/*   Updated: 2025/05/09 17:12:12 by tjorge-l         ###   ########.fr       */
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

// Is this Copy Constructor correct? Shouldn't it be:
// Fixed::Fixed(Fixed const & src) : _fixed(src._fixed)
// {
// 	std::cout << "Copy constructor called" << std::endl;
// 	return ;
// }

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixed = rhs.getFixed();
		// this->_fixed = rhs._fixed; // Need to implement get_fixed()
	// this->getRawBits();
	return (*this);
}

int		Fixed::getFixed(void) const
{
	return (this->_fixed);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fract_bits);
}

const int Fixed::_fract_bits = 8;