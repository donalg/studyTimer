cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

SET(GCC_COVERAGE_COMPILE_FLAGS " -Wall")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})


SET(COMPILE_DEFINITIONS -O2)

include_directories(${headers} resources/)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

set(ADDITIONAL_FILES ${headers}/studyTimerGUI.c ${headers}/studyTimerGUI.h)
add_executable(studyTimer src/studyTimer.c)
target_link_libraries(studyTimer ${GTK3_LIBRARIES})
