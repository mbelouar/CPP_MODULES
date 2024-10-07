#include "iter.hpp"

int main() {
    int i_array[] = {1, 2, 0, 9, 8};
    int i_len = sizeof(i_array) / sizeof(i_array[0]);

    iter(i_array, i_len, addElement<int>);

    std::cout << "\n======================" << std::endl;

    float   f_array[] = {3.23, 1.11, 88.30, 7.90};
    int     f_len = sizeof(f_array) / sizeof(f_array[0]);

    iter(f_array, f_len, printElement<float>);

    std::cout << "\n======================" << std::endl;

    char    c_array[] = {'a', 'z', 'e', 'r', 't', 'y'};
    int     c_len = sizeof(c_array) / sizeof(c_array[0]);

    iter(c_array, c_len, upperElement<char>);
}