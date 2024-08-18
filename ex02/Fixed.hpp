/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:24:21 by yowoo             #+#    #+#             */
/*   Updated: 2024/08/18 13:12:32 by yowoo            ###   ########.fr       */
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
	
	bool	operator>(const Fixed& other);
	bool	operator<(const Fixed& other);
	bool	operator>=(const Fixed& other);
	bool	operator<=(const Fixed& other);
	bool	operator==(const Fixed& other);
	bool	operator!=(const Fixed& other);
	
	Fixed operator+(const Fixed& other);
	Fixed operator-(const Fixed& other);
	Fixed operator*(const Fixed& other);
	Fixed operator/(const Fixed& other);

	const Fixed operator++(int);
	const Fixed operator--(int);
	Fixed& operator++(void);
	Fixed& operator--(void);
	
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat(void) const;
	int toInt(void) const;

	static Fixed &min(Fixed &f1, Fixed &f2);
	static const Fixed &min(const Fixed &f1, const Fixed &f2);
	static Fixed &max(Fixed &f1, Fixed &f2);
	static const Fixed &max(const Fixed &f1, const Fixed &f2);

};

std::ostream& operator <<(std::ostream &out, Fixed const &fixed);
