/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:22:46 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/13 12:22:48 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    {
        Cat cat = Cat();
        cat.makeSound();
    }
    {
        Dog dog = Dog();
        dog.makeSound();
    }
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
    }
    {
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
    {
        Cat cat = Cat();
        Cat meow = Cat(cat);
    }
    {
        Dog dog = Dog();
        Dog woof = Dog(dog);
    }
    {
        Cat cat = Cat();
        Cat meow = Cat(cat);
        cat.getBrain()->setIdea("eating", 0);
        meow.getBrain()->setIdea("eating", 0);
    }
}
