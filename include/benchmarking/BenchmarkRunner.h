#ifndef BENCHMARKRUNNER_H
#define BENCHMARKRUNNER_H

#include "../io/ArgumentParser.h"
#include "SortingBenchmark.h"
#include "../io/CSVFileHandler.h"
#include "../util/TypeMapper.h"
#include <memory>
#include <iostream>
#include <iomanip>

class BenchmarkRunner {
public:
    template<typename T>
    static void run(const ArgumentParser& args);
    
    static void displayResults(const BenchmarkResult& result, const ArgumentParser& args);
};

#endif