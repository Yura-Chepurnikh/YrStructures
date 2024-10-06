#include <initializer_list>
#include <move>
#include <iostream>
#include <vcruntime.h>
using namespace std;

template<typename T>
class YrVector {
private:
    T* ptr;
public:
    YrVector();
    YrVector(size_t n, const T& value);
    YrVector(T* startOfRange, T* endOfRange);
    YrVector(const YrVector<T>& other);
    YrVector(YrVector<T>&& other) noexcept;
    YrVector(initializer_list<T> items);
};