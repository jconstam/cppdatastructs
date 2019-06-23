TRAVIS_BUILD_NUMBER ?= 0

ROOT_PATH=$(shell pwd)

SOURCE_PATH=${ROOT_PATH}/src
INCLUDE_PATH=${ROOT_PATH}/include
TEST_PATH=${ROOT_PATH}/test

BUILD_PATH=${ROOT_PATH}/build
OUTPUT_PATH=${BUILD_PATH}/cppdatastructs
OUTPUT_TEST_PATH=${OUTPUT_PATH}/test

.PHONY: build
build:
	mkdir -p ${OUTPUT_PATH}
	cd ${OUTPUT_PATH} && cmake ${SOURCE_PATH} && $(MAKE) $(MAKEFLAGS)

.PHONY: test
test: build_tests
	cd ${OUTPUT_TEST_PATH} && ctest --output-on-failure

.PHONY: test_coverage
test_coverage: build_tests_coverage
	cd ${OUTPUT_TEST_PATH} && ctest --output-on-failure

.PHONY: build_tests
build_tests:
	mkdir -p ${OUTPUT_TEST_PATH}
	cd ${OUTPUT_TEST_PATH} && cmake ${TEST_PATH} && $(MAKE) $(MAKEFLAGS)

.PHONY: build_tests_coverage
build_tests_coverage:
	mkdir -p ${OUTPUT_TEST_PATH}
	cd ${OUTPUT_TEST_PATH} && cmake ${TEST_PATH} -DCOVERAGE_FLAGS=--html-detail && $(MAKE) $(MAKEFLAGS)

.PHONY: clean
clean:
	rm -rf ${BUILD_PATH}
