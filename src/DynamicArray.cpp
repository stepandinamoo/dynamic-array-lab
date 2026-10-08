#include "DynamicArray.h"
#include <iostream>
#include <stdexcept>


DynamicArray::DynamicArray(int n) : size(n) {
    if (n < 0) throw std::invalid_argument("Size cannot be negative");
    data = (n > 0) ? new int[n]() : nullptr;  
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::print() const {
    std::cout << "[ ";
    for (int i = 0; i < size; ++i) std::cout << data[i] << ' ';
    std::cout << "]\n";
}

int DynamicArray::getSize() const { return size; }

void DynamicArray::set(int index, int value) {
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");
    if (value < -100 || value > 100)
        throw std::invalid_argument("Value must be in [-100, 100]");
    data[index] = value;
}

int DynamicArray::get(int index) const {
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");
    return data[index];
}


DynamicArray::DynamicArray(const DynamicArray& other) : size(other.size) {
    if (size > 0) {
        data = new int[size];
        for (int i = 0; i < size; ++i) data[i] = other.data[i];
    } else {
        data = nullptr;
    }
}

void DynamicArray::push_back(int value) {
    if (value < -100 || value > 100)
        throw std::invalid_argument("Value must be in [-100, 100]");

    int* newData = new int[size + 1];
    for (int i = 0; i < size; ++i) newData[i] = data[i];
    newData[size] = value;

    delete[] data;
    data = newData;
    ++size;
}


void DynamicArray::add(const DynamicArray& other) {
    int n = (size < other.size) ? size : other.size;
    for (int i = 0; i < n; ++i) {
        int v = data[i] + other.data[i];
        data[i] = v;
    }
}

void DynamicArray::subtract(const DynamicArray& other) {
    int n = (size < other.size) ? size : other.size;
    for (int i = 0; i < n; ++i) {
        data[i] = data[i] - other.data[i];
    }
}