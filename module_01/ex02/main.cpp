#include <iostream>
#include <string>

int main(void) {
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    std::cout << "Adrdess of brain     : " << &brain << std::endl;
    std::cout << "Address of stringPTR : " << stringPTR << std::endl;
    std::cout << "Address of stringREF : " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "Value of brain :" << brain << std::endl;
    std::cout << "Value pointed by PTR :" << *stringPTR << std::endl;
    std::cout << "Value by REF :" << stringREF << std::endl;


}