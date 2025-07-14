#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "algorithms/ISortingAlgorithm.h"
#include "types/PivotStrategy.h"

template<typename T>
class QuickSort : public ISortingAlgorithm<T> {
private:
    PivotStrategy pivotStrategy;
    int choosePivot(IDataContainer<T>& data, int low, int high);
    int partition(IDataContainer<T>& data, int low, int high);
    void quickSort(IDataContainer<T>& data, int low, int high);

public:
    explicit QuickSort(PivotStrategy strategy) : pivotStrategy(strategy) {}
    void sort(IDataContainer<T>& data) override;
    [[nodiscard]] const AlgorithmStatistics& getStatistics() const override;
    void resetStatistics() override;
};

#endif 