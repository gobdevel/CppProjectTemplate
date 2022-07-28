project(${PROJECT_NAME})

set(INFRA "infra")
add_library(${INFRA} config.cpp logger.cpp)
target_include_directories(${INFRA} PUBLIC ${CMAKE_SOURCE_DIR}/include)
