#pragma once

#include "pricing/core/types.hpp"

namespace pricing {

/**
 * Abstract random number generator.
 * Allows reproducibility and testing.
 */
class RandomGenerator
{
public:
    virtual ~RandomGenerator() = default;

    virtual Real next() = 0;
};

} // namespace pricing
