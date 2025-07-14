#include "io/FileRunner.h"
#include "types/Boardgame.h"
#include "util/TypeMapper.h"
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

template<typename T>
void FileRunner::run(const ArgumentParser& args) {
    DynamicArray<T> container;
    
    if (FileHandler<T>::loadFromFile(args.getInputFile(), container)) {
        std::cout << "Loaded " << container.size() << " elements from file " << args.getInputFile() << std::endl;
        
        auto algorithm = createAlgorithm<T>(args.getAlgorithm(), args);
        
        Timer timer;
        timer.start();
        algorithm->sort(container);
        timer.stop();
        
        bool isSorted = container.isSorted();
        std::cout << "Data sorted correctly: " << (isSorted ? "YES" : "NO") << std::endl;
        std::cout << "Sorting time: " << timer.result() << " ms" << std::endl;
        
        std::string outputFile = args.getOutputFile();
        if (outputFile.empty()) {
            std::string baseName = args.getInputFile();
            
            size_t lastSlash = baseName.find_last_of("/\\");
            if (lastSlash != std::string::npos) {
                baseName = baseName.substr(lastSlash + 1);
            }
            
            size_t lastDot = baseName.find_last_of('.');
            if (lastDot != std::string::npos) {
                baseName = baseName.substr(0, lastDot);
            }
            
            std::string algorithmName = TypeMapper::getAlgorithmName(args.getAlgorithm());
            for (char& c : algorithmName) {
                if (c == ' ') c = '_';
                else c = std::tolower(c);
            }
            
            outputFile = baseName + "_" + algorithmName + "_sorted.txt";
            std::cout << "No output file specified, using default: " << outputFile << std::endl;
        }
        
        if (FileHandler<T>::saveToFile(outputFile, container)) {
            std::cout << "Saved sorted data to file " << outputFile << std::endl;
        } else {
            std::cerr << "Error saving to file " << outputFile << std::endl;
        }
    } else {
        std::cerr << "Error loading file " << args.getInputFile() << std::endl;
    }
}

template void FileRunner::run<int>(const ArgumentParser& args);
template void FileRunner::run<float>(const ArgumentParser& args);
template void FileRunner::run<std::string>(const ArgumentParser& args);
template void FileRunner::run<Boardgame>(const ArgumentParser& args); 