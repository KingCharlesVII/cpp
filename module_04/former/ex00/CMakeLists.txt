cmake_minimum_required(VERSION 3.14)

project(MonProjet)

set(CMAKE_CXX_STANDARD 98)

enable_testing()

# =========================
# GoogleTest
# =========================

add_subdirectory(external/googletest)

# =========================
# Librairie du projet
# =========================

add_library(
    mon_code
    srcs/main.cpp
)

# Répertoires d'include
target_include_directories(
    mon_code
    PUBLIC
    includes
)

# =========================
# Executable de tests
# =========================

add_executable(
    tests_unitaires
    tests/test.cpp
)

# Link tests -> ton code + gtest
target_link_libraries(
    tests_unitaires
    PRIVATE
    mon_code
    GTest::gtest_main
)

# Découverte auto des tests
include(GoogleTest)
gtest_discover_tests(tests_unitaires)