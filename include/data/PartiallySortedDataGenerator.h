#ifndef PARTIALLYSORTEDDATAGENERATOR_H
#define PARTIALLYSORTEDDATAGENERATOR_H

#include "IDataGenerator.h"
#include "SortedDataGenerator.h"
#include <random>

template<typename T>
class PartiallySortedDataGenerator : public IDataGenerator<T> {
private:
    double sortedPortion;
    std::mt19937 rng;
    SortedDataGenerator<T> sortedGen;

public:
    explicit PartiallySortedDataGenerator(double sortedPortion = 0.5);
    void generate(IDataContainer<T>& container, int size) override;
};

#endif 