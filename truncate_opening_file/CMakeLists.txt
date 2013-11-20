project (truncate_opening_file)
cmake_minimum_required (VERSION 2.6)

set (truncate_opening_file_SOURCE_FILES
	error.c
	tellwait.c
	main.c
)

add_executable (truncate_opening_file ${truncate_opening_file_SOURCE_FILES})
