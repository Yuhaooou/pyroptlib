include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR} 
    ${CMAKE_CURRENT_SOURCE_DIR}/cwrapper/blas
    ${CMAKE_CURRENT_SOURCE_DIR}/cwrapper/lapack
    ${CMAKE_CURRENT_SOURCE_DIR}/tools/f2c
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
    ${TESTSRC}
)


add_library(roptlib STATIC ${ALL_SRC})
