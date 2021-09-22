cmake_minimum_required(VERSION 3.10)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(Test test_extraction_maximum_clique.cpp)
target_link_libraries(Test extraction_maximum_clique
                      GTest::GTest
                      GTest::Main)
include_directories(${PROJECT_SOURCE_DIR}/src
                    ${GTEST_INCLUDE_DIRS})

gtest_add_tests(TARGET Test)
