#include <iostream>
#include "io/ArgumentParser.h"
#include "util/TypeMapper.h"
#include "benchmarking/BenchmarkRunner.h"
#include "types/Boardgame.h"
#include "io/FileRunner.h"

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    try {
        ArgumentParser args(argc, argv);

        switch (args.getMode()) {
            case ArgumentParser::Mode::HELP:
                ArgumentParser::printHelp();
                break;

            case ArgumentParser::Mode::TEST:
                switch (args.getDataType()) {
                    case DataType::INT:
                        BenchmarkRunner::run<int>(args);
                        break;
                    case DataType::FLOAT:
                        BenchmarkRunner::run<float>(args);
                        break;
                    case DataType::STRING:
                        BenchmarkRunner::run<std::string>(args);
                        break;
                    case DataType::BOARDGAME:
                        BenchmarkRunner::run<Boardgame>(args);
                        break;
                    default:
                        throw std::runtime_error("Unsupported data type");
                }
                break;

            case ArgumentParser::Mode::FILE:
                switch (args.getDataType()) {
                    case DataType::INT:
                        FileRunner::run<int>(args);
                        break;
                    case DataType::FLOAT:
                        FileRunner::run<float>(args);
                        break;
                    case DataType::STRING:
                        FileRunner::run<std::string>(args);
                        break;
                    case DataType::BOARDGAME:
                        FileRunner::run<Boardgame>(args);
                        break;
                    default:
                        throw std::runtime_error("Unsupported data type");
                }
                break;

            default:
                ArgumentParser::printHelp();
                throw std::runtime_error("Unsupported mode");
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}