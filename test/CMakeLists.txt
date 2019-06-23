cmake_minimum_required( VERSION 3.5 )

enable_testing( )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror" )

set( SOURCES_ROOT ${PROJECT_SOURCE_DIR}/../src )
set( UNITTEST_ROOT ${PROJECT_SOURCE_DIR}/unittests )

add_subdirectory( ${SOURCES_ROOT} ${PROJECT_BINARY_DIR}/zerombq )
add_subdirectory( ${UNITTEST_ROOT} )
