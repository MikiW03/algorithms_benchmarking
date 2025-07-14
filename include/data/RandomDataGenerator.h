#ifndef RANDOMDATAGENERATOR_H
#define RANDOMDATAGENERATOR_H

#include "IDataGenerator.h"
#include <random>
#include <type_traits>
#include <climits>

template<typename T>
class RandomDataGenerator : public IDataGenerator<T> {
private:
    std::mt19937 rng;
public:
    RandomDataGenerator();
    
    void generate(IDataContainer<T>& container, int size) override;
};

template<>
void RandomDataGenerator<int>::generate(IDataContainer<int>& container, int size);

template<>
void RandomDataGenerator<double>::generate(IDataContainer<double>& container, int size);

#endif