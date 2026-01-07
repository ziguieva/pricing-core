#include <gtest/gtest.h>

#include "pricing/payoff/european_call.hpp"

using namespace pricing;

TEST(EuropeanCallPayoff, PositivePayoff)
{
    EuropeanCall call(100.0);
    EXPECT_DOUBLE_EQ(call(120.0), 20.0);
}

TEST(EuropeanCallPayoff, ZeroPayoffAtTheMoney)
{
    EuropeanCall call(100.0);
    EXPECT_DOUBLE_EQ(call(100.0), 0.0);
}

TEST(EuropeanCallPayoff, ZeroPayoffOutOfTheMoney)
{
    EuropeanCall call(100.0);
    EXPECT_DOUBLE_EQ(call(80.0), 0.0);
}
