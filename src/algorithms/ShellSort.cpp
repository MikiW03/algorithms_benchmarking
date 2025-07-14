#include "algorithms/ShellSort.h"
#include "types/Boardgame.h"

template<typename T>
void ShellSort<T>::calculateGaps(int n, int* gaps, int& gapCount) {
    gapCount = 0;
    
    switch (gapSequence) {
        case GapSequence::KNUTH: {
            int h = 1;
            int tempGaps[32];
            int tempCount = 0;
            
            while (h < n/3) {
                h = 3*h + 1;
            }
            while (h >= 1) {
                tempGaps[tempCount++] = h;
                h = (h - 1) / 3;
            }
            
            for(int i = 0; i < tempCount; i++) {
                gaps[i] = tempGaps[i];
            }
            gapCount = tempCount;
            break;
        }
            
        case GapSequence::SHELL:
        default: {
            int gap = n/2;
            while (gap > 0) {
                gaps[gapCount++] = gap;
                gap /= 2;
            }
            break;
        }
    }
}

template<typename T>
void ShellSort<T>::sort(IDataContainer<T>& data) {
    int n = data.size();
    int gaps[32];
    int gapCount;
    
    calculateGaps(n, gaps, gapCount);
    
    for (int i = 0; i < gapCount; i++) {
        int gap = gaps[i];
        for (int x = gap; x < n; x++) {
            T temp = data.get(x);
            int j;
            
            for (j = x; j >= gap; j -= gap) {
                this->stats.comparisons++;
                if (data.get(j - gap) > temp) {
                    data.set(j, data.get(j - gap));
                    this->stats.swaps++;
                } else {
                    break;
                }
            }
            
            if (j != x) {
                data.set(j, temp);
                this->stats.swaps++;
            }
        }
    }
}

template <typename T>
const AlgorithmStatistics& ShellSort<T>::getStatistics() const {
    return this->stats;
}

template <typename T>
void ShellSort<T>::resetStatistics() {
    this->stats.reset();
}

template class ShellSort<int>;
template class ShellSort<float>;
template class ShellSort<std::string>;
template class ShellSort<Boardgame>; 