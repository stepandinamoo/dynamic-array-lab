#include "DynamicArray.h"
#include <iostream>
#include <stdexcept>
#include <new>

int main() {
    std::cout << "=== Task 1: basic operations ===\n";
    DynamicArray a(3);
    a.set(0, 10);
    a.set(1, -20);
    a.set(2, 30);
    a.print();

    std::cout << "\n=== Task 2: copy ctor ===\n";
    DynamicArray b = a;
    b.set(0, 100);
    std::cout << "a: "; a.print();
    std::cout << "b: "; b.print();

    std::cout << "\n=== Task 3: push_back ===\n";
    DynamicArray c(2);
    c.set(0, 1);
    c.set(1, 2);
    c.push_back(3);
    c.print();

    std::cout << "\n=== Task 4: add / subtract ===\n";
    DynamicArray x(4); x.set(0, 1); x.set(1, 2); x.set(2, 3); x.set(3, 4);
    DynamicArray y(2); y.set(0, 10); y.set(1, 20);
    x.add(y);       std::cout << "x.add(y):      "; x.print();
    x.subtract(y);  std::cout << "x.subtract(y): "; x.print();

    std::cout << "\n=== Exceptions demo ===\n";

    try {
        std::cout << "Trying a.get(100)...\n";
        a.get(100);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught std::out_of_range: " << e.what() << '\n';
    }

    try {
        std::cout << "Trying a.set(0, 999)...\n";
        a.set(0, 999);
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught std::invalid_argument: " << e.what() << '\n';
    }

    try {
        std::cout << "Trying to allocate huge array...\n";
        DynamicArray huge(1000000000000LL);   
        std::cout << "Allocated (unexpected)\n";
    } catch (const std::bad_alloc& e) {
        std::cout << "Caught std::bad_alloc: " << e.what() << '\n';
    }

    std::cout << "\nDone.\n";
    return 0;
}