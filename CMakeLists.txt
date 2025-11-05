cmake_minimum_required(VERSION 4.0) 
project(my_fbp C) 

# for nvim
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Compiles the source files into a SHARED library named 'my_fbp'
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.c)
add_library(
    my_fbp
    SHARED 
		${sources}
)

# Tells CMake where the public header files are.
# INTERFACE means these headers are required by users, but not to build the library itself.
target_include_directories(
    my_fbp													# Target Name
		PUBLIC													# Headers for user and library
    $<INSTALL_INTERFACE:include>		# Path (The generator expression handles installation)
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# Installs the compiled library file (.so/.dll) to the system's /lib directory
install(
    TARGETS my_fbp
    EXPORT my_fbp_targets					# For use by other CMake projects
    LIBRARY DESTINATION lib       # Where the .so file goes
    ARCHIVE DESTINATION lib       # Where the .a file (if any) goes
)

# Installs the public header files to the system's /include directory
install(
    DIRECTORY include/my_fbp/
    DESTINATION include          # Where the header files go
)

add_subdirectory(tests)
