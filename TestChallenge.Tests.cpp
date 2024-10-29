#include "TestChallenge.h"
#include <gtest/gtest.h>

TEST(AddFunctionTest, PositiveNumbers) {
    int result;
    add(10, 20, &result);
    EXPECT_EQ(result, 30);
}
