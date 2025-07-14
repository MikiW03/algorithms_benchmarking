#ifndef SORTEDDATAGENERATOR_H
#define SORTEDDATAGENERATOR_H

#include "IDataGenerator.h"
#include "RandomDataGenerator.h"
#include <vector>

template<typename T>
class SortedDataGenerator : public IDataGenerator<T> {
private:
    bool ascending;
    RandomDataGenerator<T> randomGen;

public:
    explicit SortedDataGenerator(bool ascending = true);
    void generate(IDataContainer<T>& container, int size) override;
};

#endif