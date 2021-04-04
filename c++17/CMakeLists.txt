enable_testing()

add_executable(c++17_test
    aggregate_initialization.cpp
    constexpr_if.cpp
    structured_binding.cpp
)

set_property(TARGET c++17_test PROPERTY CXX_STANDARD 17)

target_link_libraries(
    c++17_test
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(c++17_test)
