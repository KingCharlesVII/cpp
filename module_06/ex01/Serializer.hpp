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