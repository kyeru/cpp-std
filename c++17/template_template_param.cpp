#include <type_traits>
#include <vector>
#include <gtest/gtest.h>

template <typename T>
struct Param {
    using elem = T;
};

TEST(TemplateParam, ParamCheck) {
    ASSERT_TRUE((std::is_same<Param<std::vector<int>>::elem, std::vector<int>>::value));
}

template <template <typename> typename U>
struct ParamParam {
    using IntElem = U<int>;
    using FloatElem = U<float>;
};

TEST(TemplateParam, ParamParamCheck) {
    using IntVector = ParamParam<std::vector>::IntElem;
    ASSERT_TRUE((std::is_same<IntVector, std::vector<int>>::value));

    using FloatVector = ParamParam<std::vector>::FloatElem;
    ASSERT_TRUE((std::is_same<FloatVector, std::vector<float>>::value));
}

