add_library(
	library
	src/MM/Message.h
	src/MM/Message.cpp
)

target_include_directories(library PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")