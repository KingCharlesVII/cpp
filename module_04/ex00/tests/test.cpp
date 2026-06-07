#include <gtest/gtest.h>
#include <string>
#include "animal.hpp"

namespace color_test{
    std::string red = "\033[31m";
    std::string reset = "\033[0m";
}

TEST(TestCat, TestMakeSound) {
    Cat cat = Cat();
    cat.makeSound();
}

TEST(TestCat, TestName) {
    Cat cat = Cat();
    ASSERT_EQ(cat.getType(), "Cat");
}

TEST(TestDog, TestMakeSound) {
    Dog dog = Dog();
    dog.makeSound();
}

TEST(TestDog, TestName) {
    Dog dog = Dog();
    ASSERT_EQ(dog.getType(), "Dog");
}

TEST(TestAnimal, TestAllTogether) {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
}

TEST(TestWrongAnimal, TestWrongCat) {
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* i = new WrongCat();
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    meta->makeSound();
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}