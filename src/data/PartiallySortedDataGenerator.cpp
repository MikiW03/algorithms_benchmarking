#include "data/PartiallySortedDataGenerator.h"
#include "types/Boardgame.h"

template<typename T>
PartiallySortedDataGenerator<T>::PartiallySortedDataGenerator(double sortedPortion)
    : sortedPortion(sortedPortion)
    , rng(std::random_device{}()) {}

template<typename T>
void PartiallySortedDataGenerator<T>::generate(IDataContainer<T>& container, int size) {
    sortedGen.generate(container, size);
    
    int sortedCount = static_cast<int>(size * sortedPortion);
    
    for (int i = sortedCount; i < size; i++) {
        int j = std::uniform_int_distribution<int>{sortedCount, size-1}(rng);
        container.swap(i, j);
    }
}


template class PartiallySortedDataGenerator<int>;
template class PartiallySortedDataGenerator<float>;
template class PartiallySortedDataGenerator<std::string>;
template class PartiallySortedDataGenerator<Boardgame>; 