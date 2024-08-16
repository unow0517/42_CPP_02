/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:24:21 by yowoo             #+#    #+#             */
/*   Updated: 2024/08/16 12:43:17 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int fpval;
	const static int frac_bits = 8;
public:
	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed &anothercl);

	Fixed(const int num);
	Fixed(const float num);
	
	Fixed& operator=(const Fixed& other);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat(void) const;
	int toInt(void) const;

};

std::ostream& operator <<(std::ostream &out, Fixed const &fixed);
