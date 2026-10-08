#include "DynamicArray.h"
#include <iostream>

// ---------- Задание 1 ----------

DynamicArray::DynamicArray(int n) : size(n), data(nullptr) {
    if (n < 0)
        throw std::invalid_argument("Size cannot be negative");

    if (n > 0) {
        // Если память не выделится — new сам бросит std::bad_alloc
        data = new int[n]();
    }
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

// ---------- Задание 2 ----------

DynamicArray::DynamicArray(const DynamicArray& other)
    : size(other.size), data(nullptr) {
    if (size > 0) {
        data = new int[size];               // может бросить std::bad_alloc
        for (int i = 0; i < size; ++i) data[i] = other.data[i];
    }
}

// ---------- Задание 3 ----------

void DynamicArray::push_back(int value) {
    if (value < -100 || value > 100)
        throw std::invalid_argument("Value must be in [-100, 100]");

    int* newData = new int[size + 1];        // может бросить std::bad_alloc
    for (int i = 0; i < size; ++i) newData[i] = data[i];
    newData[size] = value;

    delete[] data;
    data = newData;
    ++size;
}

// ---------- Задание 4 ----------

void DynamicArray::add(const DynamicArray& other) {
    int n = (size < other.size) ? size : other.size;
    for (int i = 0; i < n; ++i) {
        data[i] = data[i] + other.data[i];
    }
}

void DynamicArray::subtract(const DynamicArray& other) {
    int n = (size < other.size) ? size : other.size;
    for (int i = 0; i < n; ++i) {
        data[i] = data[i] - other.data[i];
    }
}