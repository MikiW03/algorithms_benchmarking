#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "../data/IDataContainer.h"
#include <string>
#include <vector>
#include <memory>
#include "../types/Boardgame.h"

template<typename T>
class FileHandler {
public:
    static bool loadFromFile(const std::string& filename, IDataContainer<T>& container);
    static bool saveToFile(const std::string& filename, const IDataContainer<T>& container);

private:
    static std::string getInputPath(const std::string& filename);
    static std::string getOutputPath(const std::string& filename);
};

#endif