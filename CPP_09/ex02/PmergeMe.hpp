#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <algorithm>
# include <stdexcept>
# include <chrono>

class PmergeMe {
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;
        
        bool addNumberToContainers(int number);

        void sortVectorUsingMerge(int first, int last);
        void mergeVector(int first, int middle, int last);

        void sortDequeUsingMerge(int first, int last);
        void mergeDeque(int first, int middle, int last);

    public:
        void start(char **argv);
        const std::vector<int> &getVector() const;
        const std::deque<int> &getDeque() const;
        
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe& operator=(const PmergeMe &src);
        ~PmergeMe();
};

#endif
