#pragma once
#include <cstddef>
#include <new>          
#include <stdexcept>    

class DynamicArray {
private:
    int* data;
    int size;

public:
    
    explicit DynamicArray(int n);
    ~DynamicArray();

    void print() const;
    int getSize() const;
    void set(int index, int value);
    int get(int index) const;

    DynamicArray(const DynamicArray& other);

    void push_back(int value);

    void add(const DynamicArray& other);
    void subtract(const DynamicArray& other);
};