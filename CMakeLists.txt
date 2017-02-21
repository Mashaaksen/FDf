cmake_minimum_required(VERSION 3.6)
project(FdF)

set(CMAKE_C_FLAGS "-std=c99 -Wall -Wextra -Werror")

include_directories(includes libft/includes minilibx) # headers
link_directories(libft minilibx_macos) # libraries

set(SOURCE_FILES fdf.h get_next_line.c or_file.c fdf.c main.c) # sources

add_executable(FdF ${SOURCE_FILES}) # compilation

target_link_libraries(FdF libft.a libmlx.a "-framework OpenGL" "-framework AppKit") # linkage