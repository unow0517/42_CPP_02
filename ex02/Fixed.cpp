/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:23:55 by yowoo             #+#    #+#             */
/*   Updated: 2024/08/18 13:33:13 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructors
Fixed::Fixed():fpval(0)
{
};

Fixed::Fixed(const Fixed &anothercl)
{
	*this = anothercl;
};

Fixed::Fixed(const int num)
{
	this->fpval = (num << this->frac_bits);
};

Fixed::Fixed(const float num)
{
	this->fpval = roundf(num * (1 << this->frac_bits));		
};

//Destructor
Fixed::~Fixed()
{
};

//Getter
int Fixed::getRawBits( void ) const
{
	return fpval;
}

//Setter
void Fixed::setRawBits( int const raw )
{
	fpval = raw;
}

//Converters
float Fixed::toFloat(void) const
{
	return ((float)this->fpval /(1 << this->frac_bits));
};

int Fixed::toInt(void) const
{
	return (this->fpval /(1 << this->frac_bits));
};

//Operators
Fixed& Fixed::operator=(const Fixed& other)
{
	if (this == &other){
		return *this;
	}
	this->fpval = other.getRawBits();
	return (*this);
}

std::ostream& operator <<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return (out);
};

bool	Fixed::operator>(const Fixed& other)
{
	if (this->getRawBits() > other.getRawBits()){
		return 1;
	}
	else
		return 0;
};

bool	Fixed::operator<(const Fixed& other)
{
	if (this->getRawBits() < other.getRawBits()){
		return 1;
	}
	else
		return 0;
};

bool	Fixed::operator>=(const Fixed& other)
{
	if (this->getRawBits() >= other.getRawBits()){
		return 1;
	}
	else
		return 0;
};

bool	Fixed::operator<=(const Fixed& other)
{
	if (this->getRawBits() <= other.getRawBits()){
		return 1;
	}
	else
		return 0;
};

bool	Fixed::operator==(const Fixed& other)
{
	if (this->getRawBits() == other.getRawBits()){
		return 1;
	}
	else
		return 0;
};

bool	Fixed::operator!=(const Fixed& other)
{
	if (this->getRawBits() != other.getRawBits()){
		return 1;
	}
	else
		return 0;
};

Fixed Fixed::operator+(const Fixed& other)
{
	Fixed result(this->toFloat() + other.toFloat());
	return (result);
};

Fixed Fixed::operator-(const Fixed& other)
{
	Fixed result(this->toFloat() - other.toFloat());
	return (result);
};

Fixed Fixed::operator*(const Fixed& other)
{
	Fixed result(this->toFloat() * other.toFloat());
	return (result);
};

Fixed Fixed::operator/(const Fixed& other)
{
	Fixed result( this->toFloat() / other.toFloat());
	return (result);
};

//post-increment,decrement
const Fixed Fixed::operator++(int)
{
	const Fixed res(*this);
	
	this->fpval++;
	return (res);
}

const Fixed Fixed::operator--(int)
{
	const Fixed res(*this);
	
	this->fpval--;
	return (res);
}

//pre-increment,decrement
Fixed& Fixed::operator++(void)
{
	this->fpval++;

	return (*this);	
}

Fixed& Fixed::operator--(void)
{
	this->fpval--;
	return (*this);	
}

//Min,Max
Fixed & Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() <= f2.getRawBits())
		return (f1);
	else
		return (f2);
};

const Fixed & Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() <= f2.getRawBits())
		return (f1);
	else
		return (f2);
}

Fixed & Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() >= f2.getRawBits())
		return (f1);
	else
		return (f2);
};

const Fixed & Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() >= f2.getRawBits())
		return (f1);
	else
		return (f2);
}

