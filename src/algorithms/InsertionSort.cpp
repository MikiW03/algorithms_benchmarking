#include "algorithms/InsertionSort.h"
#include "types/Boardgame.h"

template <typename T>
void InsertionSort<T>::sort(IDataContainer<T>& data) {
    this->resetStatistics();
    int n = data.size();
    
    for (int i = 1; i < n; i++) {
        T key = data.get(i);
        int j = i - 1;
        
        this->stats.comparisons++;
        while (j >= 0 && data.get(j) > key) {
            data.set(j + 1, data.get(j));
            j--;
            this->stats.swaps++;
            if (j >= 0) this->stats.comparisons++;
        }
        
        data.set(j + 1, key);
    }
}

template <typename T>
const AlgorithmStatistics& InsertionSort<T>::getStatistics() const {
    return this->stats;
}

template <typename T>
void InsertionSort<T>::resetStatistics() {
    this->stats.reset();
}

template class InsertionSort<int>;
template class InsertionSort<float>;
template class InsertionSort<std::string>;
template class InsertionSort<Boardgame>; 