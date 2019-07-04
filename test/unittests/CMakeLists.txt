# Download and unpack googletest at configure time
configure_file( CMakeLists.txt.in googletest-download/CMakeLists.txt )
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" . RESULT_VARIABLE result WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if( result )
  message( FATAL_ERROR "CMake step for googletest failed: ${result}" )
endif()
execute_process( COMMAND ${CMAKE_COMMAND} --build . RESULT_VARIABLE result WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message( FATAL_ERROR "Build step for googletest failed: ${result}" )
endif()

# Prevent overriding the parent project's compiler/linker settings on Windows
set( gtest_force_shared_crt ON CACHE BOOL "" FORCE )

# Add googletest directly to our build. This defines the gtest and gtest_main targets.
add_subdirectory( ${CMAKE_CURRENT_BINARY_DIR}/googletest-src ${CMAKE_CURRENT_BINARY_DIR}/googletest-build EXCLUDE_FROM_ALL )

set( UNITTEST_SOURCES
    ${GIF_ROOT}/gifenc.c
    ${SOURCES_ROOT}/data.cpp
    ${SOURCES_ROOT}/htmlGen.cpp
    ${SOURCES_ROOT}/sort.cpp
    ${SOURCES_ROOT}/sort_bubble.cpp
    ${SOURCES_ROOT}/sort_insertion.cpp
    ${SOURCES_ROOT}/sort_merge.cpp
    ${SOURCES_ROOT}/sort_quick.cpp
    ${SOURCES_ROOT}/sort_selection.cpp

    ${UNITTEST_ROOT}/dataTest.cpp
    ${UNITTEST_ROOT}/gifTest.cpp
    ${UNITTEST_ROOT}/sortTest.cpp
)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -fno-exceptions -fno-inline -g -O0" )

set( UNITTEST_PROJECT_NAME "cppdatastructstest" )
include_directories( ${UNITTEST_PROJECT_NAME} ${PROJECT_SOURCE_DIR}/../include ${GIF_ROOT} )
add_executable( ${UNITTEST_PROJECT_NAME} ${UNITTEST_SOURCES} )
target_link_libraries( ${UNITTEST_PROJECT_NAME} gtest_main )

add_test( unittests 
          ${UNITTEST_PROJECT_NAME} 
          --gtest_output=xml:${CMAKE_CURRENT_BINARY_DIR}/${UNITTEST_PROJECT_NAME}_unittests.xml
          )
add_test( unittest_coverage_html 
          gcovr 
          --root ${PROJECT_SOURCE_DIR}/.. 
          --exclude .*test.* 
          --sort-percentage 
          --print-summary 
          --fail-under-line 100 
          --fail-under-branch 100 
          --html -o ${CMAKE_CURRENT_BINARY_DIR}/${UNITTEST_PROJECT_NAME}_coverage.html
          ${COVERAGE_FLAGS}
          )
add_test( unittest_coverage_xml
          gcovr
          --root ${PROJECT_SOURCE_DIR}/.. 
          --exclude .*test.* 
          --sort-percentage 
          --print-summary 
          --fail-under-line 100 
          --fail-under-branch 100 
          --xml -o ${CMAKE_CURRENT_BINARY_DIR}/${UNITTEST_PROJECT_NAME}_coverage.xml
          )
