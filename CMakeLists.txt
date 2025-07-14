cmake_minimum_required(VERSION 3.10)
project(sorting_algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
    if(MINGW)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
    endif()
endif()

include_directories(include)

file(GLOB_RECURSE LIB_SOURCES 
    "src/algorithms/*.cpp"
    "src/benchmarking/*.cpp"
    "src/io/*.cpp"
    "src/util/*.cpp"
)

add_library(sorting_lib STATIC ${LIB_SOURCES}
        src/algorithms/ShellSort.cpp)

add_executable(sorting_algorithms src/main.cpp
        include/benchmarking/SortingBenchmark.h
        src/benchmarking/SortingBenchmark.cpp
        src/algorithms/AlgorithmFactory.cpp
        src/data/DynamicArray.cpp
        src/data/PartiallySortedDataGenerator.cpp
        src/data/RandomDataGenerator.cpp
        src/data/SortedDataGenerator.cpp
        src/util/TypeMapper.cpp
        src/data/GeneratorFactory.cpp
        src/benchmarking/BenchmarkRunner.cpp
        src/types/Boardgame.cpp
        include/algorithms/HeapSort.h
        include/algorithms/QuickSort.h
        include/algorithms/ShellSort.h
        src/algorithms/QuickSort.cpp
        src/algorithms/ShellSort.cpp
        include/algorithms/DrunkShellSort.h
        src/algorithms/DrunkShellSort.cpp
        src/io/FileHandler.cpp
        src/io/FileRunner.cpp
)

target_link_libraries(sorting_algorithms PRIVATE sorting_lib)

enable_testing()