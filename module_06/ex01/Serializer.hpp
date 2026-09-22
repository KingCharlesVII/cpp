/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:33:01 by gmurzi            #+#    #+#             */
/*   Updated: 2026/09/22 11:33:02 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stdint.h>
#include <cstdlib>
#include <string>

struct Data {
    std::string key;
    std::size_t value;
};

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer& other);
        ~Serializer();
        Serializer& operator=(const Serializer& other);
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *unserialize(uintptr_t raw);
};
