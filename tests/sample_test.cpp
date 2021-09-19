#include "sample.h"

#include "gtest/gtest.h"

TEST(SampleTest, SumTest)
{
    int x = 10, y = 20;
    auto ret = sum(x, y);
    EXPECT_EQ(ret, 30);
}