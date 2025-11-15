cmake_minimum_required(VERSION 4.0)

# project name & language
project(my_fbp C)

# for nvim
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# find FFTW (stop if not found)
find_package(FFTW3 REQUIRED)

# find all .c files in src/
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.c)

# create shared library
add_library(my_fbp SHARED ${sources})

# link library against FFTW (only my_fbp uses fftw)
target_link_libraries(my_fbp PRIVATE FFTW3::fftw3)

# export headers
target_include_directories(
  my_fbp # Target Name
  PUBLIC # Headers for user and library
         $<INSTALL_INTERFACE:include> # when building
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>) # when
                                                                 # installing

# how library is installed
install(
  TARGETS my_fbp
  EXPORT my_fbp_targets # For use by other CMake projects
  LIBRARY DESTINATION lib # Where the .so file goes
  ARCHIVE DESTINATION lib # Where the .a file (if any) goes
)
install(DIRECTORY include/my_fbp/ DESTINATION include # Where the headers go
)

# add test directory
add_subdirectory(tests)
