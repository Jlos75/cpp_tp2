cmake_minimum_required(VERSION 4.0)
project(tp2_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(tp2_cpp main.cpp
        TimeSeriesGenerator.cpp
        TimeSeriesGenerator.h
        GaussianGenerator.cpp
        GaussianGenerator.h
        StepGenerator.cpp
        StepGenerator.h
        SinWaveGenerator.cpp
        SinWaveGenerator.h
        TimeSeriesDataset.cpp
        TimeSeriesDataset.h
        KNN.cpp
        KNN.h)
