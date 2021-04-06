#include <gtest/gtest.h>

namespace outer {

struct OuterS {
};

int overloaded_func(OuterS) {
    return 1;
}
 
}

namespace outer::inner {

struct InnerS {
};

int overloaded_func(InnerS) {
    return 2;
}

}

TEST(NestedNamespaceTest, ADL) {
    outer::OuterS s1;
    ASSERT_EQ(overloaded_func(s1), 1);

    outer::inner::InnerS s2;
    ASSERT_EQ(overloaded_func(s2), 2);
}
