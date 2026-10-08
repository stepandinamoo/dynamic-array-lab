#include "DynamicArray.h"
#include <iostream>
#include <stdexcept>

int main() {
    std::cout << "=== Task 1 ===\n";
    DynamicArray a(3);
    a.set(0, 10);
    a.set(1, -20);
    a.set(2, 30);
    a.print();
    std::cout << "a[1] = " << a.get(1) << '\n';

    try { a.set(5, 1); }   catch (const std::exception& e) { std::cout << "set err: " << e.what() << '\n'; }
    try { a.set(0, 999); } catch (const std::exception& e) { std::cout << "set err: " << e.what() << '\n'; }
    try { a.get(99); }     catch (const std::exception& e) { std::cout << "get err: " << e.what() << '\n'; }

    std::cout << "\n=== Task 2 (copy ctor) ===\n";
    DynamicArray b = a;   
    b.set(0, 100);
    std::cout << "a: "; a.print();
    std::cout << "b: "; b.print();   

    std::cout << "\n=== Task 3 (push_back) ===\n";
    DynamicArray c(2);
    c.set(0, 1);
    c.set(1, 2);
    c.push_back(3);
    c.push_back(-4);
    c.print();

    std::cout << "\n=== Task 4 (add/subtract) ===\n";
    DynamicArray x(4); x.set(0, 1); x.set(1, 2); x.set(2, 3); x.set(3, 4);
    DynamicArray y(2); y.set(0, 10); y.set(1, 20);

    std::cout << "x: "; x.print();
    std::cout << "y: "; y.print();

    x.add(y);
    std::cout << "x.add(y): "; x.print();

    x.subtract(y);
    std::cout << "x.subtract(y): "; x.print(); 

    return 0;
}