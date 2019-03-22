cmake_minimum_required (VERSION 2.6)
project(CMake_SubDirectory)

  	# set stuff for windows
  	#set mysql connector path
	set(FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR C:/mysql_connector_8_0_12_winx64)
	
	#set log4cpp path
	set(PATH_TO_LOG4CPP C:/log4cpp/origin)
	set(PATH_TO_LOG_BOOST C:/mingw_boost_64/MinGW)
	
	#set boost library path
	set(PATH_TO_BOOST "C:/mingw_boost_64/MinGW")
	set(BOOST_USE_STATIC_LIBS OFF)
	set(CMAKE_INSTALL_PREFIX ../../) 
	
	#assign above path into include_directories accordingly
	include_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include)
	include_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include/cppconn)
	include_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include/jdbc)
	
	#log4cpp
	include_directories(${PATH_TO_LOG4CPP}/include)
	
	#boost
	include_directories(${PATH_TO_BOOST}/include)
	
	#assign project header file from include folder to include_directories
	#include_directories(${CMAKE_CURRENT_BINARY_DIR}/libcms)
	
	#add link library using set path
	link_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/lib64)
	link_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/lib64/vs14)
	
	#link_directories(${PATH_TO_LOG4CPP}/lib)
	#link_directories(${PATH_TO_BOOST}/lib)
	link_directories(${PATH_TO_LOG_BOOST})
  


add_subdirectory(library)
add_subdirectory(tests)