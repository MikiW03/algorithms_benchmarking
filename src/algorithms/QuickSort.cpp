#include "algorithms/QuickSort.h"
#include "types/Boardgame.h"
#include <random>

template<typename T>
int QuickSort<T>::choosePivot(IDataContainer<T>& data, int low, int high) {
    switch (pivotStrategy) {
        case PivotStrategy::FIRST:
            return low;
            
        case PivotStrategy::RANDOM: {
            static std::random_device rd;
            static std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(low, high);
            return dis(gen);
        }
            
        case PivotStrategy::MEDIAN: {
            int mid = low + (high - low) / 2;
            T a = data.get(low);
            T b = data.get(mid);
            T c = data.get(high);
            
            if (a < b) {
                if (b < c) return mid;
                if (a < c) return high;
                return low;
            } else {
                if (a < c) return low;
                if (b < c) return high;
                return mid;
            }
        }
            
        case PivotStrategy::LAST:
        default:
            return high;
    }
}

template<typename T>
int QuickSort<T>::partition(IDataContainer<T>& data, int low, int high) {
    int pivotIndex = choosePivot(data, low, high);
    
    if (pivotIndex != high) {
        data.swap(pivotIndex, high);
        this->stats.swaps++;
    }
    
    T pivot = data.get(high);
    int i = low - 1;

    for (int j = low; j < high; j++) {
        this->stats.comparisons++;
        if (data.get(j) < pivot) {
            i++;
            data.swap(i, j);
            this->stats.swaps++;
        }
    }

    data.swap(i + 1, high);
    this->stats.swaps++;
    return i + 1;
}

template<typename T>
void QuickSort<T>::quickSort(IDataContainer<T>& data, int low, int high) {
    if (low < high) {
        int pi = partition(data, low, high);
        quickSort(data, low, pi - 1);
        quickSort(data, pi + 1, high);
    }
}

template<typename T>
void QuickSort<T>::sort(IDataContainer<T>& data) {
    quickSort(data, 0, data.size() - 1);
}

template <typename T>
const AlgorithmStatistics& QuickSort<T>::getStatistics() const {
    return this->stats;
}

template <typename T>
void QuickSort<T>::resetStatistics() {
    this->stats.reset();
}

template class QuickSort<int>;
template class QuickSort<float>;
template class QuickSort<std::string>;
template class QuickSort<Boardgame>; 