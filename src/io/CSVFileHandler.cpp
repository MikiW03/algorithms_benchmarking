#include "io/CSVFileHandler.h"
#include "util/TypeMapper.h"
#include <fstream>
#include <sstream>

std::string CSVFileHandler::getCSVHeader() {
    return "Algorithm,DataType,Size,Distribution,Time,Comparisons,Swaps,Pivot,Gaps,DrunkLevel\n";
}

std::string CSVFileHandler::formatResultAsCSV(const BenchmarkResult& result) {
    std::string pivot = result.pivotStrategy;
    std::string gap = result.gapSequence;
    std::string drunkenness = std::to_string(result.drunkLevel);

    if(result.algorithmName != TypeMapper::getAlgorithmName(AlgorithmType::QUICK_SORT)){
        pivot = "N/A";
    }

    if(result.algorithmName != TypeMapper::getAlgorithmName(AlgorithmType::SHELL_SORT)){
        gap = "N/A";
    }

    if(result.algorithmName != TypeMapper::getAlgorithmName(AlgorithmType::DRUNK_SHELL_SORT)){
        drunkenness = "N/A";
    }

    return result.algorithmName + "," +
           result.dataType + "," +
           std::to_string(result.dataSize) + "," +
           result.distributionName + "," +
           std::to_string(result.time) + "," +
           std::to_string(result.comparisons) + "," +
           std::to_string(result.swaps) + "," +
           pivot + "," +
           gap + "," +
           drunkenness + "\n";
}

bool CSVFileHandler::saveToCSV(const std::vector<BenchmarkResult>& results, const std::string& filename) {
    bool fileExists = std::ifstream(filename).good();
    
    std::ofstream file(filename, std::ios::app);
    if (!file) {
        return false;
    }

    if (!fileExists) {
        file << getCSVHeader();
    }

    for (const auto& result : results) {
        file << formatResultAsCSV(result);
    }

    file.close();

    return true;
} 