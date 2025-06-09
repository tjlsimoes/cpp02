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
# define SCALE 256
# define SCALE_F 256.0
# define OVERFLOW_MAX 8388607
# define OVERFLOW_MIN -8388608

class Fixed
{
	private:
		int					_fixed;
		static const int	_fract_bits;
	
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