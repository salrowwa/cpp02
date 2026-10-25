#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const Fixed& other)
{
    _value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        _value = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(int const value)
{
    _value = value << _fractional_bits;
}

Fixed::Fixed(float const value)
{
    _value = roundf(value * (1 << _fractional_bits));
}

int Fixed::getRawBits(void) const
{
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(_value) / (1 << _fractional_bits);
}

int Fixed::toInt(void) const
{
    return _value >> _fractional_bits;
}

bool Fixed::operator>(const Fixed& other) const
{
    return _value > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const
{
    return _value < other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const
{
    return _value != other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const
{
    return _value == other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const
{
    return _value >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const
{
    return _value <= other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed& Fixed::operator--()
{
    _value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    _value--;
    return temp;
}

Fixed& Fixed::operator++()
{
    _value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    _value++;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed const& Fixed::min(Fixed const& a, Fixed const& b)
{
   if (a < b)
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}

Fixed const& Fixed::max(Fixed const& a, Fixed const& b)
{
    if (a > b)
        return (a);
    return (b);
}

std::ostream & operator<<(std::ostream & o, Fixed const & input)
{
    o << input.toFloat();
    return (o);
}