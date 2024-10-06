#include "Base.hpp"

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    Base* basePtr = generate();
    identify(basePtr);  // Pointer version
    identify(*basePtr);  // Reference version

    // Clean up
    delete basePtr;

    return 0;
}
