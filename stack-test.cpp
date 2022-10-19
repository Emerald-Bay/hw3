#include <iostream>
#include "stack.h"

int main(int argc, char* argv[]) {
    Stack<int> test;

    for (int i = 1; i < 11; ++i) {
        test.push(i);
    }

    std::cout << "Size of the test stack is - " << test.size() << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::cout << test.top() << std::endl;
        test.pop();
    }

    std::cout << "The test stack is empty?  - " << (test.empty() ? "true" : "false") << std::endl;

    std::cout << "Push 1... \n";
    test.push(1);

    std::cout << "Size of the test stack is - " << test.size() << std::endl;
    std::cout << "The test stack is empty?  - " << (test.empty() ? "true" : "false") << std::endl;

    test.pop();

    std::cout << std::endl;

    // Comment/Uncomment each section to test either error throw

    // std::cout << "Popping when stack is empty..." << std::endl;
    // test.pop();

    std::cout << "Calling top() when stack is empty..." << std::endl;
    std::cout << test.top() << std::endl;
}