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

const std::vector<int> &PmergeMe::getVector() const {
    return _vec;
}

const std::list<int> &PmergeMe::getList() const {
    return _list;
}

bool PmergeMe::addNumberToContainers(int number) {
    bool vectFind = std::find(_vec.begin(), _vec.end(), number) != _vec.end();
    bool listFind = std::find(_list.begin(), _list.end(), number) != _list.end();

    if (vectFind || listFind) {
        return false;
    } else {
        this->_vec.push_back(number);
        this->_list.push_back(number);
        return true;
    }
}

void PmergeMe::merge(int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (int i = 0; i< n1; i++) {
        L[i] = _vec[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = _vec[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            _vec[k] = L[i];
            i++;
        } else {
            _vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        _vec[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        _vec[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::sortVectorUsingMerge(int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        sortVectorUsingMerge(left, middle);
        sortVectorUsingMerge(middle + 1, right);
        merge(left, middle, right);
    }
}

bool is_number(const std::string &s) {
    if (s.empty())
        return false;
    size_t start = 0;

    if (s[0] == '-' || s[0] == '+') {
        if (s.length() == 1)
            return false;
        start = 1;
    }

    for (size_t i = start; i < s.length(); i++) {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

void PmergeMe::start(char **argv) {
    int i = 1;
    while (argv[i]) {
        std::string arg = argv[i];
        if (!is_number(arg)) {
            std::cout << "Error: Invalid input." << std::endl;
            return;
        }
        int number = std::stoi(arg);
        if (!addNumberToContainers(number)) {
            std::cout << "Error: Number " << number << " already exists in the containers." << std::endl;
            return;        
        }
        i++;
    }
    // print the vector
    const std::vector<int>& vec = getVector();
    std::cout << "Before: ";
    for(std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    if (vec.size() == 2 && vec[0] > vec[1]) {
        std::swap(_vec[0], _vec[1]);
    } else if (vec.size() > 2) {
        sortVectorUsingMerge(0, vec.size() - 1);
    }
    std::cout << std::endl;
    // print the vector
    std::cout << "After : ";
    for(std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
