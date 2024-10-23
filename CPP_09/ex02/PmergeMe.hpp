#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <string>
# include <stdexcept>
# include <chrono>

class PmergeMe {
    private:
        std::vector<int> _vec;
        std::list<int> _list;

        // Pushes a number to both containers
        bool addNumberToContainers(int number);

        // Sorting algorithms for vector
        void sortVectorUsingInsertion(int first, int last);
        void sortVectorUsingMerge(int first, int last);
        void mergeVectorSections(int first, int mid, int last);

        // Sorting algorithms for list
        void sortListUsingInsertion(int first, int last);
        void sortListUsingMerge(int first, int last);
        void mergeListSections(int first, int mid, int last);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        ~PmergeMe();
        PmergeMe& operator=(const PmergeMe &src);
};

#endif
