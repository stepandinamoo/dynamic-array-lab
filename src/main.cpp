#include "DynamicArray.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <typeinfo>
#include <new>

int main() {
    std::cout << "=== DynamicArray<int> ===\n";
    DynamicArray<int> a(3);
    a.set(0, 10);
    a.set(1, -20);
    a.set(2, 30);
    std::cout << "a = " << a << '\n';

    try { a.set(0, 999); }
    catch (const std::invalid_argument& e) { std::cout << "set err: " << e.what() << '\n'; }

    try { a.get(99); }
    catch (const std::out_of_range& e) { std::cout << "get err: " << e.what() << '\n'; }

    DynamicArray<int> b = a;
    b.set(0, 100);
    std::cout << "a = " << a << " (не изменился)\n";
    std::cout << "b = " << b << '\n';

    DynamicArray<int> c(2);
    c.set(0, 1);
    c.set(1, 2);
    c.push_back(3);
    std::cout << "c = " << c << '\n';

    DynamicArray<int> x(4); x.set(0, 1); x.set(1, 2); x.set(2, 3); x.set(3, 4);
    DynamicArray<int> y(4); y.set(0, 10); y.set(1, 20); y.set(2, 30); y.set(3, 40);
    x.add(y);       std::cout << "x.add(y)      = " << x << '\n';
    x.subtract(y);  std::cout << "x.subtract(y) = " << x << '\n';

    std::cout << "\n=== DynamicArray<double> ===\n";
    DynamicArray<double> da(2);
    da.set(0, 1.5);
    da.set(1, 9999.99);          
    std::cout << "da = " << da << '\n';

    std::cout << "\n=== distance() ===\n";
    DynamicArray<double> p(2); p.set(0, 0); p.set(1, 0);
    DynamicArray<double> q(2); q.set(0, 3); q.set(1, 4);
    std::cout << "distance(p, q) = " << distance(p, q) << " (ожидается 5)\n";

    try {
        DynamicArray<double> r(3);
        std::cout << "trying distance with different sizes...\n";
        distance(p, r);
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught std::invalid_argument: " << e.what() << '\n';
    }


    std::cout << "\n=== DynamicArray<std::string> ===\n";
    DynamicArray<std::string> s(3);
    s.set(0, "hello");
    s.set(1, "world");
    s.set(2, "!");
    std::cout << "s = " << s << '\n';


    try {
        std::cout << "trying distance on strings...\n";
        distance(s, s);
    } catch (const std::bad_typeid& e) {
        std::cout << "Caught std::bad_typeid: " << e.what() << '\n';
    }

    std::cout << "\nDone.\n";
    return 0;
}