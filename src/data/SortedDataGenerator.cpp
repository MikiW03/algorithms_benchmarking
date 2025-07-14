#include "data/SortedDataGenerator.h"
#include "types/Boardgame.h"
#include <algorithm>

template<typename T>
SortedDataGenerator<T>::SortedDataGenerator(bool ascending) 
    : ascending(ascending) {}

template<typename T>
void SortedDataGenerator<T>::generate(IDataContainer<T>& container, int size) {
    randomGen.generate(container, size);
    
    std::vector<T> temp(size);
    for (int i = 0; i < size; i++) {
        temp[i] = container.get(i);
    }
    
    if (ascending) {
        std::sort(temp.begin(), temp.end());
    } else {
        std::sort(temp.begin(), temp.end(), std::greater<T>());
    }
    
    for (int i = 0; i < size; i++) {
        container.set(i, temp[i]);
    }
}

template class SortedDataGenerator<int>;
template class SortedDataGenerator<float>;
template class SortedDataGenerator<std::string>;
template class SortedDataGenerator<Boardgame>; 