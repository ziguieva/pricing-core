#pragma once

#include "pricing/core/types.hpp"

namespace pricing {

/**
 * Abstract payoff.
 */
class Payoff
{
public:
    virtual ~Payoff() = default;

    /**
     * @brief Evaluate payoff given terminal asset price.
     */
    virtual Real operator()(Real spot) const = 0;
};

} // namespace pricing
