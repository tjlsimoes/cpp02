/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:03:59 by tjorge-l          #+#    #+#             */
/*   Updated: 2025/06/09 17:39:18 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include <iostream>

int	main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;



	Fixed d(42.42f);
	Fixed c(42.42f);

	// Uses non-const min(Fixed&, Fixed&)
	std::cout << Fixed::min(a, d) << std::endl;

	// Uses const max(const Fixed&, const Fixed&)
    std::cout << Fixed::max(c, d) << std::endl;

	// Uses const min(const Fixed&, const Fixed&)
    std::cout << Fixed::min(c, d) << std::endl;

	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;

	return (0);
}
