pybind11_add_module(pyroptlib
    bindings.cpp
)

target_link_libraries(pyroptlib
    PRIVATE
        roptlib
        pybind11::module
)

target_include_directories(pyroptlib
    PRIVATE
        ${PROJECT_SOURCE_DIR}/pybind11
        ${PROJECT_SOURCE_DIR}/ROPTLIB
        ${PROJECT_SOURCE_DIR}/ROPTLIB/cwrapper/blas
        ${PROJECT_SOURCE_DIR}/ROPTLIB/cwrapper/lapack
)

add_custom_command(TARGET pyroptlib POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:pyroptlib> ${PROJECT_SOURCE_DIR}
    COMMENT "Copying generated Python module to project root directory"
)