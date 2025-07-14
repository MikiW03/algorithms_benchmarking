#ifndef SORTINGBENCHMARK_H
#define SORTINGBENCHMARK_H

#include "../util/Timer.h"
#include "../data/DynamicArray.h"
#include "../algorithms/ISortingAlgorithm.h"
#include "../data/IDataGenerator.h"
#include "BenchmarkResult.h"
#include <stdexcept>

template <typename T>
class SortingBenchmark {
public:
    SortingBenchmark();
    void setAlgorithm(std::shared_ptr<ISortingAlgorithm<T>> algo);
    void setDataGenerator(std::shared_ptr<IDataGenerator<T>> generator);
    void setDataSize(int size);
    BenchmarkResult run();

private:
    std::shared_ptr<ISortingAlgorithm<T>> algorithm;
    std::shared_ptr<IDataGenerator<T>> dataGenerator;
    int dataSize;

    void validateConfiguration();
    void runSingleIteration(DynamicArray<T>* container, Timer& timer, BenchmarkResult& result);
    void finalizeResult(BenchmarkResult& result);
};

#endif