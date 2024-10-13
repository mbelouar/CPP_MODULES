#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::Span(Span const &src) {
    *this = src;
}

Span &Span::operator=(Span const &src) {
    if (this != &src) {
        this->_n = src._n;
        this->_v = src._v;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
    if (_v.size() == this->_n) {
        throw FullSpanException();
    }
    _v.push_back(n);
}

int Span::shortestSpan() {
    if (_v.size() < 2) {
        throw NoSpanException();
    }
    std::vector<int> vect = _v;
    std::sort(vect.begin(), vect.end());
    int min = vect[1] - vect[0];
    for (std::vector<int>::iterator it = vect.begin(); it != vect.end() - 1; it++) {
        if (min > *(it + 1) - *it) {
            min = *(it + 1) - *it;
        }
    }
    return min;
}

int Span::longestSpan() {
    if (_v.size() < 2) {
        throw NoSpanException();
    } 
    std::vector<int> vect = _v;
    std::sort(vect.begin(), vect.end());
    return vect[vect.size() - 1] - vect[0];
}

void Span::addRange(std::vector<int>::iterator first, std::vector<int>::iterator last) {
    while (first != last) {
        addNumber(*first);
        ++first;
    }
}

const char *Span::FullSpanException::what() const throw() {
    return "Exception: Span is full!";
}

const char *Span::NoSpanException::what() const throw() {
    return "Exception: No span to find!";
}