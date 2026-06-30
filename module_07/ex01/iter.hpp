#pragma once

#include <cstdlib>

template<typename A>
void iter(A *array, std::size_t length, void (*function)(A& parameter)) {
    if (!array || !function)
        return;
    for(std::size_t index(0); index < length; index++) {
        function(array[index]);
    }
}