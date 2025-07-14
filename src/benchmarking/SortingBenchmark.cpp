#include "benchmarking/SortingBenchmark.h"
#include "types/Boardgame.h"

#include <iostream>

template <typename T>
SortingBenchmark<T>::SortingBenchmark()
    : algorithm(nullptr)
    , dataGenerator(nullptr)
    , dataSize(0) {}

template <typename T>
void SortingBenchmark<T>::setAlgorithm(std::shared_ptr<ISortingAlgorithm<T>> algo) {
    algorithm = algo;
}

template <typename T>
void SortingBenchmark<T>::setDataGenerator(std::shared_ptr<IDataGenerator<T>> generator) {
    dataGenerator = generator;
}

template <typename T>
void SortingBenchmark<T>::setDataSize(int size) {
    dataSize = size;
}

template <typename T>
BenchmarkResult SortingBenchmark<T>::run() {
    validateConfiguration();

    algorithm->resetStatistics();

    BenchmarkResult result;
    result.dataSize = dataSize;

    DynamicArray<T> container(dataSize);

    Timer timer;
    runSingleIteration(&container, timer, result);

    finalizeResult(result);

    return result;
}

template <typename T>
void SortingBenchmark<T>::validateConfiguration() {
    if (!algorithm || !dataGenerator || dataSize <= 0) {
        throw std::runtime_error("Benchmark not properly configured");
    }
}

template <typename T>
void SortingBenchmark<T>::runSingleIteration(DynamicArray<T>* container, Timer& timer, BenchmarkResult& result) {
    dataGenerator->generate(*container, dataSize);

    timer.reset();
    timer.start();
    algorithm->sort(*container);
    timer.stop();
    
    if (!container->isSorted()) {
        throw std::runtime_error("Sorting failed - array not sorted");
    }
    
    result.time = timer.result();
}

template <typename T>
void SortingBenchmark<T>::finalizeResult(BenchmarkResult& result) {
    const auto& stats = algorithm->getStatistics();
    result.comparisons = stats.comparisons;
    result.swaps = stats.swaps;
}

template class SortingBenchmark<int>;
template class SortingBenchmark<float>;
template class SortingBenchmark<std::string>;
template class SortingBenchmark<Boardgame>; 