#include <iostream>
#include "heap.h"

int main(int argc, char* argv[]) {
    Heap<int> test;

    for (int i = 0; i <= 10; ++i) {
        test.push(i * 1);
    }

    for (int i = 10; i > 0; --i) {
        test.push(i + i);
    }

    std::cout << "Current size of Heap is " << test.size() << std::endl;

    while (!(test.empty())) {
        std::cout << "Top element is " << test.top() << std::endl;
        test.pop();
    }

    std::cout << "Testing pop() error throw\n";
    test.pop();

    std::cout << "Testing top() error throw\n";
    test.top();
}