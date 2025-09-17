// File: python/bindings.cpp
#include <pybind11/pybind11.h>
#include "cpptest.cpp"
#include "manifolds/element.cpp"

namespace py = pybind11;


PYBIND11_MODULE(pyroptlib, m) {
    m.doc() = "My awesome C++ library exposed to Python";

    bind_test_functions(m);

    bind_element_class(m);
}