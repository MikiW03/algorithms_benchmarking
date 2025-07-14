#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "ISortingAlgorithm.h"
#include "../data/IDataContainer.h"

template <typename T>
class BubbleSort : public ISortingAlgorithm<T> {
public:
    void sort(IDataContainer<T>& data) override;
    [[nodiscard]] const AlgorithmStatistics& getStatistics() const override;
    void resetStatistics() override;
};

#endif 