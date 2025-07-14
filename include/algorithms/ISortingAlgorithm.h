#ifndef ISORTINGALGORITHM_H
#define ISORTINGALGORITHM_H

#include "../data/IDataContainer.h"
#include <string>
#include <random>

struct AlgorithmStatistics {
    long comparisons;
    long swaps;
    
    AlgorithmStatistics() : comparisons(0), swaps(0) {}
    
    void reset() {
        comparisons = 0;
        swaps = 0;
    }
};

template <typename T>
class ISortingAlgorithm {
protected:
    AlgorithmStatistics stats;

public:
    virtual ~ISortingAlgorithm() = default;
    virtual void sort(IDataContainer<T>& data) = 0;
    [[nodiscard]] virtual const AlgorithmStatistics& getStatistics() const = 0;
    virtual void resetStatistics() = 0;
};

#endif