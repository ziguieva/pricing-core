#pragma once

#include "pricing/core/types.hpp"

namespace pricing {

/**
 * Time utilities used across the pricing engine.
 */
struct TimeGrid
{
    Time start;
    Time end;
    Size steps;
};

} // namespace pricing
