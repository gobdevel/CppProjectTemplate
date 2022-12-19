project(${PROJECT_NAME})

set(LIBNAME ${PROJECT_NAME}_lib)
set(TESTNAME ${PROJECT_NAME}_test)

# define my tests
enable_testing()

add_executable(${TESTNAME} sampleTest.cpp cacheTest.cpp)
target_link_libraries(${TESTNAME} ${LIBNAME} infra ${CONAN_LIBS})
add_test(NAME ${TESTNAME} COMMAND $<TARGET_FILE:${TESTNAME}> --no-version)
