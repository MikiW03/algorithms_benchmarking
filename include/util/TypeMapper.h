#ifndef TYPEMAPPER_H
#define TYPEMAPPER_H

#include "types/DataType.h"
#include "types/AlgorithmType.h"
#include "types/DistributionType.h"
#include "types/PivotStrategy.h"
#include "types/GapSequence.h"
#include <string>

class TypeMapper {
public:
    static DataType toDataType(int id);
    static std::string getDataTypeName(DataType type);
    static AlgorithmType toAlgorithmType(int id);
    static std::string getAlgorithmName(AlgorithmType type);
    static DistributionType toDistributionType(int id);
    static std::string getDistributionName(DistributionType type);
    static PivotStrategy toPivotStrategy(int stoi);
    static std::string getPivotStrategyName(PivotStrategy type);
    static GapSequence toGapSequence(int stoi);
    static std::string getGapSequenceName(GapSequence type);

};

#endif