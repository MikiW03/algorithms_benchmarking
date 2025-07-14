#include "data/DynamicArray.h"
#include "types/Boardgame.h"
#include <stdexcept>
#include <algorithm>

template <typename T>
void DynamicArray<T>::resize(int newCapacity) {
    T* newArray = new T[newCapacity];
    for (int i = 0; i < currentSize; i++) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    capacity = newCapacity;
}

template <typename T>
DynamicArray<T>::DynamicArray() : array(new T[1]), currentSize(0), capacity(1) {}

template <typename T>
DynamicArray<T>::DynamicArray(int initialSize) : 
    array(new T[initialSize]), 
    currentSize(initialSize),
    capacity(initialSize) {
    for (int i = 0; i < initialSize; i++) {
        array[i] = T();
    }
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] array;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other) {
    if (this != &other) {
        delete[] array;
        capacity = other.capacity;
        currentSize = other.currentSize;
        array = new T[capacity];
        for (int i = 0; i < currentSize; i++) {
            array[i] = other.array[i];
        }
    }
    return *this;
}

template <typename T>
void DynamicArray<T>::add(const T& element) {
    if (currentSize == capacity) {
        resize(capacity * 2);
    }
    array[currentSize++] = element;
}

template <typename T>
T DynamicArray<T>::get(int index) const {
    if (index < 0 || index >= currentSize) {
        throw std::out_of_range("Index out of bounds");
    }
    return array[index];
}

template <typename T>
void DynamicArray<T>::set(int index, const T& element) {
    if (index < 0 || index >= currentSize) {
        throw std::out_of_range("Index out of bounds");
    }
    array[index] = element;
}

template <typename T>
void DynamicArray<T>::swap(int i, int j) {
    if (i < 0 || i >= currentSize || j < 0 || j >= currentSize) {
        throw std::out_of_range("Index out of bounds");
    }
    T temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

template <typename T>
int DynamicArray<T>::size() const {
    return currentSize;
}

template <typename T>
void DynamicArray<T>::clear() {
    currentSize = 0;
}

template <typename T>
bool DynamicArray<T>::isSorted() const {
    for (int i = 1; i < currentSize; i++) {
        if (array[i] < array[i-1]) {
            return false;
        }
    }
    return true;
}

template class DynamicArray<int>;
template class DynamicArray<float>;
template class DynamicArray<std::string>;
template class DynamicArray<Boardgame>;