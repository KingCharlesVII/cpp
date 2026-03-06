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
        bool    operator>(const Fixed& fixed) const;
        bool    operator<(const Fixed& fixed) const;
        bool    operator>=(const Fixed &fixed) const;
        bool    operator<=(const Fixed &fixed) const;
        bool operator==(const Fixed& fixed) const;
        bool operator!=(const Fixed& fixed) const;
        int getRawBits(void) const;
        void setRawBits(const int raw);
        int getFractionalBits(void) const;
        float toFloat(void) const;
        int toInt(void) const;
        static Fixed& min(Fixed& a, Fixed& b);
        const static Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        const static Fixed& max(const Fixed& a, const Fixed& b);
};
    
const Fixed operator+(const Fixed& a, const Fixed& b);
const Fixed operator-(const Fixed& a, const Fixed& b);
const Fixed operator/(const Fixed& a, const Fixed& b);
const Fixed operator*(const Fixed&a, const Fixed& b);
void operator++(Fixed& fixed);
void operator--(Fixed& fixed);

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

bool    Fixed::operator==(const Fixed& fixed) const {
    return (this->fixedPointValue == fixed.fixedPointValue);
}

bool    Fixed::operator!=(const Fixed& fixed) const {
    return (!(*this == fixed));
}

bool    Fixed::operator>(const Fixed& fixed) const {
    return (this->fixedPointValue > fixed.fixedPointValue);
}

bool    Fixed::operator<=(const Fixed& fixed) const {
    return (!(*this > fixed));
}

bool    Fixed::operator<(const Fixed& fixed) const {
    return ((!(*this > fixed)) && (*this != fixed));
}

bool    Fixed::operator>=(const Fixed& fixed) const {
    return (!(*this < fixed ));
}

int Fixed::getFractionalBits(void) const {
    return (this->fractionalBits);
}

const Fixed operator+(const Fixed& a, const Fixed& b) {
    Fixed addition;

    addition.setRawBits(a.toFloat() + b.toFloat());
    return (addition);
}

const Fixed operator-(const Fixed& a, const Fixed& b) {
    Fixed substraction;

    substraction.setRawBits(a.toInt() - b.toInt());
    return (substraction);
}

const Fixed operator/(const Fixed& a, const Fixed& b) {
    Fixed division;

    if (b.toInt() == 0)
        std::cerr << "Division zero error" << std::endl;
    division.setRawBits((a.toInt() / b.toInt()) / (1 << division.getFractionalBits()));
    return (division);
}

const Fixed operator*(const Fixed&a, const Fixed& b) {
    Fixed multiplication;

    multiplication.setRawBits((a.toInt() * b.toInt()) * (1 << multiplication.getFractionalBits()));
    return (multiplication);
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

int     main(void) {
    Fixed a(10);
    Fixed b(10);

    std::cout << a + b << std::endl;
    return 0;
}