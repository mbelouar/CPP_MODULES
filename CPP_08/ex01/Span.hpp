#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span {
    private:
        unsigned int _n;
        std::vector<int> _v;
    public:
        Span(unsigned int n);
        Span(Span const &src);
        Span &operator=(Span const &src);
        ~Span();

        void addNumber(int n);
        void addRange(std::vector<int>::iterator first, std::vector<int>::iterator last);
        int shortestSpan();
        int longestSpan();

        class FullSpanException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class NoSpanException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

#endif