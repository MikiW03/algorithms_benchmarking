#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "IDataContainer.h"
#include <vector>
#include <memory>
#include <algorithm>

template <typename T>
class DynamicArray : public IDataContainer<T> {
private:
    T* array;
    int currentSize;
    int capacity;
    void resize(int newCapacity);

public:
    DynamicArray();
    explicit DynamicArray(int initialSize);
    ~DynamicArray();

    DynamicArray& operator=(const DynamicArray& other);

    void add(const T& element);
    T get(int index) const;
    void set(int index, const T& element);
    void swap(int i, int j);
    [[nodiscard]] int size() const;
    void clear();
    [[nodiscard]] bool isSorted() const;
};

#endif
