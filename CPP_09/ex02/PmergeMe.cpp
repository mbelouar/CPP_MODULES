#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) : _vec(src._vec), _deq(src._deq) {
    *this = src;
}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe &src) {
    if (this != &src) {
        _vec = src._vec;
        _deq = src._deq;
    }
    return *this;
}

const std::vector<int> &PmergeMe::getVector() const {
    return _vec;
}

const std::deque<int> &PmergeMe::getDeque() const {
    return _deq;
}

bool PmergeMe::addNumberToContainers(int number) {
    this->_vec.push_back(number);
    this->_deq.push_back(number);
    return true;
}

void PmergeMe::SortVector() {
    std::chrono::high_resolution_clock::time_point startVec = std::chrono::high_resolution_clock::now();
    sortVectorUsingMerge(0, _vec.size() - 1);
    std::chrono::high_resolution_clock::time_point endVec = std::chrono::high_resolution_clock::now();
    this->durationVec = endVec - startVec;
}

void PmergeMe::SortDeque() {
    std::chrono::high_resolution_clock::time_point startDeq = std::chrono::high_resolution_clock::now();
    sortDequeUsingMerge(0, _deq.size() - 1);
    std::chrono::high_resolution_clock::time_point endDeq = std::chrono::high_resolution_clock::now();
    this->durationDeq = endDeq - startDeq;
}

void PmergeMe::sortVectorUsingMerge(int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        sortVectorUsingMerge(left, middle);
        sortVectorUsingMerge(middle + 1, right);
        mergeVector(left, middle, right);
    }
}

void PmergeMe::sortDequeUsingMerge(int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        sortDequeUsingMerge(left, middle);
        sortDequeUsingMerge(middle + 1, right);
        mergeDeque(left, middle, right);
    }
}

void PmergeMe::mergeVector(int left, int middle, int right) {
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

void PmergeMe::mergeDeque(int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::deque<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = _deq[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = _deq[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            _deq[k] = L[i];
            i++;
        } else {
            _deq[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        _deq[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        _deq[k] = R[j];
        j++;
        k++;
    }
}

bool is_number(const std::string &s) {
    if (s.empty())
        return false;
    size_t start = 0;

    if (s[0] == '+') {
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
            std::cout << "Error" << std::endl;
            return;        
        }
        i++;
    }
    // print container before sorting
    const std::vector<int>& vec = getVector();
    std::cout << "Before: ";
    for(std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    if (vec.size() == 2 && vec[0] > vec[1]) {
        std::swap(_vec[0], _vec[1]);
    } else if (vec.size() > 2) {
        SortVector();
        SortDeque();
    }
    std::cout << std::endl;
    // print container after sorting
    std::cout << "After : ";
    for(std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector: " << this->durationVec.count() << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque: " << this->durationDeq.count() << " us" << std::endl;
}
