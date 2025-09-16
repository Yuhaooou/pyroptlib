cmake_minimum_required(VERSION 3.10)
project(ROPTLIB LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${PROJECT_SOURCE_DIR} 
    ${PROJECT_SOURCE_DIR}/cwrapper/blas
    ${PROJECT_SOURCE_DIR}/cwrapper/lapack
    ${PROJECT_SOURCE_DIR}/tools/f2c
)

file(GLOB MANIFOLDS_SRC Manifolds/*.cpp)
file(GLOB PROBLEMS_SRC Problems/*.cpp)
file(GLOB SOLVERS_SRC Solvers/*.cpp)
file(GLOB OTHERS_SRC Others/*.cpp)
file(GLOB TESTSRC test/*.cpp)

set(ALL_SRC
    ${MANIFOLDS_SRC}
    ${PROBLEMS_SRC}
    ${SOLVERS_SRC}
    ${OTHERS_SRC}
    ${CWRAPPER_SRC}
    ${TESTSRC}
)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(roptlib STATIC ${ALL_SRC})


find_package(BLAS REQUIRED)
find_package(FFTW3 REQUIRED)
add_definitions(-DROPTLIB_WITH_FFTW=1)

target_link_libraries(roptlib PUBLIC ${BLAS_LIBRARIES})
target_link_libraries(roptlib PUBLIC ${FFTW3_LIBRARIES})


find_package(Python REQUIRED COMPONENTS Interpreter Development)
add_subdirectory(pybind11)
add_subdirectory(python)
