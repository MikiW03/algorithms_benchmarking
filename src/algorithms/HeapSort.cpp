#include "algorithms/HeapSort.h"
#include "types/Boardgame.h"

template<typename T>
void HeapSort<T>::heapify(IDataContainer<T>& data, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        this->stats.comparisons++;
        if (data.get(left) > data.get(largest)) {
            largest = left;
        }
    }

    if (right < n) {
        this->stats.comparisons++;
        if (data.get(right) > data.get(largest)) {
            largest = right;
        }
    }

    if (largest != i) {
        data.swap(i, largest);
        this->stats.swaps++;
        heapify(data, n, largest);
    }
}

template<typename T>
void HeapSort<T>::sort(IDataContainer<T>& data) {
    int n = data.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(data, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        data.swap(0, i);
        this->stats.swaps++;
        heapify(data, i, 0);
    }
}

template <typename T>
const AlgorithmStatistics& HeapSort<T>::getStatistics() const {
    return this->stats;
}

template <typename T>
void HeapSort<T>::resetStatistics() {
    this->stats.reset();
}

template class HeapSort<int>;
template class HeapSort<float>;
template class HeapSort<std::string>;
template class HeapSort<Boardgame>;