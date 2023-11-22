cmake_minimum_required(VERSION 3.21)
project(raylib_cpp_roguelike LANGUAGES CXX)

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Adding Raylib
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG 5.0
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(raylib)

# FetchContent_Declare(
#         imgui
#         GIT_REPOSITORY https://github.com/ocornut/imgui.git
#         GIT_TAG v1.90-docking
# )

# if (NOT imgui_POPULATED)
#     FetchContent_Populate(imgui)
#     set(IMGUI_INCLUDE_DIR ${imgui_SOURCE_DIR}/)
#     file(GLOB IMGUI_SOURCES ${imgui_SOURCE_DIR}/*.cpp)
#     file(GLOB IMGUI_HEADERS ${imgui_SOURCE_DIR}/*.h)
#     add_library(imgui STATIC ${IMGUI_SOURCES} ${IMGUI_SOURCES} ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp)
#     add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLAD)
#     target_include_directories(imgui PUBLIC ${IMGUI_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLFW_INCLUDE_DIR} ${GLAD_INCLUDE_DIR})
#     target_link_libraries(imgui ${OPENGL_LIBRARIES} glfw )
# endif ()

FetchContent_Declare(
    RlImGui
        GIT_REPOSITORY https://github.com/ProfAndreaPollini/rlImGui.git
        GIT_TAG 2c0df9e55a94a9f6991770fd2c11e5a67d40255d
)
FetchContent_MakeAvailable(RlImGui)


FetchContent_Declare(
    spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG "master"
)
FetchContent_MakeAvailable(spdlog)




add_executable(${PROJECT_NAME} main.cpp 
    src/Entity.cpp 
    src/Core/IntVector2.cpp 
    src/Core/Grid.cpp
    src/Core/World.cpp
    src/Commands/MoveCommand.cpp) 
target_link_libraries(${PROJECT_NAME} PRIVATE raylib imgui RlImGui spdlog)

target_include_directories(${PROJECT_NAME} PRIVATE ${RLIMGUI_HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC ${RLIMGUI_HEADERS} 
    src/ 
    src/Core/
    src/Commands/)

target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")