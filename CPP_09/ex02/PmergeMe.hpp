#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <string>
# include <algorithm>
# include <stdexcept>
# include <chrono>

class PmergeMe {
    private:
        std::vector<int> _vec;
        std::list<int> _list;

        // Sorting algorithms for vector
        void sortVectorUsingMerge(int first, int last);
        void merge(int first, int middle, int last);

    public:
        void start(char **argv);
        bool addNumberToContainers(int number);
        const std::vector<int> &getVector() const;
        const std::list<int> &getList() const;
        
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe& operator=(const PmergeMe &src);
        ~PmergeMe();
};

#endif
