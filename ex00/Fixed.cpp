/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:23:55 by yowoo             #+#    #+#             */
/*   Updated: 2024/08/13 18:26:55 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(int val):fpval(val){};
Fixed::Fixed(const Fixed &anothercl):fpval(anothercl.fpval),frac_bits(anothercl.frac_bits){};
Fixed::~Fixed(){};
Fixed& Fixed::operator=(const Fixed& other)
{
	if (this == &other){
		return *this;
	}
	fpval = other.fpval;
	return *this;
}

int Fixed::getRawBits( void ) const{
	
}
