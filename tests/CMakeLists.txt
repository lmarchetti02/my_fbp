cmake_minimum_required(VERSION 4.0) 
project(test_fft)

add_executable(
	test_fft
	test_fft.c
)

target_link_libraries(
    test_fft
    PRIVATE
    my_fbp
)
