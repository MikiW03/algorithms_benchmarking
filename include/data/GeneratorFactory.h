#ifndef GENERATORFACTORY_H
#define GENERATORFACTORY_H

#include "IDataGenerator.h"
#include "../util/TypeMapper.h"
#include <memory>

template<typename T>
std::shared_ptr<IDataGenerator<T>> createGenerator(DistributionType distribution);

#endif