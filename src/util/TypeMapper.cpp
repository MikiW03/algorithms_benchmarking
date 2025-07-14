#include "util/TypeMapper.h"
#include <stdexcept>

DataType TypeMapper::toDataType(int id) {
    if (id < 0 || id >= static_cast<int>(DataType::COUNT)) {
        throw std::runtime_error("Invalid data type identifier");
    }
    return static_cast<DataType>(id);
}

std::string TypeMapper::getDataTypeName(DataType type) {
    switch (type) {
        case DataType::INT:
            return "int";
        case DataType::FLOAT:
            return "float";
        case DataType::STRING:
            return "string";
        case DataType::BOARDGAME:
            return "boardgame";
        default: throw std::runtime_error("Invalid data type");
    }
}

AlgorithmType TypeMapper::toAlgorithmType(int id) {
    if (id < 0 || id >= static_cast<int>(AlgorithmType::COUNT)) {
        throw std::runtime_error("Invalid algorithm identifier");
    }
    return static_cast<AlgorithmType>(id);
}

std::string TypeMapper::getAlgorithmName(AlgorithmType type) {
    switch (type) {
        case AlgorithmType::BUBBLE_SORT:
            return "Bubble Sort";
        case AlgorithmType::INSERTION_SORT:
            return "Insertion Sort";
        case AlgorithmType::DRUNK_SHELL_SORT:
            return "Drunk Shell Sort";
        case AlgorithmType::HEAP_SORT:
            return "Heap Sort";
        case AlgorithmType::QUICK_SORT:
            return "Quick Sort";
        case AlgorithmType::SHELL_SORT:
            return "Shell Sort";
        default: throw std::runtime_error("Unknown algorithm type");
    }
}

DistributionType TypeMapper::toDistributionType(int id) {
    if (id < 0 || id >= static_cast<int>(DistributionType::COUNT)) {
        throw std::runtime_error("Invalid distribution identifier");
    }
    return static_cast<DistributionType>(id);
}

std::string TypeMapper::getDistributionName(DistributionType type) {
    switch (type) {
        case DistributionType::RANDOM:
            return "random";
        case DistributionType::SORTED_ASC:
            return "sorted ascending";
        case DistributionType::SORTED_DESC:
            return "sorted descending";
        case DistributionType::SORTED_33:
            return "sorted_33%";
        case DistributionType::SORTED_66:
            return "sorted_66%";
        default: throw std::runtime_error("Invalid distribution type");
    }
}

PivotStrategy TypeMapper::toPivotStrategy(int id) {
    if (id < 0 || id >= static_cast<int>(PivotStrategy::COUNT)) {
        throw std::runtime_error("Invalid pivot strategy identifier");
    }
    return static_cast<PivotStrategy>(id);
}

std::string TypeMapper::getPivotStrategyName(PivotStrategy strategy) {
    switch (strategy) {
        case PivotStrategy::FIRST:
            return "First element";
        case PivotStrategy::LAST:
            return "Last element";
        case PivotStrategy::MEDIAN:
            return "Median-of-three element";
        case PivotStrategy::RANDOM:
            return "Random element";
        default: throw std::runtime_error("Invalid pivot strategy type");
    }
}

GapSequence TypeMapper::toGapSequence(int id) {
    if (id < 0 || id >= static_cast<int>(GapSequence::COUNT)) {
        throw std::runtime_error("Invalid gap sequence identifier");
    }
    return static_cast<GapSequence>(id);
}

std::string TypeMapper::getGapSequenceName(GapSequence sequence) {
    switch (sequence) {
        case GapSequence::SHELL:
            return "Shell (n/2)";
        case GapSequence::KNUTH:
            return "Knuth (3k+1)";
        default: throw std::runtime_error("Invalid gap sequence type");
    }
}
