#include <iostream>

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
        void    operator<<(void) const;
        int getRawBits(void) const;
        void setRawBits(const int raw);
        float toFloat(void) const;
        int toInt(void) const;
};

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
s
Fixed&  Fixed::operator=(const Fixed& fixed) {
    std::cout << "Copy asignment operator called" << std::endl;
    this->setRawBits(fixed.getRawBits());
    return (*this);
}

Fixed::Fixed(const Fixed& fixed) {
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPointValue = fixed.getRawBits();
}

Fixed::Fixed(const int toConvert) {
    std::cout << "Int constuctor called" << std::endl;
    (void)toConvert;
}

Fixed::Fixed(const float toConvert) {
    std::cout << "Float constructor called" << std::endl;
    (void)toConvert;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

float   Fixed::toFloat(void) const {
    return (0.0);
}

int Fixed::toInt(void) const {
    return (0);
}

void    Fixed::operator<<(void) const {

}

int     main(void) {
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
}