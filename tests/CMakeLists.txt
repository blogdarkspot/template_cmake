add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set_target_properties(gtest PROPERTIES FOLDER extern)
set_target_properties(gtest_main PROPERTIES FOLDER extern)
set_target_properties(gmock PROPERTIES FOLDER extern)
set_target_properties(gmock_main PROPERTIES FOLDER extern)

macro(package_add_test_with_libraries TESTNAME FILES LIBRARIES TEST_WORKING_DIRECTORY)
    add_executable(${TESTNAME} ${FILES})
    target_link_libraries(${TESTNAME} gtest gmock gtest_main ${LIBRARIES})
    gtest_discover_tests(${TESTNAME}
        WORKING_DIRECTORY ${TEST_WORKING_DIRECTORY}
        PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${TEST_WORKING_DIRECTORY}"
    )
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

package_add_test_with_libraries(sample_test sample_test.cpp template::sample "")

if (CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage)
    append_coverage_compiler_flags()

    # optional excludes - None needed here
    #    set(COVERAGE_EXCLUDES)

    # Works
    setup_target_for_coverage_gcovr_xml(
            NAME TestSampleCoverageXml
            EXECUTABLE sample_test 
            DEPENDENCIES sample_test template::sample 
    )
    # Works
    setup_target_for_coverage_gcovr_html(
            NAME TestSampleCoverageHtml
            EXECUTABLE sample_test 
            DEPENDENCIES sample_test template::sample 
    )
    # This one did not work for me:
    setup_target_for_coverage_lcov(
            NAME TestSampleCoverageLcov
            EXECUTABLE sample_test 
            DEPENDENCIES sample_test template::sample 
    )
endif ()