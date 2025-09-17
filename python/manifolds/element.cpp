#include "pybind11/pybind11.h"
#include "pybind11/operators.h"
#include "pybind11/stl.h"
#include "pybind11/numpy.h"
#include "Manifolds/Element.h"

namespace py = pybind11;
using namespace ROPTLIB;

void bind_element_class(py::module& m){
    py::class_<Element, std::shared_ptr<Element>>(m, "Element")
        // Constructors
        .def(py::init<>(), "Construct an empty Element")
        .def(py::init<const Element&>(), "Copy constructor")
        .def(py::init<integer, integer, integer, const char*>(), 
             py::arg("r"), py::arg("l") = 1, py::arg("n") = 1, py::arg("type") = "real",
             "Construct an empty Element with size information")
        .def(py::init<integer, integer, integer, bool>(),
             py::arg("r"), py::arg("l"), py::arg("n"), py::arg("iscomplex"),
             "Construct an empty Element with size information")
        .def(py::init<integer, integer, const char*>(),
             py::arg("r"), py::arg("l"), py::arg("type"),
             "Construct an empty Element with size information")
        .def(py::init<integer, const char*>(),
             py::arg("r"), py::arg("type"),
             "Construct an empty Element with size information")
        
        // Basic operations
        .def("Print", &Element::Print,
             py::arg("name") = "", py::arg("isonlymain") = true,
             "Print the element to screen")
        .def("PrintSize", &Element::PrintSize,
             py::arg("name") = "", py::arg("isonlymain") = true,
             "Print size of the data")
        .def("CopyTo", &Element::CopyTo, "Copy the element to another one")
        .def("CopyFieldsTo", &Element::CopyFieldsTo, "Copy all temp data to another element")
        
        // Memory and data access
        .def("ObtainWriteEntireData", &Element::ObtainWriteEntireData,
             py::return_value_policy::reference_internal,
             "Obtain pointer to data for overwriting")
        .def("ObtainWritePartialData", &Element::ObtainWritePartialData,
             py::return_value_policy::reference_internal,
             "Obtain pointer to data with copy-on-write")
        .def("NewMemoryOnWrite", &Element::NewMemoryOnWrite,
             "Allocate new memory without copying data")
        .def("CopyOnWrite", &Element::CopyOnWrite,
             "Allocate new memory and copy data")
        
        // Random generation and initialization
        .def("RandUnform", &Element::RandUnform,
             py::arg("start") = 0, py::arg("end") = 1,
             "Randomly generate element with uniform distribution")
        .def("RandGaussian", &Element::RandGaussian,
             py::arg("mean") = 0, py::arg("variance") = 1,
             "Randomly generate element with Gaussian distribution")
        .def("SetToZeros", &Element::SetToZeros, "Set all entries to zero")
        .def("SetToIdentity", &Element::SetToIdentity, "Set matrix to identity")
        .def("ScaledIdOPE", &Element::ScaledIdOPE,
             py::arg("scalar") = 1,
             "Set element to scalar times identity")
        
        // Norms and distances
        .def("Fnorm", &Element::Fnorm, "Compute Frobenius norm")
        .def("Onenorm", &Element::Onenorm, "Compute one-norm")
        .def("DotProduct", &Element::DotProduct, "Compute real part of conjugate transpose product")
        .def("Max", &Element::Max, "Compute maximum element")
        .def("Min", &Element::Min, "Compute minimum element")
        .def("MinNozero", &Element::MinNozero, "Compute minimum non-zero element")
        
        // Linear algebra operations
        .def("LUdecom", &Element::LUdecom, "LU decomposition")
        .def("CholDecom", &Element::CholDecom, "Cholesky decomposition")
        .def("TriangleLinSol", &Element::TriangleLinSol,
             py::arg("L"), py::arg("trans") = "N",
             "Solve triangular linear system")
        .def("EigenDecomSym", &Element::EigenDecomSym,
             py::arg("JobZ") = "V", py::arg("UorL") = "L",
             "Eigenvalue decomposition for symmetric matrix")
        .def("ExpSym", &Element::ExpSym,
             py::arg("UorL") = "L",
             "Matrix exponential for symmetric matrix")
        .def("LogSym", &Element::LogSym,
             py::arg("UorL") = "L",
             "Matrix logarithm for symmetric matrix")
        .def("SqrtMSym", &Element::SqrtMSym,
             py::arg("UorL") = "L",
             "Matrix square root for symmetric matrix")
        .def("HHRDecom", &Element::HHRDecom, "Householder reflections decomposition")
        .def("HHRMtp", &Element::HHRMtp,
             py::arg("HHR"), py::arg("tau"), py::arg("Trans") = "N", py::arg("Side") = "L",
             "Multiply by Householder reflectors")
        .def("QRDecom", &Element::QRDecom, "QR decomposition")
        .def("SVDDecom", &Element::SVDDecom, "SVD decomposition")
        .def("PseudoInverseMatrix", &Element::PseudoInverseMatrix, "Pseudo-inverse matrix")
        .def("SchurForm", &Element::SchurForm,
             py::arg("jobvs") = "V",
             "Schur form decomposition")
        .def("SYL", &Element::SYL, "Solve Sylvester equation")
        
        // Matrix operations that return new elements
        .def("GetDiagTimesM", &Element::GetDiagTimesM,
             py::arg("M"), py::arg("side") = "L",
             "Compute diagonal times matrix")
        .def("GetHadamardProduct", &Element::GetHadamardProduct,
             "Compute Hadamard (element-wise) product")
        .def("GetHadamardDivision", &Element::GetHadamardDivision,
             "Compute Hadamard (element-wise) division")
        .def("GetReshape", &Element::GetReshape,
             py::arg("r"), py::arg("c") = 1, py::arg("n") = 1,
             "Reshape element")
        .def("GetHaddRankone", static_cast<Element (Element::*)(realdp, Element, Element) const>(&Element::GetHaddRankone),
             "Add rank-one update (real)")
        .def("GetHaddRankone", static_cast<Element (Element::*)(realdpcomplex, Element, Element) const>(&Element::GetHaddRankone),
             "Add rank-one update (complex)")
        .def("GetMax", static_cast<Element (Element::*)(Element) const>(&Element::GetMax),
             "Element-wise maximum with another element")
        .def("GetMax", static_cast<Element (Element::*)(realdp) const>(&Element::GetMax),
             "Element-wise maximum with scalar")
        .def("GetMin", static_cast<Element (Element::*)(Element) const>(&Element::GetMin),
             "Element-wise minimum with another element")
        .def("GetMin", static_cast<Element (Element::*)(realdp) const>(&Element::GetMin),
             "Element-wise minimum with scalar")
        .def("GetAbs", &Element::GetAbs, "Element-wise absolute value")
        .def("GetSqrt", &Element::GetSqrt, "Element-wise square root")
        .def("GetOrth", &Element::GetOrth, "Orthogonalization")
        .def("GetConj", &Element::GetConj, "Complex conjugate")
        .def("GetHtimesRankone", static_cast<Element (Element::*)(realdp, Element, char*) const>(&Element::GetHtimesRankone),
             py::arg("scalar"), py::arg("v"), py::arg("side") = "L",
             "Householder transformation (real)")
        .def("GetHtimesRankone", static_cast<Element (Element::*)(realdpcomplex, Element, char*) const>(&Element::GetHtimesRankone),
             py::arg("scalar"), py::arg("v"), py::arg("side") = "L",
             "Householder transformation (complex)")
        .def("GetSubmatrix", &Element::GetSubmatrix,
             "Extract submatrix")
        .def("GetTranspose", &Element::GetTranspose, "Matrix transpose")
        .def("GetColNormsSquare", &Element::GetColNormsSquare, "Column norms squared")
        .def("GetColDotProducts", &Element::GetColDotProducts, "Column dot products")
        .def("GetRealToComplex", &Element::GetRealToComplex, "Convert real to complex")
        .def("GetRealInComplex", &Element::GetRealInComplex, "Get real part of complex")
        .def("GetImagInComplex", &Element::GetImagInComplex, "Get imaginary part of complex")
        
        // In-place operations
        .def("DiagTimesM", &Element::DiagTimesM,
             py::arg("M"), py::arg("side") = "L",
             py::return_value_policy::reference,
             "In-place diagonal times matrix")
        .def("HaddRankone", static_cast<Element& (Element::*)(realdp, const Element&, const Element&)>(&Element::HaddRankone),
             py::return_value_policy::reference,
             "In-place rank-one update (real)")
        .def("HaddRankone", static_cast<Element& (Element::*)(realdpcomplex, const Element&, const Element&)>(&Element::HaddRankone),
             py::return_value_policy::reference,
             "In-place rank-one update (complex)")
        .def("AlphaXaddThis", static_cast<Element& (Element::*)(realdp, const Element&)>(&Element::AlphaXaddThis),
             py::return_value_policy::reference,
             "this = this + alpha * X (real)")
        .def("AlphaXaddThis", static_cast<Element& (Element::*)(realdpcomplex, const Element&)>(&Element::AlphaXaddThis),
             py::return_value_policy::reference,
             "this = this + alpha * X (complex)")
        .def("ScalarTimesThis", static_cast<Element& (Element::*)(realdp)>(&Element::ScalarTimesThis),
             py::return_value_policy::reference,
             "this = alpha * this (real)")
        .def("ScalarTimesThis", static_cast<Element& (Element::*)(realdpcomplex)>(&Element::ScalarTimesThis),
             py::return_value_policy::reference,
             "this = alpha * this (complex)")
        .def("AlphaABaddBetaThis", static_cast<Element& (Element::*)(realdp, const Element&, char*, const Element&, char*, realdp)>(&Element::AlphaABaddBetaThis),
             py::return_value_policy::reference,
             "this = alpha * A^? * B^? + beta * this (real)")
        .def("AlphaABaddBetaThis", static_cast<Element& (Element::*)(realdpcomplex, const Element&, char*, const Element&, char*, realdpcomplex)>(&Element::AlphaABaddBetaThis),
             py::return_value_policy::reference,
             "this = alpha * A^? * B^? + beta * this (complex)")
        .def("Reshape", &Element::Reshape,
             py::arg("r"), py::arg("c") = 1, py::arg("n") = 1,
             py::return_value_policy::reference,
             "In-place reshape")
        .def("Conj", &Element::Conj,
             py::return_value_policy::reference,
             "In-place complex conjugate")
        .def("SubmatrixAssignment", &Element::SubmatrixAssignment,
             py::return_value_policy::reference,
             "Assign to submatrix")
        .def("Transpose", &Element::Transpose,
             py::return_value_policy::reference,
             "In-place transpose")
        
        // Wavelet transforms
        .def("GetHaarFWT", &Element::GetHaarFWT, "Haar wavelet transform")
        .def("GetInvHaarFWT", &Element::GetInvHaarFWT, "Inverse Haar wavelet transform")
        
        // Field operations
        .def("AddToFields", static_cast<void (Element::*)(std::string, const Element&) const>(&Element::AddToFields),
             "Add element to fields")
        .def("AddToFields", static_cast<void (Element::*)(std::string, Element&) const>(&Element::AddToFields),
             "Add element to fields")
        .def("Field", &Element::Field,
             py::return_value_policy::reference,
             "Access field by name")
        .def("RemoveFromFields", &Element::RemoveFromFields, "Remove field by name")
        .def("RemoveAllFromFields", &Element::RemoveAllFromFields, "Remove all fields")
        .def("FieldsExist", &Element::FieldsExist, "Check if field exists")
        .def("GetSizeofFields", &Element::GetSizeofFields, "Get number of fields")
        
        // Getters
        .def("Getiscomplex", &Element::Getiscomplex, "Check if element is complex")
        .def("Getrow", &Element::Getrow, "Get number of rows")
        .def("Getcol", &Element::Getcol, "Get number of columns")
        .def("Getnum", &Element::Getnum, "Get number of matrices")
        .def("Getelements", &Element::Getelements,
             py::return_value_policy::reference_internal,
             "Get elements array")
        .def("Getnumofelements", &Element::Getnumofelements, "Get number of elements")
        .def("Getpowsinterval", &Element::Getpowsinterval,
             py::return_value_policy::reference_internal,
             "Get powers interval")
        .def("Getnumoftypes", &Element::Getnumoftypes, "Get number of types")
        .def("GetElement", &Element::GetElement,
             py::return_value_policy::reference,
             "Get element by index")
        
        // Setters
        .def("Setiscomplex", &Element::Setiscomplex, "Set if element is complex")
        
        // Sparse matrix operations
        .def("AddSparseMatrixToFields", &Element::AddSparseMatrixToFields,
             "Add sparse matrix to fields")
        .def("GetSparseMatrixinFields", &Element::GetSparseMatrixinFields,
             py::return_value_policy::reference_internal,
             "Get sparse matrix from fields")
        
        // Operators
        .def("__getitem__", [](const Element &e, integer i) { return e[i]; })
        .def("__setitem__", [](Element &e, integer i, realdp val) { e[i] = val; })
        .def(py::self + py::self)
        .def(py::self + realdp())
        .def(realdp() + py::self)
        .def(py::self += py::self)
        .def(py::self - py::self)
        .def(py::self - realdp())
        .def(realdp() - py::self)
        .def(py::self -= py::self)
        .def(py::self * py::self)
        .def(py::self * realdp())
        .def(realdp() * py::self)
        .def(py::self / py::self)
        .def(py::self / realdp())
        .def(realdp() / py::self)
        .def(py::self % py::self)
        .def(py::self == py::self)
        .def(py::self == realdp())
        .def(realdp() == py::self)
        .def(py::self > py::self)
        .def(py::self > realdp())
        .def(realdp() > py::self)
        .def(py::self >= py::self)
        .def(py::self >= realdp())
        .def(realdp() >= py::self)
        .def(py::self < py::self)
        .def(py::self < realdp())
        .def(realdp() < py::self)
        .def(py::self <= py::self)
        .def(py::self <= realdp())
        .def(realdp() <= py::self)
        
        // Memory management
        .def("Delete", &Element::Delete, "Delete element data");
}