#include "data/GeneratorFactory.h"
#include "data/RandomDataGenerator.h"
#include "data/SortedDataGenerator.h"
#include "data/PartiallySortedDataGenerator.h"
#include "types/Boardgame.h"
#include <stdexcept>

template<typename T>
std::shared_ptr<IDataGenerator<T>> createGenerator(DistributionType distribution) {
    switch (distribution) {
        case DistributionType::RANDOM:
            return std::make_shared<RandomDataGenerator<T>>();
        case DistributionType::SORTED_ASC:
            return std::make_shared<SortedDataGenerator<T>>(true);
        case DistributionType::SORTED_DESC:
            return std::make_shared<SortedDataGenerator<T>>(false);
        case DistributionType::SORTED_33:
            return std::make_shared<PartiallySortedDataGenerator<T>>(0.33);
        case DistributionType::SORTED_66:
            return std::make_shared<PartiallySortedDataGenerator<T>>(0.66);
        default:
            throw std::runtime_error("Invalid distribution type");
    }
}

template std::shared_ptr<IDataGenerator<int>> createGenerator(DistributionType);
template std::shared_ptr<IDataGenerator<float>> createGenerator(DistributionType);
template std::shared_ptr<IDataGenerator<std::string>> createGenerator(DistributionType);
template std::shared_ptr<IDataGenerator<Boardgame>> createGenerator(DistributionType); 