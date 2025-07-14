#include "io/ArgumentParser.h"
#include "util/TypeMapper.h"
#include <iostream>
#include <string>
#include <stdexcept>

ArgumentParser::ArgumentParser(int argc, char* argv[])
    : mode(Mode::HELP)
    , algorithm(AlgorithmType::BUBBLE_SORT)
    , dataType(DataType::INT)
    , size(1000)
    , distribution(DistributionType::RANDOM)
    , pivotStrategy(PivotStrategy::LAST)
    , gapSequence(GapSequence::SHELL)
    , drunkLevel(0)
{
    if (argc < 2) {
        printHelp();
        return;
    }
    
    parseArguments(argc, argv);
    validateArguments();
}

void ArgumentParser::parseArguments(int argc, char* argv[]) {
    std::string arg = argv[1];

    if (arg == "--help") {
        mode = Mode::HELP;
        return;
    }

    if (arg == "--test") {
        mode = Mode::TEST;
        if (argc < 7) {
            printHelp();
            throw std::runtime_error("Not enough arguments.");
        }
        
        try {
            algorithm = TypeMapper::toAlgorithmType(std::stoi(argv[2]));
            dataType = TypeMapper::toDataType(std::stoi(argv[3]));
            distribution = TypeMapper::toDistributionType(std::stoi(argv[4]));

            size = std::stoi(argv[5]);
            if (size <= 0) {
                throw std::runtime_error("Size must be positive");
            }

            outputFile = argv[6];

            
            for (int i = 1; i < argc; i++) {
                arg = argv[i];
                if (arg == "-p" || arg == "--pivot") {
                    if (i + 1 < argc) {
                        pivotStrategy = TypeMapper::toPivotStrategy(std::stoi(argv[++i]));
                    }
                }
                else if (arg == "-g" || arg == "--gap") {
                    if (i + 1 < argc) {
                        gapSequence = TypeMapper::toGapSequence(std::stoi(argv[++i]));
                    }
                }
                else if (arg == "-d" || arg == "--drunkenness") {
                    if (i + 1 < argc) {
                        drunkLevel = std::stoi(argv[++i]);
                    }
                }
            }
        } catch (const std::invalid_argument& e) {
            printHelp();
            throw std::runtime_error("Error parsing numeric arguments");
        } catch (const std::out_of_range& e) {
            printHelp();
            throw std::runtime_error("Argument value out of range");
        }
    } else if (arg == "--file") {
        mode = Mode::FILE;
        if (argc < 5) {
            printHelp();
            throw std::runtime_error("Not enough arguments for file mode");
        }
        
        try {
            algorithm = TypeMapper::toAlgorithmType(std::stoi(argv[2]));
            dataType = TypeMapper::toDataType(std::stoi(argv[3]));
            inputFile = argv[4];
            
            if (argc >= 6) {
                outputFile = argv[5];
            }
            
            for (int i = 5; i < argc; i++) {
                arg = argv[i];
                if (arg == "-p" || arg == "--pivot") {
                    if (i + 1 < argc) {
                        pivotStrategy = TypeMapper::toPivotStrategy(std::stoi(argv[++i]));
                    }
                }
                else if (arg == "-g" || arg == "--gap") {
                    if (i + 1 < argc) {
                        gapSequence = TypeMapper::toGapSequence(std::stoi(argv[++i]));
                    }
                }
                else if (arg == "-d" || arg == "--drunkenness") {
                    if (i + 1 < argc) {
                        drunkLevel = std::stoi(argv[++i]);
                    }
                }
            }
        } catch (const std::invalid_argument& e) {
            printHelp();
            throw std::runtime_error("Error parsing numeric arguments");
        } catch (const std::out_of_range& e) {
            printHelp();
            throw std::runtime_error("Argument value out of range");
        }
    } else {
        throw std::runtime_error("Unknown mode");
    }
}

void ArgumentParser::validateArguments() const {
    if (mode == Mode::TEST) {
        if (size <= 0) throw std::runtime_error("Invalid size");
    } else if (mode == Mode::FILE) {
        if (inputFile.empty()) throw std::runtime_error("Missing input file");
    }
}

void ArgumentParser::printHelp() {
    std::cout << "Sorting Algorithms Benchmark\n"
              << "===========================\n\n"
              << "Usage:\n"
              << "  --test <algorithm> <data_type> <distribution> <size> <output_file>\n"
              << "  --file <algorithm> <data_type> <input_file> [output_file]\n"
              << "  --help\n\n"
              << "Algorithms:\n";
    
    for (int i = 0; i < static_cast<int>(AlgorithmType::COUNT); i++) {
        AlgorithmType type = TypeMapper::toAlgorithmType(i);
        std::cout << "  " << i << " - " << TypeMapper::getAlgorithmName(type) << "\n";
    }
    
    std::cout << "\nData types:\n";
    
    for (int i = 0; i < static_cast<int>(DataType::COUNT); i++) {
        DataType type = TypeMapper::toDataType(i);
        std::cout << "  " << i << " - " << TypeMapper::getDataTypeName(type) << "\n";
    }
    
    std::cout << "\nData distributions:\n";
    
    for (int i = 0; i < static_cast<int>(DistributionType::COUNT); i++) {
        DistributionType type = TypeMapper::toDistributionType(i);
        std::cout << "  " << i << " - " << TypeMapper::getDistributionName(type) << "\n";
    }
    
    std::cout << "\nPivot selection strategies:\n";
    
    for (int i = 0; i < static_cast<int>(PivotStrategy::COUNT); i++) {
        auto type = static_cast<PivotStrategy>(i);
        std::cout << "  " << i << " - " << TypeMapper::getPivotStrategyName(type) << "\n";
    }

    std::cout << "\nGap sequences:\n";
    
    for (int i = 0; i < static_cast<int>(GapSequence::COUNT); i++) {
        auto type = static_cast<GapSequence>(i);
        std::cout << "  " << i << " - " << TypeMapper::getGapSequenceName(type) << "\n";
    }
    
    std::cout << "\nTEST mode parameters:\n"
            << "  <algorithm>       - algorithm number (0-" << static_cast<int>(AlgorithmType::COUNT)-1 << ")\n"
            << "  <data_type>       - data type (0-" << static_cast<int>(DataType::COUNT)-1 << ")\n"
            << "  <distribution>    - data distribution type (0-" << static_cast<int>(DistributionType::COUNT)-1 << ")\n"
            << "  <size>            - number of elements to sort\n"
            << "  <output_file>     - filename to save the results\n";
    
    std::cout << "\nFILE mode parameters:\n"
            << "  <algorithm>       - algorithm number (0-" << static_cast<int>(AlgorithmType::COUNT)-1 << ")\n"
            << "  <data_type>       - data type (0-" << static_cast<int>(DataType::COUNT)-1 << ")\n"
            << "  <input_file>      - filename with data to sort (relative to input_files/ directory )\n"
            << "  [output_file]     - optional filename to save sorted data (relative to output_files/ directory)\n"
            << "\n  The input file should have the following format:\n"
            << "    - First line: integer N (number of elements)\n"
            << "    - Next N lines: one element per line\n"
            << "    - For boardgames: 'name,publisher,minPlayers,maxPlayers,playTime,complexity,funFactor'\n";

    std::cout << "\nOptional parameters:\n"
            << "  -p, --pivot       Pivot selection strategy for QuickSort (0-" << static_cast<int>(PivotStrategy::COUNT)-1 << ")\n"
            << "  -g, --gap         Gap sequence for ShellSort (0-" << static_cast<int>(GapSequence::COUNT)-1 << ")\n"
            << "  -d, --drunkenness Drunkenness parameter for DrunkShellSort (1-100)\n";
    
    std::cout << "\nExamples:\n"
            << "  Test QuickSort with integers, random distribution, size 10000, median pivot:\n"
            << "    --test 3 0 0 10000 results.csv -p 3\n\n"
            << "  Test ShellSort with strings, ascending order, size 5000, Knuth gap sequence:\n"
            << "    --test 4 2 1 5000 string_results.csv -g 1\n\n"
            << "  Sort data from file using HeapSort (integers):\n"
            << "    --file 2 0 my_data.txt sorted_data.txt\n\n"
            << "  Sort boardgames from file using QuickSort with random pivot strategy:\n"
            << "    --file 3 3 boardgames.txt sorted_boardgames.txt -p 2\n";
}