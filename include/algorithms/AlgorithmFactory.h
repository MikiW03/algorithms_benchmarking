#ifndef ALGORITHMFACTORY_H
#define ALGORITHMFACTORY_H

#include "algorithms/ISortingAlgorithm.h"
#include "io/ArgumentParser.h"
#include "../util/TypeMapper.h"
#include <memory>
#include "../types/AlgorithmType.h"

template<typename T>
std::shared_ptr<ISortingAlgorithm<T>> createAlgorithm(AlgorithmType algorithmType, const ArgumentParser& args);

#endif 