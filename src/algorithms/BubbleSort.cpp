#include "algorithms/BubbleSort.h"
#include "types/Boardgame.h"

template <typename T>
void BubbleSort<T>::sort(IDataContainer<T>& data) {
    this->resetStatistics();
    int n = data.size();
    
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            this->stats.comparisons++;
            if (data.get(j) > data.get(j + 1)) {
                data.swap(j, j + 1);
                this->stats.swaps++;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

template <typename T>
const AlgorithmStatistics& BubbleSort<T>::getStatistics() const {
    return this->stats;
}

template <typename T>
void BubbleSort<T>::resetStatistics() {
    this->stats.reset();
}

template class BubbleSort<int>;
template class BubbleSort<float>;
template class BubbleSort<std::string>;
template class BubbleSort<Boardgame>; 