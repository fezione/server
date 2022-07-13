cmake_minimum_required( VERSION 3.0 )

project( server )

set( default_build_type "Debug" )

set( CMAKE_BUILD_TYPES ${default_build_type}  )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )
set( CMAKE_AUTORCC ON )

set( src 
	main.cpp
	tcpserver.cpp
)

set( hdrs
	tcpserver.h
)

add_executable( ${PROJECT_NAME} ${src} ${hdrs} )

find_package( Qt5 REQUIRED COMPONENTS Widgets )
find_package( Qt5 REQUIRED COMPONENTS Core )

target_link_libraries( ${PROJECT_NAME} Qt5::Widgets Qt5::Core )
