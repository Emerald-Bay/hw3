#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>
#include <iostream>

template <typename T>
class Stack : private std::vector<T> {
public:
    Stack();
    ~Stack();

    bool empty() const;
    size_t size() const;

    void push(const T& item);
    void pop(); // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
};

// Defined all member functions in the header file as they all require
// the templated type T

template <typename T>
Stack<T>::Stack() {

}

template <typename T>
Stack<T>::~Stack() {

}

template <typename T>
bool Stack<T>::empty() const {
    return (this->size() == (size_t)(0));
};

template <typename T>
size_t Stack<T>::size() const {
    return std::vector<T>::size();
};

template <typename T>
void Stack<T>::push(const T& item) {
    this->push_back(item);
};

template <typename T>
void Stack<T>::pop() { // throws std::underflow_error if empty
    if (Stack::empty()) {
        throw std::underflow_error("Stack is empty - pop() error");
    }
    else this->pop_back();
};

template <typename T>
const T& Stack<T>::top() const { // throws std::underflow_error if empty
    if (Stack::empty()) {
        throw std::underflow_error("Stack is empty - top() error");
    }
    else return this->back();
};

#endif

