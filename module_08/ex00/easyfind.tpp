template<typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator iterator(std::find(container.begin(), container.end(), value));
    if (iterator == container.end())
        throw std::runtime_error("Value not found in this container");
    return iterator;
}

template<typename T>
typename T::const_iterator easyfind(const T& container, int value) {
    typename T::const_iterator iterator(std::find(container.begin(), container.end(), value));
    if (iterator == container.end())
        throw std::runtime_error("Value not found in this container");
    return iterator;
}