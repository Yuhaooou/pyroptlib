cmake_minimum_required(VERSION 3.20)
project(PYROPTLIB LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(BLAS REQUIRED)
find_package(FFTW3 REQUIRED)
add_definitions(-DROPTLIB_WITH_FFTW=1)

add_subdirectory(src)

target_link_libraries(roptlib PUBLIC ${BLAS_LIBRARIES})
target_link_libraries(roptlib PUBLIC ${FFTW3_LIBRARIES})

find_package(Python REQUIRED COMPONENTS Interpreter Development)
message(STATUS "Python include dirs: ${Python_INCLUDE_DIRS}")
add_subdirectory(pybind11)
add_subdirectory(bindings)
