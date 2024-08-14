/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:23:55 by yowoo             #+#    #+#             */
/*   Updated: 2024/08/14 16:30:44 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():fpval(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &anothercl)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fpval = anothercl.getRawBits();
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;;
	if (this == &other){
		return *this;
	}
	fpval = other.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;;
	return fpval;
}

void Fixed::setRawBits( int const raw )
{
	fpval = raw;
}