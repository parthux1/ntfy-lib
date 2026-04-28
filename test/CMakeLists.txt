enable_testing()

add_executable(ntfy-test test_jsonFunc.cpp)

target_link_libraries(ntfy-test GTest::gtest_main ntfy)
include(GoogleTest)
gtest_discover_tests(ntfy-test)
