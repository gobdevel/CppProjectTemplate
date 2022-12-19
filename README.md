# This is a template/skeleton for c++ application.

## It uses cmake and conan as build and package manager infra.

## How to use it -

- clone this repository.
- run setup.sh to clean up old git references.
- change project name in root's CMakeLists.txt.
- Edit conanfile.txt as per your need.
- create `build` directory in root folder.
- cd to build directory

- First pull all dependent libraries for this project using -

	```bash
	conan install .. # To install libraries defined in conanfile.txt
	conan install .. -b  # To build missing packages locally
	```
- Now build the project using `cmake`
  ```
  cmake .. # For normal cmake
  cmake .. -DBUILD_TEST=Yes # To build tests
  cmake .. -DBUILD_EXAMPLES=Yes # To build examples as well

  ```
- To compile the project use `make`

### How to update conan config on compiler update
`conan config init --force`
