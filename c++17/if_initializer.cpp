#include <gtest/gtest.h>

int if_initialize_func(int i) {
    if (auto base = 10u; base + i < 20)
        return 0;
    else if (auto base = 5u; base + i < 20)
        return 1;
    else
        return 2;
}

TEST(IfInitializeTest, InitTest) {
    ASSERT_EQ(if_initialize_func(1), 0);
    ASSERT_EQ(if_initialize_func(11), 1);
    ASSERT_EQ(if_initialize_func(21), 2);
}
