enable_testing()

add_executable(c++17_test
    aggregate_initialization.cpp
    constexpr_if.cpp
    if_initializer.cpp
    inline_variable.cpp inline_variable2.cpp
    nested_namespace.cpp
    structured_binding.cpp
    template_template_param.cpp
    variadic_template_fold.cpp
    string_view.cpp
)

set_property(TARGET c++17_test PROPERTY CXX_STANDARD 17)

target_link_libraries(
    c++17_test
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(c++17_test)
