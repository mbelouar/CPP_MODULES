#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename T>
class   Array {

    private:
        T*              elements;
        unsigned int    length;

    public:
        Array() : elements(nullptr), length(0) {}
        
        Array(unsigned int n) : length(n) {
            elements = new T[n];
        }

        Array(Array const &src) : elements(nullptr), length(src.length) {
            if (src.length > 0) {
                elements = new T[src.length];
                for (unsigned int i = 0; i < src.length; i++) {
                    elements[i] = src.elements[i];
                }
            }
        }

        Array &operator=(Array const &src) {
            if (this != &src) {
                if (elements) {
                    delete[] elements;
                }
                length = src.length;
                if (src.length > 0) {
                    elements = new T[src.length];
                    for (unsigned int i = 0; i < src.length; i++) {
                        elements[i] = src.elements[i];
                    }
                } else {
                    elements = nullptr;
                }
            }
            return *this;
        }

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