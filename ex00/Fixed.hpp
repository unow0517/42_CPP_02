/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:24:21 by yowoo             #+#    #+#             */
/*   Updated: 2024/08/13 18:26:39 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed
{
private:
	int fpval;
	int frac_bits = 8;
public:
	Fixed(int val);
	Fixed(const Fixed &anothercl);
	~Fixed();

	Fixed& operator=(const Fixed& other);
	int getRawBits( void ) const;
};
