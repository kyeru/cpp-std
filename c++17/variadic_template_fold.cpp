#include <algorithm>
#include <vector>
#include <gtest/gtest.h>

template <typename ... T>
auto sum(T ... args) {
    return (args + ...);
}

template <typename ... T>
auto sum2(T ... args) {
    return (... + args);
}

template <typename ... T, typename U>
auto sumWithBase(U base, const T ... args) {
    return (args + ... + base);
}

template <typename ... T, typename U>
auto subtractFromBase(U base, const T ... args) {
    return (base - ... - args);
}

TEST(VariadicTemplateTest, FoldExpression) {
    ASSERT_EQ(sum(1, 2, 3), 6);
    ASSERT_EQ(sum(1, 2, 3, 4), 10);

    ASSERT_EQ(sum2(1, 2, 3), 6);
    ASSERT_EQ(sum2(1, 2, 3, 4), 10);

    ASSERT_EQ(sumWithBase(0, 1, 2, 3), 6);
    ASSERT_EQ(sumWithBase(10, 1, 2, 3, 4), 10 + 10);

    ASSERT_EQ(subtractFromBase(100, 1, 2, 3), 100 - 6);
    ASSERT_EQ(subtractFromBase(0, 1, 2, 3), -6);
}
