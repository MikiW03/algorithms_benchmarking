#include "benchmarking/BenchmarkRunner.h"
#include "algorithms/AlgorithmFactory.h"
#include "data/GeneratorFactory.h"
#include "types/Boardgame.h"
#include <stdexcept>

template<typename T>
void BenchmarkRunner::run(const ArgumentParser& args) {
    auto benchmark = std::make_unique<SortingBenchmark<T>>();
    
    auto algorithm = createAlgorithm<T>(args.getAlgorithm(), args);
    benchmark->setAlgorithm(algorithm);
    
    auto generator = createGenerator<T>(args.getDistribution());
    benchmark->setDataGenerator(generator);

    benchmark->setDataSize(args.getSize());
    
    auto result = benchmark->run();
    result.dataType = TypeMapper::getDataTypeName(args.getDataType());
    result.algorithmName = TypeMapper::getAlgorithmName(args.getAlgorithm());
    result.distributionName = TypeMapper::getDistributionName(args.getDistribution());
    result.pivotStrategy = TypeMapper::getPivotStrategyName(args.getPivotStrategy());
    result.gapSequence = TypeMapper::getGapSequenceName(args.getGapSequence());
    result.drunkLevel = args.getDrunkLevel();

    if (!CSVFileHandler::saveToCSV({result}, args.getOutputFile())) {
        throw std::runtime_error("Failed to save results to file");
    }

    displayResults(result, args);
}

void BenchmarkRunner::displayResults(const BenchmarkResult& result, [[maybe_unused]] const ArgumentParser& args) {
    std::cout << "Benchmark results:" << std::endl;
    std::cout << "Algorithm: " << result.algorithmName << std::endl;
    std::cout << "Data size: " << result.dataSize << std::endl;
    std::cout << "Data type: " << result.dataType << std::endl;
    std::cout << "Data distribution: " << result.distributionName << std::endl;
    std::cout << "Time: " << result.time << " ms" << std::endl;
    std::cout << "Comparisons: " << result.comparisons << std::endl;
    std::cout << "Swaps: " << result.swaps << std::endl;

    if(result.algorithmName == TypeMapper::getAlgorithmName(AlgorithmType::QUICK_SORT)){
        std::cout << "Pivot strategy: " << result.pivotStrategy << std::endl;
    }

    if(result.algorithmName == TypeMapper::getAlgorithmName(AlgorithmType::SHELL_SORT)){
        std::cout << "Gap sequence: " << result.gapSequence << std::endl;
    }

    if(result.algorithmName == TypeMapper::getAlgorithmName(AlgorithmType::DRUNK_SHELL_SORT)){
        std::cout << "Drunk level: " << result.drunkLevel << std::endl;
    }
}

template void BenchmarkRunner::run<int>(const ArgumentParser& args);
template void BenchmarkRunner::run<float>(const ArgumentParser& args);
template void BenchmarkRunner::run<std::string>(const ArgumentParser& args);
template void BenchmarkRunner::run<Boardgame>(const ArgumentParser& args); 