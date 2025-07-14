#ifndef SHELLSORT_H
#define SHELLSORT_H

#include "algorithms/ISortingAlgorithm.h"
#include "types/GapSequence.h"

template<typename T>
class ShellSort : public ISortingAlgorithm<T> {
private:
    GapSequence gapSequence;
    void calculateGaps(int n, int* gaps, int& gapCount);

public:
    explicit ShellSort(GapSequence sequence) : gapSequence(sequence) {}
    void sort(IDataContainer<T>& data) override;
    [[nodiscard]] const AlgorithmStatistics& getStatistics() const override;
    void resetStatistics() override;
};

#endif 