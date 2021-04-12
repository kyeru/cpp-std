#include <map>
#include <numeric>
#include <tuple>
#include <gtest/gtest.h>

TEST(StructuredBindingTest, InitializerList) {
    auto [a, b, c] = std::tuple{1, 2, 3};
    ASSERT_EQ(a, 1);
    ASSERT_EQ(b, 2);
    ASSERT_EQ(c, 3);

    int l[3] = {2, 2, 3};
    auto& [d, e, f] = l;
    d = 0;
    ASSERT_EQ(l[0], d);
    ASSERT_EQ(l[1], e);
    ASSERT_EQ(l[2], f);
}

int return_key_sum(const std::map<int, int>& m) {
    int sum = 0;
    for (const auto& [key, value] : m) {
        sum += key;
    }
    return sum;
}

int return_value_sum(const std::map<int, int>& m) {
    int sum = 0;
    for (const auto& [key, value] : m) {
        sum += value;
    }
    return sum;
}

TEST(StructuredBindingTest, KeySum) {
    std::map<int, int> m;
    m.try_emplace(1, 10);
    m.try_emplace(2, 20);
    m.try_emplace(3, 30);

    EXPECT_EQ(return_key_sum(m), 6);
    EXPECT_EQ(return_value_sum(m), 60);
}

auto return_tuple2() {
    return std::tuple{1, 2};
}

auto return_tuple3() {
    return std::tuple{1, 2, 3};
}

TEST(StructuredBindingTest, ReturnTuple2) {
    auto [a, b] = return_tuple2();
    ASSERT_EQ(a, 1);
    ASSERT_EQ(b, 2);
}

TEST(StructuredBindingTest, ReturnTuple3) {
    auto [a, b, c] = return_tuple3();
    ASSERT_EQ(a, 1);
    ASSERT_EQ(b, 2);
    ASSERT_EQ(c, 3);
}
