#pragma once

#include <cstddef>
#include <new>
#include <stdexcept>
#include <iostream>
#include <cmath>
#include <typeinfo>
#include <type_traits>

template <typename T>
class DynamicArray {
private:
    T* data;
    int size;

public:
    explicit DynamicArray(int n) : size(n), data(nullptr) {
        if (n < 0)
            throw std::invalid_argument("Size cannot be negative");
        if (n > 0)
            data = new T[n]();       
    }

    ~DynamicArray() {
        delete[] data;
    }

    DynamicArray(const DynamicArray& other) : size(other.size), data(nullptr) {
        if (size > 0) {
            data = new T[size];
            for (int i = 0; i < size; ++i) data[i] = other.data[i];
        }
    }

    int getSize() const { return size; }

    int get(int index) const {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index out of range");
        return data[index];
    }

    void set(int index, const T& value) {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index out of range");

        if constexpr (std::is_integral_v<T>) {
            if (value > 100 || value < -100)
                throw std::invalid_argument("Value must be in [-100, 100]");
        }

        data[index] = value;
    }

    void push_back(const T& value) {
        if constexpr (std::is_integral_v<T>) {
            if (value > 100 || value < -100)
                throw std::invalid_argument("Value must be in [-100, 100]");
        }

        T* newData = new T[size + 1];
        for (int i = 0; i < size; ++i) newData[i] = data[i];
        newData[size] = value;

        delete[] data;
        data = newData;
        ++size;
    }

    void add(const DynamicArray& other) {
        int n = (size < other.size) ? size : other.size;
        for (int i = 0; i < n; ++i)
            data[i] = data[i] + other.data[i];
    }

    void subtract(const DynamicArray& other) {
        int n = (size < other.size) ? size : other.size;
        for (int i = 0; i < n; ++i)
            data[i] = data[i] - other.data[i];
    }


    friend std::ostream& operator<<(std::ostream& os, const DynamicArray& arr) {
        os << "[ ";
        for (int i = 0; i < arr.size; ++i) os << arr.data[i] << ' ';
        os << "]";
        return os;
    }
};


template <typename T>
double distance(const DynamicArray<T>& a, const DynamicArray<T>& b) {

    if constexpr (!std::is_arithmetic_v<T>) {
        throw std::bad_typeid();
    } else {
        if (a.getSize() != b.getSize())
            throw std::invalid_argument("Array sizes must match");

        double sum = 0.0;
        for (int i = 0; i < a.getSize(); ++i) {
            double d = static_cast<double>(a.get(i)) - static_cast<double>(b.get(i));
            sum += d * d;
        }
        return std::sqrt(sum);
    }
}