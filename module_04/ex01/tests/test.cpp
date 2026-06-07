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

TEST(TestAnimal, TestBrainFeature) {
    std::cout << "NEW TEST" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    #define ANIMALS_ARRAY 10
    Animal *animals[ANIMALS_ARRAY];
    for (std::size_t index = 0; index < ANIMALS_ARRAY / 2; index++) {
        animals[index] = new Cat();
    }
    for (std::size_t index = ANIMALS_ARRAY / 2 ; index < ANIMALS_ARRAY; index++) {
        animals[index] = new Dog();
    }
    for (std::size_t index = 0; index < ANIMALS_ARRAY; index++) {
        if (animals[index])
            delete animals[index];
    }
}

TEST(TestCat, TestCatBrainCopy) {
    Cat cat = Cat();
    Cat meow = Cat(cat);

    ASSERT_NE(cat.getBrain(), meow.getBrain());
}

TEST(TestDog, TestDogCopy) {
    Dog dog = Dog();
    Dog woof = Dog(dog);

    ASSERT_NE(dog.getBrain(), woof.getBrain());
}

TEST(TestCat, TestSameIdea) {
    Cat cat = Cat();
    Cat meow = Cat(cat);

    cat.getBrain()->setIdea("eating", 0);
    meow.getBrain()->setIdea("eating", 0);
    ASSERT_EQ(cat.getBrain()->getIdea(0), meow.getBrain()->getIdea(0));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}