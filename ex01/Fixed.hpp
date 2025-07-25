/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:04:01 by tjorge-l          #+#    #+#             */
/*   Updated: 2025/06/09 15:51:41 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <math.h>

class Fixed
{
	private:
		int					_fixed;
		static const int	_fract_bits;
		
		static	int	scale();
		static	float	scaleFloat();
		static	float	overflowMax();
		static	float	overflowMin();
	public:
		Fixed(void);							// Canonical: Default Constructor
		Fixed(Fixed const & src);				// Canonical: Copy Constructor
		Fixed(const int i);
		Fixed(const float i);
		~Fixed(void);							// Canonical: Destructor
	
	Fixed & operator=(Fixed const & rhs);		// Canonical: Copy Assignement Operator
	float	toFloat(void) const;
	int		toInt(void) const;
	void	setRawBits(int const raw);
	int		getRawBits(void) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif