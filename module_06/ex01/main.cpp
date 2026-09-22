/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:32:43 by gmurzi            #+#    #+#             */
/*   Updated: 2026/09/22 11:32:44 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serializer.hpp"

void    printData(const Data& data) {
    std::cout << "adress: " << &data << std::endl;
    std::cout << "key: " << data.key << std::endl;
    std::cout << "value: " << data.value << std::endl;
}

int main() {
    {
        Data data1;

        data1.key = "book";
        data1.value = 10;

        printData(data1);

        Data data2;

        data2.key = "car";
        data2.value = 100000;
        printData(data2);

        uintptr_t s(Serializer::serialize(&data1));
        Data *r(Serializer::unserialize(s));
        
        printData(*r);
    }
}
