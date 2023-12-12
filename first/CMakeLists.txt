cmake_minimum_required(VERSION 3.5)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
 
project(Test)
 
find_package(glfw3 REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/thirdparty/glm  
                    ${PROJECT_SOURCE_DIR}/thirdparty/stb)


file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/main.cpp
                    ${PROJECT_SOURCE_DIR}/src/glad.c
                    ${PROJECT_SOURCE_DIR}/src/stb_adapter.cpp
                    ${PROJECT_SOURCE_DIR}/src/shader_program.h
                    ${PROJECT_SOURCE_DIR}/src/Utils.h
                    ${PROJECT_SOURCE_DIR}/src/Utils.cpp
                    )

add_executable(${PROJECT_NAME} ${SRC_FILES})
 
target_link_libraries(${PROJECT_NAME} glfw)
