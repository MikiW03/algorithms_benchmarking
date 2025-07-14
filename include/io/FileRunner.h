#ifndef FILERUNNER_H
#define FILERUNNER_H

#include "io/ArgumentParser.h"
#include "data/DynamicArray.h"
#include "io/FileHandler.h"
#include "algorithms/AlgorithmFactory.h"
#include "util/Timer.h"
#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

class FileRunner {
public:
    template<typename T>
    static void run(const ArgumentParser& args);
    static void run(const ArgumentParser& args);
};

#endif