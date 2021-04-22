#include <string_view>
#include <gtest/gtest.h>

int len(const std::string& s) {
    return std::string_view{s}.size();
}

TEST(StringView, length) {
    ASSERT_EQ(len("abc"), 3);
    ASSERT_EQ(len(std::string(10, 'a')), 10);
}
