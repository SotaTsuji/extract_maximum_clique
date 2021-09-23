cmake_minimum_required(VERSION 3.10)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(Test test_extract_maximum_clique.cpp test_calculate_km.cpp)
target_link_libraries(Test
                      extract_maximum_clique calculate_km
                      GTest::GTest GTest::Main)
include_directories(${PROJECT_SOURCE_DIR}/src
                    ${GTEST_INCLUDE_DIRS})

gtest_add_tests(TARGET Test)
