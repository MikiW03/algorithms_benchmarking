#include "algorithms/AlgorithmFactory.h"
#include "algorithms/BubbleSort.h"
#include "algorithms/InsertionSort.h"
#include "algorithms/DrunkShellSort.h"
#include "algorithms/HeapSort.h"
#include "algorithms/QuickSort.h"
#include "algorithms/ShellSort.h"
#include "types/Boardgame.h"
#include <stdexcept>
#include "io/ArgumentParser.h"

template<typename T>
std::shared_ptr<ISortingAlgorithm<T>> createAlgorithm(AlgorithmType algorithmType, const ArgumentParser& args) {
    switch (algorithmType) {
        case AlgorithmType::BUBBLE_SORT:
            return std::make_shared<BubbleSort<T>>();
        case AlgorithmType::INSERTION_SORT:
            return std::make_shared<InsertionSort<T>>();
        case AlgorithmType::HEAP_SORT:
            return std::make_shared<HeapSort<T>>();
        case AlgorithmType::QUICK_SORT:
            return std::make_shared<QuickSort<T>>(args.getPivotStrategy());
        case AlgorithmType::SHELL_SORT:
            return std::make_shared<ShellSort<T>>(args.getGapSequence());
        case AlgorithmType::DRUNK_SHELL_SORT:
            return std::make_shared<DrunkShellSort<T>>(args.getDrunkLevel());
        default:
            throw std::runtime_error("Unknown algorithm");
    }
}

template std::shared_ptr<ISortingAlgorithm<int>> createAlgorithm(AlgorithmType, const ArgumentParser&);
template std::shared_ptr<ISortingAlgorithm<float>> createAlgorithm(AlgorithmType, const ArgumentParser&);
template std::shared_ptr<ISortingAlgorithm<std::string>> createAlgorithm(AlgorithmType, const ArgumentParser&);
template std::shared_ptr<ISortingAlgorithm<Boardgame>> createAlgorithm(AlgorithmType, const ArgumentParser&); 