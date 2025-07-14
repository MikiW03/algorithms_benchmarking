#ifndef IDATACONTAINER_H
#define IDATACONTAINER_H

#include <memory>

template<typename T>
class IDataContainer {
public:
    virtual T get(int index) const = 0;
    virtual void set(int index, const T& value) = 0;
    virtual void swap(int index1, int index2) = 0;
    [[maybe_unused]] [[nodiscard]] virtual bool isSorted() const = 0;
    [[nodiscard]] virtual int size() const = 0;
    virtual ~IDataContainer() = default;
};

#endif