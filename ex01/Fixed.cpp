#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called\n";
        *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        _value = other.getRawBits();
    return *this;
}

Fixed::Fixed(int const value)
{
    std::cout << "Int constructor called\n";
    _value = value << _fractional_bits;
}

Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called\n";
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

std::ostream & operator<<(std::ostream & o, Fixed const & input)
{
    o << input.toFloat();
    return (o);
}