#include "../inc/YrVector.hpp"
#include <initializer_list>
#include <vcruntime.h>

template<typename T>
YrVector<T>::YrVector() { }

template<typename T>
YrVector<T>::YrVector(size_t n, const T& value) {   
    ptr = new T[n];
    for (int i = 0; i < n; ++i)
        ptr[i] = value;   
    delete ptr;
}

template<typename T>
YrVector<T>::YrVector(T* startOfRange, T* endOfRange) {   
    int k = 0;
    int size = (endOfRange - startOfRange) / sizeof(T);
    ptr = new YrVector<T>[size];
    while (startOfRange++ < endOfRange) {
        ptr[k++] = *startOfRange;
    }
    delete ptr;
}

template<typename T>
YrVector<T>::YrVector(const YrVector<T>& other) {
    this->ptr = other.ptr;
}

template<typename T>
YrVector<T>::YrVector(YrVector<T>&& other) noexcept {
    ptr = move(other.ptr);
}

template<typename T>
YrVector<T>::YrVector(initializer_list<T> items) {
    auto startOfRange = items.begin();
    auto endOfRange = items.end();
    YrVector(startOfRange, endOfRange);
}