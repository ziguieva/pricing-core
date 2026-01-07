#pragma once

#include "pricing/math/random.hpp"
#include "pricing/core/types.hpp"

#include <random>

namespace pricing {

/**
 * Gaussian random number generator using standard normal distribution.
 *
 * This generator is reproducible through explicit seeding.
 */
class GaussianRNG : public RandomGenerator
{
public:
    explicit GaussianRNG(unsigned int seed);

    Real next() override;

private:
    std::mt19937 engine_;
    std::normal_distribution<Real> distribution_;
};

} // namespace pricing
