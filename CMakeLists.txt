cmake_minimum_required(VERSION 3.23)

set(srcfiles "src/main.c")
set(includefiles "src/include/files")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)

project(oncamera)

add_executable(${PROJECT_NAME} ${srcfiles})
target_link_libraries(${PROJECT_NAME} PRIVATE ${GTK_LIBRARIES})
target_compile_definitions(${PROJECT_NAME} PRIVATE ${GTK_CFLAGS_OTHER})
target_include_directories(${PROJECT_NAME} PRIVATE ${GTK_INCLUDE_DIRS})
target_link_directories(${PROJECT_NAME} PRIVATE ${GTK_LIBRARY_DIRS})
add_compile_options(-mwindows)

# Create UI files

if (EXISTS "${CMAKE_CURRENT_BINARY_DIR}/ui") 
file(REMOVE_RECURSE "${CMAKE_CURRENT_BINARY_DIR}/ui/")
endif()
file(MAKE_DIRECTORY "ui")
file(COPY "ui/" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/ui")
