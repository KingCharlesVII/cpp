#include <iostream>
#include <cmath>

class Fixed {
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed& fixed);
        Fixed(const int toConvert);
        Fixed(const float toConvert);
        ~Fixed();
        Fixed& operator=(const Fixed& fixed);
        int getRawBits(void) const;
        void setRawBits(const int raw);
        float toFloat(void) const;
        int toInt(void) const;
    };
    
std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->fixedPointValue = 0;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedPointValue);
}

void Fixed::setRawBits(const int raw) {
    this->fixedPointValue = raw;
}

Fixed&  Fixed::operator=(const Fixed& fixed) {
    std::cout << "Copy asignment operator called" << std::endl;
    this->setRawBits(fixed.getRawBits());
    return (*this);
}

float   Fixed::toFloat(void) const {
    return ((float)this->fixedPointValue / (1 << this->fractionalBits));
}

int Fixed::toInt(void) const {
    return (this->fixedPointValue >> this->fractionalBits);
}

Fixed::Fixed(const Fixed& fixed) {
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPointValue = fixed.getRawBits();
}

Fixed::Fixed(const int toConvert) {
    std::cout << "Int constuctor called" << std::endl;
    this->fixedPointValue = toConvert << this->fractionalBits;
}

Fixed::Fixed(const float toConvert) {
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(toConvert * (1 << this->fractionalBits));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return (os);
}

int     main(void) {
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}