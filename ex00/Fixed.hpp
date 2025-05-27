/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:04:01 by tjorge-l          #+#    #+#             */
/*   Updated: 2025/05/27 10:56:01 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	private:
		int					_fixed;
		static const int	_fract_bits;
	
	public:
		Fixed(void);							// Canonical: Default Constructor
		Fixed(Fixed const & src);				// Canonical: Copy Constructor
		~Fixed(void);							// Canonical: Destructor
	
	Fixed & operator=(Fixed const & rhs);		// Canonical: Copy Assignement Operator
	void	setRawBits(int const raw);
	int		getRawBits(void) const;
};

#endif