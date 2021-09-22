cmake_minimum_required(VERSION 3.10)
project(extraction_maximum_clique
        VERSION 1.0.0
        DESCRIPTION "Polynomial-time Extraction of the Maximum Clique Using Eigenvalue Relation"
        LANGUAGES CXX)
add_library(extraction_maximum_clique
            STATIC
            ./src/extraction_maximum_clique.cpp)
target_compile_features(extraction_maximum_clique
                        PRIVATE
                        cxx_std_17)
target_include_directories(extraction_maximum_clique
                           INTERFACE
                           ./include)
set_target_properties(extraction_maximum_clique
                      PROPERTIES
                      VERSION ${PROJECT_VERSION})
