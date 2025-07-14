#ifndef CSVFILEHANDLER_H
#define CSVFILEHANDLER_H

#include "../benchmarking/BenchmarkResult.h"
#include <string>
#include <vector>

class CSVFileHandler {
public:
    static std::string getCSVHeader();
    static std::string formatResultAsCSV(const BenchmarkResult& result);
    static bool saveToCSV(const std::vector<BenchmarkResult>& results, const std::string& filename);
};

#endif 