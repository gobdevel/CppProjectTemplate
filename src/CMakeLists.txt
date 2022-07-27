project(${PROJECT_NAME})

set(LIBNAME ${PROJECT_NAME}_lib)

add_library(${LIBNAME} app.cpp logger.cpp)
target_include_directories(
    ${LIBNAME}
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include)
