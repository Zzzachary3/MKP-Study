from setuptools import setup, Extension
import pybind11

# List all your C++ source files
cpp_files = [
    'Graph.cpp',
    'bindings.cpp',
    # Add any other .cpp files your project uses (e.g., Utility.cpp?)
]

# Define the C++ extension
ext_modules = [
    Extension(
        'kplex_finder',  # Must match the name in PYBIND11_MODULE
        sources=cpp_files,
        include_dirs=[
            pybind11.get_include(), # Add pybind11 headers
            # Add any other include directories your project needs
        ],
        language='c++',
        extra_compile_args=['-std=c++11'], # Or c++14, c++17, etc.
    ),
]

setup(
    name='kplex_finder',
    version='0.1.0',
    description='Python binding for k-plex finder',
    ext_modules=ext_modules,
)
