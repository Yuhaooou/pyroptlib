// File: python/bindings.cpp
#include <pybind11/pybind11.h>
#include <test/TestFRankETextureInpainting.h>

namespace py = pybind11;

PYBIND11_MODULE(pyroptlib, m) {
    m.doc() = "My awesome C++ library exposed to Python";

    m.def("test", &testFRankETextureInpainting, "A function that tests CFRankQ2FBlindDecon2D");

}