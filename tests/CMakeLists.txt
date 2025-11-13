cmake_minimum_required(VERSION 4.0)
project(test_fft)

# copy csv files to build/
configure_file(data_fft.csv ${PROJECT_BINARY_DIR}/data_fft.csv COPYONLY)

add_executable(test_fft test_fft.c)

target_link_libraries(test_fft PRIVATE my_fbp)
