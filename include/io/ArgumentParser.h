#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H

#include <string>
#include <stdexcept>
#include "types/DataType.h"
#include "types/AlgorithmType.h"
#include "types/DistributionType.h"
#include "types/PivotStrategy.h"
#include "types/GapSequence.h"

class ArgumentParser {
public:
    enum class Mode { TEST, HELP, FILE };

    ArgumentParser(int argc, char* argv[]);

    [[nodiscard]] Mode getMode() const { return mode; }
    [[nodiscard]] AlgorithmType getAlgorithm() const { return algorithm; }
    [[nodiscard]] DataType getDataType() const { return dataType; }
    [[nodiscard]] int getSize() const { return size; }
    [[nodiscard]] int getDrunkLevel() const { return drunkLevel; }
    [[nodiscard]] std::string getInputFile() const { return inputFile; }
    [[nodiscard]] std::string getOutputFile() const { return outputFile; }
    [[nodiscard]] DistributionType getDistribution() const { return distribution; }
    [[nodiscard]] PivotStrategy getPivotStrategy() const { return pivotStrategy; }
    [[nodiscard]] GapSequence getGapSequence() const { return gapSequence; }

    static void printHelp() ;

private:
    Mode mode;
    AlgorithmType algorithm;
    DataType dataType;
    int size;
    std::string inputFile;
    std::string outputFile;
    DistributionType distribution;
    PivotStrategy pivotStrategy;
    GapSequence gapSequence;
    int drunkLevel;

    void parseArguments(int argc, char* argv[]);
    void validateArguments() const;
};

#endif 