#include <gtest/gtest.h>

#include "pricing/models/black_scholes.hpp"

using namespace pricing;

TEST(BlackScholesDynamics, DriftComputation)
{
    const Real mu = 0.05;
    const Real sigma = 0.2;

    BlackScholesDynamics bs(mu, sigma);

    const Real spot = 100.0;
    EXPECT_DOUBLE_EQ(bs.drift(0.0, spot), mu * spot);
}

TEST(BlackScholesDynamics, DiffusionComputation)
{
    const Real mu = 0.05;
    const Real sigma = 0.2;

    BlackScholesDynamics bs(mu, sigma);

    const Real spot = 100.0;
    EXPECT_DOUBLE_EQ(bs.diffusion(0.0, spot), sigma * spot);
}
