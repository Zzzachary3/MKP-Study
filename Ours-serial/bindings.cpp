#include <pybind11/pybind11.h>
#include <pybind11/stl.h> // Needed to convert std::vector to Python lists
#include "Graph.h"       // Include your main Graph header

namespace py = pybind11;

// This macro creates the Python module.
// "kplex_finder" is the name Python will use (e.g., import kplex_finder)
// "m" is the module object.
PYBIND11_MODULE(kplex_finder, m) {
    m.doc() = "Python module for finding k-plexes"; // Optional module docstring

    // Bind your Graph class
    py::class_<Graph>(m, "Graph")
        // Bind the constructor
        // This maps Python: g = kplex_finder.Graph("file.csv", 3)
        // To C++: new Graph("file.csv", 3)
        .def(py::init<const char *, int>(), py::arg("filename"), py::arg("k"))

        // Bind the methods you want to call from Python
        .def("read", &Graph::read, "Reads the graph from the file")
        .def("search", &Graph::search, "Finds the maximum k-plex")
        .def("search_dense", &Graph::search_dense, "Finds the densest k-plex")
        
        // Bind the new getter function
        .def("get_kplex", &Graph::get_kplex, "Returns the list of nodes in the found k-plex");

    // You can also bind other functions or classes here if needed
}
