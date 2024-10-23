#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) : _vec(src._vec), _list(src._list) {
    *this = src;
}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe &src) {
    if (this != &src) {
        _vec = src._vec;
        _list = src._list;
    }
    return *this;
}

bool PmergeMe::addNumberToContainers(int number) {
    int vectFind = find(_vec.begin(), _vec.end(), number) != _vec.end();
    int listFind = find(_list.begin(), _list.end(), number) != _list.end();

    if (vectFind || listFind) {
        return false;
    } else {
        _vec.push_back(number);
        _list.push_back(number);
        return true;
    }
}

