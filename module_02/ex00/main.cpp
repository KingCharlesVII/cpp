#include <iostream>

class Fixed {
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed& fixed);
        ~Fixed();
        Fixed& operator=(const Fixed& fixed);
        int getRawBits(void) const;
        void setRawBits(const int raw);
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

Fixed&  Fixed::operator=(const Fixed& fixed) {
    std::cout << "Copy asignment operator called" << std::endl;
    this->setRawBits(fixed.getRawBits());
    return (*this);
}

Fixed::Fixed(const Fixed& fixed) {
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPointValue = fixed.getRawBits();
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
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