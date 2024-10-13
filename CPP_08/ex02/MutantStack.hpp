#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(const MutantStack &src) : std::stack<T>(src) {}
        MutantStack &operator=(const MutantStack &src) {
            if (this == &src)
                return *this;
            std::stack<T>::operator=(src);
            return *this;
        }
        virtual ~MutantStack() {}

        // deque : double-ended queue
        // the same as : typename std::deque<T>::iterator
        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin() { return std::stack<T>::c.begin(); }
        iterator end() { return std::stack<T>::c.end(); }

        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        const_iterator begin() const { return std::stack<T>::c.begin(); }
        const_iterator end() const { return std::stack<T>::c.end(); }

};

#endif