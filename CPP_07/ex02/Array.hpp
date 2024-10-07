#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename T>
class   Array {

    private:
        T* elements;
        unsigned int length;

    public:
        Array() : elements(nullptr), length(0) {}
        
        Array(unsigned int n);
        Array(Array const &src);
        Array &operator=(Array const &src);

        ~Array() {
            delete[] elements;
        }

        T& operator[](unsigned int index) {
            if (index >= length) {
                throw std::out_of_range("Index out of bounds");
            }
            return elements[index];
        }

        const T& operator[](unsigned int index) const {
            if (index >= length) {
                throw std::out_of_range("Index out of bounds");
            }
            return elements[index];
        }

        unsigned int size() const {
            return length;
        }
};

#endif