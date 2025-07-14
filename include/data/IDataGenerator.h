#ifndef IDATAGENERATOR_H
#define IDATAGENERATOR_H

#include "IDataContainer.h"
#include <string>

template<typename T>
class IDataGenerator {
public:
    virtual void generate(IDataContainer<T>& container, int size) = 0;
    virtual ~IDataGenerator() = default;
};

#endif