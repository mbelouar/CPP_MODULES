#include "Span.hpp"

int main() {

    std::cout << "== Exception cases ==" << std::endl;

    Span sp = Span(1);
    try {
        sp.addNumber(5);
        sp.shortestSpan();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "====================" << std::endl;

    Span sp3 = Span(2);
    try {
        sp3.addNumber(5);
        sp3.addNumber(3);
        sp3.addNumber(17);
        std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "== Normal case ==" << std::endl;

    Span sp1 = Span(5);
    sp1.addNumber(5);
    sp1.addNumber(3);
    sp1.addNumber(17);
    sp1.addNumber(9);
    sp1.addNumber(11);
    std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp1.longestSpan() << std::endl;

    std::cout << "== Adding a range of numbers ==" << std::endl;
    Span sp2 = Span(10000);
    std::vector<int> v;
    
    for (int i = 0; i < 10000; i++) {
        v.push_back(i);
    }

    sp2.addRange(v.begin(), v.end());
    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

    return 0;
}