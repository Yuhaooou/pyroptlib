pybind11_add_module(pyroptlib
    bindings.cpp
)

target_link_libraries(pyroptlib
    PRIVATE
        roptlib
        pybind11::module
)

# 包含头文件目录
target_include_directories(pyroptlib
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/..
        ${CMAKE_CURRENT_SOURCE_DIR}/../cwrapper/blas
        ${CMAKE_CURRENT_SOURCE_DIR}/../cwrapper/lapack
)

add_custom_command(TARGET pyroptlib POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:pyroptlib> ${CMAKE_CURRENT_SOURCE_DIR}/..
    COMMENT "Copying generated Python module to project root directory"
)