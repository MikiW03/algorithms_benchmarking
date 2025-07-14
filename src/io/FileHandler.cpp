#include "io/FileHandler.h"
#include "data/DynamicArray.h"
#include "types/Boardgame.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <filesystem>

namespace fs = std::filesystem;

template<typename T>
bool FileHandler<T>::loadFromFile(const std::string& filename, IDataContainer<T>& container) {
    std::string inputPath = getInputPath(filename);
    
    std::ifstream file(inputPath);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << inputPath << std::endl;
        return false;
    }
    
    int size;
    file >> size;
    
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    auto* dynamicArray = dynamic_cast<DynamicArray<T>*>(&container);
    if (dynamicArray) {
        dynamicArray->clear();
        for (int i = 0; i < size; i++) {
            dynamicArray->add(T());
        }
    } else if (container.size() < size) {
        std::cerr << "Container too small for the number of elements to be loaded" << std::endl;
        return false;
    }
    
    if constexpr (std::is_same_v<T, int> || std::is_same_v<T, float>) {
        T value;
        for (int i = 0; i < size; i++) {
            if (file >> value) {
                container.set(i, value);
            } else {
                std::cerr << "Error while reading data from file" << std::endl;
                return false;
            }
        }
    } else if constexpr (std::is_same_v<T, std::string>) {
        std::string line;
        for (int i = 0; i < size; i++) {
            if (std::getline(file, line)) {
                container.set(i, line);
            } else {
                std::cerr << "Error while reading data from file" << std::endl;
                return false;
            }
        }
    } else if constexpr (std::is_same_v<T, Boardgame>) {
        std::string line;
        for (int i = 0; i < size; i++) {
            if (std::getline(file, line)) {
                std::stringstream ss(line);
                std::string name, publisher;
                int minPlayers, maxPlayers, playTime, complexity, funFactor;
                
                std::getline(ss, name, ',');
                std::getline(ss, publisher, ',');
                ss >> minPlayers; ss.ignore();
                ss >> maxPlayers; ss.ignore();
                ss >> playTime; ss.ignore();
                ss >> complexity; ss.ignore();
                ss >> funFactor;
                
                Boardgame boardgame(name, publisher, minPlayers, maxPlayers, playTime, complexity, funFactor);
                container.set(i, boardgame);
            } else {
                std::cerr << "Error while reading data from file" << std::endl;
                return false;
            }
        }
    } else {
        std::cerr << "Unsupported data type" << std::endl;
        return false;
    }
    
    return true;
}

template<typename T>
bool FileHandler<T>::saveToFile(const std::string& filename, const IDataContainer<T>& container) {
    std::string outputPath = getOutputPath(filename);
    
    fs::path dirPath = fs::path(outputPath).parent_path();
    if (!dirPath.empty() && !fs::exists(dirPath)) {
        try {
            fs::create_directories(dirPath);
        } catch (const std::exception& e) {
            std::cerr << "Cannot create directory: " << dirPath.string() << " - " << e.what() << std::endl;
            return false;
        }
    }
    
    std::ofstream file(outputPath);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << outputPath << std::endl;
        return false;
    }
    
    file << container.size() << std::endl;
    
    if constexpr (std::is_same_v<T, int> || std::is_same_v<T, float> || std::is_same_v<T, std::string>) {
        for (int i = 0; i < container.size(); i++) {
            file << container.get(i) << std::endl;
        }
    } else if constexpr (std::is_same_v<T, Boardgame>) {
        for (int i = 0; i < container.size(); i++) {
            Boardgame bg = container.get(i);
            file << bg.getName() << ","
                 << bg.getPublisher() << ","
                 << bg.getMinPlayers() << ","
                 << bg.getMaxPlayers() << ","
                 << bg.getPlayTime() << ","
                 << bg.getComplexity() << ","
                 << bg.getFunFactor() << std::endl;
        }
    } else {
        std::cerr << "Unsupported data type" << std::endl;
        return false;
    }
    
    return true;
}

template<typename T>
std::string FileHandler<T>::getInputPath(const std::string& filename) {
    return filename;
}

template<typename T>
std::string FileHandler<T>::getOutputPath(const std::string& filename) {
    return filename;
}

template class FileHandler<int>;
template class FileHandler<float>;
template class FileHandler<std::string>;
template class FileHandler<Boardgame>; 