#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T, typename F>
void    iter(T* array, int len, F func) {
    for (int i = 0; i < len; i++) {
        std::cout << func(array[i]) << " ";
    }
}

template <typename T>
T printElement(T const& elem) {
    return elem;
}

template <typename T>
T   addElement(T const& elem) {
    return elem + 10;
}

template <typename T>
T   upperElement(T const& elem) {
    return elem - 32;
}

#endif