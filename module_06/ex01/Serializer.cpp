/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:32:54 by gmurzi            #+#    #+#             */
/*   Updated: 2026/09/22 11:32:55 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
    std::cout << "Default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& other) {
    std::cout << "Copy constructor called" << std::endl;
    (void)other;
}

Serializer& Serializer::operator=(const Serializer& other) {
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &other) {
        return *this;
    }
    std::cout << "Warning: objects refer to the same address" << std::endl;
    return *this;
}

Serializer::~Serializer() {
    std::cout << "Destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::unserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}
