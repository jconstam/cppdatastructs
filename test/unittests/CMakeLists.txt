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
    ${SOURCES_ROOT}/htmlGen.cpp
    ${SOURCES_ROOT}/gifData.cpp

    ${SOURCES_ROOT}/data/linkList.cpp
    ${SOURCES_ROOT}/data/queue.cpp

    ${SOURCES_ROOT}/sort/dataStor.cpp
    ${SOURCES_ROOT}/sort/sort.cpp
    ${SOURCES_ROOT}/sort/sort_bubble.cpp
    ${SOURCES_ROOT}/sort/sort_insertion.cpp
    ${SOURCES_ROOT}/sort/sort_merge.cpp
    ${SOURCES_ROOT}/sort/sort_quick.cpp
    ${SOURCES_ROOT}/sort/sort_selection.cpp

    ${UNITTEST_ROOT}/dataTest.cpp
    ${UNITTEST_ROOT}/gifTest.cpp
    ${UNITTEST_ROOT}/htmlGenTest.cpp
    ${UNITTEST_ROOT}/linkListTest.cpp
    ${UNITTEST_ROOT}/queueTest.cpp
    ${UNITTEST_ROOT}/sortTest.cpp
)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -fno-inline -O0" )

set( UNITTEST_PROJECT_NAME "cppdatastructstest" )
include_directories( ${UNITTEST_PROJECT_NAME} ${PROJECT_SOURCE_DIR}/../include ${GIF_ROOT} )
add_executable( ${UNITTEST_PROJECT_NAME} ${UNITTEST_SOURCES} )
target_link_libraries( ${UNITTEST_PROJECT_NAME} gtest_main )

add_test( unittests 
          ${UNITTEST_PROJECT_NAME} 
          --gtest_output=xml:${CMAKE_CURRENT_BINARY_DIR}/${UNITTEST_PROJECT_NAME}_unittests.xml
          )
add_test( unittest_coverage
          lcov
          --capture
          --directory ${PROJECT_SOURCE_DIR}/..
          --output-file ${CMAKE_CURRENT_BINARY_DIR}/${UNITTEST_PROJECT_NAME}_raw.info
          )
add_test( unittest_coverage_filter 
          lcov 
          --remove ${CMAKE_CURRENT_BINARY_DIR}/${UNITTEST_PROJECT_NAME}_raw.info "/usr/*" "*googletest*" "*unittests*"
          --output-file ${CMAKE_CURRENT_BINARY_DIR}/${UNITTEST_PROJECT_NAME}_filtered.info 
          )
add_test( unittest_coverage_html 
          genhtml
          ${CMAKE_CURRENT_BINARY_DIR}/${UNITTEST_PROJECT_NAME}_filtered.info
          --output-directory ${CMAKE_CURRENT_BINARY_DIR}
          )
add_test( unittest_coverage_xml
          python -m lcov_cobertura
          ${CMAKE_CURRENT_BINARY_DIR}/${UNITTEST_PROJECT_NAME}_filtered.info
          -b ${PROJECT_SOURCE_DIR}
          -o ${CMAKE_CURRENT_BINARY_DIR}/${UNITTEST_PROJECT_NAME}.xml
          )
