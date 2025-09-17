#include <pybind11/pybind11.h>
#include <test/TestCFRankQ2FBlindDecon2D.h>
#include <test/TestFRankETextureInpainting.h>
#include <test/TestProdStieSumBrockett.h>
#include <test/TestGrassSVPCA.h>
#include <test/TestElement.h>
#include <test/TestSphereSparsestVector.h>
#include <test/TestGrassPCA.h>
#include <test/TestGrassMatCompletion.h>
#include <test/TestSFRQLyapunov.h>
#include <test/TestStieSoftICA.h>
#include <test/TestFRankESparseApprox.h>
#include <test/TestFRankEWeightApprox.h>
#include <test/TestFRankE3FMatCompletion.h>
#include <test/TestCStieBrockett.h>
#include <test/TestSPDKarcherMean.h>
#include <test/TestEucQuadratic.h>
#include <test/TestObliqueSPCA.h>
#include <test/TestFRankQ2FMatCompletion.h>
#include <test/TestStieSPCA.h>
#include <test/TestPoincareEmbeddings.h>
#include <test/TestGrassRQ.h>
#include <test/TestCSFRQPhaseRetrieval.h>
#include <test/TestFRankETextureInpainting.h>

namespace py = pybind11;

void bind_test_functions(py::module& m) {
    m.def("testCFRankQ2FBlindDecon2D", &testCFRankQ2FBlindDecon2D);
    m.def("testFRankETextureInpainting", &testFRankETextureInpainting);
    m.def("testProdStieSumBrockett", &testProdStieSumBrockett);
    m.def("testGrassSVPCA", &testGrassSVPCA);
    m.def("testElement", &testElement);
    m.def("testSphereSparsestVector", &testSphereSparsestVector);
    m.def("testGrassPCA", &testGrassPCA);
    m.def("testGrassMatCompletion", &testGrassMatCompletion);
    m.def("testSFRQLyapunov", &testSFRQLyapunov);
    m.def("testStieSoftICA", &testStieSoftICA);
    m.def("testFRankESparseApprox", &testFRankESparseApprox);
    m.def("testFRankEWeightApprox", &testFRankEWeightApprox);
    m.def("testFRankE3FMatCompletion", &testFRankE3FMatCompletion);
    m.def("testCStieBrockett", &testCStieBrockett);
    m.def("testSPDKarcherMean", &testSPDKarcherMean);
    m.def("testEucQuadratic", &testEucQuadratic);
    m.def("testObliqueSPCA", &testObliqueSPCA);
    m.def("testFRankQ2FMatCompletion", &testFRankQ2FMatCompletion);
    m.def("testStieSPCA", &testStieSPCA);
    m.def("testPoincareEmbeddings", &testPoincareEmbeddings);
    m.def("testGrassRQ", &testGrassRQ);
    m.def("testCSFRQPhaseRetrieval", &testCSFRQPhaseRetrieval);
}