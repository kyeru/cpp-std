#include "inline_variable.hpp"
#include <gtest/gtest.h>

TEST(InlineVariable, AccessVar) {
    ASSERT_EQ(myspace::return_inline_var(), myspace::inline_var);
}
