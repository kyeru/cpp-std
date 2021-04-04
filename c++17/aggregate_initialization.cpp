#include <gtest/gtest.h>

struct NoUserCtor {
    int i;
    int j;
};

struct WithUserCtor {
    int i;
    int j;

    // two user-declared constructors below prohibits aggregate initialization
    // WithUserCtor() : i{1}, j{2} {}
    // WithUserCtor() {}
    WithUserCtor() = default;
};


TEST(AggregateInitializerTest, InitTest) {
    NoUserCtor s1{1, 2};
    ASSERT_EQ(s1.i, 1);
    ASSERT_EQ(s1.j, 2);

    WithUserCtor s2{3, 4};
    ASSERT_EQ(s2.i, 3);
    ASSERT_EQ(s2.j, 4);
}
