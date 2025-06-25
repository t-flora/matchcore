cmake_minimum_required(VERSION 3.15)
project(matchcore)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set vcpkg toolchain file (optional, for local development)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
endif()

# Find Boost package
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

# Set Liquibook paths
set(LIQUIBOOK_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/external/liquibook")
set(LIQUIBOOK_INCLUDE_DIR "${LIQUIBOOK_ROOT}/src")
set(LIQUIBOOK_LIB_DIR "${LIQUIBOOK_ROOT}/lib")

# Add include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${LIQUIBOOK_INCLUDE_DIR}
    ${Boost_INCLUDE_DIRS}
)

# Add library directories
link_directories(
    ${LIQUIBOOK_LIB_DIR}
    ${Boost_LIBRARY_DIRS}
)

# Add executable
add_executable(matchcore src/main.cpp)

# Link libraries
target_link_libraries(matchcore PRIVATE 
    ${Boost_LIBRARIES}
    liquibook_simple
)

# Add test executable
add_executable(matchcore_tests src/main.cpp)
target_link_libraries(matchcore_tests PRIVATE 
    ${Boost_LIBRARIES}
    liquibook_simple
)

# Set output directories
set_target_properties(matchcore PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

set_target_properties(matchcore_tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)