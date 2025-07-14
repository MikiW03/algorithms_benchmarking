#ifndef DRUNKSHELLSORT_H
#define DRUNKSHELLSORT_H

#include "ISortingAlgorithm.h"
#include "../data/IDataContainer.h"

template <typename T>
class DrunkShellSort : public ISortingAlgorithm<T> {
public:
    explicit DrunkShellSort(int drunkenness) : drunkLevel(drunkenness) {}
    int drunkLevel;
    void sort(IDataContainer<T>& data) override;
    [[nodiscard]] const AlgorithmStatistics& getStatistics() const override;
    void resetStatistics() override;
};

#endif 