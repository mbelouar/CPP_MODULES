#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;

    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    std::cout << "Top element: " << mstack.top() << std::endl;

    // Test pop
    mstack.pop();
    std::cout << "Top element after pop: " << mstack.top() << std::endl;

    // Test size
    std::cout << "Stack size: " << mstack.size() << std::endl;

    // Add more elements
    mstack.push(40);
    mstack.push(50);

    // Iterate through elements using iterators
    std::cout << "Stack elements: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Iterate through elements using const_iterator
    std::cout << "Stack elements (const_iterator): ";
    for (MutantStack<int>::const_iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test copy constructor
    MutantStack<int> mstack_copy(mstack);
    std::cout << "Copied stack elements: ";
    for (MutantStack<int>::iterator it = mstack_copy.begin(); it != mstack_copy.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test assignment operator
    MutantStack<int> mstack_assigned;
    mstack_assigned = mstack;
    std::cout << "Assigned stack elements: ";
    for (MutantStack<int>::iterator it = mstack_assigned.begin(); it != mstack_assigned.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
