#include <map>
#include <numeric>
#include <gtest/gtest.h>

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
