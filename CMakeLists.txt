cmake_minimum_required(VERSION 3.22)

set(srcfiles "src/main.c" "src/ui/mainwindow.c")
set(includedirs "src/include/ui")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)
set(ONCAMERA_DEBUG "false")

project(oncamera)

if(${ONCAMERA_DEBUG} STREQUAL "false" AND WIN32 EQUAL TRUE)

set(CMAKE_C_FLAGS "-mwindows")
endif()
add_executable(${PROJECT_NAME} ${srcfiles})
if(WIN32 EQUAL TRUE)
target_compile_definitions(${PROJECT_NAME} PRIVATE ${GTK_CFLAGS_OTHER})
target_link_libraries(${PROJECT_NAME} PRIVATE ${GTK_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${GTK_INCLUDE_DIRS} ${includedirs})
target_link_directories(${PROJECT_NAME} PRIVATE ${GTK_LIBRARY_DIRS})
else()

endif()

# Create UI files

if (EXISTS "${CMAKE_CURRENT_BINARY_DIR}/ui") 
file(REMOVE_RECURSE "${CMAKE_CURRENT_BINARY_DIR}/ui/")
endif()
file(MAKE_DIRECTORY "ui")
file(COPY "ui/" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/ui")
