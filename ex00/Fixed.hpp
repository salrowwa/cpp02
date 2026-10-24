#include <iostream>

class Fixed
{
private:
    int _int_part;
    static const int _fractional_bits = 8;

public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);

    int getRawBits(void) const;
    void setRawBits(int const raw);

};

