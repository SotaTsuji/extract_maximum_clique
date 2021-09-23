cmake_minimum_required(VERSION 3.10)
project(extract_maximum_clique
        VERSION 1.0.0
        DESCRIPTION "Polynomial-time Extraction of the Maximum Clique Using Eigenvalue Relation"
        LANGUAGES CXX)
add_library(extract_maximum_clique STATIC ./src/extract_maximum_clique.cpp)
add_library(calculate_km STATIC ./src/calculate_km.cpp)
target_compile_features(extract_maximum_clique PRIVATE cxx_std_20)
target_compile_features(calculate_km PRIVATE cxx_std_20)
target_include_directories(extract_maximum_clique INTERFACE
                           calculate_km INTERFACE
                           ./include)
set_target_properties(extract_maximum_clique
                      calculate_km
                      PROPERTIES VERSION ${PROJECT_VERSION})
