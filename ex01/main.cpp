/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:03:59 by tjorge-l          #+#    #+#             */
/*   Updated: 2025/06/09 15:53:20 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include <iostream>

int	main(void)
{
	// Test C
	Fixed const		a(8388607);
	Fixed const		b(-8388608);
	Fixed const		c(8388609);
	Fixed const		d(-8388609);

	std::cout << "a is " << a.toInt() << " as an Integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as an Integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as an Integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as an Integer" << std::endl;

	// Test B
	// Fixed const		a(8388607.0f);
	// Fixed const		b(-8388608.0f);
	// Fixed const		c(8388609.0f);
	// Fixed const		d(-8388610.0f);

	// std::cout << "a is " << a.toInt() << " as an Integer" << std::endl;
	// std::cout << "b is " << b.toInt() << " as an Integer" << std::endl;
	// std::cout << "c is " << c.toInt() << " as an Integer" << std::endl;
	// std::cout << "d is " << d.toInt() << " as an Integer" << std::endl;

	// Test A
	// Fixed			a;
	// Fixed const		b(10);
	// Fixed const		c(42.42f);
	// Fixed const		d(b);

	// a = Fixed(1234.4321f);

	// std::cout << "a is " << a << std::endl;
	// std::cout << "b is " << b << std::endl;
	// std::cout << "d is " << c << std::endl;
	// std::cout << "c is " << d << std::endl;

	// std::cout << "a is " << a.toInt() << " as an Integer" << std::endl;
	// std::cout << "b is " << b.toInt() << " as an Integer" << std::endl;
	// std::cout << "c is " << c.toInt() << " as an Integer" << std::endl;
	// std::cout << "d is " << d.toInt() << " as an Integer" << std::endl;

	return (0);
}
