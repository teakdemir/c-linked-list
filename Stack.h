// Stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cassert>

template <class T>
class Stack {
protected:
    T *arr;         // Array to hold stack elements
    int top;        // Index of the empty space after the topmost element
    int size;       // Size of the stack (maximum capacity)

public:
    // Constructor with default size
    Stack(int sz = 10) {
        size = sz;
        arr = new T[size];
        top = 0;
    }

    // Destructor to free the allocated memory
    ~Stack() {
        delete[] arr;
        size = 0;
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return (top == 0);
    }

    // Check if the stack is full
    bool isFull() const {
        return (top == size);
    }

    // Push an element onto the stack
    void push(T &data) {
        if (!isFull()) {
            arr[top++] = data;
        } else {
            std::cout << "Stack Full" << std::endl;
        }
    }

    // Pop an element from the stack
    T pop() {
        assert(!isEmpty()); // Ensure stack is not empty before popping
        return arr[--top];
    }

    // Peek at the top element of the stack
    T topData() const {
        assert(!isEmpty()); // Ensure stack is not empty before accessing top
        return arr[top - 1];
    }

    // Destroy stack contents (reset top index)
    void destroy() {
        top = 0;
    }

    // Copy another stack into this one
    void copy(const Stack<T> &st) {
        delete[] arr;
        size = st.size;
        top = st.top;
        arr = new T[size];
        for (int n = 0; n < top; n++) {
            arr[n] = st.arr[n];
        }
    }
};

#endif // STACK_H