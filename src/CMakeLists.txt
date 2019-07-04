cmake_minimum_required( VERSION 3.5 )

set( PROJECT_NAME_LIBRARY "cppdatastructs" )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror" )

project( ${PROJECT_NAME_LIBRARY} ) 

set( SOURCES 
	${PROJECT_SOURCE_DIR}/../gif/gifenc.c

	${PROJECT_SOURCE_DIR}/main.cpp
	${PROJECT_SOURCE_DIR}/htmlGen.cpp
)

include_directories( ${PROJECT_NAME_LIBRARY} ${PROJECT_SOURCE_DIR}/../include ${PROJECT_SOURCE_DIR}/../gif )
add_executable( ${PROJECT_NAME_LIBRARY} ${SOURCES} )