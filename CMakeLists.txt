cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(CoCsCube)

find_package(Geant4 REQUIRED ui_all vis_all)

include_directories(include)

include(${Geant4_USE_FILE})

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)

file(GLOB MACRO_FILES "*.mac")

file(COPY ${MACRO_FILES} DESTINATION ${PROJECT_BINARY_DIR})

add_executable(CoCsCubeEXE main.cc ${sources})
target_link_libraries(CoCsCubeEXE ${Geant4_LIBRARIES})
add_custom_target(CoCsCube DEPENDS CoCsCubeEXE)
