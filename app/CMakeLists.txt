project(${PROJECT_NAME})
set(APP_NAME "app")

add_executable(${APP_NAME} main.cpp)

target_link_libraries(${APP_NAME} ${PROJECT_NAME}_lib ${CONAN_LIBS})
target_include_directories(${APP_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
