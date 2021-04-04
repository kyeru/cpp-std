#include <type_traits>
#include <string>
#include <gtest/gtest.h>

template <typename T>
constexpr bool is_integral() {
    if constexpr (std::is_integral_v<T>)
        return true;
    else
        return false;
}

TEST(ConstexprTest, IsIntegral) {
    ASSERT_EQ(is_integral<int>(), true);
    ASSERT_EQ(is_integral<float>(), false);
    ASSERT_EQ(is_integral<char>(), true);
    ASSERT_EQ(is_integral<double>(), false);
    ASSERT_EQ(is_integral<std::string>(), false);
}
