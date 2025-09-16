// File: python/bindings.cpp
#include <pybind11/pybind11.h>
#include <test/TestCFRankQ2FBlindDecon2D.h>

namespace py = pybind11;

PYBIND11_MODULE(pyroptlib, m) {
    m.doc() = "My awesome C++ library exposed to Python";

    m.def("testCFRankQ2FBlindDecon2D", &testCFRankQ2FBlindDecon2D, "A function that tests CFRankQ2FBlindDecon2D");

}