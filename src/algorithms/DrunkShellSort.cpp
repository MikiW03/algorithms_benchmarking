#include "algorithms/DrunkShellSort.h"
#include "types/Boardgame.h"
#include <thread>
#include <chrono>

template <typename T>
void DrunkShellSort<T>::sort(IDataContainer<T>& data) {
    int n = data.size();
    int gaps[32];
    int gapCount;

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
        
        if (this->drunkLevel > 0) {
            int sleepTime = this->drunkLevel/2;
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        }
    }
}

template <typename T>
const AlgorithmStatistics& DrunkShellSort<T>::getStatistics() const {
    return this->stats;
}

template <typename T>
void DrunkShellSort<T>::resetStatistics() {
    this->stats.reset();
}

template class DrunkShellSort<int>;
template class DrunkShellSort<float>;
template class DrunkShellSort<std::string>;
template class DrunkShellSort<Boardgame>;