# This is a template/skeleton for c++ application.

## It uses cmake and conan as build and package manager infra.

## How to use it -

- clone this repository.
- run setup.sh to clean up old git references.
- change project name in root's CMakeLists.txt.
- Edit conanfile.txt as per your need.
- create build directory in root folder.
- cd to build and -
  - conan install ..
  - cmake ..
  - make
