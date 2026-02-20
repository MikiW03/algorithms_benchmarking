# Sorting Algorithms Benchmark

## Overview

This project is a comprehensive C++ suite designed to benchmark and evaluate various sorting algorithms. It provides a flexible architecture for generating different types of datasets (random, sorted, partially sorted) and meticulously measuring the performance of implemented sorting techniques under varying conditions.

The primary goal of this repository is to analyze the time complexity and practical performance of classic and advanced sorting algorithms, producing detailed CSV reports (`benchmarks_results`, `ultimate_benchmarks_results`) for further analysis or graphing.

## Features & Implemented Algorithms

The application includes a rich set of sorting algorithms, all unified under a common interface (`ISortingAlgorithm`), allowing easy addition of new methods.

### Algorithms

- **Bubble Sort** (`BubbleSort.h`)
- **Insertion Sort** (`InsertionSort.h`)
- **Heap Sort** (`HeapSort.h`)
- **Quick Sort** (`QuickSort.h` - standard recursive/iterative)
- **Shell Sort** (`ShellSort.h`)
- **Drunk Shell Sort** (`DrunkShellSort.h` - custom/specialized variant)

### Data Generation

Data can be dynamically generated in arrays of varied sizes using different strategies:

- Randomly distributed data
- Completely sorted data
- Partially sorted data
- Reverse sorted data

## Project Architecture

The project is modularized into distinct directories inside `src/` and `include/` to separate concerns:

- **`algorithms/`**: Contains the implementations of all sorting algorithms and the `AlgorithmFactory` for dynamic instantiation.
- **`benchmarking/`**: Core logic for running tests (`BenchmarkRunner`), measuring execution times, and collecting statistics.
- **`data/`**: Classes responsible for generating and managing the datasets tested during benchmarks (`DynamicArray`, `GeneratorFactory`).
- **`io/`**: Handles reading configuration files, as well as saving the output benchmark metrics to CSV files.
- **`types/`**: Definitions for custom data structures (like `Boardgame.cpp`) used if object-based sorting is required instead of primitive types.
- **`util/`**: Helper files and basic utilities.

## Technologies Used

- **Language:** C++17 (Strictly enforced standard)
- **Build System:** CMake (Minimum version 3.10)
- **Environment:** Compatible with MSVC, MinGW, and standard Linux/macOS compilers (GCC/Clang).

## Build & Run Instructions

To compile and execute the benchmark suite locally, ensure you have a C++17 compliant compiler and CMake installed.

### 1. Build using CMake

```bash
# Create a build directory
mkdir build && cd build

# Configure and compile
cmake ..
cmake --build .
```

### 2. Run the Application

After a successful build, the executable will be generated (typically named `sorting_algorithms` or `sorting_algorithms.exe`). Run it from the terminal:

```bash
# On Linux/macOS
./sorting_algorithms

# On Windows
sorting_algorithms.exe
```

## Output & Results

The application outputs execution logs to the standard output and generates detailed benchmark reports
