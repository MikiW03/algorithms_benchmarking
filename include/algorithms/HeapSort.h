#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "algorithms/ISortingAlgorithm.h"

template<typename T>
class HeapSort : public ISortingAlgorithm<T> {
private:
    void heapify(IDataContainer<T>& data, int n, int i);

public:
    void sort(IDataContainer<T>& data) override;
    [[nodiscard]] const AlgorithmStatistics& getStatistics() const override;
    void resetStatistics() override;
};

#endif 