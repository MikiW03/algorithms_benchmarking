#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "ISortingAlgorithm.h"
#include "../data/IDataContainer.h"

template <typename T>
class InsertionSort : public ISortingAlgorithm<T> {
public:
    void sort(IDataContainer<T>& data) override;
    [[nodiscard]] const AlgorithmStatistics& getStatistics() const override;
    void resetStatistics() override;
};

#endif 