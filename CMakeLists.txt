cmake_minimum_required(VERSION 3.22)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain")

project(ARAP-Visualizer LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.h include/*.hpp)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES}
        src/Application.cpp
        src/Application.h
        src/BaseModel.cpp
        src/BaseModel.h
        src/Camera.cpp
        src/Camera.h
        src/Vector.cpp
        src/Vector.h
        src/Matrix.cpp
        src/Matrix.h
        src/GameObject.cpp
        src/GameObject.h
        src/Model.cpp
        src/Model.h
        src/AABB.cpp
        src/AABB.h
        src/Texture.cpp
        src/Texture.h
        src/IndexBuffer.cpp
        src/IndexBuffer.h
        src/VertexBuffer.cpp
        src/VertexBuffer.h
        src/Color.cpp
        src/Color.h
        src/PhongShader.cpp
        src/PhongShader.h
        src/BaseShader.cpp
        src/BaseShader.h)

# dependencies (vcpkg)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(assimp CONFIG REQUIRED)
find_package(GLEW CONFIG REQUIRED)
# stb = header only → no find_package needed

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        glfw
        imgui::imgui
        assimp::assimp
        GLEW::GLEW
)

# include dirs for your headers + stb
target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/include
)

if (WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

if(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE GL X11 pthread dl)
endif()

message(STATUS "Configured for ${CMAKE_SYSTEM_NAME}")
