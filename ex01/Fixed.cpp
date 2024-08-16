/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:23:55 by yowoo             #+#    #+#             */
/*   Updated: 2024/08/16 13:19:29 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():fpval(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed &anothercl)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = anothercl;
};

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fpval = (num << this->frac_bits);
};

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->fpval = roundf(num * (1 << this->frac_bits));		
};

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;;
	if (this == &other){
		return *this;
	}
	this->fpval = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;;
	return fpval;
}

void Fixed::setRawBits( int const raw )
{
	fpval = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->fpval /(1 << this->frac_bits));
};

int Fixed::toInt(void) const
{
	return (this->fpval /(1 << this->frac_bits));
};

std::ostream& operator <<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return (out);
};
