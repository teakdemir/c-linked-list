#include <iostream>
#include "Stack.h"

int main() {
    int n, x;

    std::cout << "How many numbers? ";
    std::cin >> n;

    // Create a stack of size n
    Stack<int> nums(n);

    // Push numbers onto the stack
    std::cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        nums.push(x);
    }

    // Pop and print numbers in reverse order
    std::cout << "Numbers in reverse order: ";
    while (!nums.isEmpty()) {
        std::cout << nums.pop() << " ";
    }
    std::cout << std::endl;

    return 0;
}
