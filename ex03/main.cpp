#include <iostream>
#include <cmath>

class Fixed {
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed& fixed);
        Fixed& operator=(const Fixed& fixed);
        ~Fixed();

        Fixed(const int toConvert);
        Fixed(const float toConvert);

        float toFloat(void) const;
        int toInt(void) const;

        bool    operator>(const Fixed& fixed) const;
        bool    operator<(const Fixed& fixed) const;
        bool    operator>=(const Fixed &fixed) const;
        bool    operator<=(const Fixed &fixed) const;
        bool    operator==(const Fixed& fixed) const;
        bool    operator!=(const Fixed& fixed) const;

        Fixed operator+(const Fixed&  fixed) const;
        Fixed operator-(const Fixed&  fixed) const;
        Fixed operator/(const Fixed&  fixed) const;
        Fixed operator*(const Fixed&  fixed) const;

        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);
      
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};
    
std::ostream& operator<<(std::ostream &os, const Fixed &fixed);


Fixed::Fixed() : fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float toConvert) {
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(toConvert * (1 << this->fractionalBits));
}

Fixed::Fixed(const Fixed& fixed) {
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPointValue = fixed.fixedPointValue;
}

Fixed::Fixed(const int toConvert) {
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = toConvert << this->fractionalBits;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed&  Fixed::operator=(const Fixed& fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        fixedPointValue = fixed.fixedPointValue;
    return (*this);
}

float   Fixed::toFloat(void) const {
    return ((float)this->fixedPointValue / (1 << this->fractionalBits));
}

int Fixed::toInt(void) const {
    return (this->fixedPointValue >> this->fractionalBits);
}

bool    Fixed::operator>(const Fixed& fixed) const {
    return (this->fixedPointValue > fixed.fixedPointValue);
}

bool    Fixed::operator<(const Fixed& fixed) const {
    return (this->fixedPointValue < fixed.fixedPointValue);
}

bool    Fixed::operator>=(const Fixed& fixed) const {
    return (fixedPointValue >= fixed.fixedPointValue);
}

bool    Fixed::operator<=(const Fixed& fixed) const {
    return (fixedPointValue <= fixed.fixedPointValue);
}

bool    Fixed::operator==(const Fixed& fixed) const {
    return (this->fixedPointValue == fixed.fixedPointValue);
}

bool    Fixed::operator!=(const Fixed& fixed) const {
    return (this->fixedPointValue != fixed.fixedPointValue);
}

Fixed Fixed::operator+(const Fixed& fixed) const {
    return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed& fixed) const {
    return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed& fixed) const {
    return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed& fixed) const {
    if (fixed.toFloat() == 0)
        return (Fixed(0));
    return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed& Fixed::operator++(void) {
    this->fixedPointValue++;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed result(*this);
    this->fixedPointValue++;
    return (result);
}

Fixed& Fixed::operator--(void) {
    this->fixedPointValue--;
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed result(*this);
    this->fixedPointValue--;
    return (result);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b ? a: b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b ? a: b);
}


Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b ? a: b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b ? a: b);
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return (os);
}

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}