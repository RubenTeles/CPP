/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:46:51 by rteles            #+#    #+#             */
/*   Updated: 2023/01/30 01:06:58 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : rawBits(0) {}

Fixed::Fixed(float const value) : rawBits(roundf(value * (1 << this->factionalBit)))  {}

Fixed::Fixed(int const value) : rawBits(value << this->factionalBit)  {}

Fixed::Fixed( Fixed const & src)
{
    *this = src;
}

Fixed::~Fixed() {}

/*  Metods  */

int Fixed::getRawBits(void) const
{
    return this->rawBits;
}

void Fixed::setRawBits(int const raw)
{
    this->rawBits = raw;

    return ;
}

float Fixed::toFloat(void) const
{   
    return ((float) this->rawBits) / (1 << this->factionalBit);;   
}

int Fixed::toInt(void) const
{
    return this->rawBits >> this->factionalBit;;
}

/*  Operators   */

Fixed & Fixed::operator=(Fixed const & rhs)
{
    if (this != &rhs)
        this->setRawBits(rhs.getRawBits());

    return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
    o << i.toFloat();

    return o;
}

/*  Arithmetic Operators    */

Fixed   Fixed::operator+(Fixed const & rhs) const
{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed   Fixed::operator-(Fixed const & rhs) const
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed   Fixed::operator*(Fixed const & rhs) const
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed   Fixed::operator/(Fixed const & rhs) const
{
    return Fixed(this->toFloat() / rhs.toFloat());
}

/*  Comparison Operators    */

bool   Fixed::operator>(Fixed const & rhs) const
{
    return (this->getRawBits() > rhs.getRawBits());
}

bool   Fixed::operator<(Fixed const & rhs) const
{
    return (this->getRawBits() < rhs.getRawBits());
}

bool   Fixed::operator>=(Fixed const & rhs) const
{
    return (this->getRawBits() >= rhs.getRawBits());
}

bool   Fixed::operator<=(Fixed const & rhs) const
{
    return (this->getRawBits() <= rhs.getRawBits());
}

bool   Fixed::operator==(Fixed const & rhs) const
{
    return (this->getRawBits() == rhs.getRawBits());
}

bool   Fixed::operator!=(Fixed const & rhs) const
{
    return (this->getRawBits() != rhs.getRawBits());
}

/*  Increment/Decrement Operator*/

Fixed & Fixed::operator++(void)
{
    this->setRawBits(this->rawBits + 1);
    return *this;
}

Fixed & Fixed::operator--(void)
{
    this->setRawBits(this->rawBits - 1);
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);

    this->setRawBits(this->rawBits + 1);
    
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);

    this->setRawBits(this->rawBits - 1);

    return tmp;
}

/*  Min/Max */

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
    if (a < b)
        return a;
    return (b);
}

Fixed & Fixed::min(Fixed const & a, Fixed const & b)
{
    if (a < b)
        return (Fixed&) a;
    return (Fixed&) b;
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
    if (a > b)
        return a;
    return (b);
}

Fixed & Fixed::max(Fixed const & a, Fixed const & b)
{
    if (a > b)
        return (Fixed&) a;
    return (Fixed&) b;
}
