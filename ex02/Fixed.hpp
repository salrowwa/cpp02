#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int                 _value;
        static const int    _fractional_bits;

    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);

        Fixed(int const num);
        Fixed(float const num);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
        
        Fixed &operator--();
        Fixed &operator++();
        Fixed operator--(int);
        Fixed operator++(int);

        bool operator==(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>(const Fixed& other) const;

        Fixed operator/(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator+(const Fixed& other) const;

        static Fixed& min(Fixed& a, Fixed& b);
        static Fixed const& min(Fixed const& a, Fixed const& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static Fixed const& max(Fixed const& a, Fixed const& b);

};

std::ostream & operator<<(std::ostream & o, Fixed const & input);

#endif