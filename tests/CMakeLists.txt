include_directories(${COMMON_INCLUDES})

add_executable(run_tests ${SOURCES} ${PROJECT_NAME}_tests.cpp)

# Standard linking to gtest stuff.
target_link_libraries(run_tests gtest gtest_main)

# Extra linking for the project.
target_link_libraries(run_tests ${PROJECT_NAME})

# This is so you can do 'make test' to see all your tests run, instead of
# manually running the executable run_tests to see those specific tests.
# add_test(NAME that-test-I-made COMMAND run_tests)

# You can also omit NAME and COMMAND. The second argument could be some other
# test executable.
# TODO: `make test` doesn't work because it wants tests specififed here
# Figure out how to make it more generic!
#add_test(QueueInitTest run_tests)

# Testing C with googletest
# https://meekrosoft.wordpress.com/2009/11/09/unit-testing-c-code-with-the-googletest-framework/
