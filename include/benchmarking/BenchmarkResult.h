#ifndef BENCHMARKRESULT_H
#define BENCHMARKRESULT_H

#include <string>
#include <vector>

struct BenchmarkResult {
    std::string algorithmName;
    std::string dataType;
    int dataSize;
    std::string distributionName;
    std::string gapSequence;
    std::string pivotStrategy;
    int drunkLevel;
    int time;
    long long comparisons;
    long long swaps;
};

#endif