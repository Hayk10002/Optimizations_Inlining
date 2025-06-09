# Optimizations_Inlining

## Table of Contents
- [Introduction](#introduction)
- [Build and Run](#build-and-run)
- [Example Output](#example-output)
- [How does this work](#how-does-this-work)

## Introduction
This program measures the effect of inlining small functions in the code

## Build and Run
To clone and run this project, you'll need [Git](https://git-scm.com) and [CMake](https://cmake.org/) installed on your computer. From your command line:

```bash
# Clone this repository
$ git clone https://github.com/Hayk10002/Optimizations_Inlining

# Go into the repository
$ cd Optimizations_Inlining

# Generate the build files
$ cmake -DCMAKE_BUILD_TYPE=Release -S . -B build

# Build the project
$ cmake --build build --config Release

# Then, run the executable generated in the `build` directory.
$ your/path/to/exe/main.exe
```

## Example Output
```
Inline sum:   -1001592323 in 20ms
Noinline sum: -1001592323 in 155ms
```

## How does this work
From the output it can be seen that inlining small functions can reduce execution time almost 8x.